
#ifndef Moto_h
#define Moto_h

#include "Arduino.h"

class Moto
{
  public:
     
      Moto(int rf, int lf, int rb, int lb);
      void forward(int spd);
      void reverse(int spd);
      void left(int spd);
      void right(int spd);
      void mStop();
      
  private:
      int _mrf;
      int _mlf;
      int _mrb;
      int _mlb;
};
#endif
      
