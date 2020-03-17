String relay_status;
String data;

void setup ()
{
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);


Serial.begin (115200);
}

void loop()
{

if(Serial.available()){
        data = Serial.readStringUntil('\n');
 
        //Serial.println("Reived via serial " + data);

     //relay_status = data.toInt();
       relay_status = data;
 
if (relay_status=="on")
{
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
Serial.println();
Serial.println("Target is Turned ON ");
Serial.println();
}

else if (relay_status=="off")
{
digitalWrite(4,LOW);
digitalWrite(5,LOW);
Serial.println();
Serial.println("Target is Turned OFF ");
Serial.println();
}        

else
{
Serial.println();
Serial.println("############################################");
Serial.println("To command the power supply:   ");
Serial.println("send command 'on' to power ON the target");
Serial.println("send command 'off' to power OFF the target");
Serial.println("############################################");
Serial.println();
}        
}
}
