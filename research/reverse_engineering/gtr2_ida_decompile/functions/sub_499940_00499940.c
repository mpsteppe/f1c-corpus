int __fastcall sub_499940(int a1, int a2, float a3)
{
  double v3; // st7
  int v5; // [esp+0h] [ebp-4h]

  v3 = a3;
  v5 = a1;
  if ( a3 >= 0.0 )
  {
    if ( v3 > 1.0 )
      v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  LOBYTE(a1) = 0;
  BYTE1(a1) = (unsigned __int64)((double)HIBYTE(a1) * (1.0 - v3) + (double)HIBYTE(a2) * v3);
  a1 = (unsigned __int16)a1;
  LOBYTE(a1) = (unsigned __int64)((double)BYTE2(v5) * (1.0 - v3) + (double)BYTE2(a2) * v3);
  return (unsigned __int8)(unsigned __int64)((double)(unsigned __int8)v5 * (1.0 - v3) + (double)(unsigned __int8)a2 * v3)
       | (((unsigned __int8)(unsigned __int64)((double)BYTE1(v5) * (1.0 - v3) + (double)BYTE1(a2) * v3) | (a1 << 8)) << 8);
}
