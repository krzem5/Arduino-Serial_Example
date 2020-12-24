void setup(){
	Serial.begin(9600);
}



void loop(){
	if (Serial&&millis()%1000==0){
		Serial.println(millis()/1000);
	}
}
