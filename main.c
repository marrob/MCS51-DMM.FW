/* Includes ------------------------------------------------------------------*/
#include <reg51.h>
#include "knvlib.h"
//#include <stdio.h>
int main(void)
{
  uint32_t timestamp = 0;
  //uint32_t period = 0;
  uint8_t led = 0; 
  //uint32_t line=0;
  
  SystemTickInit();
  InterruptEnable();
  SerialPortInit();
  //printf ("Hello World\n");   /* Print "Hello World" */
  
  
  for(;;)
  {
     if(GetTick() - timestamp > 1000)
     {
       timestamp = GetTick();
       //printf("%d It is a test\n\r", line);
       //line +=1;

       if(led)
       {
        P1 |= 0x01;
        led = 0;
       }
       else
       {
        P1 &= ~(0x01);
        led = 1;
       }
     }

     //P1 ^= 0x01;     		    /* Toggle P1.0 each time we print */
  }
return(0);
}



