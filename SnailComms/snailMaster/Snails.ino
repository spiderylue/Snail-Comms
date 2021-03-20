
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
  B01111
};

uint8_t snailtail[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11110
};

uint8_t snailtail2[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11000,
  B11100
};

int bottomDrawPosition = -1;
int topDrawPosition = 9;
int variation = 0;
bool moveBottom = true;

void SetupSnails()
{
//    lcd.begin();
//    lcd.backlight();

    lcd.createChar(10, snailhead1);
    lcd.createChar(11, snailhead2);
    lcd.createChar(12, snailshell);
    lcd.createChar(13, snailtail);
    lcd.createChar(14, snailtail2);

}

void DrawSnails()
{   
    lcd.clear();
    // draw top
    lcd.setCursor(max(topDrawPosition, 0), 0);
    if (topDrawPosition >= 0)
    {
      lcd.write(10 + variation);      
    }

    variation = (variation + 1) % 2;
    lcd.write(12);
    lcd.write(13 + variation);


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
      lcd.write(10 + variation);
    }
    
    lcd.write(12);
    lcd.write(13 + variation);

    if (moveBottom) {
      bottomDrawPosition--;
    }
    
    if (bottomDrawPosition == -2) {
      bottomDrawPosition = 16;
    }
    moveBottom = !moveBottom;
   
    delay(800);
}
