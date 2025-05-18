#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

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

      // Message with a good checksum received, dump it.
      //driver.printBuffer("Got:", buf, buflen);
    }
}
