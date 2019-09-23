#include <Arduino.h>

String py_data = "";
char* string_arr[255];

void setup() {

  Serial.begin(115200);
  pinMode(13,OUTPUT);

}

void loop() {

  if (Serial.available() > 0){
    py_data = Serial.read();
    int index1 = py_data.indexOf(',');
    py_data.toCharArray(string_arr,255);

  }

}
