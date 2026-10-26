char __stdcall sub_599C10(float *a1, float a2)
{
  double v2; // st7
  double v4[6]; // [esp+4h] [ebp-38h] BYREF
  int v5; // [esp+34h] [ebp-8h]

  v4[0] = a1[9];
  v4[1] = a1[10];
  v5 = 0;
  v4[2] = a1[11];
  v4[3] = 4.0;
  v4[4] = 9.999999933815813e36;
  if ( !sub_45D190(dbl_B68610, (int)v4) )
    return 0;
  v2 = v4[5] + a2;
  if ( v2 <= a1[10] )
    return 0;
  a1[10] = v2;
  return 1;
}
