void __thiscall sub_4FD8B0(_DWORD *this, float a2, float a3)
{
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  int v18; // ecx
  double v19; // st7
  float *v20; // ecx
  int v21; // ecx
  double v22; // st6
  double v23; // st7
  double v24; // st6
  _DWORD *v25; // eax
  _DWORD *v26; // eax
  float v27; // [esp+4h] [ebp-28h]
  float v28; // [esp+8h] [ebp-24h]
  float v29; // [esp+Ch] [ebp-20h]
  float v30; // [esp+10h] [ebp-1Ch]
  float v31; // [esp+14h] [ebp-18h]
  float v32; // [esp+18h] [ebp-14h]
  float v33; // [esp+1Ch] [ebp-10h]
  float v34; // [esp+20h] [ebp-Ch]
  float v35; // [esp+24h] [ebp-8h]
  float v36; // [esp+28h] [ebp-4h]
  float v37; // [esp+28h] [ebp-4h]

  DualLinkedListDestruction((int)this);
  v4 = RandomNoiseValueGenerator(&dword_8AAE70) * 360.0;
  v29 = v4;
  if ( v4 >= -900.0 )
  {
    if ( v29 > 900.0 )
      v29 = 900.0;
  }
  else
  {
    v29 = -900.0;
  }
  v5 = v29 * 0.25;
  v32 = v5;
  if ( v5 >= -900.0 )
  {
    if ( v32 > 900.0 )
      v32 = 900.0;
  }
  else
  {
    v32 = -900.0;
  }
  v6 = RandomNoiseValueGenerator(&dword_8AAE70) * 0.40000001;
  v27 = v6;
  if ( v6 >= -1.0 )
  {
    if ( v27 > 1.0 )
      v27 = 1.0;
  }
  else
  {
    v27 = -1.0;
  }
  v7 = v27 * 0.0056250002;
  v31 = v7;
  if ( v7 >= -0.1 )
  {
    if ( v31 > 0.1 )
      v31 = 0.1;
  }
  else
  {
    v31 = -0.1;
  }
  v8 = RandomNoiseValueGenerator(&dword_8AAE70) * 5.0;
  v28 = v8;
  if ( v8 >= -12.5 )
  {
    if ( v28 > 12.5 )
      v28 = 12.5;
  }
  else
  {
    v28 = -12.5;
  }
  v9 = v28 * 0.0025000002;
  v30 = v9;
  if ( v9 >= -2.0 )
  {
    if ( v30 > 2.0 )
      v30 = 2.0;
  }
  else
  {
    v30 = -2.0;
  }
  v10 = v27 + 0.30000001;
  v33 = v10;
  if ( v10 >= 0.0 )
  {
    if ( v33 > 1.0 )
      v33 = 1.0;
  }
  else
  {
    v33 = 0.0;
  }
  v11 = (_DWORD *)OperatorNewNhMallocWrapper(16);
  if ( v11 )
    v12 = FloatArrayInitializer(v11);
  else
    v12 = 0;
  this[15] = v12;
  *v12 = 0;
  for ( this[14] = this[15]; ; this[14] = *(_DWORD *)(this[14] + 12) )
  {
    v13 = a2 + *(float *)this[14];
    InterruptDispatch(v13);
    v35 = v13;
    v36 = sin(v13 * 0.0000363610260832152) * 10.0 + 15.0 - (v33 - 0.5) * 5.0;
    v14 = RandomNoiseValueGenerator(&dword_8AAE70) * 0.19 + v30 - v28 * 0.0025000002;
    v30 = v14 - 0.1 * v14;
    if ( v30 >= -2.0 )
    {
      if ( v30 > 2.0 )
        v30 = 2.0;
    }
    else
    {
      v30 = -2.0;
    }
    v15 = v30 + v28;
    v28 = v15;
    if ( v15 >= -12.5 )
    {
      if ( v28 > 12.5 )
        v28 = 12.5;
    }
    else
    {
      v28 = -12.5;
    }
    v16 = RandomNoiseValueGenerator(&dword_8AAE70) * 0.013 + v31 - v27 * 0.0056250002;
    v31 = v16 - 0.15000001 * v16;
    if ( v31 >= -0.1 )
    {
      if ( v31 > 0.1 )
        v31 = 0.1;
    }
    else
    {
      v31 = -0.1;
    }
    v17 = v31 + v27;
    v27 = v17;
    if ( v17 >= -1.0 )
    {
      if ( v27 > 1.0 )
        v27 = 1.0;
    }
    else
    {
      v27 = -1.0;
    }
    *(float *)(this[14] + 4) = v36 + v28;
    *(float *)(this[14] + 8) = v27 + 0.30000001;
    v18 = this[14];
    v19 = *(float *)(v18 + 8);
    v20 = (float *)(v18 + 8);
    if ( v19 >= 0.0 )
    {
      if ( *v20 > 1.0 )
        *v20 = 1.0;
    }
    else
    {
      *v20 = 0.0;
    }
    v21 = this[14];
    v33 = *(float *)(v21 + 8);
    if ( v33 > 0.60000002 && *(float *)(v21 + 8) < 0.64999998 )
    {
      if ( *(float *)(v21 + 8) >= 0.625 )
        *(_DWORD *)(v21 + 8) = 1059481190;
      else
        *(_DWORD *)(v21 + 8) = 1058642330;
    }
    if ( *(float *)this[14] > (double)a3 )
      break;
    v22 = RandomNoiseValueGenerator(&dword_8AAE70) * 500.0 + v32 - v29 * 0.25;
    v32 = v22 - v22;
    if ( v32 >= -900.0 )
    {
      if ( v32 > 900.0 )
        v32 = 900.0;
    }
    else
    {
      v32 = -900.0;
    }
    v23 = 1200.0;
    v34 = 900.0;
    if ( v35 > 28800.0 && v35 < 57600.0 )
    {
      v34 = 280.0;
      v23 = 400.0;
    }
    v29 = v32 + v29;
    v24 = -v34;
    if ( v29 >= v24 )
    {
      if ( v29 > (double)v34 )
        v29 = v34;
    }
    else
    {
      v29 = v24;
    }
    v25 = (_DWORD *)OperatorNewNhMallocWrapper(16);
    if ( v25 )
      v26 = FloatArrayInitializer(v25);
    else
      v26 = 0;
    *(_DWORD *)(this[14] + 12) = v26;
    v37 = v23 + v29;
    **(float **)(this[14] + 12) = v37 + *(float *)this[14];
  }
}

