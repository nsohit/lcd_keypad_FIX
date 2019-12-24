#include <Password.h>
#include <Keypad.h>
Password password = Password( "45" ); //Ubah password
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
const byte baris = 3; //Baris
const byte kolom = 3; //Kolom

char keys[baris][kolom] = {
//{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};


byte barisPin[baris] = {2,3,4};
byte kolomPin[kolom]= {8,9,10};

// Buat objek keypad
Keypad keypad = Keypad( makeKeymap(keys), barisPin, kolomPin, baris, kolom );
LiquidCrystal_I2C lcd(0x27, 16, 2);  


void setup() {
  // put your setup code here, to run once:
  lcd.backlight();
  lcd.init(); 
  keypad.addEventListener(keypadEvent);
}

void loop() {
  char key =keypad.getKey();
  //myservo.write(0);
  
  lcd.setCursor(3,0); 
  lcd.print("Masukan PWD");
}
 
  void keypadEvent(KeypadEvent key){ 
  
  switch (keypad.getState()){
  case PRESSED:
  
  lcd.setCursor(3,1);
  lcd.print(key);
  delay(10);
  
  //Serial.write(254);
  
  switch (key){
    case '*': Login(); delay(1); break;
    
    case '#': password.reset(); delay(1); break;
    
     default: password.append(key); delay(1);
    }
  }
}

void Login(){ 
if (password.evaluate()){
    lcd.setCursor(3,1);
     lcd.print("Akses Diterima!");
 //   Serial.write(254);
   // myservo.write(180);
    //digitalWrite(LEDhijau, HIGH);
    //delay(5000);
    //myservo.write(10);
    //digitalWrite(LEDhijau, LOW);
    //delay(500);
}

else{
    lcd.setCursor(3,1);
    lcd.print("Akses Ditolak!");
    //Serial.write(254);
    //delay(10);
    //myservo.write(0);
    //digitalWrite(LEDmerah, HIGH);
    //delay(500);
    //digitalWrite(LEDmerah, LOW);
  }
}
