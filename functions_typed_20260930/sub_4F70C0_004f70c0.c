int __thiscall sub_4F70C0(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx
  _DWORD *v4; // esi
  int v5; // ebx
  int i; // eax
  const char *v7; // ecx
  const char *v8; // eax
  int j; // esi
  char *v10; // eax
  int v11; // edx
  char v12; // cl
  char *v13; // eax
  int v14; // eax
  char v15; // cl
  int v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v19; // ebx
  int k; // ebp
  int v21; // esi
  float *v22; // ecx
  double v23; // st7
  double v25; // st6
  unsigned __int8 v26; // c0
  unsigned __int8 v27; // c3
  float *v28; // esi
  double v29; // st7
  double v31; // st6
  unsigned __int8 v32; // c0
  unsigned __int8 v33; // c3
  int v34; // ebx
  _BYTE *v35; // esi
  int v36; // edi
  void *v37; // eax
  _BYTE *v38; // esi
  int v39; // edi
  void *v40; // eax
  float v42; // [esp+10h] [ebp-928h] BYREF
  int v43; // [esp+14h] [ebp-924h] BYREF
  float v44; // [esp+18h] [ebp-920h] BYREF
  int v45; // [esp+1Ch] [ebp-91Ch] BYREF
  float v46; // [esp+20h] [ebp-918h] BYREF
  float v47; // [esp+24h] [ebp-914h]
  int v48; // [esp+28h] [ebp-910h]
  float v49; // [esp+2Ch] [ebp-90Ch]
  _BYTE v50[900]; // [esp+30h] [ebp-908h] BYREF
  _BYTE v51[900]; // [esp+3B4h] [ebp-584h] BYREF
  _BYTE v52[512]; // [esp+738h] [ebp-200h] BYREF

  v48 = 0;
  v2 = v50;
  v3 = 45;
  do
  {
    *v2 = 0;
    v2[1] = -1;
    TireSlotStructInit(v2);
    v2 += 5;
    --v3;
  }
  while ( v3 );
  v4 = v51;
  v5 = 45;
  do
  {
    *v4 = 0;
    v4[1] = -1;
    TireSlotStructInit(v4);
    v4 += 5;
    --v5;
  }
  while ( v5 );
  if ( this[421] || this[438] )
  {
    v34 = 1;
  }
  else
  {
    this[421] = OperatorNewNhMallocWrapper(180);
    this[438] = OperatorNewNhMallocWrapper(180);
    for ( i = 0; i < 180; i += 4 )
    {
      *(_DWORD *)(i + this[421]) = 0;
      *(_DWORD *)(i + this[438]) = 0;
    }
    if ( !byte_8AFC74 )
    {
      v7 = (const char *)dword_5EC428;
      if ( !dword_5EC428 )
        v7 = byte_5EA438;
      v8 = (const char *)dword_5EC3D8;
      if ( !dword_5EC3D8 )
        v8 = byte_5EA438;
      StringFormatWithBufferOverflowCheck(v52, "%s%s%s", v8, v7, aF1soundsSfx);
      if ( !sub_4F7460(v52, dword_8AF8F0, dword_8AF568) )
        byte_8AFC74 = 1;
    }
    for ( j = 0; j < 225; j += 5 )
    {
      v10 = (char *)dword_8AF8F0[j];
      if ( !v10 )
        v10 = byte_5EA438;
      StringCopyWithBufferRealloc(v10);
      v11 = dword_8AF8F8[j];
      v12 = byte_8AF900[j * 4];
      *(_DWORD *)&v50[j * 4 + 12] = dword_8AF8FC[j];
      v13 = (char *)dword_8AF568[j];
      *(_DWORD *)&v50[j * 4 + 8] = v11;
      v50[j * 4 + 16] = v12;
      if ( !v13 )
        v13 = byte_5EA438;
      StringCopyWithBufferRealloc(v13);
      v14 = dword_8AF574[j];
      v15 = byte_8AF578[j * 4];
      *(_DWORD *)&v51[j * 4 + 8] = dword_8AF570[j];
      *(_DWORD *)&v51[j * 4 + 12] = v14;
      v51[j * 4 + 16] = v15;
    }
    v16 = ConditionalDispatch_40b0(*this + 18196);
    if ( v16 )
    {
      v17 = *(char **)(v16 + 24);
      if ( !v17 )
        v17 = byte_5EA438;
      sub_4F7460(v17, v50, v51);
    }
    if ( dword_8AC4C4 )
    {
      v18 = (char *)dword_5EC3E8;
      if ( !dword_5EC3E8 )
        v18 = byte_5EA438;
      (*(void (__stdcall **)(char *))(*(_DWORD *)dword_8AC4C4 + 68))(v18);
    }
    v19 = 0;
    for ( k = 0; k < 900; k += 20 )
    {
      SwitchBasedParamSetting(v19, &v43, &v45);
      ColorPaletteLookupByIndex(v19, &v42, &v46, &v44);
      v21 = 4 * v19;
      StringMatchWithWildcard(4 * v19 + this[421], &v50[k], v43, v45);
      v22 = *(float **)(4 * v19 + this[421]);
      if ( v22 )
      {
        v23 = v46;
        v47 = v44;
        v25 = 1.0;
        if ( !(v26 | v27) )
          v25 = 1.0 / v42;
        v22[7] = v25;
        v22[8] = 1.0 - v25 * v47;
        v22[9] = v23;
      }
      StringMatchWithWildcard(v21 + this[438], &v51[k], v43, v45);
      v28 = *(float **)(v21 + this[438]);
      if ( v28 )
      {
        v29 = v46;
        v49 = v44;
        v31 = 1.0;
        if ( !(v32 | v33) )
          v31 = 1.0 / v42;
        v28[7] = v31;
        v28[8] = 1.0 - v31 * v49;
        v28[9] = v29;
      }
      ++v19;
    }
    v34 = v48;
  }
  v35 = v52;
  v36 = 45;
  do
  {
    v37 = (void *)*((_DWORD *)v35 - 5);
    v35 -= 20;
    if ( v37 )
      FreeWrapper_7bcf(v37);
    --v36;
  }
  while ( v36 );
  v38 = v51;
  v39 = 45;
  do
  {
    v40 = (void *)*((_DWORD *)v38 - 5);
    v38 -= 20;
    if ( v40 )
      FreeWrapper_7bcf(v40);
    --v39;
  }
  while ( v39 );
  return v34;
}

