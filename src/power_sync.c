
#include "ztimer.h"
#include "led.h"
#include "log.h"
static int BIT_SPEED_MS = 200;

//static bool BARKER11[] = {true, true, true, false, false, false, true, false, false, true, false};
static bool BLINK[] = {true, false, true, false, true, false, true, false, true, false, true, false};

static inline void turn_all_leds_on(void){
    LED0_ON;
    LED1_ON;
    LED2_ON;
    LED3_ON;
    LED4_ON;
    LED5_ON;
    LED6_ON;
    LED7_ON;
}

static inline void turn_all_leds_off(void){
    LED0_OFF;
    LED1_OFF;
    LED2_OFF;
    LED3_OFF;
    LED4_OFF;
    LED5_OFF;
    LED6_OFF;
    LED7_OFF;
}

static inline void toggle_all_leds(void){
    LED0_TOGGLE;
    LED1_TOGGLE;
    LED2_TOGGLE;
    LED3_TOGGLE;
    LED4_TOGGLE;
    LED5_TOGGLE;
    LED6_TOGGLE;
    LED7_TOGGLE;
}
void play_single_blink(void){
    LOG_INFO("Running single blink...");
    turn_all_leds_on();
    ztimer_sleep(ZTIMER_MSEC, BIT_SPEED_MS);
    turn_all_leds_off();
}

void play_syncword(void){
    LOG_INFO("Running sync word...");
    for (size_t i = 0; i < (sizeof(BLINK) / sizeof(BLINK[0])); i++)
    {
        if (BLINK[i])
        {
            turn_all_leds_on();
        } else {
            turn_all_leds_off();
        }
        ztimer_sleep(ZTIMER_MSEC, BIT_SPEED_MS);
    }
    LOG_INFO("Done\n");
}
