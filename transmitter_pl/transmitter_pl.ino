#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

//RH_ASK driver(4800);
RH_ASK driver;
//RH_ASK driver(4800,11,12,10,false);

#define SWITCH_PIN   9

char switch_value = 0;
char message[5];
uint16_t p1= 0, p2 = 0;

void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");

    pinMode(SWITCH_PIN, INPUT_PULLUP);   
    digitalWrite(12,LOW); 
}

void loop()
{
    
    switch_value = digitalRead(SWITCH_PIN);
    p1 = analogRead(A0);
    p2 = analogRead(A1);

     message[1] = (p1 & 0xFF00) >> 8;
     message[2] = (p1 & 0x00FF);
     message[3] = (p2 & 0xFF00) >> 8;
     message[4] = (p2 & 0x00FF);

    if(switch_value == 0)
    {
      //driver.send((uint8_t *)msg1, strlen(msg1));
      message[0] ='a';
      driver.send((uint8_t *)message, strlen(message));
      driver.waitPacketSent();
    }
    else
    {
      message[0] ='s';
      driver.send((uint8_t *)message, strlen(message));
      driver.waitPacketSent();
    }
    
    
}
