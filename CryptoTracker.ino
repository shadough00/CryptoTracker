// include the library code:
#include <LiquidCrystal.h>

#define RED 6
#define GREEN 5

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

double cryptoPrice = 38238;
long randomNumber;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Stores crypto tickers in string array
  char *cryptoArray[] = {"BTC", "ETH", "XRP", "DOT", "ADA"};
  // Print a message to the LCD.
  lcd.print("BTC");
  lcd.setCursor(0, 1);
  lcd.print("$");
  lcd.print(cryptoPrice);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  randomSeed(analogRead(0));
}

void loop() {
  double newCryptoPrice;
  randomNumber = random(2);
  if (randomNumber == 1) {
    newCryptoPrice = cryptoPrice++;
  } else {
    newCryptoPrice = cryptoPrice--;
  }
  lcd.setCursor(0, 1);
  lcd.print("$");
  lcd.print(newCryptoPrice);
  if (randomNumber == 1) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
  delay(1000);
}
