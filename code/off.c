#include<stdio.h>
#include<pigpio.h>

#define PIN 17
#define OFF 0

int main(void)
{
  if(gpioInitialise() < 0)
  {
    printf("pigpio초기화 실패\n");
    return 1;
  }

  int pin = PIN;

  gpioSetMode(pin, PI_OUTPUT);//출력모드 설정
  
  gpioWrite(pin,OFF);//켜짐

  gpioTerminate();//라이브러리 종료

  return 0;
}