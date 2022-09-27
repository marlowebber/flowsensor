#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include <SFM4X00.h>

Adafruit_ST7735 tft = Adafruit_ST7735(     8,      A3,      A2,       A1,      9);


// char array to print to the screen
char sensorPrintout[12];

// delay between readings
#define SAMPLE_DELAY   550

// address of sensor
// usually 64 or 0x40 by default
#define FLOW_SENSOR_ADDRESS 0x40

// create instance of sensor with address
SFM4x00 flowSensor(FLOW_SENSOR_ADDRESS);

void testdrawtext(char *text, uint16_t color) 
{
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void setup(void) 
{  

    pinMode(A0, OUTPUT);    
  digitalWrite(A0, HIGH); // A0 supplies power to the screen backlight.
  pinMode(10, OUTPUT);     
  digitalWrite(10, HIGH); // 10 supplies power to the flow sensor.

delay(1000);
  
  Wire.begin();

  
delay(100);

  flowSensor.begin();
  

  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab

  tft.setTextWrap(false);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(4);
}

void loop() 
{
   float flow = flowSensor.takeFlowMeas();
  String sensorVal = String(flow) + String("\nL/min");
  sensorVal.toCharArray(sensorPrintout, 12);
  
  tft.fillScreen(ST77XX_BLACK);
//  testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);

  testdrawtext(sensorPrintout, 12);
  delay(2000);
}


