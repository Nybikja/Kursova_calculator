#include <LiquidCrystal.h>
#include <Keypad.h>

long Num1,Num2,Number;
char action;
boolean result = false;


const int rs = 52, rw = 51, en = 50, c0 = 37, c1 = 36, c2 = 35, c3 = 34, c4 = 33, c5 = 32, c6 = 31, c7 = 30;
LiquidCrystal lcd(rs, rw, en, c0, c1, c2, c3, c4, c5, c6, c7);


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); //We are using a 16*2 LCD display
}


void loop() {
  String inBytes = Serial.readStringUntil('\n');  
  DetectButtons(inBytes);
  if (result==true) {
    calculateResult();
    sendResult(Num1, action, Num2, Number);
  } 
  displayResult();    
}


void DetectButtons(String inBytes) { 
  lcd.clear();

  if (inBytes == "button_0") {
    if (Number==0)  {
      Number=0;
    }
    else {
      Number = (Number*10) + 0; //Pressed twice
    }
  }

  if (inBytes == "button_1") {
    if (Number==0) {
      Number=1; 
    }
    else {
      Number = (Number*10) + 1; //Pressed twice
    }
  }

  if (inBytes == "button_2") {
    if (Number==0) {
      Number=2; 
    }
    else {
      Number = (Number*10) + 2; //Pressed twice
    }  
  }

  if (inBytes == "button_3") {
    if (Number==0) {
      Number=3;
    }
    else {
      Number = (Number*10) + 3; //Pressed twice
    }
  }
     
  if (inBytes == "button_4") {
    if (Number==0){
      Number=4;
    }
    else {
      Number = (Number*10) + 4; //Pressed twice 
    }
  }

  if (inBytes == "button_5") {
    if (Number==0) {
      Number=5; 
    }
    else {
      Number = (Number*10) + 5; //Pressed twice
    }
  }

  if (inBytes == "button_6") {
    if (Number==0) {
      Number=6;
    }
    else {
      Number = (Number*10) + 6; //Pressed twice
    }
  }

  if (inBytes == "button_7") {
    if (Number==0) {
      Number=7;
    }
    else {
      Number = (Number*10) + 7;
    }
  }
  
  if (inBytes == "button_8") {
    if (Number==0) {
      Number=8;
    }
    else {
      Number = (Number*10) + 8; //Pressed twice
    }   
  }

  if (inBytes == "button_9") {
    if (Number==0) {
      Number=9;
    }
    else {
      Number = (Number*10) + 9; //Pressed twice
    }
  }

  if (inBytes == "button_clear") {
    Number=Num1=Num2=0;
    result=false;
  }

  if (inBytes == "button_equals") {
    Num2=Number;
    result = true;
  }

  //Detecting Buttons on Column 4
  if (inBytes == "button_divide" || inBytes == "button_multiply" || inBytes == "button_minus" || inBytes == "button_plus") {
    Num1 = Number;    

    Number =0;

    if (inBytes == "button_divide") { 
      action = '/';
    }
    
    if (inBytes == "button_multiply") {
      action = '*';
    }

    if (inBytes == "button_minus") {
      action = '-';
    }

    if (inBytes == "button_plus") {
      action = '+';
    }
  }
}


void calculateResult() {
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}


void displayResult() {
  lcd.setCursor(0, 0);

  lcd.print(Num1); lcd.print(action); lcd.print(Num2); 

  if (result==true) {
    lcd.print(" ="); 
    lcd.print(Number);}
    
    lcd.setCursor(0, 1);
    
    lcd.print(Number);
}

void sendResult(int num1,char act, int num2, int sum) { 
  Serial.print(num1);
  Serial.print(act);
  Serial.print(num2);
  Serial.print("=");
  Serial.println(sum);
  
}
