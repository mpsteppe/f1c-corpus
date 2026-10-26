float *__thiscall sub_526050(_BYTE *this, int a2, int a3, float a4, int a5)
{
  int v5; // edx
  double v6; // st7
  float *result; // eax

  this[a2 + 177] = 1;
  v5 = a3;
  if ( *(_DWORD *)(*(_DWORD *)this + 16584) )
  {
    v6 = flt_767874 * a4;
  }
  else
  {
    v6 = a4;
    v5 = a3 + 1;
  }
  result = (float *)&this[32 * a2];
  result[58] = v6;
  this[32 * a2 + 224] = 1;
  *((_DWORD *)result + 59) = a5;
  if ( v5 >= 0 )
  {
    if ( v5 <= 3 )
      *((_DWORD *)result + 57) = v5;
    else
      *((_DWORD *)result + 57) = 3;
    *((_BYTE *)result + 240) = 0;
  }
  else
  {
    result[57] = 0.0;
    *((_BYTE *)result + 240) = 0;
  }
  return result;
}
