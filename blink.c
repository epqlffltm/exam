#include<stdio.h>
#include<pigpio.h>//pigpio의 모든 GPIO함수를 사용하기 위한 헤더
#include<unistd.h>//sleep같은 POSIX함수 사용을 위함 라이브러리

#define PIN 17//17번 핀 할당

enum{OFF=0,ON=1}//onoff설정

int main(void)
{
  if(gpioInitialise() < 0)//라이브러리 초기화
  {
    printf("pigpio초기화 실패\n");
    return 1;
  }

  int pin = PIN;//핀번호 할당

  gpioSetMode(pin, PI_OUTPUT);//출력모드 설정

  while(1)//무한루프
  {
    gpioWrite(pin,ON);//켜짐
    sleep(1);
    gpioWrite(pin,OFF);//꺼짐
    sleep(1);
  }

  gpioTerminate();//라이브러리 종료

  return 0;
}