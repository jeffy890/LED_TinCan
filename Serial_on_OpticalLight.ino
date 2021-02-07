
#include <SoftwareSerial.h>
SoftwareSerial sSerial(10, 11);

int count = 0;

void setup() {
  Serial.begin(9600);
  sSerial.begin(9600);
}

void loop() {
  
  sSerial.println(100);
  if(Serial.available()){
    count += 1;
    Serial.print("got signal !!  ");
    Serial.print(count);
    Serial.print("  times !!  read >>");
    Serial.println(Serial.read());
  }

  delay(10);
}
