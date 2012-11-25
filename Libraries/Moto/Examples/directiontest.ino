//example for Moto Library written by Helreizer and open source
#include <Moto.h>
// moto(A-iA,B-iA,A-iB,B-iB)
Moto moto(12,11,10,9);

void setup()
{
  moto.forward(255);
  delay(500);
  moto.mStop();
  moto.reverse(255);
  delay(500);
  moto.mStop();
  moto.right(255);
  delay(500);
  moto.mStop();
}

void loop()
{
  moto.left(255);
}


