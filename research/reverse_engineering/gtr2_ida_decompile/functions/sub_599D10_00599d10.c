int __cdecl sub_599D10(float a1, int a2, int a3, float a4)
{
  float v4; // ecx
  double v5; // st7
  long double v6; // st7
  long double v7; // st6
  long double v8; // st7
  int v9; // eax
  double v10; // st7
  int v12; // [esp+10h] [ebp-B0h]
  float v13; // [esp+24h] [ebp-9Ch]
  float v14; // [esp+44h] [ebp-7Ch]
  float v15[3]; // [esp+54h] [ebp-6Ch] BYREF
  float v16; // [esp+60h] [ebp-60h]
  float v17[8]; // [esp+70h] [ebp-50h] BYREF
  float v18; // [esp+90h] [ebp-30h] BYREF
  float v19; // [esp+94h] [ebp-2Ch]
  float v20; // [esp+98h] [ebp-28h]

  v5 = a1 - *(float *)(a2 + 4);
  v17[7] = v4;
  v13 = v5;
  v6 = flt_B7378C;
  if ( v13 >= -1.25 )
  {
    if ( v13 > 1.25 )
      v13 = 1.25;
  }
  else
  {
    v13 = -1.25;
  }
  v7 = fabs(v13);
  if ( v7 >= 0.25 )
  {
    v14 = -0.125;
    if ( v13 >= 0.0 )
      v14 = 0.125;
  }
  else
  {
    v14 = (2.0 - v7 * 4.0) * v13 * 0.5;
  }
  if ( v7 >= v6 )
  {
    if ( v13 >= 0.0 )
      v8 = v6 * 0.5;
    else
      v8 = v6 * -0.5;
    v16 = v8;
  }
  else
  {
    v16 = (2.0 - v7 / v6) * v13 * 0.5;
  }
  *(_DWORD *)a3 = *(_DWORD *)a2;
  *(_DWORD *)(a3 + 844) = *(_DWORD *)(a2 + 844);
  *(float *)(a3 + 4) = a1;
  sub_519E70((_DWORD *)(a2 + 24), v15);
  sub_519FA0(a2 + 8, (int)&v18);
  v9 = (unsigned __int8)*(_DWORD *)a2;
  v19 = a4 * -9.8100004;
  v10 = v14 * 0.5;
  v12 = dword_9248F4[5654 * v9];
  v17[0] = (v18 * v10 + v15[0]) * v13 + *(float *)(a2 + 36);
  v17[1] = (v19 * v10 + v15[1]) * v13 + *(float *)(a2 + 40);
  v17[2] = (v20 * v10 + v15[2]) * v13 + *(float *)(a2 + 44);
  sub_402D40(&flt_91BCA0, v17, v12);
  return off_16C9534();
}
