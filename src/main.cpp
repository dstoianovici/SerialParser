#include <Arduino.h>


void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  Serial.println("initialized");
}

void loop() {
  String py_data = "/n";
  String sub_string = "/n";
  char str_arrbuff[255]; //array buffer for string conversion
  int nums[100]; //Return array for individual int values in the string
  int index = 0; //Index of the comma
  int i = 0; // itterator for nums array
  int flag = 1; //Flag for end of string object processing


  if (Serial.available() > 0){
    Serial.println("Recieved");
    py_data = Serial.readString();

    while(flag == 1){

      index = py_data.indexOf(',');

      if(index == -1){//No more commas
        py_data.toCharArray(str_arrbuff,255);
        // len = py_data.length() - 1;
        nums[i] = py_data.toInt();
        //Serial.println(num);
        i++;
        flag = 0;
      }

      else{
        sub_string = py_data.substring(0,index);
        // len = sub_string.length();
        py_data.remove(0,index+1);
        nums[i] = sub_string.toInt();
      // Serial.println(num);
        i++;
        flag = 1;
      }
    }
  }

  if(flag == 0){
    for(int j=0; j<i; j++){
      Serial.println(nums[j],DEC);
    }
  }
}
