
#include <LCD_I2C.h>

LCD_I2C lcd(0x27); // Default address of most PCF8574 modules, change according

uint8_t snailhead1[8] =
{
  B00000,
  B10100,
  B10010,
  B01111,
  B00111,
  B01011,
  B00011,
  B00111
};

uint8_t snailhead2[8] =
{
  B00000,
  B01010,
  B10010,
  B01111,
  B00111,
  B01011,
  B00011,
  B00111
};

uint8_t snailshell[8] =
{
  B00000,
  B00000,
  B01110,
  B10001,
  B11101,
  B10101,
  B10001,
  B01110
};

int bottomDrawPosition = -1;
int topDrawPosition = 9;
int variation = 0;
bool moveBottom = true;

void setup()
{
    lcd.begin();
    lcd.backlight();

    lcd.createChar(0, snailhead1);
    lcd.createChar(1, snailhead2);
    lcd.createChar(2, snailshell);

}

void loop()
{   
    lcd.clear();
    // draw top
    lcd.setCursor(max(topDrawPosition, 0), 0);
    if (topDrawPosition >= 0)
    {
      lcd.write(0 + variation);      
    }

    variation = (variation + 1) % 2;
    lcd.write(2);


    if (!moveBottom)
    {
      topDrawPosition--;
    }
    if (topDrawPosition == -2) {
      topDrawPosition = 16;
    }

//  // draw bottom
    lcd.setCursor(bottomDrawPosition, 1); 
    if (bottomDrawPosition >=0)
    {
      lcd.write(0 + variation);
    }
    
    lcd.write(2);

    if (moveBottom) {
      bottomDrawPosition--;
    }
    
    if (bottomDrawPosition == -2) {
      bottomDrawPosition = 16;
    }
    moveBottom = !moveBottom;
   
    delay(800);
}
