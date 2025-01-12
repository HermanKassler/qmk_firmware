#include QMK_KEYBOARD_H
#include <keymap_swedish.h>

enum layer_number {
    _QWERTY = 0,
    _LOWER,  // 1
    _RAISE,  // 2
    _THIRD,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
     * |------+------+------+------+------+------|   [   |    |ENTER  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BckSp \  |tp lft|Right | RALT |
     *                   |      |      |      |/       /         \      \ |hld L2|      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT( KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_MNXT, 
                        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                       KC_Y, KC_U, KC_I, KC_O, KC_P, SE_ARNG, 
                        KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K, KC_L, SE_ODIA, SE_ADIA, 
                        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SLSH,     KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, SE_QUOT, KC_RSFT, 
                        KC_Z, KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,         KC_BSPC, LT(_LOWER, KC_LEFT), LT(_RAISE, KC_LEFT), KC_RGHT, LT(_RAISE, KC_MNXT)),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | THIRD|  -   |   -  |  -   |  -   |  -   |                    |  -   |  -   |  -   |  -   |  -   | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  &   |   =  |  [   |   ]  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   ~  |   !  |   "  |   #  |   $  |   %  |-------.    ,-------|   +  |   {  |   (  |   )  |   }  |  ?   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |   |  |  @   |   <  |  >   |  |   |-------|    |-------|  -   |   _  |   /  |   \  |   ^  |   *  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] =  LAYOUT(TG(_THIRD), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                           KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
                _______, _______, _______, _______, _______, _______,                                           SE_AMPR, SE_EQL, SE_LBRC, SE_RBRC, SE_TILD, KC_F12, 
                SE_TILD, KC_EXLM, SE_DQUO, KC_HASH, SE_DLR, KC_PERC,                                            SE_PLUS, SE_LCBR, SE_LPRN, SE_RPRN, SE_RCBR, SE_QUES, 
                _______, SE_PIPE, SE_AT, SE_LABK, SE_RABK, SE_PIPE, _______,                           _______, SE_MINS, SE_UNDS, SE_SLSH, SE_BSLS, SE_CIRC, SE_ASTR, 
                _______, _______, _______, _______, _______,                                                    _______, _______, _______, _______, _______),
    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      | L4   |  L3  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_RAISE] = LAYOUT(  _______, _______, _______, _______, _______, _______,                                          _______, _______, _______,   _______,    _______, TG(_THIRD), 
                        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                                                          KC_6,    KC_PGUP,  KC_UP,    KC_PGDN,       KC_0,    _______, 
                        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                                      KC_HOME, KC_LEFT, KC_DOWN,   KC_RGHT,      KC_END, XXXXXXX, 
                        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,                                 _______, KC_PLUS, KC_MINS, KC_INS,    KC_DEL,       KC_RBRC, KC_BSLS, 
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* THIRD
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |     |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
     * |------+------+------+------+------+------|   [   |    |ENTER  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \BckSp \  |tp lft|Right | RALT |
     *                   |      |      |      |/       /         \      \ |hld L2|      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_THIRD] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MPRV, KC_MSTP, KC_MNXT, KC_9, KC_0, _______, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RBRC, KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_GRV, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, TG(_THIRD), KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RALT, KC_RALT, KC_LALT, KC_SPC, KC_M, _______, _______, _______, _______, _______),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_ADJUST] = LAYOUT(RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 *
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
    /* With an if statement we can check which encoder was turned. */
    if (index == 0) { /* First encoder */
        /* And with another if statement we can check the direction. */
        if (clockwise) {
            /* This is where the actual magic happens: this bit of code taps on the
               Page Down key. You can do anything QMK allows you to do here.
               You'll want to replace these lines with the things you want your
               encoders to do. */
            tap_code(KC_DOWN);
        } else {
            /* And likewise for the other direction, this time Page Down is pressed. */
            tap_code(KC_UP);
        }
        /* You can copy the code and change the index for every encoder you have. Most
           keyboards will only have two, so this piece of code will suffice. */
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif  // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}
