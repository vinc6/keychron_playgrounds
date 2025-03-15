/* Copyright 2025 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "keychron_task.h"
#ifdef FACTORY_TEST_ENABLE
#    include "factory_test.h"
#    include "keychron_common.h"
#endif
#ifdef LK_WIRELESS_ENABLE
#    include "lkbt51.h"
#    include "wireless.h"
#    include "keychron_wireless_common.h"
#    include "battery.h"
#endif
#if HAL_USE_ADC
#    include "analog.h"
#endif
#include "eeprom_he.h"
#ifdef ANANLOG_MATRIX
#    include "analog_matrix.h"
#endif

#ifndef POWER_ON_LED_DURATION
#    define POWER_ON_LED_DURATION 3000
#endif

static uint32_t power_on_indicator_timer;

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? 2 : 0));
    }
    dip_switch_update_user(index, active);

    return true;
}
#endif

void keyboard_post_init_kb(void) {
    setPinInputLow(B2);
#ifdef LK_WIRELESS_ENABLE
    setPinInput(P2P4_MODE_SELECT_PIN);
    setPinInput(BT_MODE_SELECT_PIN);

    lkbt51_init(false);
    wireless_init();
#    ifdef BAT_LOW_LED_PIN
    setPinOutputPushPull(BAT_LOW_LED_PIN);
    writePin(BAT_LOW_LED_PIN, BAT_LOW_LED_PIN_ON_STATE);
#    endif
#endif

    power_on_indicator_timer = timer_read32();
#ifdef ENCODER_ENABLE
    encoder_cb_init();
#endif

    keyboard_post_init_user();
}

bool keychron_task_kb(void) {
    if (power_on_indicator_timer) {
        if (timer_elapsed32(power_on_indicator_timer) > POWER_ON_LED_DURATION) {
            power_on_indicator_timer = 0;
#ifdef BAT_LOW_LED_PIN
            writePin(BAT_LOW_LED_PIN, !BAT_LOW_LED_PIN_ON_STATE);
#endif

        } else {
#ifdef BAT_LOW_LED_PIN
            writePin(BAT_LOW_LED_PIN, BAT_LOW_LED_PIN_ON_STATE);
#endif
        }
    }
    return true;
}

#ifdef LK_WIRELESS_ENABLE
bool lpm_is_kb_idle(void) {
    return power_on_indicator_timer == 0 && !factory_reset_indicating();
}
#endif
