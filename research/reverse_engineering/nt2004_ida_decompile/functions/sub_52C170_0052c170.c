void __thiscall sub_52C170(_DWORD *this, float a2, float a3, int a4)
{
  float *v4; // edx
  int v5; // eax
  float *v6; // eax
  double v7; // st7
  float *v8; // ecx
  bool v9; // c0
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  float *v14; // ecx
  double v15; // st7
  float v16; // [esp+0h] [ebp-4h]
  float v17; // [esp+Ch] [ebp+8h]

  while ( 1 )
  {
    v4 = *(float **)(this[13] + 12);
    if ( !v4 )
    {
      v5 = this[13];
      v16 = *(float *)(v5 + 4);
      v17 = *(float *)(v5 + 8);
      goto LABEL_6;
    }
    if ( a3 < (double)*v4 )
      break;
    this[13] = v4;
  }
  v6 = (float *)this[13];
  v7 = (a3 - *v6) / (*v4 - *v6);
  v16 = (v4[1] - v6[1]) * v7 + v6[1];
  v17 = (v4[2] - v6[2]) * v7 + v6[2];
LABEL_6:
  sub_52C0C0((int)this, v17);
  v9 = v8[9] < (double)v8[8];
  v8[11] = v16;
  if ( v9 )
  {
    v8[9] = v8[8];
  }
  else if ( v8[9] > 0.0 )
  {
    v10 = v8[12] >= 0.0 ? v8[12] : 0.0;
    v11 = v8[9] - ((double)a4 * 0.000011574074 + v10 * 0.0000011574074 + 0.000011574074) * a2;
    v8[9] = v11;
    if ( v11 < v8[8] )
      v8[9] = v8[8];
  }
  if ( v8[10] >= (double)v8[8] )
  {
    if ( v8[10] > 0.0 )
    {
      v12 = v8[12] >= 0.0 ? v8[12] : 0.0;
      v13 = v8[10] - (v12 * 0.0000011574074 + 0.000011574074) * a2;
      v8[10] = v13;
      if ( v13 < v8[8] )
        v8[10] = v8[8];
    }
  }
  else
  {
    v8[10] = v8[8];
  }
  sub_52B7E0(v8);
  v15 = (v14[10] + v14[9]) * 0.5 * -3.0 + 2.0 + (1.0 - v17) * 7.0 + (double)a4 * 0.1 + v14[11];
  if ( a2 < 499.99997 )
    v15 = (v15 - v14[12]) * a2 * 0.0020000001 + v14[12];
  v14[12] = v15;
}
