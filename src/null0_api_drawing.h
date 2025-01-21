#pragma once

#define PNTR_IMPLEMENTATION
#define PNTR_BRUSH_IMPLEMENTATION
#include "pntr_brush.h"
#include "cvector.h"

static cvector_vector_type(pntr_font*) fonts;
static cvector_vector_type(pntr_brush*) brushes;

// called to initialize drawing stuff
void null0_drawing_init(pntr_image* screen);

// called when the engine unloads
void null0_drawing_unload();

// start a path
void null0_begin_path(unsigned int brush);

// create a new canvas
unsigned int null0_new_canvas(int width, int height, pntr_color color);

// load a canvas from a file
unsigned int null0_load_canvas(char* filename);

// create a canvas from a part of an existing canvas
unsigned int null0_sub_canvas(unsigned int src, int sx, int sy, int sw, int sh, int dx, int dy);

// unload a canvas
void null0_unload_canvas(unsigned int canvas);

// save a canvas to a file
void null0_save_canvas(unsigned int canvas, char* filename);

// draw a canvas on another canvas
void null0_draw_canvas(unsigned int dest, unsigned int src, int posX, int posY);

// draw some text on a canvas, as a path
void null0_text(unsigned int canvas, const char* text);

// create a line in path
void null0_line_to(unsigned int canvas, int posX, int posY);

// create an arc or curve in path
void null0_arc(unsigned int canvas, int centerX, int centerY, float radius, float startAngle, float endAngle, int segments);

// fill current path (ending path)
void null0_fill(unsigned int canvas);

// stroke current path (ending path)
void null0_stroke(unsigned int canvas);

// move to a position without drawing
void null0_move_to(unsigned int canvas, int posX, int posY);

// load a BMF font from a canvas
unsigned int null0_font_bmf(unsigned int canvas, const char* characters);

// load a TTY font from a canvas
unsigned int null0_font_tty(unsigned int canvas, int glyphWidth, int glyphHeight, const char* characters);

// load a font from a TTF file
unsigned int null0_font_ttf(const char* fileName, int fontSize);

// measure some text
pntr_vector null0_measure_text(unsigned int font, const char* text);

// set fill color
void null0_fill_color(unsigned int canvas, pntr_color color);

// set stroke color
void null0_stroke_color(unsigned int canvas, pntr_color color);

/// IMPLEMENTATION

void null0_drawing_init(pntr_image* screen){
    cvector_push_back(fonts, pntr_load_font_default());
    pntr_brush* brush = pntr_load_brush(screen);
    cvector_push_back(brushes, brush);
    pntr_brush_font(brush, fonts[0]);
    pntr_brush_line_width(brush, 1);
    pntr_brush_stroke_style(brush, PNTR_BLACK);
    pntr_brush_fill_style(brush, PNTR_BLACK);
}

void null0_drawing_unload() {
    // TODO: unload brushes
    // TODO: unload fonts
}

void null0_begin_path(unsigned int brush) {
    pntr_brush_begin_path(brushes[brush]);
}

unsigned int null0_new_canvas(int width, int height, pntr_color color) {
    unsigned int id = cvector_size(brushes);
    pntr_image* image = pntr_gen_image_color(width, height, color);
    pntr_brush* brush = pntr_load_brush(image);
    cvector_push_back(brushes, brush);
    return id;
}

unsigned int null0_load_canvas(char* filename) {}

unsigned int null0_sub_canvas(unsigned int src, int sx, int sy, int sw, int sh, int dx, int dy) {}

void null0_unload_canvas(unsigned int canvas) {}

void null0_save_canvas(unsigned int canvas, char* filename) {
    pntr_save_image(brushes[canvas]->dst, filename);
}

void null0_draw_canvas(unsigned int dest, unsigned int src, int posX, int posY) {}

void null0_text(unsigned int canvas, const char* text) {}

void null0_line_to(unsigned int canvas, int posX, int posY) {}

void null0_arc(unsigned int canvas, int centerX, int centerY, float radius, float startAngle, float endAngle, int segments) {
    pntr_brush_arc(brushes[canvas], centerX, centerY, radius, startAngle, endAngle, segments);
}

void null0_fill(unsigned int canvas) {
    pntr_brush_fill(brushes[canvas]);
}

void null0_stroke(unsigned int canvas) {
    pntr_brush_stroke(brushes[canvas]);
}

void null0_move_to(unsigned int canvas, int posX, int posY) {}

unsigned int null0_font_bmf(unsigned int canvas, const char* characters) {}

unsigned int null0_font_tty(unsigned int canvas, int glyphWidth, int glyphHeight, const char* characters) {}

unsigned int null0_font_ttf(const char* fileName, int fontSize) {}

pntr_vector null0_measure_text(unsigned int font, const char* text) {}

void null0_fill_color(unsigned int canvas, pntr_color color) {
    pntr_brush_fill_style(brushes[canvas], color);
}

void null0_stroke_color(unsigned int canvas, pntr_color color) {
    pntr_brush_stroke_style(brushes[canvas], color);
}
