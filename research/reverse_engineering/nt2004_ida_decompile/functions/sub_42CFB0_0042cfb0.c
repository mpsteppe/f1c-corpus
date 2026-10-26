int __thiscall sub_42CFB0(int this)
{
  int v2; // edi
  bool v3; // bl
  int v4; // edi
  double v5; // st7
  int v6; // ebp
  int v7; // ecx
  int v8; // eax
  bool v9; // cc
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st6
  int result; // eax
  double v21; // st7
  _WORD *v22; // [esp+Ch] [ebp-1Ch]
  float v23; // [esp+Ch] [ebp-1Ch]
  int v24; // [esp+10h] [ebp-18h]
  float v25; // [esp+10h] [ebp-18h]
  float v26; // [esp+10h] [ebp-18h]
  float v27; // [esp+10h] [ebp-18h]
  int v28; // [esp+18h] [ebp-10h]
  signed int v29; // [esp+1Ch] [ebp-Ch]
  int v30; // [esp+20h] [ebp-8h]
  float v31; // [esp+24h] [ebp-4h]
  float v32; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD *)(this + 20884);
  v30 = v2;
  v29 = NumOfElements;
  v24 = 0;
  v31 = (double)(5 - v2 / 4) * 0.0049999999;
  if ( (int)NumOfElements > 0 )
  {
    v22 = (_WORD *)(this + 24300);
    do
    {
      v3 = 0;
      v28 = rand() % 1000;
      v4 = dword_75AAD0[v24];
      v5 = *(float *)(v4 + 23988) * 0.5;
      v6 = (__int64)((*(float *)(this + 23964) - v5) * 150.0);
      v7 = this + 21256;
      v8 = 5;
      do
      {
        if ( *(_DWORD *)v7 )
          v3 = v3 || *(_DWORD *)(v4 + 25248) == *(_DWORD *)(*(_DWORD *)v7 + 25248);
        v7 += 128;
        --v8;
      }
      while ( v8 );
      if ( v3 )
        v6 = (__int64)(((*(float *)(this + 24168) - *(float *)(v4 + 24168)) * 100.0 + 1.0)
                     * (double)(int)(__int64)((*(float *)(this + 23964) - v5) * 150.0));
      if ( v6 <= v28 )
      {
        if ( (int)(1000 - (__int64)((*(float *)(this + 23992) * 0.5 + v5) * 200.0)) >= v28 )
          *v22 = *(_WORD *)(v4 + 4 * *(_DWORD *)(this + 68) + 24302);
        else
          *v22 = 1;
      }
      else
      {
        *v22 = 0;
      }
      v9 = ++v24 < v29;
      v22 += 2;
    }
    while ( v9 );
    v2 = v30;
  }
  v10 = v31 + *(float *)(this + 24160);
  if ( *(float *)(this + 23976) < v10 )
    v10 = *(float *)(this + 23976);
  *(float *)(this + 24160) = v10;
  if ( *(float *)(this + 24168) <= (double)*(float *)(this + 23996) )
  {
    v11 = *(float *)(this + 24156) + 0.029999999;
    if ( *(float *)(this + 23980) < v11 )
      v11 = *(float *)(this + 23980);
  }
  else
  {
    v11 = *(float *)(this + 23980) * 0.5;
    v25 = *(float *)(this + 24156) - (*(float *)(this + 24168) - *(float *)(this + 23996));
    if ( v11 <= v25 )
      v11 = v25;
  }
  *(float *)(this + 24156) = v11;
  v26 = 0.003;
  v32 = (double)(rand() % 100 + 1) * 0.0099999998;
  if ( dword_7D7928 == 3 )
    v26 = 0.015;
  v23 = *(float *)(this + 23996)
      - (1.0
       - (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
       * 0.25)
      * flt_5FD1F8;
  if ( v2 <= 1 )
  {
    if ( *(float *)(this + 24164) > 0.0 && *(_DWORD *)(this + 24020) == 11 )
      *(_DWORD *)(this + 24164) = 0;
    v17 = *(float *)(this + 24164) - v26;
    if ( v17 < -0.045000002 )
      v17 = -0.045000002;
    *(float *)(this + 24164) = v17;
    if ( dword_7D7928 == 1 )
      *(float *)(this + 24284) = v17 + *(float *)(this + 23924);
    else
      v23 = v17 + v23;
    *(float *)(this + 24172) = v23;
    *(float *)(this + 24168) = v23;
  }
  else
  {
    if ( dword_7D7928 == 1 )
    {
      *(_BYTE *)(this + 24292) = 0;
      if ( !(rand() % 50) && (double)(int)NumOfElements * 0.69999999 > (double)*(int *)(this + 20884) )
        *(_BYTE *)(this + 24292) = 1;
    }
    v12 = v26 + *(float *)(this + 24164);
    if ( v12 > 0.039999999 )
      v12 = 0.039999999;
    *(float *)(this + 24164) = v12;
    if ( v32 < (double)*(float *)(this + 24160) )
    {
      if ( dword_7D7928 == 1 )
      {
        *(float *)(this + 24284) = v12 + *(float *)(this + 24284);
      }
      else
      {
        v13 = v12 + v23;
        v23 = v13 <= 1.0 ? v13 : 1.0;
      }
      if ( (double)(rand() % 100 + 1) * 0.0099999998 > *(float *)(this + 24156) )
      {
        v14 = *(float *)(this + 23976) * 0.5;
        v27 = *(float *)(this + 24160) - (1.0 - *(float *)(this + 23988)) * 0.2;
        if ( v14 <= v27 )
          v14 = v27;
        *(float *)(this + 24160) = v14;
      }
    }
    if ( *(float *)(this + 24284) >= (double)*(float *)(this + 23924) )
      v15 = *(float *)(this + 24284);
    else
      v15 = *(float *)(this + 23924);
    if ( v15 <= 1.0 )
    {
      if ( *(float *)(this + 24284) >= (double)*(float *)(this + 23924) )
        v16 = *(float *)(this + 24284);
      else
        v16 = *(float *)(this + 23924);
    }
    else
    {
      v16 = 1.0;
    }
    *(float *)(this + 24284) = v16;
    *(float *)(this + 24172) = v23;
    *(float *)(this + 24168) = v23;
  }
  v18 = *(float *)(this + 23924) - 0.050000001;
  if ( v18 <= *(float *)(this + 24284) )
    v19 = *(float *)(this + 24284);
  else
    v19 = v18;
  if ( *(float *)(this + 23924) >= v19 )
  {
    if ( v18 <= *(float *)(this + 24284) )
      v18 = *(float *)(this + 24284);
  }
  else
  {
    v18 = *(float *)(this + 23924);
  }
  *(float *)(this + 24284) = v18;
  result = dword_7D7928;
  if ( dword_7D7928 != 1 )
  {
    v21 = (1.0
         - (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
         * 0.25)
        * flt_5FD1F8;
    *(float *)(this + 24172) = v23 - (v21 + v21);
  }
  return result;
}
