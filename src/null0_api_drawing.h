#pragma once

typedef struct {
  int width;
  int height;
} Measurement;

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
} Null0Color;

typedef struct {
  unsigned int id;
  Measurement dimensions;
  int strokeWidth;
  Null0Color stroke;
  Null0Color fill;
  unsigned int font;
} Null0Canvas;

// create a new canvas
Null0Canvas* null0_new_canvas(int width, int height, Null0Color color);

// load a canvas from a file
Null0Canvas* null0_load_canvas(char* filename);

// create a canvas from a part of an existing canvas
Null0Canvas* null0_sub_canvas(Null0Canvas* src, int sx, int sy, int sw, int sh, int dx, int dy, int sw, int sh);

// unload a canvas
void null0_unload_canvas(Null0Canvas* canvas);

// save a canvas to a file
void null0_save_canvas(Null0Canvas* canvas, char* filename);

// draw a canvas on another canvas
void null0_draw_canvas(Null0Canvas* dest, Null0Canvas* src, int posX, int posY);

// draw some text on a canvas, as a path
void null0_text(Null0Canvas* canvas, const char* text);

// create a line in path
void null0_line_to(Null0Canvas* canvas, int posX, int posY);

// create an arc or curve in path
void null0_arc(Null0Canvas* canvas, int centerX, int centerY, float radius, float startAngle, float endAngle, int segments);

// fill current path (ending path)
void null0_fill(Null0Canvas* canvas);

// stroke current path (ending path)
void null0_stroke(Null0Canvas* canvas);

// move to a position without drawing
void null0_move_to(Null0Canvas* canvas, int posX, int posY);

// load a BMF font from a canvas
unsigned int null0_font_bmf(Null0Canvas* canvas, const char* characters);

// load a TTY font from a canvas
unsigned int null0_font_tty(Null0Canvas* canvas, int glyphWidth, int glyphHeight, const char* characters);

// load a font from a TTF file
unsigned int null0_font_ttf(const char* fileName, int fontSize);

// measure some text
Measurement null0_measure_text(unsigned int font, const char* text);
