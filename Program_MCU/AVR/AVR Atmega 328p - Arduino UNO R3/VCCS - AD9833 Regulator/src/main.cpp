
#include <Arduino.h>
#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>

// Angka ini di-set dengan mengasumsikan oscillator 25 MHz.
#define AD9833_MCLK_HZ 25000000UL

#define AD9833_MIN_FREQ 10UL
#define AD9833_MAX_FREQ 10000UL

// Alamat register AD9833
#define AD9833_FREQ0       0x4000
#define AD9833_PHASE0      0xC000

// Alamat register kontrol AD9833
#define AD9833_B28         0x2000
#define AD9833_RESET       0x0100

// FSYNC = PB2 (ATmega328P physical pin 16)
#define AD9833_FSYNC       PB2

// Inisialisasi SPI
void SPI_Init(void) {
//set up pin IO untuk SPI
    // PB2 = FSYNC output
    // PB3 = MOSI output
    // PB5 = SCK output

    DDRB |= (1 << DDB2)
          | (1 << DDB3)
          | (1 << DDB5);

    // FSYNC HIGH (inactive)
    // SCK HIGH (SPI Mode 2 idle state)

    PORTB |= (1 << AD9833_FSYNC)
           | (1 << PB5);

    // SPI Master
    /* SPI Mode 2: CPOL = 1, CPHA = 0 - Sample (Falling edge), Setup (Rising edge)
       MSB First
    */
    // Perhitungan frekuensi Clock = F_CPU / 4 = 4 MHz - SPR0 & SPR1 = 0
    SPCR = (1 << SPE) // Enable SPI
         | (1 << MSTR) // Master/slave Select - Master
         | (1 << CPOL); // Clock Polarity = 1 (Idle High) - Leading Edge : Falling, Trailing Edge : Rising

    // Disable SPI2X - Bit Mode Double Speed SPI
    SPSR = 0;
}

// SPI TRANSMISSION
void SPI_WriteByte(uint8_t data) {
    // Start transmission
    SPDR = data; // SPI Data Register

    // Wait until transmission is complete
    while (!(SPSR & (1 << SPIF))); // tunggu hingga bit flag SPIF pada SPI Status Register[SPSR] set (1)

    // Baca SPDR utk clear bit SPIF saat Bit SPIF di-set (1) setelah transmisi selesai
    uint8_t dummy = SPDR;
    (void)dummy;
}

// AD9833 16-BIT WRITE
void AD9833_Write16(uint16_t data) {

    // Activate AD9833
    PORTB &= ~(1 << AD9833_FSYNC);

    // Send MSB first
    SPI_WriteByte((uint8_t)(data >> 8));

    // Send LSB
    SPI_WriteByte((uint8_t)(data & 0xFF));

    // End transmission
    PORTB |= (1 << AD9833_FSYNC);
}

// Konfigurasi Frekuensi AD9833
bool AD9833_SetFrequency(uint32_t frequencyHz) {
    // Frequency range validation
    if (frequencyHz < AD9833_MIN_FREQ ||
        frequencyHz > AD9833_MAX_FREQ) {
        return false;
    }

    // hitung 28-bit frequency tuning word
    // Bulatkan ke nilai integer / bulat terdekat

    uint64_t numerator =
        ((uint64_t)frequencyHz << 28)
        + (AD9833_MCLK_HZ / 2ULL);

    uint32_t tuningWord =
        (uint32_t)(numerator / AD9833_MCLK_HZ);

    // Write 14 LSBs to FREQ0
    AD9833_Write16(
        AD9833_FREQ0 |
        (uint16_t)(tuningWord & 0x3FFF)
    );

    // Write 14 MSBs to FREQ0
    AD9833_Write16(
        AD9833_FREQ0 |
        (uint16_t)((tuningWord >> 14) & 0x3FFF)
    );

    return true;
}


// Inisialisasi AD9833
void AD9833_Init(void) {

    SPI_Init();

    // Meng-set B28 and RESET
    // B28 = 1: 28-bit frequency register mode
    // RESET = 1: Hold DDS output in reset

    AD9833_Write16(
        AD9833_B28 | AD9833_RESET
    );

    // Set phase register0 ke nol
    AD9833_Write16(AD9833_PHASE0);

    // Set output frequency awal ke 1 kHz
    AD9833_SetFrequency(1000UL);

    // Release RESET
    // B28 remains enabled
    // MODE = 0 and OPBITEN = 0: sine output

    AD9833_Write16(AD9833_B28);

    delayMicroseconds(10);
}

// SERIAL COMMAND HANDLER - UART

char commandBuffer[16];
uint8_t commandLength = 0;
bool commandOverflow = false;

void Serial_Command(void) {

    while (Serial.available() > 0) {

        char incoming = Serial.read();

        // Ignore carriage return
        if (incoming == '\r') {
            continue;
        }

        // Process command when Enter is pressed
        if (incoming == '\n') {

            if (commandOverflow) {

                Serial.println(F("ERROR: Input too long"));

            }
            else if (commandLength > 0) {

                commandBuffer[commandLength] = '\0';

                char *endptr;

                unsigned long frequency =
                    strtoul(commandBuffer, &endptr, 10);

                if (*endptr != '\0') {

                    Serial.println(F("ERROR: Invalid input"));

                }
                else if (AD9833_SetFrequency(
                             (uint32_t)frequency)) {

                    Serial.print(F("Frequency set: "));
                    Serial.print(frequency);
                    Serial.println(F(" Hz"));

                }
                else {

                    Serial.println(
                        F("ERROR: Frequency must be 10-10000 Hz")
                    );
                }
            }

            // Reset command buffer
            commandLength = 0;
            commandOverflow = false;

        }

        // Store numeric characters
        else if (incoming >= '0' && incoming <= '9') {

            if (commandLength < sizeof(commandBuffer) - 1) {

                commandBuffer[commandLength++] = incoming;

            }
            else {

                commandOverflow = true;
            }
        }

        // Ignore spaces and tabs
        else if (incoming != ' ' && incoming != '\t') {

            commandOverflow = true;
        }
    }
}

// MAIN PROGRAM
void setup() {

    Serial.begin(115200);

    AD9833_Init();

    Serial.println(F("=============================="));
    Serial.println(F(" AD9833 VCCS Frequency Control "));
    Serial.println(F("=============================="));

    Serial.println(F("Initial Frequency: 1000 Hz"));
    Serial.println(F("Range: 10 Hz - 10000 Hz"));
    Serial.println(F("Enter frequency in Hz:"));
}

void loop() {

    Serial_Command();
}
