#include <Arduino.h>

int serial_pintc(char c,struct __file *);
void printf_begin(void);

void setup() {
  Serial.begin(9600);
  printf_begin();
}

void loop() {
  int cs=12345;
  float cf=12.345;
  char c[15]="Hello,world!";

  printf("***arduino.cn***\n\r");
  printf("111:%d\n",cs);
  printf("222:%lf\n",cf);
  printf("333:%s\n",c);
  printf("111:%d\n222:%lf\n333:%s\n",cs,cf,c);
}

int serial_putc( char c, struct __file * )
{
  Serial.write( c );
  return c;
}
void printf_begin(void)
{
  fdevopen( &serial_putc, 0 );
}