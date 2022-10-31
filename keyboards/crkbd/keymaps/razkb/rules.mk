MOUSEKEY_ENABLE   = yes    # Mouse keys
RGBLIGHT_ENABLE   = no
RGB_MATRIX_ENABLE = yes
OLED_ENABLE       = yes
OLED_DRIVER       = SSD1306
LTO_ENABLE        = yes
BOOTLOADER        = atmel-dfu
TAP_DANCE_ENABLE  = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
#DYNAMIC_TAPPING_TERM_ENABLE = yes

SRC += ./oled.c ./rgb.c ./tap_dances.c