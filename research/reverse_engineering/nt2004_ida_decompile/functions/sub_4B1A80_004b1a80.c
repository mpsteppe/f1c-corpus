int __stdcall sub_4B1A80(int a1, int a2, float a3)
{
  long double v3; // st7
  long double v4; // st7
  int v5; // ecx
  float v7; // [esp+10h] [ebp+Ch]

  v3 = fmod(dbl_7DA9D0 + a3, 1.0);
  if ( v3 >= 0.5 )
    v4 = 1.0 - (v3 - 0.5 + v3 - 0.5);
  else
    v4 = v3 + v3;
  v7 = v4;
  if ( v7 >= 0.0 )
  {
    if ( v7 > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  LOBYTE(v5) = 0;
  BYTE1(v5) = (__int64)((double)HIBYTE(a1) * (1.0 - v4) + (double)HIBYTE(a2) * v4);
  v5 = (unsigned __int16)v5;
  LOBYTE(v5) = (__int64)((double)BYTE2(a1) * (1.0 - v4) + (double)BYTE2(a2) * v4);
  return (unsigned __int8)(__int64)((double)(unsigned __int8)a1 * (1.0 - v4) + (double)(unsigned __int8)a2 * v4)
       | (((unsigned __int8)(__int64)((double)BYTE1(a1) * (1.0 - v4) + (double)BYTE1(a2) * v4) | (v5 << 8)) << 8);
}
