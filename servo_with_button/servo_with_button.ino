#include <Servo.h>
Servo Myservo;
int pos=0;
void setup()
{
  pinMode(2,INPUT);
  Myservo.attach(3);
}

void loop()
{
  if(digitalRead(2)==LOW){
    Myservo.write(180);
  }
  else
    
 Myservo.write(0);

}
