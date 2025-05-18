#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

char switch_value = 0;


void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");

    pinMode(8, INPUT);    
}

void loop()
{
    const char *msg1 = "a";
    const char *msg2 = "s";

    switch_value = digitalRead(8);
    if(switch_value == 1)
    {
      driver.send((uint8_t *)msg1, strlen(msg1));
      driver.waitPacketSent();
    }
    else
    {
      driver.send((uint8_t *)msg2, strlen(msg2));
      driver.waitPacketSent();
    }
    
    
}
