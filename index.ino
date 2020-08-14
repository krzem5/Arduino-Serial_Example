#include <LCD.h>
#include <Ultrasonic.h>



LCD lcd(12,11,5,4,3,2);
Ultrasonic ds(10,9);



void setup(){
	ds.init();
	lcd.size(16,2);
	lcd.init();
	lcd.write("Distance:");
	Serial.begin(9600);
}



void loop(){
	static uint8_t ml=0;
	unsigned int d=ds.distance();////////// SLOW
	lcd.move(0,1);
	lcd.write(d);
	lcd.write(" cm");
	if (String(d).length()<ml){
		for (uint8_t i=String(d).length();i<ml;i++){
			lcd.write(" ");
		}
	}
	else if (String(d).length()>ml){
		ml=String(d).length();
	}
	if (Serial){
		Serial.print((millis()%500)/1e3);
		Serial.print(",");
		Serial.println(d);
	}
}
