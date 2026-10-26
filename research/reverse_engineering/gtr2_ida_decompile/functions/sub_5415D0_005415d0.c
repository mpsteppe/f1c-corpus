float *__thiscall sub_5415D0(float *this, float a2)
{
  double v2; // st7
  float *result; // eax

  *(_DWORD *)this = &off_71E634;
  this[1] = 0.0;
  if ( a2 <= 0.0 )
    this[5] = 1.0;
  else
    this[5] = a2;
  v2 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 1.5;
  result = this;
  this[6] = v2 + this[5];
  this[2] = 0.0;
  this[3] = 0.0;
  this[4] = 0.0;
  return result;
}
