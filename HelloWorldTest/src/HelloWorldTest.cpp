//============================================================================
// Name        : HelloWorldTest.cpp
// Author      : Dayton
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	cout << "LED Flash Start" << endl;

	FILE *LEDHandle = NULL;
	char *LEDBrightness = "/sys/class/leds/beaglebone:green:usr3/brightness";
	for(int i=0; i<10;i++){
		if((LEDHandle = fopen(LEDBrightness, "r+"))!=NULL){
			fwrite("1",sizeof(char),1,LEDHandle);
			fclose(LEDHandle);
		}
		sleep(1);
		if((LEDHandle = fopen(LEDBrightness, "r+"))!=NULL){
			fwrite("0",sizeof(char),1,LEDHandle);
			fclose(LEDHandle);
		}
		sleep(1);
	}
	cout << "LED Flash End" << endl;
	return 0;
}
