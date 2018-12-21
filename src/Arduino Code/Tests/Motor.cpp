#include"Arduino.h"
#include "Joint.h"
#include "Servo.h"
#include"Motor.h"


Motor::Motor(int Motorpin, int Analog_Motorpin)
{
 motorpin=Motorpin; 
 analog_motorpin=Analog_Motorpin;
 analogReference(EXTERNAL); 
 //servo.attach(motorpin); 
 
 
}


float Motor::get_Motor_angle(float offset)
{
  float b=0;
  for(int i=0; i<10; i++){
   b =b+ analogRead(analog_motorpin);
  }
  b=b/10;
  float b_degree=(b/1024*360);
  
  b_degree=b_degree-offset;
    if (b_degree<0){
      b_degree=b_degree+360;
    }
  
  return b_degree;
}

    
//int Motor::get_Tendon_Force()
//{
//get the way of deflection from Potentiometer
//return int
//}



void Motor::drive_Motor(int velocity)
{
servo.write(velocity);
}



void Motor::drive_Motor_until_Jdegree (int angle_desired, Joint joint) //velocity=100 und 89
{ 
  int velocity;
  int d=joint.get_Joint_angle(joint.offset_angle);
  int d2;
      
      
      while(true)
      {
          if(d>angle_desired)
          {
              velocity=85;
              servo.write (velocity); // negative acceleration: if diff = 45° the servo drives with speed 0 (fastest) , if diff = 0° the servo stops
              d=joint.get_Joint_angle(joint.offset_angle);
              d2=d+joint.get_Joint_angle(joint.offset_angle);
              Serial.println(d);
              if(d<=angle_desired)
                {
                  break;
                }
             continue;                     
          }

          if(d<angle_desired)
          {
              velocity=180;
              servo.write (velocity); // negative acceleration: if diff = 45° the servo drives with speed 0 (fastest) , if diff = 0° the servo stops
              d=joint.get_Joint_angle(joint.offset_angle);
              if(d>=angle_desired)
                {
                  break;
                }
             continue;                     
          }   
      }
      servo.write(95);
}

    

void Motor::drive_Motor_until_Mdegree (int degree) //Possible to drive forward and backward to a certain Motor position
{ 
  int velocity;
  float d=get_Motor_angle(Motoroffset_angle);

  if(d>degree)
  {
    velocity=100;
  }else if(d<degree)
   {
    velocity=89;
   }

   
  while ( d!=degree)
  {
    servo.write (velocity); // negative acceleration: if diff = 45° the servo drives with speed 0 (fastest) , if diff = 0° the servo stops
    d=get_Motor_angle(Motoroffset_angle);  
  }
  servo.write (95);
}


void Motor::drive_Motor_for_Jdegree (int angle_desired, Joint joint)
{
  float d1=joint.get_Joint_angle(joint.offset_angle);
  Serial.println (d1);
  float d2=d1+angle_desired;
  Serial.println (d2);

  if(d2>45)
  {
    d2=45;
  }else if( d2<0)
   {
     d2=0;
   }
  Serial.println (d2);
  drive_Motor_until_Jdegree (d2, joint);
}


void Motor::drive_Motor_for_Mdegree (int degree)
{
  float d1=get_Motor_angle(Motoroffset_angle);
  Serial.println (d1);
  float d2=d1-degree;
  Serial.println (d2);

  if(d2>340)
  {
    d2=d2-340;
  }else if( d2<20)
   {
     d2=340+d2;
   }
  Serial.println (d2);
  drive_Motor_until_Mdegree (d2);
}


void Motor::drive_Motor_for_Sek (int Sekunden, int velocity){
  int a1=millis();
      int a2= a1+Sekunden;
      int a=0;
      
      while ( a < a2){
          servo.write (velocity); 
          a=millis();   
      }
      servo.write (95);
      
}

void Motor::drive_Motor_until_S(int velocity)
{
      Serial.println( "for Stop write: S");
      int a=1;

      while (a=1)
      { 
        if (Serial.available())
        {
          if(Serial.read()=='S')
          {
            break;
          }
        }
        servo.write (velocity);
      }
      servo.write (95);
}

//void Motor::drive_Motor_until_contact(int velocity)
   // {
      //int F=get_Tendon_Force();
      //while (F!=//Value Contact Measured Force+Toleranzwert){
          //servo.write (velocity);
          //F=get_Tendon_Force();
    //}

//void Motor::drive_Motor_until_Force(int Force, int velocity)
   // {
      //int F=get_Tendon_Force();
      //while (F<Force){
          //servo.write (velocity);
          //F=get_Tendon_Force();
    //}
