
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
      void R180(int spd);
      void R360(int spd);
  private:
      int _mrf;
      int _mlf;
      int _mrb;
      int _mlb;
};
#endif
      
