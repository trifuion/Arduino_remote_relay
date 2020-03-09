String relay_status;
String data;

void setup ()
{
pinMode(9, OUTPUT);
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
digitalWrite(9,HIGH);
Serial.println();
Serial.println("Target is Turned ON ");
Serial.println();
}

else if (relay_status=="off")
{
digitalWrite(9,LOW);
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
