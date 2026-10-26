void __thiscall sub_5936E0(_DWORD *this, float a2, float a3, int a4)
{
  int v4; // edx
  int v5; // eax
  float *v6; // eax
  double v7; // st7
  int v8; // ecx
  bool v9; // c0
  bool v10; // c3
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  float *v15; // ecx
  double v16; // st7
  float v17; // [esp+0h] [ebp-4h]
  float v18; // [esp+0h] [ebp-4h]
  float v19; // [esp+Ch] [ebp+8h]

  v4 = *(_DWORD *)(this[15] + 12);
  if ( v4 )
  {
    while ( a3 >= (double)*(float *)v4 )
    {
      this[15] = v4;
      v4 = *(_DWORD *)(v4 + 12);
      if ( !v4 )
        goto LABEL_4;
    }
    v6 = (float *)this[15];
    v7 = (a3 - *v6) / (*(float *)v4 - *v6);
    v17 = (*(float *)(v4 + 4) - v6[1]) * v7 + v6[1];
    v19 = (*(float *)(v4 + 8) - v6[2]) * v7 + v6[2];
  }
  else
  {
LABEL_4:
    v5 = this[15];
    v17 = *(float *)(v5 + 4);
    v19 = *(float *)(v5 + 8);
  }
  sub_592B20((int)this, v19);
  v9 = *(float *)(v8 + 56) > 0.0;
  v10 = 0.0 == *(float *)(v8 + 56);
  *(float *)(v8 + 52) = v17;
  if ( v9 || v10 )
    v11 = *(float *)(v8 + 56);
  else
    v11 = 0.0;
  v18 = v11 * 0.0000011574074 + 0.000011574074;
  if ( *(float *)(v8 + 44) >= (double)*(float *)(v8 + 40) )
  {
    if ( *(float *)(v8 + 44) > 0.0 )
    {
      v12 = (double)a4 * 0.000023148148;
      *(float *)(v8 + 496) = a2 * v12 + *(float *)(v8 + 496);
      if ( *(float *)(v8 + 496) >= 0.0 )
      {
        if ( *(float *)(v8 + 496) > 1.0 )
          *(_DWORD *)(v8 + 496) = 1065353216;
      }
      else
      {
        *(_DWORD *)(v8 + 496) = 0;
      }
      v13 = *(float *)(v8 + 44) - (v12 + v18) * a2;
      *(float *)(v8 + 44) = v13;
      if ( v13 < *(float *)(v8 + 40) )
        *(_DWORD *)(v8 + 44) = *(_DWORD *)(v8 + 40);
    }
  }
  else
  {
    *(_DWORD *)(v8 + 44) = *(_DWORD *)(v8 + 40);
  }
  if ( *(float *)(v8 + 48) >= (double)*(float *)(v8 + 40) )
  {
    if ( *(float *)(v8 + 48) > 0.0 )
    {
      v14 = *(float *)(v8 + 48) - v18 * a2;
      *(float *)(v8 + 48) = v14;
      if ( v14 < *(float *)(v8 + 40) )
        *(_DWORD *)(v8 + 48) = *(_DWORD *)(v8 + 40);
    }
  }
  else
  {
    *(_DWORD *)(v8 + 48) = *(_DWORD *)(v8 + 40);
  }
  sub_592990((float *)v8);
  v16 = (v15[12] + v15[11]) * 0.5 * -3.0 + 2.0 + (1.0 - v19) * 7.0 + (double)a4 * 0.1 + v15[13];
  if ( a2 < 499.99997 )
    v16 = (v16 - v15[14]) * a2 * 0.0020000001 + v15[14];
  v15[14] = v16;
}
