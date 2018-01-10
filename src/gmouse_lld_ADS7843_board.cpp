#include <Arduino.h>
#include <SPI.h>

extern "C" {
#include "user_interface.h"
}

#define ESP_TC_IRQ 4
#define ESP_TC_CS 16

#define SPISPEED 2000000

static SPISettings spiSettings(SPISPEED, MSBFIRST, SPI_MODE0);


extern "C" int esp_gmouse_init_board() {
    pinMode(ESP_TC_CS, OUTPUT);
    digitalWrite(ESP_TC_CS, 1);
    pinMode(ESP_TC_IRQ, INPUT);
    return 1;
}

extern "C" int esp_getpin_pressed() {
    system_soft_wdt_feed ();
    return digitalRead (ESP_TC_IRQ)==0;
}

static int aquire_count = 0;

extern "C" void esp_aquire_bus() {
    if (!aquire_count++) {
        SPI.beginTransaction(spiSettings);
        digitalWrite(ESP_TC_CS, 0);
    }
}

extern "C" void esp_release_bus() {
    if (aquire_count && !--aquire_count) {
        digitalWrite(ESP_TC_CS, 1);
        SPI.endTransaction();
    }
}

extern "C" uint16_t esp_read_value(uint16_t port) {
    SPI.write (port);
    return SPI.transfer16(0);
}
