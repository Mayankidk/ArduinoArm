#include<Servo.h>

Servo servo[5];

const int buttonpin[7]={2,3,4,7,8,12,13};
const int servopin[5]={5,6,9,10,11};

bool button[7]={};
bool doub[7]={};
bool sing[7]={};
int pos[5]={0,180,90,90,0};

bool doom=false;
bool grab=false;      

void setup()
{
  for(int i=0;i<7;i++)
  	pinMode(buttonpin[i],INPUT);
  for(int i=0;i<5;i++)
  {
    while(!doom)
      doom=digitalRead(buttonpin[0]);
    servo[i].attach(servopin[i]);
    servo[i].write(pos[i]);
    delay(600);
  }
}

void loop()
{
  delay(20);
  for(int i=3;i<7;i++)
  {
    button[i]=digitalRead(buttonpin[i]);
    if(button[i] && !doub[i] && !sing[i])
    {
      for(int j=0;j<6;j++)
      {
        delay(50);
        if(!digitalRead(buttonpin[i]))
        {
          j=10;
          for(int k=0;k<8;k++)
          {
            if(digitalRead(buttonpin[i]))
            {
              k=10;
              doub[i]=true;
              sing[i]=false;
            }
            delay(50);
          }
        }
        else
          sing[i]=true;
      }
    }
    else if(!button[i])
    {
      doub[i]=false;
      sing[i]=false;
    }
  }
  
  if(digitalRead(buttonpin[1]))
    if(pos[0]<180)
      servo[0].write(pos[0]+=1);
      
  if(digitalRead(buttonpin[2]))
    if(pos[0]>0)
      servo[0].write(pos[0]-=1);
    
  if(sing[3])
    if(pos[1]<180)
      servo[1].write(pos[1]+=1);
      
  if(doub[3])
    if(pos[1]>0)
      servo[1].write(pos[1]-=1);
    
  if(sing[4])
    if(pos[2]<180)
      servo[2].write(pos[2]+=1);
      
  if(doub[4])
    if(pos[2]>0)
      servo[2].write(pos[2]-=1);
      
  if(sing[5])
    if(pos[3]<180)
      servo[3].write(pos[3]+=1);
      
  if(doub[5])
    if(pos[3]>0)
      servo[3].write(pos[3]-=1);
      
  if(sing[6])
    if(pos[4]>0)
      servo[4].write(pos[4]-=2);
  
  if(doub[6])
    if(pos[4]<180)
      servo[4].write(pos[4]+=2);
  
  /*if(digitalRead(buttonpin[6]))
  {
    if(grab)
    {
      servo[4].write(0);
      grab=false;
    }
    else
    {
      servo[4].write(180);
      grab=true;
    }
    delay(250);
  }*/
}