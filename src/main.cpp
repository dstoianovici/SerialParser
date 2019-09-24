#include <Arduino.h>
#include <Serial_Parser.h>
// #include <stdio.h>
// #include <stdlib.h>


#define BAUD_RATE 115200

Serial_Parser parser(',');

void setup() {
Serial.begin(BAUD_RATE);
}

void loop() {
  int nums[100];
  int i = parser.GetParams(nums);


  if(i > 0){
    Serial.println(i);
    for(int j=0; j<i; j++){
      Serial.println(nums[j],DEC);
      //delay(500);
    }
  }



  // String py_data = "/n";
  // String sub_string = "/n";
  // char str_arrbuff[255]; //array buffer for string conversion
  // int nums[100]; //Return array for individual int values in the string
  // int index = 0; //Index of the comma
  // int i = 0; // itterator for nums array
  // int flag = 1; //Flag for end of string object processing
  //
  //
  // if (Serial.available() > 0){
  //   Serial.println("Recieved");
  //   py_data = Serial.readString();
  //
  //   while(flag == 1){
  //
  //     index = py_data.indexOf(',');
  //
  //     if(index == -1){//No more commas
  //       py_data.toCharArray(str_arrbuff,255);
  //       // len = py_data.length() - 1;
  //       nums[i] = py_data.toInt();
  //       //Serial.println(num);
  //       i++;
  //       flag = 0;
  //     }
  //
  //     else{
  //       sub_string = py_data.substring(0,index);
  //       // len = sub_string.length();
  //       py_data.remove(0,index+1);
  //       nums[i] = sub_string.toInt();
  //     // Serial.println(num);
  //       i++;
  //       flag = 1;
  //     }
  //   }
  // }
  //
  // if(flag == 0){
  //   for(int j=0; j<i; j++){
  //     Serial.println(nums[j],DEC);
  //   }
  // }
}
