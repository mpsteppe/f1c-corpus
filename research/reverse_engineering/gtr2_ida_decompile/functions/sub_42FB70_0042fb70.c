int __thiscall sub_42FB70(float *this, float a2)
{
  int result; // eax
  long double v3; // st7
  long double v4; // st6

  result = 0;
  v3 = sin(a2);
  this[1] = 0.0;
  this[3] = 0.0;
  this[4] = 0.0;
  this[5] = 1.0;
  this[6] = 0.0;
  this[7] = 0.0;
  this[9] = 0.0;
  this[11] = 0.0;
  this[12] = 0.0;
  this[13] = 0.0;
  this[14] = 0.0;
  this[15] = 1.0;
  v4 = cos(a2);
  *this = v4;
  this[2] = -v3;
  this[8] = v3;
  this[10] = v4;
  return result;
}
