int __thiscall sub_6BD921(_DWORD *this, char **a2, char *a3, unsigned int *a4)
{
  int *v5; // eax
  unsigned int v6; // ebx
  int result; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  bool v11; // zf
  int v12; // edi
  int v13; // edx
  int v14; // edi
  _DWORD *v15; // eax
  int v16; // eax
  const void *v17; // esi
  char *v18; // eax
  void *v19; // edi
  unsigned int v20; // edx
  int v21; // esi
  const void *v22; // esi
  int *v23; // esi
  int v24; // ecx
  int v25; // edi
  int v26; // esi
  int v27; // edi
  int v28; // ecx
  int v29; // edx
  unsigned int v30; // eax
  int *v31; // [esp-20h] [ebp-160h]
  char v32[64]; // [esp+Ch] [ebp-134h] BYREF
  _DWORD v33[4]; // [esp+4Ch] [ebp-F4h] BYREF
  char v34; // [esp+5Ch] [ebp-E4h] BYREF
  char v35; // [esp+6Ch] [ebp-D4h] BYREF
  char v36; // [esp+7Ch] [ebp-C4h] BYREF
  char v37; // [esp+8Ch] [ebp-B4h] BYREF
  int v38[4]; // [esp+ECh] [ebp-54h] BYREF
  int v39; // [esp+FCh] [ebp-44h]
  int v40; // [esp+100h] [ebp-40h]
  char *v41; // [esp+104h] [ebp-3Ch]
  char *v42; // [esp+108h] [ebp-38h]
  char *v43; // [esp+10Ch] [ebp-34h]
  char *v44; // [esp+110h] [ebp-30h]
  char *v45; // [esp+114h] [ebp-2Ch]
  unsigned int v46; // [esp+118h] [ebp-28h] BYREF
  char *v47; // [esp+11Ch] [ebp-24h]
  int v48; // [esp+120h] [ebp-20h]
  char *v49; // [esp+124h] [ebp-1Ch]
  char *v50; // [esp+128h] [ebp-18h]
  unsigned int v51; // [esp+12Ch] [ebp-14h]
  _DWORD *v52; // [esp+130h] [ebp-10h]
  unsigned int v53; // [esp+134h] [ebp-Ch]
  unsigned int v54; // [esp+138h] [ebp-8h]
  char *v55; // [esp+13Ch] [ebp-4h]

  v5 = (int *)this[64];
  v6 = *v5 & 0xFFFFF;
  v46 = 0;
  v38[0] = 0;
  v55 = 0;
  v48 = 0;
  v52 = this;
  v38[1] = 1;
  v38[2] = 2;
  v38[3] = 3;
  if ( sub_6BB35B(this, v5, dword_745D90, v32, &v46, (int)v33, v38, v6, a2 == 0) )
  {
    v31 = (int *)this[64];
    v48 = 1;
    result = sub_6BB35B(this, v31, dword_745E10, v32, &v46, (int)v33, v38, v6, a2 == 0);
    if ( result )
      return result;
  }
  v54 = 0;
  v42 = &v34;
  v41 = &v35;
LABEL_4:
  v51 = 0;
  v43 = &v36;
  v47 = &v37;
  while ( 1 )
  {
    v53 = 0;
    if ( v6 )
    {
      v8 = this[5];
      v44 = v41;
      v49 = v47;
      v50 = v43;
      v45 = v42;
      do
      {
        v9 = *(_DWORD *)(v8 + 4 * v33[v53]);
        v10 = *(_DWORD *)(v8 + 4 * *(_DWORD *)v45);
        v11 = *(_DWORD *)(v10 + 8) == -1;
        v12 = *(_DWORD *)(v8 + 4 * *(_DWORD *)v50);
        v39 = v9;
        v40 = v12;
        if ( !v11 )
          break;
        if ( *(_DWORD *)(v9 + 8) != -1 )
          break;
        if ( *(_DWORD *)(v12 + 8) != -1 )
          break;
        v13 = this[4];
        if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v10 + 4)) + 5) & 1) == 0 )
          break;
        if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v40 + 4)) + 5) & 1) == 0 )
          break;
        if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v39 + 4)) + 5) & 1) == 0 )
          break;
        if ( fabs(*(double *)(v40 + 32) - *(double *)(v10 + 32) - *(double *)(v39 + 32)) > 0.000009999999747378752 )
          break;
        if ( *(_DWORD *)v44 != *(_DWORD *)v49 )
          break;
        ++v53;
        v45 += 4;
        v50 += 4;
        v49 += 4;
        v44 += 4;
      }
      while ( v53 < v6 );
    }
    if ( v53 == v6 )
      break;
    ++v51;
    v47 -= 16;
    v43 += 16;
    if ( v51 >= 2 )
    {
      ++v54;
      v41 -= 16;
      v42 += 16;
      if ( v54 < 2 )
        goto LABEL_4;
      goto LABEL_19;
    }
  }
  v15 = (_DWORD *)sub_681186(116);
  if ( v15 )
    v55 = (char *)sub_680CEC(v15);
  else
    v55 = 0;
  if ( !v55 )
    return -2147024882;
  if ( v48 )
  {
    if ( a2 )
      goto LABEL_19;
    v16 = sub_6811D1(v55, v6 & 0xFFFFF | 0x70C00000, 2 * v6, v6, 0);
  }
  else
  {
    v16 = sub_6811D1(v55, v6 & 0xFFFFF | 0x70B00000, 2 * v6, v6, 0);
  }
  v14 = v16;
  if ( v16 < 0 )
    goto LABEL_20;
  v14 = sub_680D22(v55, this[64]);
  if ( v14 < 0 )
    goto LABEL_20;
  v17 = *(const void **)(this[64] + 16);
  v18 = v55;
  v19 = (void *)*((_DWORD *)v55 + 4);
  v54 = 4 * v6;
  v20 = 4 * v6;
  qmemcpy(v19, v17, 4 * ((4 * v6) >> 2));
  qmemcpy(*((void **)v18 + 2), v33, 4 * ((4 * v6) >> 2));
  v21 = *(_DWORD *)(v52[64] + 8);
  if ( v48 )
    v22 = (const void *)(v20 + v21);
  else
    v22 = (const void *)(v21 + 8 * v6);
  qmemcpy((void *)(4 * v6 + *((_DWORD *)v18 + 2)), v22, v20);
  v23 = (int *)*((_DWORD *)v18 + 2);
  v24 = v52[5];
  v25 = *v23;
  v26 = *(_DWORD *)(v24 + 4 * v23[v6]);
  v27 = *(_DWORD *)(v24 + 4 * v25);
  v28 = *(_DWORD *)(v24 + 4 * **((_DWORD **)v18 + 4));
  v29 = *(_DWORD *)(v28 + 4);
  if ( v29 == *(_DWORD *)(v27 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v27 + 12)
    || v29 == *(_DWORD *)(v26 + 4) && *(_DWORD *)(v28 + 12) == *(_DWORD *)(v26 + 12) )
  {
LABEL_19:
    v14 = 1;
    goto LABEL_20;
  }
  if ( a2 )
  {
    v55 = 0;
    *a2 = v18;
    v30 = v46;
    if ( v46 )
      qmemcpy(a3, v32, 4 * v46);
    *a4 = v30;
  }
  else
  {
    sub_681430(*(char **)(v52[6] + 4 * v52[63]), v18);
  }
  v14 = 0;
LABEL_20:
  if ( v55 )
    sub_66238F(v55, 1);
  return v14;
}
