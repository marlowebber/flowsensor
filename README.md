# flowsensor
sensirion air flow sensor that prints to a little screen.

connection map:
using sensirion SFM4200-MGE, arduino uno R3 'kuman', altronics/duinotech ST7735 1.44" 128x128 TFT screen.   
tft screen  -> arduino   
	VCC -> 5V   
	GND -> GND   
	LED -> A0   
	CLK -> A1   
	SDI -> A2   
	RS  -> A3   
	RST -> 9   
	CS  -> 8
	      
flow sensor -> arduino   
	the flow sensor is plugged into a module which contains the pull up resistors.   
	sda and scl are pulled up to 5V using 10k ohm resistors.   
	gnd  -> GND   
	vcc  -> 10 . pin 10 is high and this is used to power the flow sensor.   
	clk  -> A5 OR package pin 28 near reset button.   
	sda  -> A4 OR package pin 27.    
