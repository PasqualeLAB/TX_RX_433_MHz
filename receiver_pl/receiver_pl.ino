#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile


//RH_ASK(uint16_t speed = 9000, uint8_t rxPin = 11, uint8_t txPin = 12, uint8_t pttPin = 10, bool pttInverted = false);
//RH_ASK driver(4800);
//RH_ASK driver;
//RH_ASK driver(4800,11,12,10,false);
RH_ASK driver;

uint16_t p1 = 0, p2 = 0;

void setup()
{
    Serial.begin(9600);	// Debugging only
    pinMode(13,OUTPUT);
    digitalWrite(13, LOW);
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      if((char)buf[0] == 'a')
        digitalWrite(13, HIGH);
      
      else if((char)buf[0] == 's')
        digitalWrite(13, LOW);

      else
        digitalWrite(13, LOW);

      p1 = (buf[1] << 8) | (buf[2]);  
      p2 = (buf[3] << 8) | (buf[4]);  

      Serial.print("p1: ");
      Serial.print(p1);
      Serial.print("   p2: ");
      Serial.println(p2);

      // Message with a good checksum received, dump it.
      //driver.printBuffer("Got:", buf, buflen);
    }
}
