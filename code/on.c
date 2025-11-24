#include<stdio.h>
#include<pigpio.h>

#define PIN 17
#define on 1

int main(void)
{
  if (gpioInitialise() < 0)
  {
    printf("pigpio 초기화 실패\n");
    return 1;
  }

  int pin = PIN;

  gpioSetMode(pin, PI_OUTPUT);

  gpioWrite(pin,ON);

  gpioTerminate();//라이브러리 종료

  return 0;
}