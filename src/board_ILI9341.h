
#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

void esp_lcd_init_board(void);
void esp_lcd_post_init_board(void);
void esp_lcd_aquirebus(void);
void esp_lcd_releasebus(void);
void esp_lcd_write_index(uint16_t cmd);
void esp_lcd_write_data(uint16_t data);

static GFXINLINE void init_board(GDisplay *g) { esp_lcd_init_board (); }
static GFXINLINE void post_init_board(GDisplay *g) {esp_lcd_post_init_board ();}
static GFXINLINE void setpin_reset(GDisplay *g, bool_t state) {}
static GFXINLINE void set_backlight(GDisplay *g, uint8_t percent) {}
static GFXINLINE void acquire_bus(GDisplay *g) {esp_lcd_aquirebus();}
static GFXINLINE void release_bus(GDisplay *g) {esp_lcd_releasebus();}
static GFXINLINE void write_index(GDisplay *g, uint16_t index) {esp_lcd_write_index (index);}
static GFXINLINE void write_data(GDisplay *g, uint16_t data) {esp_lcd_write_data(data);}
static GFXINLINE void setreadmode(GDisplay *g) {}
static GFXINLINE void setwritemode(GDisplay *g) {}
static GFXINLINE uint16_t read_data(GDisplay *g) {return 0;}

#endif
