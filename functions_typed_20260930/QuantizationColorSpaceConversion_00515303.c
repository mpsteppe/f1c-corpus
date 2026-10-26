int __cdecl sub_515303(_DWORD *a1, float *a2)
{
  unsigned int v3; // edx
  double v4; // st7
  int *v5; // edx
  int v6; // eax
  double v7; // st7
  int v8; // edx
  double v9; // st7
  float v11[16]; // [esp+Ch] [ebp-50h] BYREF
  float v12; // [esp+4Ch] [ebp-10h]
  float v13; // [esp+50h] [ebp-Ch]
  float v14; // [esp+54h] [ebp-8h]
  float *v15; // [esp+58h] [ebp-4h]
  unsigned int v16; // [esp+64h] [ebp+8h]

  *a1 = 0;
  a1[1] = 0;
  memset(v11, 0, sizeof(v11));
  FPUControlWordMerger();
  v16 = v3;
  v15 = a2 + 3;
  do
  {
    v4 = v11[v16] + *v15;
    v14 = v4;
    v13 = v4 * 15.0 + 0.5;
    LODWORD(v12) = (int)v13;
    v5 = &a1[v16 >> 3];
    v6 = (LODWORD(v12) << 28) | ((unsigned int)*v5 >> 4);
    v13 = v12;
    v7 = (double)LODWORD(v12);
    *v5 = v6;
    v8 = v16 & 3;
    v9 = v14 - v7 * 0.06666667;
    if ( v8 != 3 )
      v11[v16 + 1] = 0.4375 * v9 + v11[v16 + 1];
    if ( v16 < 0xC )
    {
      if ( (v16 & 3) != 0 )
        v11[v16 + 3] = 0.1875 * v9 + v11[v16 + 3];
      v11[v16 + 4] = 0.3125 * v9 + v11[v16 + 4];
      if ( v8 != 3 )
        v11[v16 + 5] = v9 * 0.0625 + v11[v16 + 5];
    }
    ++v16;
    v15 += 4;
  }
  while ( v16 < 0x10 );
  return TextureFilterAndLayerCompositing(a2, (int)(a1 + 2), 0);
}

