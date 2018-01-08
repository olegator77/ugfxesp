#ifndef _GINPUT_LLD_MOUSE_BOARD_H
#define _GINPUT_LLD_MOUSE_BOARD_H

// Resolution and Accuracy Settings
#define GMOUSE_ADS7843_PEN_CALIBRATE_ERROR		8
#define GMOUSE_ADS7843_PEN_CLICK_ERROR			6
#define GMOUSE_ADS7843_PEN_MOVE_ERROR			4
#define GMOUSE_ADS7843_FINGER_CALIBRATE_ERROR	14
#define GMOUSE_ADS7843_FINGER_CLICK_ERROR		18
#define GMOUSE_ADS7843_FINGER_MOVE_ERROR		14

// How much extra data to allocate at the end of the GMouse structure for the board's use
#define GMOUSE_ADS7843_BOARD_DATA_SIZE			0

int esp_gmouse_init_board();
int esp_getpin_pressed();
void esp_aquire_bus();
void esp_release_bus();
uint16_t esp_read_value(uint16_t port);

static GFXINLINE bool_t init_board(GMouse* m, unsigned driverinstance) {return esp_gmouse_init_board()?TRUE:FALSE;}
static GFXINLINE bool_t getpin_pressed(GMouse* m) {return esp_getpin_pressed()?TRUE:FALSE;}
static GFXINLINE void aquire_bus(GMouse* m) {esp_aquire_bus();}
static GFXINLINE void release_bus(GMouse* m) {esp_release_bus();}
static GFXINLINE uint16_t read_value(GMouse* m, uint16_t port) {return esp_read_value(port);}

#endif
