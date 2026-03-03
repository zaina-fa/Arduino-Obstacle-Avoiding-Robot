#define en1 11
#define in11 13
#define in12 2
#define en2 5
#define in21 10
#define in22 8
#define trig 9
#define echo 7
long duration;
int distance;
void setup()
{
pinMode(en1,OUTPUT);
pinMode(in11,OUTPUT);
pinMode(in12,OUTPUT);
pinMode(en2,OUTPUT);
pinMode(in21,OUTPUT);
pinMode(in22,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);

}
void forward(){
digitalWrite(en1,HIGH);
digitalWrite(in11,HIGH);
digitalWrite(in12,LOW);
digitalWrite(en2,HIGH);
digitalWrite(in21,HIGH);
digitalWrite(in22,LOW);
}
void backward(){
 digitalWrite(en1,HIGH);
digitalWrite(in11,LOW);
digitalWrite(in12,HIGH);
digitalWrite(en2,HIGH);
digitalWrite(in21,LOW);
digitalWrite(in22,HIGH);
}
void stop(){
digitalWrite(en1,LOW);
digitalWrite(in11,LOW);
digitalWrite(in12,LOW);
digitalWrite(en2,LOW);
digitalWrite(in21,LOW);
digitalWrite(in22,LOW);
}
void right(){
digitalWrite(en1,HIGH);
digitalWrite(in11,LOW);
digitalWrite(in12,HIGH);
digitalWrite(en2,HIGH);
digitalWrite(in21,HIGH);
digitalWrite(in22,LOW);
}
void left(){
digitalWrite(en1,HIGH);
digitalWrite(in11,HIGH);
digitalWrite(in12,LOW);
digitalWrite(en2,HIGH);
digitalWrite(in21,LOW);
digitalWrite(in22,HIGH);
}

 



void loop()
{
   digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("distance: ");
  Serial.println(distance);

  delay(500);  
  if (distance > 200) {
    forward();
    delay(1500);
  
  }
  else if(distance > 100 && distance <= 200) {
    right();
    delay(1500);
  }
  else {
    stop();
  }
 

  delay(200);
}





    



