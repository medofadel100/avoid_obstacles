/*  This code writen by "Ahmed Fadel" at 20/2/2017
   you can follow "Ahmed Fadel on Facebook from here
   www.fb.com/medofadel48
    this code prepared to make an avoiding Obstacles Robot
    component
    1-Robot 2Wheel base with freewheel
    2-daul H-bridge
    3-ultrasonuc
    4-arduino uno
    wire as showen in the code
    writen for Robot Workshop
    with best wishes makeing your Robot
*/
//#include<SoftwareSerial.h>
int trigC = 6;   //trig pin at center  ultrasonic
int echoC = 7;   //echo pin at  center ultrasonic
long durationC ; // value of time center ultrasonic
long distanceC ; // value of distance center ultrasonic
int IN1 = 9 ;    // input 1 for motor 1
int IN2 = 8 ;    // input 2 for motor 1
int IN3 = 10 ;   // input 1 for motor 2
int IN4 = 11 ;   // input 2 for motor 2
void setup()
{
  pinMode(trigC , OUTPUT); //define trig pin as output
  pinMode(echoC, INPUT);   //define echo pin as input
  //define motor pin control as output pins
  pinMode ( IN1 , OUTPUT);
  pinMode ( IN2 , OUTPUT);
  pinMode ( IN3 , OUTPUT);
  pinMode ( IN4 , OUTPUT);
  Serial.begin(9600); // start serial commuincation
}
void loop()
{
  ultrasonicC () ; //operate ultrasonic function
  // if distance less than 10 cm Robot turn
  if ( distanceC <= 10)
  {
    Serial.println("there is Obstacles on  "); //print a massage on serial monitor
    Serial.println(distanceC); // print the distance on serial monitor
    turn (); // robot change his diraction
  }
  //if distance more than 10 cm robot move forward
  else {
    delay(100); // wait 100 mile second
    Serial.println("no Obstacles ");//print a massage on serial monitor
    Serial.println(distanceC); // print the distance on serial monitor
    forward(); // robot move forward
    Serial.println("F");
  }
}
//Robot turn his movement function
void turn ()
{
  digitalWrite( IN1, LOW);
  digitalWrite( IN2, HIGH);
  digitalWrite ( IN3, LOW);
  digitalWrite ( IN4, HIGH);
}
//robot stop function
void Stop ()
{
  digitalWrite( IN1, LOW);
  digitalWrite( IN2, LOW);
  digitalWrite ( IN3, LOW);
  digitalWrite ( IN4, LOW);
}
// robot move forward function
void forward ()
{
  digitalWrite( IN1, HIGH);
  digitalWrite( IN2, LOW );
  digitalWrite ( IN3, HIGH);
  digitalWrite ( IN4, LOW);
}
//ultrasonic operating function
void ultrasonicC ()
{
  digitalWrite(trigC, LOW); // turn off trig from sending any sound wave
  delayMicroseconds(2); // wait 2 micro second
  digitalWrite(trigC, HIGH); //turn on trig and send a sound wave
  delayMicroseconds(10); // delay 2 micro second
  digitalWrite(trigC, LOW); //trun off trig
  durationC = pulseIn(echoC, HIGH); // measure time for sound wave to come back
  distanceC = durationC / 58; //equation to calculate the distance from mesured time and fixed sound speed in air
}


