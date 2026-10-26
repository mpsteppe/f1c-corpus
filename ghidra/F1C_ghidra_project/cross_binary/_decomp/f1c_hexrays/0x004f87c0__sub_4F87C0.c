// f1c  0x004f87c0  size=137
float *__thiscall sub_4F87C0(float *this, int a2, int a3, float a4, float a5)
{
  int v5; // edx
  double v6; // st7
  float *result; // eax

  v5 = a3;
  if ( *(_DWORD *)(*(_DWORD *)this + 13000) )
  {
    v6 = flt_7CF35C;
  }
  else
  {
    v6 = flt_7CF338;
    v5 = a3 + 1;
  }
  result = &this[8 * a2];
  result[47] = v6 * a4;
  this[8 * a2 + 48] = a5;
  *((_BYTE *)result + 180) = 1;
  if ( v5 >= 0 )
  {
    if ( v5 <= 3 )
      *((_DWORD *)result + 46) = v5;
    else
      *((_DWORD *)result + 46) = 3;
    *((_BYTE *)result + 196) = 0;
  }
  else
  {
    result[46] = 0.0;
    *((_BYTE *)result + 196) = 0;
  }
  return result;
}
