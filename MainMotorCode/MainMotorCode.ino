#include <SoftwareSerial.h>
#define BRAKE 0
#define CW    1
#define CCW   2

#define MOTOR_A1_PIN 7
#define MOTOR_B1_PIN 8
#define PWM_MOTOR_1 5
#define CURRENT_SEN_1 A2
#define EN_PIN_1 A0

SoftwareSerial ArdunioUno(3,2);
short usSpeed = 255;  //default motor speed
unsigned short usMotor_Status = BRAKE;
bool safe = true;
const int buttonPin1 = 13;
const int buttonPin2 = 12;   
int buttonState1 = 0;  
int buttonState2 = 0 ;
int numberOfTurns = 0;
void setup()                         
{

 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);

  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(CURRENT_SEN_1, OUTPUT);
  pinMode(EN_PIN_1, OUTPUT);

  Serial.begin(9600);   
  ArdunioUno.begin(4800);// Initiates the serial to do the monitoring 

}

void loop() 
{  
//WIFI
 ArdunioUno.print("We have Data`");
 ArdunioUno.println("\n");
  delay(30);

//Button
   buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH) {
      if ( safe == false ){
          digitalWrite(EN_PIN_1, HIGH);
            Forward();
          delay(350);
            Stop();
            safe = true;
      }
  } 
  if (buttonState2 == HIGH) {
    if (safe == true){
      digitalWrite(EN_PIN_1, HIGH);
        Reverse();
      delay(500);
        Stop();
    safe = false;
    numberOfTurns++;
    ArdunioUno.print(numberOfTurns);
ArdunioUno.println("\n");
    }
    
  } 

}

void Stop()
{
  Serial.println("Stop");
  usMotor_Status = BRAKE;
  motorGo(usMotor_Status, 0);
}

void Forward()
{
  Serial.println("Forward");
  usMotor_Status = CW;
  motorGo(usMotor_Status, usSpeed);
}

void Reverse()
{
  Serial.println("Reverse");
  usMotor_Status = CCW;
  motorGo(usMotor_Status, usSpeed);
}


void motorGo(uint8_t direct, uint8_t pwm)       
{ 
    if(direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }    
    analogWrite(PWM_MOTOR_1, pwm); 
}
