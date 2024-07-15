LTO_ENABLE = yes
CONVERT_TO = blok

MOUSEKEY_ENABLE = yes      # Mouse keys
TAP_DANCE_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes
BONGO_ENABLE = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
RGB_MATRIX_CUSTOM_USER = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./common/oled_helper.c
