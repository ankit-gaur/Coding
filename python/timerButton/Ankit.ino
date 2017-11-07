void setup() {
  // put your setup code here, to run once:
    //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(12, OUTPUT);

}
bool flag = true,toggle = false;
long t1= 0,t2 = 0;
void loop() {
  // put your main code here, to run repeatedly:
 int a = digitalRead(2);
 if(a==LOW && flag==true){
  if(!toggle){
      t1 = micros();
      Serial.println("started");
      digitalWrite(12,HIGH);
      }
      else{
        t2  = micros();
        Serial.println(t2);
        digitalWrite(12,LOW);
      }
    toggle = !toggle;
    flag = false;
 }
 a = digitalRead(2);
 if(a==HIGH && flag == false){
    flag = true;
 }
 delay(50);
}
