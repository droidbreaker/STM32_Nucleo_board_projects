/*
 * led.c
 *
 *  Created on: Jun 24, 2026
 *      Author: brak3r
 */

#include <stdint.h>
#include "led.h"


/* RCC */
#define RCC_BASE            0x40023800UL
#define RCC_AHB1ENR         (*(volatile uint32_t *)(RCC_BASE + 0x30))

/* GPIOA */
#define GPIOA_BASE          0x40020000UL
#define GPIOA_MODER         (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR           (*(volatile uint32_t *)(GPIOA_BASE + 0x14))

/* GPIOB */
#define GPIOB_BASE          0x40020400UL
#define GPIOB_MODER         (*(volatile uint32_t *)(GPIOB_BASE + 0x00))
#define GPIOB_ODR           (*(volatile uint32_t *)(GPIOB_BASE + 0x14))

/* RCC AHB1 peripheral clock enable bits */
#define GPIOA_EN            (1U << 0)
#define GPIOB_EN            (1U << 1)

/* Pins */
#define PA5                 5U
#define PA6                 6U
#define PB8                 8U
#define PB9                 9U

void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

void LED_Init(void)
{
    /* Enable GPIOA and GPIOB clocks */
    RCC_AHB1ENR |= GPIOA_EN;
    RCC_AHB1ENR |= GPIOB_EN;

    /* PA5 output */
    GPIOA_MODER &= ~(3U << (PA5 * 2));
    GPIOA_MODER |=  (1U << (PA5 * 2));

    /* PA6 output */
    GPIOA_MODER &= ~(3U << (PA6 * 2));
    GPIOA_MODER |=  (1U << (PA6 * 2));

    /* PB8 output */
    GPIOB_MODER &= ~(3U << (PB8 * 2));
    GPIOB_MODER |=  (1U << (PB8 * 2));

    /* PB9 output */
    GPIOB_MODER &= ~(3U << (PB9 * 2));
    GPIOB_MODER |=  (1U << (PB9 * 2));

    /* LEDs OFF */
    GPIOA_ODR &= ~((1U << PA5) | (1U << PA6));
    GPIOB_ODR &= ~((1U << PB8) | (1U << PB9));
}

void led_on(LED_t led)
{
    switch(led)
    {
        case LED_GREEN:
            GPIOA_ODR |= (1U << PA6);
            break;

        case LED_BLUE:
            GPIOA_ODR |= (1U << PA5);
            break;

        case LED_RED:
            GPIOB_ODR |= (1U << PB9);
            break;

        case LED_GREEN1:
            GPIOB_ODR |= (1U << PB8);
            break;
        case LED_MAX:
        	break;
    }
}

void led_off(LED_t led)
{
    switch(led)
    {
        case LED_GREEN:
            GPIOA_ODR &= ~(1U << PA6);
            break;

        case LED_BLUE:
            GPIOA_ODR &= ~(1U << PA5);
            break;

        case LED_RED:
            GPIOB_ODR &= ~(1U << PB9);
            break;

        case LED_GREEN1:
            GPIOB_ODR &= ~(1U << PB8);
            break;
        case LED_MAX:
                	break;
    }
}

void LED_Toggle(LED_t led)
{
    switch(led)
    {
        case LED_GREEN:
            GPIOA_ODR ^= (1U << PA6);
            break;

        case LED_BLUE:
            GPIOA_ODR ^= (1U << PA5);
            break;

        case LED_RED:
            GPIOB_ODR ^= (1U << PB9);
            break;

        case LED_GREEN1:
            GPIOB_ODR ^= (1U << PB8);
            break;
        case LED_MAX:
                	break;
    }
}

