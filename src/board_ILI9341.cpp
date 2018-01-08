#include <Arduino.h>
#include <SPI.h>


extern "C" {
#include "user_interface.h"
}

#define ESP_LCD_RS 15
#define ESP_LCD_CS 5

#define SPILOWSPEED 1000000
#define SPIHIGHSPEED 32000000

static SPISettings spiSettings(SPILOWSPEED, MSBFIRST, SPI_MODE0);

static inline void cmdmode() {
  digitalWrite(ESP_LCD_RS, 0);
}

static inline void datamode() {
  digitalWrite(ESP_LCD_RS, 1);
}

extern "C" void esp_lcd_init_board(void) {
  SPI.begin();
  pinMode(ESP_LCD_CS, OUTPUT);
  digitalWrite(ESP_LCD_CS, 1);
  pinMode(ESP_LCD_RS, OUTPUT);
  datamode();
}

extern "C" void esp_lcd_post_init_board(void) {
  spiSettings = SPISettings(SPIHIGHSPEED, MSBFIRST, SPI_MODE0);
}

static int aquire_count = 0;

extern "C" void esp_lcd_aquirebus(void) {
    if (!aquire_count++) {
        SPI.beginTransaction(spiSettings);
        digitalWrite(ESP_LCD_CS, 0);
    }
}

extern "C" void esp_lcd_releasebus(void) {
    if (aquire_count && !--aquire_count) {
        digitalWrite(ESP_LCD_CS, 1);
        SPI.endTransaction();
    }
}

extern "C" void esp_lcd_write_index(uint16_t cmd) {
  cmdmode();
  SPI.write(cmd);
  datamode();
}

extern "C" void esp_lcd_write_data(uint16_t data) {
  SPI.write(data);
}

