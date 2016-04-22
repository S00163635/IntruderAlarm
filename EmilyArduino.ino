#include <Bridge.h>
#include <BridgeClient.h>
#include <BridgeServer.h>
#include <BridgeUdp.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
//#include <YunClient.h>
//#include <YunServer.h>

// Function: If the sound sensor senses a sound that is up to the threshold you set in the code, the LED is on for 200ms.
// Hardware: Grove - Sound Sensor, Grove - LED
 
/*macro definitions of the sound sensor and the LED*/
#define SOUND_SENSOR 0
   // the number of the LED pin
#define BUZZER 2  
 
#define THRESHOLD_VALUE 500//The threshold to turn the led on 400.00*5/1024 = 1.95v
void setup()
{
  Bridge.begin();
  Console.begin();
//    Console.begin(9600);
    pins_init();
    //delay(10000);
    
}
 
void loop()
{
    int sensorValue = analogRead(SOUND_SENSOR);//use A0 to read the electrical signal
    Console.print("sensorValue ");
    Console.println(sensorValue);
    if(sensorValue > THRESHOLD_VALUE)
    {
        turnOnBUZZER();//if the value read from A0 is larger than 400,then light the LED
        delay(100);
    }
    turnOffBUZZER();
}
 
void pins_init()
{
    
    pinMode(BUZZER, OUTPUT);
    pinMode(SOUND_SENSOR, INPUT);
}
void turnOnBUZZER()
{
    digitalWrite(BUZZER,HIGH);
}
void turnOffBUZZER()
{
    digitalWrite(BUZZER,LOW);
}
