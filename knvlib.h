/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KNVLIB__H
#define __KNVLIB__H  1

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
typedef unsigned long uint32_t;
typedef unsigned int uint16_t;
typedef unsigned char uint8_t;

/* Exported constants --------------------------------------------------------*/
#define SystemCoreClock 11059200

#define InterruptEnable() { EA = 1; }
#define InterruptDisable() { EA = 0; }

/* Exported macro ------------------------------------------------------------*/



/* Exported functions --------------------------------------------------------*/
void SystemTickInit(void);
uint32_t GetTick(void);

#endif //__KNVLIB__H