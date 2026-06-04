#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo;

struct DisplayStep {
  const char* text;
  int duration;
  bool clearAfter;
};

DisplayStep quote1[] = {
  {"CLASS OF 2026 GG", 8000, true}
};

DisplayStep quote2[] = {
  {"Be Bold", 1500, true},
  {"Be Original", 2000, true},
  {"Be", 1500, true},
  {"INVINCIBLE", 5000, true},
};

DisplayStep* quotes[] = {
  quote1,
  quote2
};

int quoteLengths[] = {
  sizeof(quote1) / sizeof(DisplayStep),
  sizeof(quote2) / sizeof(DisplayStep)
};

void printWrapped(const char* text) {
  lcd.clear();

  int len = strlen(text);

  if (len <= 16) {
    lcd.setCursor(0, 0);
    lcd.print(text);
  } else {
    lcd.setCursor(0, 0);

    for (int i = 0; i < 16 && text[i] != '\0'; i++) {
      lcd.print(text[i]);
    }

    lcd.setCursor(0, 1);

    for (int i = 16; i < 32 && text[i] != '\0'; i++) {
      lcd.print(text[i]);
    }
  }
}

void sweepServo() {
  for (int pos = 0; pos <= 180; pos += 2) {
    servo.write(pos);
    analogWrite(6,pos);
    delay(10);
  }

  for (int pos = 180; pos >= 0; pos -= 2) {
    servo.write(pos);
    analogWrite(6,pos);
    delay(10);
  }
}

void setup() {
  lcd.begin(16, 2);

  servo.attach(9);
  servo.write(90);

  randomSeed(millis());
}

void loop() {
  int choice = random(2);

  DisplayStep* quote = quotes[choice];
  int length = quoteLengths[choice];

  for (int i = 0; i < length; i++) {
    printWrapped(quote[i].text);
    delay(quote[i].duration);

    if (quote[i].clearAfter) {
      lcd.clear();
    }
  }

  lcd.clear();
  delay(500);

  sweepServo(); 

  delay(1000);
}