int __thiscall sub_6BD325(_DWORD *this, void ***a2, char *a3, unsigned int *a4)
{
  int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // esi
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // eax
  _DWORD *v15; // eax
  void **v16; // eax
  int v17; // eax
  _DWORD *v18; // eax
  void **v19; // eax
  int v20; // esi
  const void *v21; // esi
  int v22; // edi
  unsigned int v23; // edx
  int v24; // ecx
  int v25; // edi
  int v26; // eax
  int v27; // edx
  int v28; // edx
  int v29; // eax
  int v30; // edx
  int v31; // edi
  int v32; // eax
  _DWORD *v33; // eax
  void **v34; // ecx
  unsigned int v35; // ecx
  const void *v36; // esi
  void **v37; // eax
  void *v38; // edi
  void *v39; // edi
  unsigned int v40; // edx
  _DWORD *v41; // edx
  int v42; // ecx
  int v43; // edi
  int v44; // esi
  int v45; // ecx
  int v46; // edx
  bool v47; // zf
  unsigned int v48; // eax
  char v49[64]; // [esp+Ch] [ebp-124h] BYREF
  _DWORD v50[4]; // [esp+4Ch] [ebp-E4h] BYREF
  _DWORD v51[36]; // [esp+5Ch] [ebp-D4h] BYREF
  int v52[4]; // [esp+ECh] [ebp-44h] BYREF
  unsigned int v53; // [esp+FCh] [ebp-34h] BYREF
  int v54; // [esp+100h] [ebp-30h]
  unsigned int v55; // [esp+104h] [ebp-2Ch]
  int v56; // [esp+108h] [ebp-28h]
  int v57; // [esp+10Ch] [ebp-24h]
  int v58; // [esp+110h] [ebp-20h]
  int v59; // [esp+114h] [ebp-1Ch]
  int v60; // [esp+118h] [ebp-18h]
  int v61; // [esp+11Ch] [ebp-14h]
  unsigned int v62; // [esp+120h] [ebp-10h]
  void **v63; // [esp+124h] [ebp-Ch]
  unsigned int v64; // [esp+128h] [ebp-8h]
  int v65; // [esp+12Ch] [ebp-4h]

  v5 = *(_DWORD *)this[64];
  v6 = v5 & 0xFFF00000;
  v7 = v5 & 0xFFFFF;
  v63 = 0;
  v53 = 0;
  v52[0] = 0;
  v52[1] = 1;
  v52[2] = 2;
  v52[3] = 3;
  if ( v6 != 805306368 )
    return 1;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 0;
  v64 = 0;
  if ( v7 )
  {
    v9 = *(_DWORD *)(this[64] + 8);
    v62 = 4 * v7;
    v61 = 4 * v7;
    v59 = 8 * v7;
    v65 = 8 * v7;
    do
    {
      v10 = this[5];
      v11 = *(_DWORD *)(v10 + 4 * *(_DWORD *)(v9 + v61));
      v12 = *(_DWORD *)(v10 + 4 * *(_DWORD *)(v9 + v65));
      v13 = *(_DWORD *)(v12 + 4);
      v54 = v12;
      v14 = this[4];
      v55 = *(_DWORD *)(v14 + 4 * v13);
      if ( (*(_BYTE *)(*(_DWORD *)(v14 + 4 * *(_DWORD *)(v11 + 4)) + 5) & 1) != 0
        && *(double *)(v11 + 32) == 0.0
        && *(_DWORD *)(v11 + 8) == -1
        && *(_DWORD *)(*(_DWORD *)(this[64] + 8) + v65) == *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * v64) )
      {
        v60 = 1;
      }
      else
      {
        v58 = 1;
      }
      if ( (*(_BYTE *)(v55 + 5) & 1) != 0
        && *(double *)(v54 + 32) == 0.0
        && *(_DWORD *)(v54 + 8) == -1
        && *(_DWORD *)(*(_DWORD *)(this[64] + 8) + v61) == *(_DWORD *)(*(_DWORD *)(this[64] + 8) + 4 * v64) )
      {
        v57 = 1;
      }
      else
      {
        v56 = 1;
      }
      ++v64;
      v65 += 4;
      v61 += 4;
    }
    while ( v64 < v7 );
    if ( v60 && !v58 )
    {
      v15 = (_DWORD *)sub_681186(116);
      if ( v15 )
        v16 = (void **)sub_680CEC(v15);
      else
        v16 = 0;
      v63 = v16;
      if ( v16 )
      {
        v17 = sub_6811D1((char *)v16, v7 & 0xFFFFF | 0x70B00000, 2 * v7, v7, 0);
        goto LABEL_35;
      }
      return -2147024882;
    }
    if ( v57 && !v56 )
    {
      if ( a2 )
        return 1;
      v18 = (_DWORD *)sub_681186(116);
      if ( v18 )
        v19 = (void **)sub_680CEC(v18);
      else
        v19 = 0;
      v63 = v19;
      if ( v19 )
      {
        v17 = sub_6811D1((char *)v19, v7 & 0xFFFFF | 0x70C00000, 2 * v7, v7, 0);
LABEL_35:
        v65 = v17;
        if ( v17 < 0 )
          goto LABEL_76;
        v65 = sub_680D22(v63, this[64]);
        if ( v65 < 0 )
          goto LABEL_76;
        qmemcpy(v63[4], *(const void **)(this[64] + 16), v62);
        qmemcpy(v63[2], *(const void **)(this[64] + 8), v62);
        v20 = *(_DWORD *)(this[64] + 8);
        if ( v60 )
          v21 = (const void *)(v62 + v20);
        else
          v21 = (const void *)(v59 + v20);
        qmemcpy((char *)v63[2] + v62, v21, v62);
        goto LABEL_41;
      }
      return -2147024882;
    }
  }
  v65 = sub_6BB35B(this, (int *)this[64], dword_745D30, v49, &v53, (int)v50, v52, v7, a2 == 0);
  if ( v65 )
    return v65;
  v22 = 0;
  v60 = 0;
  v64 = 0;
LABEL_44:
  v65 = 0;
  while ( 1 )
  {
    v23 = 0;
    v55 = 0;
    if ( v7 )
    {
      v24 = this[5];
      do
      {
        v58 = v50[4 * v64 + v23];
        v61 = v51[v23 - 4 * v64];
        v25 = *(_DWORD *)(*(_DWORD *)(v24 + 4 * v61) + 4);
        v26 = v51[v65 + 4 + v23];
        v57 = v51[v23 - v65 + 8];
        v62 = *(_DWORD *)(v24 + 4 * v57);
        v27 = this[4];
        v59 = *(_DWORD *)(v27 + 4 * v25);
        v54 = *(_DWORD *)(v27 + 4 * *(_DWORD *)(v62 + 4));
        v56 = *(_DWORD *)(*(_DWORD *)(v24 + 4 * v58) + 56);
        if ( (v56 == v26 || (v28 = *(_DWORD *)(*(_DWORD *)(v24 + 4 * v26) + 56), v28 == v58) || v56 != -1 && v56 == v28)
          && (*(_DWORD *)(*(_DWORD *)(v24 + 4 * v58) + 60) ^ 0x80000) == *(_DWORD *)(*(_DWORD *)(v24 + 4 * v26) + 60)
          && v61 == v57 )
        {
          v22 = 1;
        }
        else
        {
          if ( v58 == v26 )
          {
            if ( ((v29 = *(_DWORD *)(v24 + 4 * v61), v30 = *(_DWORD *)(v29 + 56), v30 == v57)
               || (v31 = *(_DWORD *)(v62 + 56), v31 == v61)
               || v30 != -1 && v30 == v31)
              && (*(_DWORD *)(v29 + 60) ^ 0x80000) == *(_DWORD *)(v62 + 60)
              || (*(_DWORD *)(v59 + 4) & 0x100) != 0
              && (*(_DWORD *)(v54 + 4) & 0x100) != 0
              && *(double *)(v62 + 32) == -*(double *)(v29 + 32) )
            {
              v32 = 1;
              v22 = 1;
              goto LABEL_66;
            }
          }
          v22 = 0;
        }
        v32 = 0;
LABEL_66:
        if ( v55 )
        {
          if ( v60 != v32 )
            v22 = 0;
        }
        else
        {
          v60 = v32;
        }
        if ( !v22 )
          goto LABEL_73;
        v23 = v55 + 1;
        v55 = v23;
      }
      while ( v23 < v7 );
    }
    if ( v22 )
      break;
LABEL_73:
    v65 += 4;
    if ( (unsigned int)v65 >= 8 )
    {
      if ( ++v64 >= 2 )
        goto LABEL_75;
      goto LABEL_44;
    }
  }
  v33 = (_DWORD *)sub_681186(116);
  if ( v33 )
    v34 = (void **)sub_680CEC(v33);
  else
    v34 = 0;
  v63 = v34;
  if ( !v34 )
    return -2147024882;
  if ( !v60 )
  {
    if ( !v64 )
      goto LABEL_99;
LABEL_101:
    if ( v64 != 1 )
      goto LABEL_88;
LABEL_87:
    v65 = sub_6811D1((char *)v63, v7 & 0xFFFFF | 0x70C00000, 2 * v7, v7, 0);
    if ( v65 >= 0 )
      goto LABEL_88;
    goto LABEL_76;
  }
  if ( v64 != 1 )
    goto LABEL_86;
LABEL_99:
  v65 = sub_6811D1((char *)v34, v7 & 0xFFFFF | 0x70B00000, 2 * v7, v7, 0);
  if ( v65 < 0 )
    goto LABEL_76;
  if ( !v60 )
    goto LABEL_101;
LABEL_86:
  if ( !v64 )
    goto LABEL_87;
LABEL_88:
  v65 = sub_680D22(v63, this[64]);
  if ( v65 < 0 )
    goto LABEL_76;
  v35 = v7;
  v36 = *(const void **)(this[64] + 16);
  v37 = v63;
  v38 = v63[4];
  v62 = 4 * v35;
  qmemcpy(v38, v36, 4 * v35);
  v39 = v37[2];
  v59 = 16 * v64;
  v40 = v62;
  qmemcpy(v39, &v50[4 * v64], v62);
  qmemcpy((char *)v37[2] + v40, (char *)v51 - v59, v40);
  v41 = v37[2];
  v42 = this[5];
  v43 = *(_DWORD *)(v42 + 4 * *(_DWORD *)((char *)v41 + v62));
  v44 = *(_DWORD *)(v42 + 4 * *v41);
  v45 = *(_DWORD *)(v42 + 4 * *(_DWORD *)v37[4]);
  v46 = *(_DWORD *)(v45 + 4);
  v47 = v46 == *(_DWORD *)(v44 + 4);
  v59 = v43;
  if ( !v47 )
  {
LABEL_92:
    if ( v46 == *(_DWORD *)(v43 + 4) && *(_DWORD *)(v45 + 12) == *(_DWORD *)(v43 + 12) )
      goto LABEL_75;
    if ( a2 )
    {
      *a2 = v37;
      v48 = v53;
      if ( v53 )
        qmemcpy(a3, v49, 4 * v53);
      *a4 = v48;
      return v65;
    }
LABEL_41:
    v65 = sub_681430(*(char **)(this[6] + 4 * this[63]), v63);
    goto LABEL_76;
  }
  if ( *(_DWORD *)(v45 + 12) != *(_DWORD *)(v44 + 12) )
  {
    v43 = v59;
    goto LABEL_92;
  }
LABEL_75:
  v65 = 1;
LABEL_76:
  if ( v63 )
    sub_66238F(v63, 1);
  return v65;
}
