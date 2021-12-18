/* Includes ------------------------------------------------------------------*/
#include <reg51.h>
#include "knvlib.h"

int main(void)
{
  uint32_t timestamp = 0;
  uint32_t period = 0;
  uint8_t led = 0;
  SystemTickInit();
  InterruptEnable();

  
  for(;;)
  {
     if(GetTick() - timestamp > 1000)
     {
       timestamp = GetTick();
       if(led)
       {
        P0 |= 0x01;
        led = 0;
       }
       else
       {
        P0 &= ~(0x01);
        led = 1;
       }
     }
  }
return(0);
}



