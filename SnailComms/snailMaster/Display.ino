#include <LCD_I2C.h>

LCD_I2C lcd(0x27); // Default address of most PCF8574 modules, change according

uint8_t degree[8] =
{
    0b01110,
    0b01010,
    0b01110,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
};

int DEGREE_CHAR = 0;

void SetupDisplay() {
    lcd.begin(); 
    lcd.backlight();
    lcd.createChar(DEGREE_CHAR, degree);
}


void ClearDisplay() {
   // Clear screen
      lcd.clear();
}

void UpdateDisplay(int row, int Hygro, int Temp, int Hum) {

    // Set cursor to the first character on desired row
    lcd.setCursor(0, row);

    // Print Hygrometer reading
    lcd.print("HG"); 
    if(Hygro >= 100) {
      lcd.setCursor(2, row);
    }
    else if(Hygro <= 9) {
      lcd.setCursor(4, row);
    }
    else {
      lcd.setCursor(3, row);
    }
    lcd.print(Hygro);

    // Print Temperature reading
    lcd.setCursor(5, row);
    lcd.print("%T");
    if(Temp <= 9) {
      lcd.setCursor(8, row);
    }
    else {
      lcd.setCursor(7, row);
    }
    lcd.print(Temp);
    lcd.setCursor(9, row);
    lcd.write(DEGREE_CHAR);   
    lcd.setCursor(10, row);

    // Print Humidity reading
    lcd.print("CH");
    if(Hum >= 100) {
      lcd.setCursor(12, row);
    }
    else if(Hum <= 9) {
      lcd.setCursor(14, row);
    }
    else {
      lcd.setCursor(13, row);
    }
    lcd.print(Hum);
    lcd.setCursor(15, row);
    lcd.print("%");
}
