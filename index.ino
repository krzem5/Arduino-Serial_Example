void setup(){
	Serial.begin(9600);
	while (!Serial);
}



void loop(){
	Serial.println(millis()/1e3);
}
