void __thiscall sub_551210(_DWORD *this, int a2, float a3)
{
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // ebp
  int v8; // eax
  float *v9; // edi
  float *v10; // esi
  double v11; // st7
  float v12; // [esp+0h] [ebp-1Ch]
  int v13; // [esp+4h] [ebp-18h]
  int i; // [esp+8h] [ebp-14h]
  float v15[4]; // [esp+Ch] [ebp-10h] BYREF

  v4 = this[7];
  if ( a3 > (double)*(float *)(v4 + 8) )
    a3 = *(float *)(v4 + 8);
  v5 = sub_587BDC(a3 / *(float *)(v4 + 8) * (double)*(int *)(v4 + 20));
  this[2] = v5;
  v6 = *(_DWORD *)(v4 + 20);
  if ( v5 >= v6 - 1 )
  {
    if ( v5 == v6 )
      this[2] = --v5;
  }
  else
  {
    ++v5;
  }
  v7 = this[6];
  v13 = v5;
  for ( i = 0; i < this[5]; ++i )
  {
    if ( (unsigned __int8)*(_DWORD *)v7 != 255 )
    {
      v8 = *(_DWORD *)(44 * (unsigned __int8)*(_DWORD *)v7 + *(_DWORD *)(this[7] + 16) + 40);
      v9 = (float *)(v8 + 32 * v13);
      v10 = (float *)(v8 + 32 * this[2]);
      v11 = *v9 - *v10;
      if ( v11 == 0.0 )
        v12 = 0.0;
      else
        v12 = (a3 - *v10) / v11;
      sub_53B490(v15);
      sub_53B5B0(v15, v10 + 4, v9 + 4, v12);
      sub_53B4C0(v15, (float *)(v7 + 4));
      *(float *)(v7 + 52) = (v9[1] - v10[1]) * v12 + v10[1];
      *(float *)(v7 + 56) = (v9[2] - v10[2]) * v12 + v10[2];
      *(float *)(v7 + 60) = (v9[3] - v10[3]) * v12 + v10[3];
      nullsub_7();
    }
    v7 += 136;
  }
  this[1] |= 0x10000u;
  if ( a2 )
    sub_54B330(*(_DWORD **)(a2 + 312), 64, 32, 0);
}
