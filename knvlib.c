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

/*--- Tick ---*/
void SystemTickInit(void)
{
  TMOD = TMOD | 0x01;     /*T0 - Mode2: 16 -Bit Auto Reload, Timer, Software Control*/
  TL0 =  T0_PERIOD;       /*T0 - Reload Register Low*/
  TH0 =  T0_PERIOD >> 8;  /*T0 - Reload Reighster High*/
  TR0 = 1;                /*T0 - Timer 0 ON*/
  ET0 = 1;                /*T0 - Interrupt Enable */
}

void T0Interrupt (void) interrupt 1 using 1 /* Int Vector at 000BH, Reg Bank 1 */
{ 
  TL0 =  T0_PERIOD;       /*T0 - Reload Register Low*/
  TH0 =  T0_PERIOD >> 8;  /*T0 - Reload Reighster High*/
  SysTick++;
}

uint32_t GetTick(void)
{
  return (SysTick);
}

/*--- UART ---*/
/*
 * OSC: 11059200-> 9600BPS
 */
void SerialPortInit(void)
{
  SCON = 0x50;        /* SCON: mode 1, 8-bit UART, enable rcvr      */
  TMOD = TMOD |0x20;  /* TMOD: timer 1, mode 2, 8-bit reload        */
  TR1   = 1;          /* TR1: timer 1 run*/
  TH1 =  0xFD;        /* TH1: see manual*/
  TI  = 1;            /* TI: set TI to send first char of UART    */
}

void SerialPortInterrupt (void) interrupt 4 using 1 /* Int Vector at 0023H, Reg Bank 1 */
{

}