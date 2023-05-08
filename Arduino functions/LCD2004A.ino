#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);


void setup() {
   setup_LCD();
  lcd.backlight();
}

void loop()
{
LCD_SHOW();
}




void setup_LCD()
{
    lcd.begin();
    lcd.backlight();
}

void LCD_SHOW()
{
  int redCount = 0;
  int goldCount = 0;
  int silverCount = 0;
  int blueCount = 0;
  int greenCount = 0;
  int whiteCount = 0;
    // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Red:   ");
  lcd.print(redCount);

  lcd.setCursor(0, 1);
  lcd.print("Gold:  ");
  lcd.print(goldCount);

  lcd.setCursor(0, 2);
  lcd.print("Silver:");
  lcd.print(silverCount);

  lcd.setCursor(0, 3);
  lcd.print("Blue:  ");
  lcd.print(blueCount);

  lcd.setCursor(10, 0);
  lcd.print("Green: ");
  lcd.print(greenCount);

  lcd.setCursor(10, 1);
  lcd.print("White: ");
  lcd.print(whiteCount);

}
