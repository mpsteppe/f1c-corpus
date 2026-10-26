// f1c  0x004c8f10  size=98
float *__thiscall sub_4C8F10(float *this, float a2)
{
  double v2; // st7
  float *result; // eax

  *(_DWORD *)this = &off_5ACE2C;
  this[1] = 0.0;
  if ( a2 <= 0.0 )
    this[5] = 1.0;
  else
    this[5] = a2;
  v2 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 1.5;
  result = this;
  this[6] = v2 + this[5];
  this[2] = 0.0;
  this[3] = 0.0;
  this[4] = 0.0;
  return result;
}
