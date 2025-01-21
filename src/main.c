#define CVECTOR_LOGARITHMIC_GROWTH
#define PNTR_ENABLE_DEFAULT_FONT

#include "null0_api_drawing.h"

int main() {
    // normally this would come from pntr_app
    pntr_image* screen = pntr_gen_image_color(640, 480, PNTR_WHITE);

    null0_drawing_init(screen);

    // draw a smiley face
    null0_begin_path(0);
    null0_fill_color(0, PNTR_YELLOW);
    null0_arc(0, 320, 240, 220.0f, 0.0f, 360.0f, 50);
    null0_stroke(0);

    null0_save_canvas(0, "screenshot.png");
    null0_drawing_unload();
    return 0;
}
