char __stdcall sub_52E740(float *a1, float a2)
{
  double v2; // st7
  double v4[3]; // [esp+4h] [ebp-34h] BYREF
  int v5; // [esp+1Ch] [ebp-1Ch]
  int v6; // [esp+20h] [ebp-18h]
  int v7; // [esp+24h] [ebp-14h]
  int v8; // [esp+28h] [ebp-10h]
  double v9; // [esp+2Ch] [ebp-Ch]
  int v10; // [esp+34h] [ebp-4h]

  v4[0] = a1[9];
  v4[1] = a1[10];
  v4[2] = a1[11];
  v5 = 0;
  v6 = 1074790400;
  v7 = 0x40000000;
  v8 = 1201543096;
  v10 = 0;
  if ( !sub_44E900(dbl_760B48, (int)v4) )
    return 0;
  v2 = v9 + a2;
  if ( v2 <= a1[10] )
    return 0;
  a1[10] = v2;
  return 1;
}
