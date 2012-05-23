#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
int move = 10; ///pin dec for movement pin
int start = 9; // pin dec for select pin
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

//menu and sub menu options
char* menut[] = {"menu option 1", "menu option 2", "menu option 3",};
char* menus1[] = {"sub option 1" , "sub option 2", "quit",};

//menu and submenu start and stop
int mstart = 0;
int mmenu =0;
int submen1 = 0;
int smenu1 = 0;
//select button functions
void select1(int x)
  {
    if ( x == 0)
    {
      mstart = 0;
      submen1 = 1;
      smenu1 = 0;
    }
  }
void select2(int x)
{
   if (x == 2)
   {
     mstart = 1;
     submen1 = 0;
     mmenu = 0;
   }
  }
  
void setup()   { 
  pinMode(move,INPUT);
  pinMode(start,INPUT);
  Serial.begin(9600);
  display.begin();
  display.clearDisplay();
  display.setContrast(100);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  mstart = 1;
  
}
void loop()
{  //main menu
  if (mstart == 1)
  {
    
    if (digitalRead(move) == HIGH)
      {
        mmenu++;  
        delay(200); 
      }
      if (mmenu > 2)
           { mmenu = 0;}
            if (digitalRead (start) == HIGH)
    {
      select1(mmenu);
      delay(200);
    }
    
    display.println(menut[mmenu]);
    display.display();
    display.clearDisplay();
    
   
  }

  //programs submenu
  if (submen1 == 1)
  {
    
    if (digitalRead(move) == HIGH)
      {
        smenu1++;  
        delay(200); 
      }
      if (digitalRead (start) == HIGH)
    {
      select2(smenu1);
      delay(200);
    }
    
      if (smenu1 > 2)
           { smenu1 = 0;}
    display.println(menus1[smenu1]);
    display.display();
    display.clearDisplay();
    
    
  }
  //Serial.println(“#S|CMD|[]# “)
}
