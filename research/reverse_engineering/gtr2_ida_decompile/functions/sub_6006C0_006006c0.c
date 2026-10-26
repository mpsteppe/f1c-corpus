float *__thiscall sub_6006C0(float *this, int a2, float *a3, float *a4, float *a5)
{
  float *result; // eax

  if ( a2 == 1 )
  {
    if ( a3 )
      *a3 = this[9] * this[6];
    if ( a4 )
      *a4 = this[9] * this[7];
    result = a5;
    if ( a5 )
      *a5 = this[9] * this[8];
  }
  else if ( a2 == 2 )
  {
    if ( a3 )
      *a3 = this[13] * this[10];
    if ( a4 )
      *a4 = this[13] * this[11];
    result = a5;
    if ( a5 )
      *a5 = this[13] * this[12];
  }
  else
  {
    result = (float *)(a2 - 3);
    if ( a2 == 3 )
    {
      if ( a3 )
        *a3 = this[17] * this[14];
      if ( a4 )
        *a4 = this[17] * this[15];
      result = a5;
      if ( a5 )
        *a5 = this[17] * this[16];
    }
  }
  return result;
}
