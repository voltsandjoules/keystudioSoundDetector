const float dBAnalogQuiet = 10; // calibrated value from analog input (48 dB equivalent)
const float dBAnalogMedium = 12;
const float dBAnalogLoud = 17;
float value = 0.0; //filtro lpf
float weight = 0.1; // how much your values are 'smoothed'lpf
void setup()
{
Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop()
{
  
int val;
val=analogRead(0); //connect mic sensor to Analog 0
  float decibelsValueQuiet = 49;
  float decibelsValueMedium = 65;
  float decibelsValueLoud = 70;
if(val>0){
    if (val < 13)
  {
    decibelsValueQuiet += 20 * log10(val/dBAnalogQuiet);
      value = (1.0-weight) * value   +   weight * decibelsValueQuiet;   // low-pass values
 // Serial.println(value); // print value

    Serial.println(value,DEC);
    }
  else if ((val > 13) && ( val <= 23) )
  {
    decibelsValueMedium += log10(val/dBAnalogMedium);
    //Serial.println(decibelsValueMedium,DEC);
    value = (1.0-weight) * value   +   weight * decibelsValueMedium;   // low-pass values
Serial.println(value,DEC);
  }
  else if(val > 22)
  {
    decibelsValueLoud += log10(val/dBAnalogLoud);
     value = (1.0-weight) * value   +   weight * decibelsValueLoud;   // low-pass values
    //Serial.println(decibelsValueLoud,DEC);
    Serial.println(value,DEC);
  }
  delay(50);
}
//Serial.println(val,DEC);//print the sound value to serial

delay(100);
}
