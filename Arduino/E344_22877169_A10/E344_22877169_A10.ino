
bool led = false;
uint8_t ledPin = 13;
String received = "";

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);  
  digitalWrite(ledPin, led);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    received = Serial.readStringUntil('\n');
  }
  
  if(received != ""){
    if(received == "Toggle LED"){
      led = !led;
      digitalWrite(ledPin, led);
      Serial.println("LED"+String(led));
    }
    received = "";
  }
}
