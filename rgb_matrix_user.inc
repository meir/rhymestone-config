
RGB_MATRIX_EFFECT(portals)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define ORNG 10
#define BLUE 160
#include "matrix.h"

const uint8_t rgbled_map[MATRIX_ROWS][MATRIX_COLS] = {
    // left side
    { 10,  11,  12,  13,   0 },
    {  9,  18,  19,  14,   1 },
    {  8,  17,  16,  15,   2 },
    {  7,   6,   5,   4,   3 },

    // right side
    { 30,  31,  32,  33,  20 },
    { 29,  38,  39,  34,  21 },
    { 28,  37,  36,  35,  22 },
    { 27,  26,  25,  24,  23 },
};

bool portals_runner(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t half = MATRIX_ROWS / 2;

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t color = 0;

            // initial color
            color = row < half ? ORNG : BLUE;

            // opposite site color if pressed on opposite side
            uint8_t mirrored_col = col;
            uint8_t mirrored_row = row < half ? row + half : row - half;
            if (matrix_is_on(mirrored_row, mirrored_col)) {
                color = row < half ? BLUE : ORNG;
            }

            // pressed color
            if (matrix_is_on(row, col)) {
                color = row < half ? BLUE : ORNG;
            }

            HSV hsv = rgb_matrix_config.hsv;
            hsv.h = color;
            RGB rgb = hsv_to_rgb(hsv);
            uint8_t led_position = rgbled_map[row][col];
            rgb_matrix_set_color(led_position, rgb.r, rgb.g, rgb.b);
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

bool portals(effect_params_t* params) {
    return portals_runner(params);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
