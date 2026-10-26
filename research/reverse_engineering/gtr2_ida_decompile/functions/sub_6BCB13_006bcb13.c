int __thiscall sub_6BCB13(_DWORD *this)
{
  _DWORD *v2; // ecx
  unsigned int v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // edx
  int v8; // esi
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  bool v14; // cf
  int v15; // eax
  int v16; // ecx
  int v17; // edi
  int v18; // esi
  int result; // eax
  int v20; // edi
  int v21; // eax
  int v22; // eax
  double *v23; // ecx
  int v24; // eax
  void **v25; // ecx
  _DWORD *v26; // eax
  char *v27; // edi
  int v28; // esi
  void *v29; // ecx
  int v30; // eax
  unsigned int v31; // ecx
  void **v32; // eax
  int v33; // [esp+4h] [ebp-58h]
  _DWORD v34[4]; // [esp+14h] [ebp-48h] BYREF
  _DWORD v35[4]; // [esp+24h] [ebp-38h] BYREF
  int v36; // [esp+34h] [ebp-28h]
  double *v37; // [esp+38h] [ebp-24h]
  unsigned int v38; // [esp+3Ch] [ebp-20h]
  int v39; // [esp+40h] [ebp-1Ch]
  unsigned int v40; // [esp+44h] [ebp-18h]
  unsigned int v41; // [esp+48h] [ebp-14h]
  void **v42; // [esp+4Ch] [ebp-10h]
  unsigned int v43; // [esp+50h] [ebp-Ch]
  void **v44; // [esp+54h] [ebp-8h]
  unsigned int v45; // [esp+58h] [ebp-4h]

  v2 = (_DWORD *)this[64];
  v3 = *v2 & 0xFFFFF;
  v43 = v3;
  if ( !v3 )
    return 1;
  v4 = v2[1];
  if ( !v4 )
    return 1;
  if ( !v2[3] )
    return 1;
  v45 = 0;
  v38 = v4 / v3;
  if ( !(v4 / v3) )
    return 1;
  v5 = this[5];
  v6 = (_DWORD *)v2[2];
  v40 = v38;
  do
  {
    v7 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * *v6) + 8);
    if ( v7 != -1 )
    {
      v3 = v43;
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(v5 + 4 * v7) + 4)) + 4) & 4) == 0 )
      {
        v8 = v45++;
        v34[v8] = v7;
      }
    }
    v6 += v3;
    --v40;
  }
  while ( v40 );
  v9 = 0;
  if ( !v45 )
    return 1;
  do
  {
    if ( v45 == 1 )
      v10 = 3;
    else
      v10 = v9;
    v11 = sub_681AAA(this, this[35], 0, v10, 0.0);
    v35[v9] = v11;
    if ( v11 == -1 )
      return -2147024882;
    v12 = this[5];
    v13 = *(_DWORD *)(v12 + 4 * v11);
    *(_DWORD *)(v13 + 20) = *(_DWORD *)(*(_DWORD *)(v12 + 4 * **(_DWORD **)(this[64] + 16)) + 20);
    v14 = ++v9 < v45;
    *(_DWORD *)(v13 + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(this[64] + 16)) + 24);
  }
  while ( v14 );
  v45 = 0;
  v40 = 0;
  v42 = 0;
  do
  {
    v15 = this[5];
    v16 = *(_DWORD *)(*(_DWORD *)(v15 + 4 * *(_DWORD *)((char *)v42 + *(_DWORD *)(this[64] + 8))) + 8);
    if ( v16 != -1 && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(v15 + 4 * v16) + 4)) + 4) & 4) == 0 )
    {
      v41 = 0;
      if ( v3 )
      {
        v44 = v42;
        while ( 1 )
        {
          v39 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)((char *)v44 + *(_DWORD *)(this[64] + 8)));
          v17 = sub_681AAA(this, 0, 0, 0, 0.0);
          v36 = v17;
          if ( v17 == -1 )
            return -2147024882;
          v18 = *(_DWORD *)(this[5] + 4 * v17);
          result = sub_6815D6((double *)v18, v39);
          if ( result < 0 )
            return result;
          if ( *(_DWORD *)(v18 + 56) != -1 )
          {
            v20 = sub_681AAA(this, 0, 0, 0, 0.0);
            if ( v20 == -1 )
              return -2147024882;
            v21 = this[5];
            v33 = *(_DWORD *)(v21 + 4 * *(_DWORD *)(v39 + 56));
            v37 = *(double **)(v21 + 4 * v20);
            sub_6815D6(v37, v33);
            v22 = v35[v45];
            v23 = v37;
            *(_DWORD *)(v18 + 56) = v20;
            v17 = v36;
            *((_DWORD *)v23 + 2) = v22;
          }
          v24 = v35[v45];
          v25 = v44;
          ++v41;
          ++v44;
          *(_DWORD *)(v18 + 8) = v24;
          *(void **)((char *)v25 + *(_DWORD *)(this[64] + 8)) = (void *)v17;
          if ( v41 >= v43 )
          {
            v3 = v43;
            break;
          }
        }
      }
      ++v45;
    }
    ++v40;
    v42 += v3;
  }
  while ( v40 < v38 );
  v26 = (_DWORD *)sub_681186(116);
  if ( v26 )
  {
    v27 = (char *)sub_680CEC(v26);
    v42 = (void **)v27;
  }
  else
  {
    v42 = 0;
    v27 = 0;
  }
  if ( !v27 )
    return -2147024882;
  v28 = sub_6811D1(v27, v45 & 0xFFFFF | 0x10000000, v45, v45, 0);
  v29 = v27;
  if ( v28 < 0 )
  {
LABEL_40:
    sub_66238F(v29, 1);
    return v28;
  }
  v28 = sub_680D22(v27, this[64]);
  if ( v28 < 0 )
  {
    v29 = v27;
    goto LABEL_40;
  }
  v30 = 4 * v45;
  qmemcpy(*((void **)v27 + 4), v35, 4 * v45);
  v31 = v30;
  v32 = v42;
  qmemcpy(v42[2], v34, v31);
  v28 = sub_681997((int)this, v32);
  if ( v28 < 0 )
  {
    v29 = v42;
    goto LABEL_40;
  }
  return 0;
}
