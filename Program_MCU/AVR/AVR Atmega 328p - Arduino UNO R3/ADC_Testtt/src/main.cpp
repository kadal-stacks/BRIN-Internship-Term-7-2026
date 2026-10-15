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
  kode normal saat ingin menggunakan I2C, bedanya ada di penggunaan alamat (chip)*/  


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

void BMP_init(){
  I2C_init();
  I2C_START();
  I2C_Write(BMP_280_ADDR << 1 | 0);
  I2C_Write(0xF4);
  I2C_Write(0x27);
  I2C_STOP();
}

void BMP_read_raw(int32_t *raw_temp, int32_t *raw_press){
  I2C_init();
  I2C_START();
  I2C_Write(BMP_280_ADDR << 1 | 0);
  I2C_Write(0xF4);

  I2C_START;
  I2C_Write(BMP_280_ADDR << 1 | 1);
  
  uint8_t p_msb  = I2C_Read_ACK();
  uint8_t p_lsb  = I2C_Read_ACK();
  uint8_t p_xlsb = I2C_Read_ACK();
    
  uint8_t t_msb  = I2C_Read_ACK();
  uint8_t t_lsb  = I2C_Read_ACK();
  uint8_t t_xlsb = I2C_Read_NACK();
  
  I2C_STOP();

  // Gabungkan bit menjadi 20-bit integer
    *raw_press = ((int32_t)p_msb << 12) | ((int32_t)p_lsb << 4) | (p_xlsb >> 4);
    *raw_temp  = ((int32_t)t_msb << 12) | ((int32_t)t_lsb << 4) | (t_xlsb >> 4);
}
// --- DRIVER ADC ---
void ADC_Init(void) {
    ADMUX = (1 << REFS0) | (1 << REFS1);                     // Ref = 1.1 V
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | 
             (1 << ADPS1) | (1 << ADPS0);     // ADEN = 1 (Enable ADC), Prescaler = 128 (16MHz / 128 = 125kHz)
}

uint16_t ADC_Read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x07);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

unsigned long last_adc_time = 0;
unsigned long last_bmp_time = 0;
float r_uji = 0;


void setup() {
//1. Inisialisasi Serial bawaan Arduino (Substitusi USART manual)
    Serial.begin(9600);
    // 2. Inisialisasi Hardware Register ADC
    ADC_Init();
    
    Serial.println("--- System Started ---");
}

// Main Function
void loop() {
    // Variabel Penjadwalan Non-blocking (Timer)
    //unsigned long last_bmp_time = 0;

    unsigned long current_time = millis();

        // TASK 1: Baca ADC setiap 200 ms (Fast Task)
        if (current_time - last_adc_time >= 200) {
          last_adc_time = current_time;  
          uint16_t adc_raw = ADC_Read(0);  
          float v_in = (adc_raw * 1.1) / 1024.0; //Pembagi tegangan
          float r_uji =  (v_in * 3600.0) / (5.0 - v_in);

          char str_v_in[10];
          char str_r_uji[10];
          dtostrf(v_in, 4, 2, str_v_in);   // float, min_width, desimal, buffer_tujuan
          dtostrf(r_uji, 6, 1, str_r_uji);
          
          char buffer[100];
          snprintf(buffer, sizeof(buffer), "[ADC]: %d | V_in: %s V | R_uji: %s Ohm\r\n", adc_raw, str_v_in, str_r_uji);
          
          Serial.print(buffer);
        }
        
        // TASK 2: Baca BMP280 Chip ID setiap 1000 ms (Slow Task)
        if (current_time - last_bmp_time >= 1000){      
            last_bmp_time = current_time;  
            uint8_t id = test_sensor();

            int32_t raw_temp = 0, raw_press = 0;
            BMP_read_raw(&raw_temp, &raw_press);
            char id_str[6];
            char temp_str[6];
            char press_str[6];

            dtostrf(id, 6, 1, id_str);
            dtostrf(raw_temp, 6, 1, temp_str);
            dtostrf(raw_press, 6, 1, press_str);

            char buffer_2 [100];
            snprintf(buffer_2, sizeof(buffer_2), " [BMP280 Chip ID]: 0x%02X\r\n Raw Temp: %ld | Raw Press: %ld\r\n", id_str, temp_str, press_str);
            Serial.print(buffer_2);
        }
}