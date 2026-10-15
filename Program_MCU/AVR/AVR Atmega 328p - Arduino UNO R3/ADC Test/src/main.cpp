#include <Arduino.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>



//Deklarasikan alamat sensor BMP280 pada register 0x76 atau 0x77
#define BMP_280_ADDR 0x76
#define F_CPU 16000000UL

/*Proses komunikasi I2C source ATMEGA 328p Datasheet by Atmel
[START] ──> [SLA+W (0xEC)] ──> [Register (0xD0)] ──> [REPEATED START] ──> [SLA+R (0xED)] ──> [READ NACK] ──> [STOP]*/

//Deklarasikan alamat dari sensor BMP280 sebagai variabel global untuk nanti dipanggil dalam fungsi protokol I2C
void I2C_init(){
  // Deklarasi setting bit rate operasi SCL di 100kHZ
  TWBR = 72;
  //Inisialisasi fungsi kerja control register untuk memulai interrut service routine dari I2C
  TWCR = (1 << TWEN);
}

void I2C_START(void){
    TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTA);
    while(!(TWCR & (1 << TWINT)));
}

void I2C_Write(uint8_t data_reg){
    TWDR = data_reg;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

//Penambahan bit TWEA pada nilai register kontrol Aknowledge Paket Alamat pada slave device 
uint8_t I2C_Read_ACK(void){
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

uint8_t I2C_Read_NACK(void){
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

void I2C_STOP(void){
    TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTO);
}

/*Line Kode by ChatGPT untuk melakukan cek apakah sensor bekerja, mirip seperti
  kode normal saat ingin menggunakan I2C, bedanya ada di penggunaan alamat (chip)  
*/
uint8_t test_sensor(void){
//definisikan nilai untuk menyimpan data alamat dari chip sensor 
uint8_t chip_id = 0;

I2C_START();
 
I2C_Write(BMP_280_ADDR << 1 | 0); //Shift left 1 bit alamat BMP dengan tambahan 1 bit 0 pada LSB untuk memulai read

I2C_Write(0xD0); // Alamat chip 

I2C_START();
I2C_Write(BMP_280_ADDR << 1 | 1); //Shift left 1 bit alamat BMP dengan tambahan 1 bit 1 pada LSB untuk memulai write

chip_id = I2C_Read_NACK(); //Baca satu bit LSB dari sensor, lalu Acknowledge

I2C_STOP(); // Stop pengiriman dan pembacaan data

return chip_id; //Harusnya bernilai 0x58 kalau sensor berfungsi
}


// --- DRIVER USART ---
void USART_Init(void) {
    UBRR0 = 103;                              // 9600 baud rate @ 16MHz
    UCSR0B = (1 << TXEN0);                    // Enable Transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   // 8-bit data
}

void USART_SendString(char *str) {
    while (*str) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = *str++;
    }
}

// --- DRIVER ADC ---
void ADC_Init(void) {
    ADMUX = (1 << REFS0) | (1 << REFS1);                     // Ref = AVcc (5V)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | 
             (1 << ADPS1) | (1 << ADPS0);     // Prescaler 128
}

uint16_t ADC_Read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x07);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

// Main Function
int main(void) {
    // Inisialisasi Hardware
    I2C_init();
    USART_Init();
    ADC_Init();

    char buffer[60];
    uint16_t adc_raw = ADC_Read(0);

    float v_in = (adc_raw * 1.1) / 1024; //Pembagi tegangan
    float r_uji =  (v_in * 3600) / (5 - v_in);

    // Variabel Penjadwalan Non-blocking (Timer)
    unsigned long last_adc_time = 0;
    unsigned long last_bmp_time = 0;

    USART_SendString("Mulai membaca\r\n");

    while (1) {
        unsigned long current_time = millis();

        // TASK 1: Baca ADC setiap 200 ms (Fast Task)
        if (current_time - last_adc_time >= 200) {
            last_adc_time = current_time;
            
            uint16_t adc_val = ADC_Read(0);
            sprintf(buffer, "[ADC]: %d \n v_in: %.2f V \n r_uji: %.1f Ohm\r \n %d\r\n", adc_raw, v_in, r_uji, adc_val);
            USART_SendString(buffer);
        }

        // TASK 2: Baca BMP280 Chip ID setiap 1000 ms (Slow Task)
        if (current_time - last_bmp_time >= 1000) {
            last_bmp_time = current_time;
            
            uint8_t id = test_sensor();
            sprintf(buffer, "   [BMP280 Chip ID]: 0x%02X\r\n", id);
            USART_SendString(buffer);
        }
    }
}