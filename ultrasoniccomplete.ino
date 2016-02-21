int leftforward = 10; //yellow
int leftreverse = 11; //green
int rightforward = 6; //white
int rightreverse = 5; //blue
int trig = 3; //orange
int echo = 9; //brown
long duration; //amount of time in milliseconds for the echo to be sent out and recieved
int speed = 60; //speed of motors between 0 - 255
int threshold = 1000; //time of ping that triggers the robot to reverse

void setup() {
Serial.begin(9600);
pinMode(trig,OUTPUT); //outbound ping
pinMode(echo,INPUT); // inbound reciever
pinMode(leftforward,OUTPUT); //pin to tell left motor to go forward
pinMode(leftreverse,OUTPUT); //pin to tell left motor to go reverse
pinMode(rightforward,OUTPUT); //pin to tell right motor to go forward
pinMode(rightreverse,OUTPUT); //pin to tell right motor to go reverse


}

void loop() {

  digitalWrite(trig, LOW);  // This loop sets the transmitting speaker to be on for 10ms and off for 5ms
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  duration = pulseIn(echo, HIGH); //listen to response from echoing ping and saves in long format to duration(ms)
  Serial.println(duration); //print the duration
  delay(100); // wait 100ms
  

  if(duration<threshold) {
    analogWrite(leftforward,0); //conditions if an obstacle gets in the way of the sensor
    analogWrite(rightforward,0);
    analogWrite(rightreverse,speed*1.5);
    Serial.print("reversing  |  ");
    delay(2000);
    }
  else if(duration>=threshold) {
    analogWrite(leftreverse,0); //conditions if there is nothing in the way of the sensor
    analogWrite(rightreverse,0);
    analogWrite(leftforward,speed);
    analogWrite(rightforward,speed);
    Serial.print("moving forward  |  ");
    delay(100);
    }
}
