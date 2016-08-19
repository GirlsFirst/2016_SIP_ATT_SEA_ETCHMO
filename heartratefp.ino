// Open a serial connection and flash LED when input is received
int ledPin = 13;
void setup(){
  // Open serial connection.
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("hello");
  
}
boolean flatline = false;
int x=0;
void loop(){ 
x++;
if (x<1000){
  Serial.println(2*sin(x/10) + sin(x));
  digitalWrite(ledPin,LOW);
}
else{
  Serial.println(0);
  digitalWrite(ledPin,HIGH);
}
  }
