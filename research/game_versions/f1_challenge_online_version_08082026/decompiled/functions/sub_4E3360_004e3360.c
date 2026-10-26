LPVOID __thiscall sub_4E3360(_DWORD *this)
{
  char *v2; // eax
  int v3; // esi
  char *v4; // ebx
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // ecx
  char *v13; // esi
  int v14; // ebx
  _DWORD *v15; // ecx
  LPVOID result; // eax
  float v17; // [esp+10h] [ebp-3AE4h] BYREF
  float v18; // [esp+14h] [ebp-3AE0h] BYREF
  int v19; // [esp+18h] [ebp-3ADCh]
  int v20; // [esp+1Ch] [ebp-3AD8h]
  int v21; // [esp+20h] [ebp-3AD4h]
  _DWORD *v22; // [esp+24h] [ebp-3AD0h]
  int v23; // [esp+28h] [ebp-3ACCh] BYREF
  int v24; // [esp+2Ch] [ebp-3AC8h] BYREF
  int v25; // [esp+30h] [ebp-3AC4h] BYREF
  float v26; // [esp+34h] [ebp-3AC0h] BYREF
  int v27; // [esp+38h] [ebp-3ABCh]
  _BYTE v28[28]; // [esp+3Ch] [ebp-3AB8h] BYREF
  _BYTE v29[384]; // [esp+58h] [ebp-3A9Ch] BYREF
  int v30; // [esp+1D8h] [ebp-391Ch]
  char v31; // [esp+1DCh] [ebp-3918h]
  int v32; // [esp+1E4h] [ebp-3910h]
  int v33; // [esp+1E8h] [ebp-390Ch]
  int v34; // [esp+1ECh] [ebp-3908h]
  _BYTE v35[384]; // [esp+1F0h] [ebp-3904h] BYREF
  LPVOID v36[3]; // [esp+370h] [ebp-3784h] BYREF
  LPVOID v37; // [esp+37Ch] [ebp-3778h]
  LPVOID v38; // [esp+384h] [ebp-3770h]
  LPVOID v39; // [esp+38Ch] [ebp-3768h]
  char *v40; // [esp+394h] [ebp-3760h]
  LPVOID v41; // [esp+39Ch] [ebp-3758h]
  char v42[104]; // [esp+1DD8h] [ebp-1D1Ch] BYREF
  LPVOID v43; // [esp+1E40h] [ebp-1CB4h]
  int v44[235]; // [esp+3748h] [ebp-3ACh] BYREF

  sub_42E320(v42);
  sub_4F34E0(v36);
  v2 = *(char **)(1060 * *(_DWORD *)(*this + 18584) + dword_8AC394 + 8);
  v3 = 0;
  if ( !v2 )
    v2 = byte_5EA438;
  sub_4F4270(v2, v42, 2);
  v4 = v40;
  if ( !v40 )
    v4 = byte_5EA438;
  sub_4DD450(&v18);
  v27 = 0;
  sub_5668B0(v28);
  memset(v35, 0, sizeof(v35));
  v30 = 0;
  v34 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 1;
  if ( (unsigned __int8)sub_566B20(v4, 0) )
  {
    while ( sub_566CC0(v35, 384) )
    {
      if ( !sub_5651B0(v29) )
      {
        if ( sub_565870(aRestrictionsph, &v23, &v24, &v25, &v17, 0, 0, 0, 0) )
          ++v27;
        if ( sub_565870(aForcefieldsphe, &v23, &v24, &v25, &v17, 0, 0, 0, 0) )
          ++v3;
      }
    }
    v5 = (_DWORD *)sub_587C03(24 * v3 + 4);
    if ( v5 )
    {
      *v5 = v3;
      v6 = v5 + 1;
      if ( v3 - 1 >= 0 )
      {
        v7 = v5 + 6;
        v8 = v3;
        do
        {
          *(v7 - 1) = 0;
          *v7 = 0;
          v7 += 6;
          --v8;
        }
        while ( v8 );
      }
      v22 = v6;
    }
    else
    {
      v22 = 0;
    }
    v20 = sub_587C03(20 * v27);
    sub_566D30(v28);
    v26 = 1.0;
    while ( sub_566CC0(v35, 384) )
    {
      if ( !sub_5651B0(v29) )
      {
        if ( sub_565870(aDefaultlimit, &v18, 0, 0, 0, 0, 0, 0, 0) )
          v18 = v18 * v18;
        sub_565870(aRestrictionlim, &v26, 0, 0, 0, 0, 0, 0, 0);
        if ( sub_565870(aRestrictionsph, &v23, &v24, &v25, &v17, 0, 0, 0, 0) )
        {
          v9 = (_DWORD *)(v20 + 20 * v19);
          *v9 = v23;
          v9[1] = v24;
          v9[2] = v25;
          *(float *)(v20 + 20 * v19 + 12) = v17 * v17;
          *(float *)(v20 + 20 * v19++ + 16) = v26 * v26;
        }
        if ( sub_565870(aForcefieldsphe, &v23, &v24, &v25, &v17, 0, 0, 0, 0) )
        {
          v10 = &v22[6 * v21];
          *v10 = v23;
          v10[1] = v24;
          v10[2] = v25;
          *(float *)&v22[6 * v21 + 3] = v17 * v17;
          v22[6 * v21 + 4] = 0;
          v22[6 * v21++ + 5] = 0;
        }
      }
    }
    sub_566B90(v28);
  }
  this[746] = 1;
  sub_4DE610(this + 747, &v18, this + 1);
  if ( this[377] && *((_BYTE *)this + 1572) && *((_BYTE *)this + 1573) )
  {
    v11 = 187 * this[746]++;
    sub_4DE610(&this[v11 + 747], &v18, this + 377);
  }
  if ( this[394] && *((_BYTE *)this + 1640) && *((_BYTE *)this + 1641) )
  {
    v12 = 187 * this[746]++;
    sub_4DE610(&this[v12 + 747], &v18, this + 394);
  }
  v13 = (char *)(this + 411);
  v14 = 8;
  do
  {
    if ( *(_DWORD *)v13 && v13[64] && v13[65] )
    {
      v15 = &this[187 * this[746]++ + 747];
      sub_4DE610(v15, &v18, v13);
    }
    v13 += 68;
    --v14;
  }
  while ( v14 );
  sub_5668D0(v28);
  sub_4DD470((int)&v18);
  if ( v41 )
    sub_587BCF(v41);
  if ( v40 )
    sub_587BCF(v40);
  if ( v39 )
    sub_587BCF(v39);
  if ( v38 )
    sub_587BCF(v38);
  if ( v37 )
    sub_587BCF(v37);
  if ( v36[0] )
    sub_587BCF(v36[0]);
  sub_42DDD0(v44);
  result = v43;
  if ( v43 )
    return (LPVOID)sub_587BCF(v43);
  return result;
}
