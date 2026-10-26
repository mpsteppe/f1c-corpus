int __stdcall sub_67E443(_DWORD *a1, float *a2, int a3)
{
  unsigned int v4; // edx
  float v5; // esi
  double v6; // st7
  int v7; // esi
  double v8; // st7
  float v10[17]; // [esp+Ch] [ebp-50h] BYREF
  int v11; // [esp+50h] [ebp-Ch]
  float v12; // [esp+54h] [ebp-8h]
  float *v13; // [esp+58h] [ebp-4h]
  float v14; // [esp+64h] [ebp+8h]

  v4 = 0;
  *a1 = 0;
  a1[1] = 0;
  if ( a3 )
    memset(v10, 0, 0x40u);
  LODWORD(v10[16]) = a1;
  v13 = a2 + 3;
  do
  {
    v14 = *v13;
    if ( a3 )
      v14 = v14 + v10[v4];
    v12 = v14 * 15.0 + 0.5;
    v11 = (int)v12;
    v5 = *(float *)&v11;
    a1[v4 >> 3] = (v11 << 28) | (a1[v4 >> 3] >> 4);
    if ( a3 )
    {
      v12 = v5;
      v6 = (double)LODWORD(v5);
      v7 = v4 & 3;
      v8 = v14 - v6 * 0.06666667;
      if ( v7 != 3 )
        v10[v4 + 1] = 0.4375 * v8 + v10[v4 + 1];
      if ( v4 < 0xC )
      {
        if ( (v4 & 3) != 0 )
          v10[v4 + 3] = 0.1875 * v8 + v10[v4 + 3];
        v10[v4 + 4] = 0.3125 * v8 + v10[v4 + 4];
        if ( v7 != 3 )
          v10[v4 + 5] = v8 * 0.0625 + v10[v4 + 5];
      }
    }
    v13 += 4;
    ++v4;
  }
  while ( v4 < 0x10 );
  return sub_67D6C7(a2, (int)(a1 + 2), 0, a3);
}
