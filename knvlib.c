/* Includes ------------------------------------------------------------------*/
#include "knvlib.h"
#include <reg51.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define T0_PERIOD (65535 - ((SystemCoreClock/12)/1000)) /*1ms interrupt*/

/* Private variables ---------------------------------------------------------*/
volatile uint32_t SysTick;   /*Increment every 1ms*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
void SystemTickInit(void)
{
  TMOD = TMOD | 0x01;     /*T0 - Mode2: 16 -Bit Auto Reload, Timer, Software Control*/
  TL0 =  T0_PERIOD;       /*T0 - Reload Register Low*/
  TH0 =  T0_PERIOD >> 8;  /*T0 - Reload Reighster High*/
  TR0 = 1;                /*T0 - Timer 0 ON*/
  ET0 = 1;                /*T0 - Interrupt Enable */
}

uint32_t GetTick(void)
{
  return (SysTick);
}

/* Interrupts -----------------------------------------------------------------*/
void timer0 (void) interrupt 1 using 1 /* Int Vector at 000BH, Reg Bank 1 */
{ 
  TL0 =  T0_PERIOD;       /*T0 - Reload Register Low*/
  TH0 =  T0_PERIOD >> 8;  /*T0 - Reload Reighster High*/
  SysTick++;
}
