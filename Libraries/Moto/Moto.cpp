#include "Arduino.h"
#include "Moto.h"



Moto::Moto(int rf, int lf, int rb, int lb)
{
  pinMode(rf,OUTPUT);
  pinMode(lf,OUTPUT);
  pinMode(rb,OUTPUT);
  pinMode(lb,OUTPUT);
      _mrf= rf;
      _mlf= lf;
      _mrb= rb;
      _mlb= lb;
}

void Moto::forward(int spd)
{
  digitalWrite(_mrf,spd);
  digitalWrite(_mlf,spd);
  digitalWrite(_mrb,0);
  digitalWrite(_mlb,0);
}

void Moto::reverse(int spd)
{
  digitalWrite(_mrf,0);
  digitalWrite(_mlf,0);
  digitalWrite(_mrb,spd);
  digitalWrite(_mlb,spd);
}

void Moto::left(int spd)
{
  digitalWrite(_mrf,0);
  digitalWrite(_mlf,spd);
  digitalWrite(_mrb,spd);
  digitalWrite(_mlb,0);
}
void Moto::right(int spd)
{
  digitalWrite(_mrf,spd);
  digitalWrite(_mlf,0);
  digitalWrite(_mrb,0);
  digitalWrite(_mlb,spd);
}

void Moto::mStop()
{
  digitalWrite(_mrf,0);
  digitalWrite(_mlf,0);
  digitalWrite(_mrb,0);
  digitalWrite(_mlb,0);
}
