#include <CapacitiveSensor.h>
CapacitiveSensor   capacitivo1 = CapacitiveSensor(2,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
int sensorTati = 0;

void setup()                    
{
   capacitivo1.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode (8, OUTPUT); // piezo
}

void loop()                    
{

    
    long start = millis();
    long total1 =  capacitivo1.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.println(sensorTati);                  // print sensor output 1

   map (sensorTati, 10, 12000, 956, 1911);
 
    delay(50);                             // arbitrary delay to limit data to serial port 
    digitalWrite (8, HIGH);
    delayMicroseconds (sensorTati);
    digitalWrite (8,LOW);
    delayMicroseconds (sensorTati);

}
