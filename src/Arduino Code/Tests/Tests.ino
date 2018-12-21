#include "Joint.h"
#include "Motor.h"
#include "Greifer.h"
#include "Finger.h"
#include "Wire.h"
#include"Servo.h"


Joint Joint1MCP=Joint(4,0b0001110);
Joint Joint1PIP=Joint(5,0b0001101);
Joint Joint1DIP=Joint(6,0b0001100);

Joint Joint2MCP=Joint(7,0b0001111);
Joint Joint2PIP=Joint(8,0b0001111);
Joint Joint2DIP=Joint(9,0b0001111);

Joint Joint3MCP=Joint(10,0b0001111);
Joint Joint3PIP=Joint(11,0b0001111);
Joint Joint3DIP=Joint(12,0b0001111);

Motor motor1=Motor(3,A2);
Motor motor2=Motor(2,A3);

Finger finger1=Finger(Joint1MCP,Joint1PIP,Joint1DIP, motor1);
Finger finger2=Finger(Joint2MCP,Joint2PIP,Joint2DIP, motor2);
Finger finger3=Finger(Joint3MCP,Joint3PIP,Joint3DIP, motor2);

Greifer greifer=Greifer(finger1,finger2,finger3);

int x=0;
float angle;
int Time1;
int Time2;


void setup() {

  
   Serial.begin(9600);
   Serial.println("Date&Time, Joint_Angle1°, Joint_Angle2°");
   analogReference(EXTERNAL); 
   Wire.begin();
   motor1.servo.attach(3);
   motor2.servo.attach(2); 
   motor1.drive_Motor(95);
   motor2.drive_Motor(95);

   motor1.Motoroffset_angle=motor1.get_Motor_angle(0);
   motor2.Motoroffset_angle=motor1.get_Motor_angle(0);

   Joint1MCP.offset_angle=Joint1MCP.get_Joint_angle(0);
   Joint1PIP.offset_angle=Joint1PIP.get_Joint_angle(0);
   Joint1DIP.offset_angle=Joint1DIP.get_Joint_angle(0);

   //Joint2MCP.offset_angle=Joint2MCP.get_Joint_angle(0);
   //Joint2PIP.offset_angle=Joint2PIP.get_Joint_angle(0);
   //Joint2DIP.offset_angle=Joint2DIP.get_Joint_angle(0);

   //Joint3MCP.offset_angle=Joint3MCP.get_Joint_angle(0);
   //Joint3PIP.offset_angle=Joint3PIP.get_Joint_angle(0);
   //Joint3DIP.offset_angle=Joint3DIP.get_Joint_angle(0);
   
}

void loop() {
  //while(true){
  //Serial.println();
  //  angle=motor2.get_Motor_angle(0);
  //angle=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
    //Serial.println(angle);
    //delay(1000);
  //}
 
if (Serial.available())
{
  Serial.println("Hello");
  x=Serial.read();


  if(x=='0')
  {
    
    int Time1=millis();
    finger1.move_oneJoint_until( Joint1MCP, 45);
    finger1.move_oneJoint_until( Joint1PIP, 45);
    finger1.move_oneJoint_until_S(Joint1DIP, 180);
    int Time2=millis()-Time1;
    Serial.println(Time2);

    finger1.move_oneJoint_until( Joint1MCP, 0);
    finger1.move_oneJoint_until( Joint1PIP, 0);
    finger1.move_oneJoint_until_S(Joint1DIP, 85);
    
  }     
      
  
  else if(x=='1')
  {
   finger1.move_oneJoint_until_S(Joint1MCP, 100);
   //finger1.move_oneJoint_until( Joint1MCP, 23);
  }

  else if(x=='2')
  {
   finger1.move_oneJoint_until_S(Joint1PIP, 100);
  }
  
  else if(x=='3')
  {
   finger1.move_oneJoint_until_S(Joint1DIP, 180);
  }
  
  else if(x=='4')
  {
   finger1.move_oneJoint_until_S(Joint1MCP, 85);
  } 

  else if(x=='5')
  {
   finger1.move_oneJoint_until_S(Joint1PIP, 85);
  } 

  else if(x=='6')
  {
   finger1.move_oneJoint_until_S(Joint1DIP, 85);
  }  

  else if(x=='A')
  {
   greifer.move_all_Finger_until_S(Joint1MCP, Joint2MCP, Joint3MCP, 100);
  }  

  else if(x=='B')
  {
   greifer.move_all_Finger_until_S(Joint1PIP, Joint2PIP, Joint3PIP, 100);
  } 

  else if(x=='C')
  {
   greifer.move_all_Finger_until_S(Joint1DIP, Joint2DIP, Joint3DIP, 180);
  }  

  else if(x=='D')
  {
   greifer.move_all_Finger_until_S(Joint1MCP, Joint2MCP, Joint3MCP, 85);
  }

  else if(x=='E')
  {
   greifer.move_all_Finger_until_S(Joint1PIP, Joint2PIP, Joint3PIP, 85);
  }

  else if(x=='F')
  {
   greifer.move_all_Finger_until_S(Joint1DIP, Joint2DIP, Joint3DIP, 85);
  }

  else if(x=='G')
  {
  
   greifer.move_Finger1and_Finger2oder3_until_S(Joint1MCP, Joint2MCP, 100);
  }

  else if(x=='H')
  {
   greifer.move_Finger1and_Finger2oder3_until_S(Joint1PIP, Joint2PIP, 100);
  }  

  else if(x=='I')
  {
   greifer.move_Finger1and_Finger2oder3_until_S(Joint1DIP, Joint2DIP, 180);
  } 

  else if(x=='J')
  {
   greifer.move_Finger1and_Finger2oder3_until_S(Joint1MCP, Joint2MCP, 85);
  } 

   else if(x=='K')
  {
   greifer.move_Finger1and_Finger2oder3_until_S(Joint1PIP, Joint2PIP, 85);
  }

   else if(x=='L')
  {
   greifer.move_Finger1and_Finger2oder3_until_S(Joint1DIP, Joint2DIP, 85);
  }

   else if(x=='M')
  {
   greifer.move_Finger2oder3_until_S(Joint2MCP, 100);
  }  


   else if(x=='N')
  {
   greifer.move_Finger2oder3_until_S(Joint2PIP, 100);
  }

    else if(x=='O')
  {
   greifer.move_Finger2oder3_until_S(Joint2DIP, 100);
  } 

   else if(x=='P')
  {
   greifer.move_Finger2oder3_until_S(Joint2MCP, 85);
  }

   else if(x=='Q')
  {
   greifer.move_Finger2oder3_until_S(Joint2PIP, 85);
  }  

   else if(x=='R')
  {
   greifer.move_Finger2oder3_until_S(Joint2DIP, 85);
  }  

  else if(x=='S')
  {
   Greifer_Grasp_Underactuated(100);
  }  

   else if(x=='T')
  {
   Greifer_Grasp_Underactuated(85);
  }

  
 }
}


void drive_Motor_until_Jdegree2 (int angle_desired, Joint joint)
{


     int velocity;
     int d=joint.get_Joint_angle(joint.offset_angle);

      //int m=motor1.get_Motor_angle(motor1.Motoroffset_angle);
      //Serial.print(",");
      //Serial.print(m);
      int a1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
      Serial.print(",");
      Serial.print(a1);
      int a2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
      Serial.print(",");
      Serial.println(a2);
      
      
      
      while(true){

          if(d>angle_desired)
            {
              velocity=85;
              motor1.drive_Motor (velocity); // negative acceleration: if diff = 45° the servo drives with speed 0 (fastest) , if diff = 0° the servo stops
              d=joint.get_Joint_angle(joint.offset_angle);
              if(d<=angle_desired)
                {
                  break;
                }
             //m=motor1.get_Motor_angle(motor1.Motoroffset_angle);
             //Serial.print(",");
             //Serial.print(m);
             a1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
             Serial.print(",");
             Serial.print(a1);
             a2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
             Serial.print(",");
             Serial.println(a2);

                
             continue;                     
          }

          if(d<angle_desired)
            {
              velocity=110;
              motor1.drive_Motor (velocity); // negative acceleration: if diff = 45° the servo drives with speed 0 (fastest) , if diff = 0° the servo stops
              d=joint.get_Joint_angle(joint.offset_angle);
              if(d>=angle_desired)
                {
                  break;
                }
            // m=motor1.get_Motor_angle(motor1.Motoroffset_angle);
            // Serial.print(",");
            // Serial.print(m);
             a1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
             Serial.print(",");
             Serial.print(a1);
             a2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
             Serial.print(",");
             Serial.println(a2);

                
             continue;                     
          }   
  
      }
      motor1.drive_Motor(95);
} 

void test1_Accuracy_Force(int velocity){ // velocity has to be super low!! quasi static (100)

  finger1.open_Finger(80);

      Joint1MCP.lock_Joint(0);
      Joint1PIP.lock_Joint(0);
      Joint1DIP.lock_Joint(0);

      int f;//=motor1.get_Tendon_Force();
      //Serial.println(f);
      Serial.println("MCPPJoint:");
      

      for (int i; i<45; i=i+5){
        
        motor1.drive_Motor_until_Jdegree(i,Joint1MCP);
        //f=motor1.get_Tendon_Force();
        Serial.println(f);
      }

      Serial.println("PIPJoint:");

      for (int i; i<45; i++){
        
        motor1.drive_Motor_until_Jdegree(i,Joint1PIP);
        //f=motor1.get_Tendon_Force();
        Serial.println(f);
      }
      Serial.println("DIPJoint:");

      for (int i; i<45; i++){
        
        motor1.drive_Motor_until_Jdegree(i,Joint1DIP);
        //f=motor1.get_Tendon_Force();
        Serial.println(f);
      }   
}

void test2_Accuracy_Movement(){ // Accuracy Test for one Finger and one Joint just for Finger 1!

  for (int i=0; i<101; i++)
  {
    Joint1MCP.lock_Joint(0);
    drive_Motor_until_Jdegree2 (45, Joint1MCP);
    Joint1MCP.lock_Joint(255);
    
    Joint1PIP.lock_Joint(0);
    drive_Motor_until_Jdegree2 (45, Joint1PIP);
    Joint1PIP.lock_Joint(255);

    finger1.move_oneJoint_until( Joint1MCP, 0);

    finger1.move_oneJoint_until( Joint1PIP, 0);
    
    Serial.println(i);
    Serial.println("Fertig");
    
  }
    
}
  
void test3_Joint_Position_Precision(int angle, int velocity, unsigned long Time){

  unsigned long a1=millis();
  unsigned long a2=a1+Time;
  unsigned long a=0;
  float p1;
  float p2;
  
  finger1.Finger_lockAll();
  Joint1MCP.lock_Joint(0);

  p1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
  p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
    Serial.print(",");
    Serial.print(p1);
    Serial.print(",");
    Serial.println(p2);
  
  while(a<a2){
    if(p1>angle && p1<350){
      Joint1DIP.lock_Joint(255);
      Joint1MCP.lock_Joint(255);
      Joint1PIP.lock_Joint(0);
    }

    motor1.drive_Motor(velocity);
    a=millis();
    p1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
    
    Serial.print(",");
    Serial.print(p1);
    Serial.print(",");
    Serial.println(p2);
  }
  finger1.Finger_lockAll();
  motor1.drive_Motor(95);
    Serial.print(",");
    Serial.print(p1);
    Serial.print(",");
    Serial.println(p2);
  
}

void test4_Check_Force_For_Joint_Locking(int Force){

finger1.open_Finger(80);

      Joint1MCP.lock_Joint(255);
      Joint2PIP.lock_Joint(255);
      Joint3DIP.lock_Joint(255);

      int f;//=motor.get_Tendon_Force();
      Serial.println(f);
      Serial.println("MCPPJoint:");
      

      for (int i; i<45; i=i+5){
        
        motor1.drive_Motor_until_Jdegree(i,Joint1MCP);
        //f=motor.get_Tendon_Force();
        Serial.println(f);
      }

      Serial.println("PIPJoint:");

      for (int i; i<45; i++){
        
        motor1.drive_Motor_until_Jdegree(i,Joint1PIP);
        //f=motor.get_Tendon_Force();
        Serial.println(f);
      }
      Serial.println("DIPJoint:");

      for (int i; i<45; i++){
        
        motor1.drive_Motor_until_Jdegree(i,Joint1DIP);
        //f=motor.get_Tendon_Force();
        Serial.println(f);
      }    
}


void test5_Robustness(){
  

  for (int i=0; i<501; i++){
    Joint1MCP.lock_Joint(0);
    drive_Motor_until_Jdegree2 (20, Joint1MCP);
    Joint1MCP.lock_Joint(255);
    
    Joint1PIP.lock_Joint(0);
    drive_Motor_until_Jdegree2 (30, Joint1PIP);
    Joint1PIP.lock_Joint(255);

    Joint1MCP.lock_Joint(0);
    drive_Motor_until_Jdegree2 (10, Joint1MCP);
    Joint1MCP.lock_Joint(255);

    Joint1PIP.lock_Joint(0);
    drive_Motor_until_Jdegree2 (15, Joint1PIP);
    Joint1PIP.lock_Joint(255);
    
    //test3_Joint_Position_Precision(23,180, 500);
    Serial.println(i);
    Serial.println("Fertig");
  }
}
  


void test6_Kinetik_Finger(){ // enmal statisch bereits erhoben mit MCP Locked und einmal "dynamisch" beim erheben 
  int f;
  
  finger1.open_Finger(80);
  finger1.move_oneJoint_until( Joint1MCP, 5); //Force Mode!!!
  //f=motor1.get_Tendon_Force();
  Serial.println(f);
  
  }
  
void test7_Kinematik_Finger(){
  int p3;
  int p2;
  int p1;
  
  finger1.open_Finger(80);
  delay(2000);
  
  //lateral Precision
  finger1.move_oneJoint_until( Joint1MCP, 45);

  finger1.open_Finger(80);
  delay(2000);
  
  //lateral Power
  finger1.move_oneJoint_until( Joint1DIP, 23);
    
    
    p3=Joint1DIP.get_Joint_angle(Joint1DIP.offset_angle);
    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);

   while (p2 < 23){
    finger1.move_oneJoint_until( Joint1PIP,p2+1);
    finger1.move_oneJoint_until( Joint1DIP,p3-1);

    p3=Joint1DIP.get_Joint_angle(Joint1DIP.offset_angle);
    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
   }

   

    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
    p1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);

   while (p1 < 23){
    finger1.move_oneJoint_until( Joint1MCP,p1+1);
    finger1.move_oneJoint_until( Joint1PIP,p2-1);

    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
    p1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
   }

  finger1.open_Finger(80);
  delay(2000);
  
  //cylindrical/spherical Precision
  finger1.move_oneJoint_until( Joint1DIP,45);
  finger1.move_oneJoint_until( Joint1PIP,45);
  finger1.move_oneJoint_until_S( Joint1MCP,100);

  finger1.open_Finger(80);
  delay(2000);

  //cylindrical/spherical Power
  finger1.move_oneJoint_until( Joint1PIP,22);
  finger1.move_oneJoint_until_S( Joint1MCP,100);
  finger1.move_oneJoint_until_S( Joint1PIP,100);
}


  
void test8_Kinetik_Hand()
{
  //greifer1.lateralPowerGrasping();
  //greifer1.cylindricalPowerGrasping();
  //greifer1.sphericalPowerGrasping(); 
}

void test9_Kinematik_Hand()
{
  int p1;
  int p2;
  int p3;
  
  
  greifer.Strech_Hand(80);
  delay(2000);
  
  //lateral Precision
  
  finger1.move_oneJoint_until( Joint1MCP, 45);

  greifer.Strech_Hand(80);
  delay(2000);
  
  //lateral Power
  finger1.move_oneJoint_until( Joint1DIP, 23);
    
    
    p3=Joint1DIP.get_Joint_angle(Joint1DIP.offset_angle);
    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);

   while (p2 < 23){
    finger1.move_oneJoint_until( Joint1PIP,p2+1);
    finger1.move_oneJoint_until( Joint1DIP,p3-1);

    p3=Joint1DIP.get_Joint_angle(Joint1PIP.offset_angle);
    p2=Joint1PIP.get_Joint_angle(Joint1DIP.offset_angle);
   }

   

    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
    p1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);

   while (p1 < 23){
    finger1.move_oneJoint_until( Joint1MCP,p1+1);
    finger1.move_oneJoint_until( Joint1PIP,p2-1);

    p2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
    p1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
   }

  greifer.Strech_Hand(80);
  delay(2000);
  
  //cylindrical/spherical Precision
  greifer.move_all_Finger_until(finger1.JointDIP, finger2.JointDIP, finger3.JointDIP, 45, 45, 45, 100);
  greifer.move_all_Finger_until(finger1.JointPIP, finger2.JointPIP, finger3.JointPIP, 45, 45, 45, 100);
  greifer.move_all_Finger_until_S(finger1.JointMCP, finger2.JointMCP, finger3.JointMCP,100);
  

  greifer.Strech_Hand(80);
  delay(2000);

  //cylindrical/spherical Power
  
  greifer.move_all_Finger_until(finger1.JointPIP, finger2.JointPIP, finger3.JointPIP, 22, 22, 22, 100);
  greifer.move_all_Finger_until_S(finger1.JointDIP, finger2.JointMCP, finger3.JointMCP, 100);
  greifer.move_all_Finger_until_S(finger1.JointDIP, finger2.JointDIP, finger3.JointDIP, 100);
  
}


void Greifer_Grasp_Underactuated(int velocity){
  
  greifer.unlock_all();
  
  Serial.println( "for Stop write: S");
      int a=1;

      while (a=1)
      { 
        if (Serial.available())
        {
          if(Serial.read()=='s')
          {
           while(a=1){
            if (Serial.available())
              {
              
              if(Serial.read()=='S')
                {
                  break;
                }
              }
            motor1.drive_Motor(95);
            motor2.drive_Motor(velocity);
            }
            break;
          }
        }
        motor1.drive_Motor(velocity);
        motor2.drive_Motor(velocity);
      }
      motor1.drive_Motor(95);
      motor2.drive_Motor(95);
      greifer.lock_all();
  
}


void drive_Motor_until_Jdegree (int angle_desired, Joint joint)
{


          int velocity;
          int d=joint.get_Joint_angle(joint.offset_angle);

      //int m=motor1.get_Motor_angle(motor1.Motoroffset_angle);
      int a1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
      Serial.print(",");
      Serial.print(a1);
      int a2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
      Serial.print(",");
      Serial.println(a2);
      //Serial.print(",");
      //Serial.print(m);
      
      
      
        if(d>angle_desired)
        {
          velocity=80;
          while ( d>angle_desired)
          {
             motor1.drive_Motor (velocity); // negative acceleration: if diff = 45° the servo drives with speed 0 (fastest) , if diff = 0° the servo stops
             d=joint.get_Joint_angle(joint.offset_angle);
             if(d<=angle_desired)
                {
                  break;
                }
            //m=motor1.get_Motor_angle(motor1.Motoroffset_angle);
             a1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
             Serial.print(",");
             Serial.print(a1);
             a2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
             Serial.print(",");
             Serial.println(a2);

                //Serial.print(",");
                //Serial.print(m);                     
          }
          
        }else if(d<angle_desired)
         {
          velocity=110;
          while ( d<angle_desired)
          {
             motor1.drive_Motor (velocity); // negative acceleration: if diff = 45° the servo drives with speed 0 (fastest) , if diff = 0° the servo stops
             d=joint.get_Joint_angle(joint.offset_angle);
             if(d>=angle_desired)
                {
                  break;
                }

            //m=motor1.get_Motor_angle(motor1.Motoroffset_angle);
             a1=Joint1MCP.get_Joint_angle(Joint1MCP.offset_angle);
             Serial.print(",");
             Serial.print(a1);
             a2=Joint1PIP.get_Joint_angle(Joint1PIP.offset_angle);
             Serial.print(",");
             Serial.println(a2);
      

                //Serial.print(",");
                //Serial.print(m);
        }
      }
        
} 





      
