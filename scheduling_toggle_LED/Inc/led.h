/*
 * led.h
 *
 *  Created on: Jun 24, 2026
 *      Author: brak3r
 */



#ifndef LED_H_
#define LED_H_




#define DELAY_COUNT_1MS 		 1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(125U  * DELAY_COUNT_1MS)


/* LED IDs */
typedef enum
{
    LED_GREEN = 0,
    LED_BLUE,
    LED_RED,
    LED_GREEN1,
    LED_MAX
}LED_t;

/* APIs */
void LED_Init(void);
void led_on(LED_t led);
void led_off(LED_t led);
void LED_Toggle(LED_t led);
void delay(uint32_t count);

#endif /* LED_H_ */


