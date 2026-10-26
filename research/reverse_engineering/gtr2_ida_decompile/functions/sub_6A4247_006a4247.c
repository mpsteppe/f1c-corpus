int __thiscall sub_6A4247(_DWORD *this, int a2)
{
  unsigned int v3; // eax
  _DWORD *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  unsigned int i; // esi
  int v9; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // esi
  int v13; // eax
  _DWORD *v14; // edi
  _DWORD *v15; // ebx
  int v16; // esi
  _BYTE *v17; // edx
  int v18; // eax
  int v19; // edi
  bool v20; // zf
  _DWORD *v21; // edx
  int v22; // eax
  _DWORD *v23; // eax
  int v24; // eax
  int v25; // esi
  int v26; // edx
  int v27; // ebx
  unsigned int j; // eax
  _DWORD *v29; // ecx
  _DWORD *v30; // eax
  char *v31; // ebx
  _DWORD *v32; // esi
  int v33; // eax
  int v34; // edi
  _DWORD *v35; // edx
  unsigned int v36; // eax
  _DWORD *v37; // esi
  void *v38; // ecx
  int v39; // [esp-10h] [ebp-138h]
  _DWORD v40[16]; // [esp+4h] [ebp-124h] BYREF
  _BYTE v41[160]; // [esp+44h] [ebp-E4h] BYREF
  int v42; // [esp+E4h] [ebp-44h] BYREF
  _DWORD v43[3]; // [esp+E8h] [ebp-40h] BYREF
  _DWORD v44[6]; // [esp+F4h] [ebp-34h] BYREF
  int v45; // [esp+10Ch] [ebp-1Ch]
  unsigned int v46; // [esp+110h] [ebp-18h] BYREF
  BOOL v47; // [esp+114h] [ebp-14h]
  int v48; // [esp+118h] [ebp-10h]
  unsigned int v49; // [esp+11Ch] [ebp-Ch]
  _DWORD *v50; // [esp+120h] [ebp-8h]
  _DWORD *v51; // [esp+124h] [ebp-4h]

  v3 = (unsigned __int16)this[50];
  v51 = this;
  if ( v3 >= 0x104 )
    return 1;
  v5 = (_DWORD *)this[64];
  v6 = 0;
  v46 = 0;
  v42 = 0;
  v43[0] = 1;
  v43[1] = 2;
  v43[2] = 3;
  if ( (*v5 & 0xFFFFF) != 3 )
    return 1;
  do
  {
    v7 = sub_6BB35B(this[64], *(&off_91A3E0 + v6), v40, &v46, v41, &v42, 3, 0);
    if ( !v7 )
      break;
    ++v6;
  }
  while ( v6 < 9 );
  v48 = 0;
  v47 = v6 > 4;
  if ( v7 )
  {
    for ( i = 0; i < 3; ++i )
    {
      v9 = sub_6BB35B(this[64], *(&off_91A404 + i), v40, &v46, v41, &v42, 3, 0);
      if ( !v9 )
        break;
    }
    v47 = i > 1;
    v48 = 1;
    if ( v9 )
      return 1;
  }
  v49 = 0;
  v10 = this[5];
  v45 = 12 - (_DWORD)v44;
  do
  {
    v11 = 4 * v49;
    v12 = *(_DWORD *)&v41[4 * v49 + 16];
    v13 = *(_DWORD *)(v10 + 4 * v12);
    if ( *(_DWORD *)(v13 + 16) != v49 )
      return 1;
    if ( a2 )
    {
      if ( *(_DWORD *)(v13 + 72) != -1
        || *(_DWORD *)(v13 + 4) != v51[32]
        || *(unsigned __int8 *)(v13 + 109) != v49 + 1
        || *(_BYTE *)(v13 + 108) != 5 )
      {
        return 1;
      }
      v20 = !v47;
      v44[v49] = v12;
      if ( v20 )
      {
        if ( *(_DWORD *)(v13 + 60) != 0x80000 )
          return 1;
        v14 = *(_DWORD **)(v13 + 56);
        v15 = &v41[v11 + 48];
        v20 = *(_DWORD *)&v41[v11 + 48] == (_DWORD)v14;
        v50 = v14;
        if ( v20 )
        {
          v16 = *(v15 - 4);
          if ( *(_DWORD *)&v41[v11 + 64] == v16 )
          {
            v17 = &v41[v11 + 80];
            v18 = *(_DWORD *)&v41[v11 + 80];
            if ( v18 == v15[12] && *(_DWORD *)&v41[v11 + 64] == v18 )
              goto LABEL_51;
          }
        }
LABEL_46:
        v20 = *(_DWORD *)&v41[v11 + 64] == (_DWORD)v14;
      }
      else
      {
        if ( *(_DWORD *)(v13 + 60) )
          return 1;
        v15 = &v41[v11 + 48];
        if ( *(_DWORD *)&v41[v11 + 48] == v12 )
        {
          v19 = *(_DWORD *)&v41[v11 + 64];
          v16 = *(v15 - 4);
          if ( v19 == v16 )
          {
            v17 = &v41[v11 + 80];
            v18 = *(_DWORD *)&v41[v11 + 80];
            if ( v18 == v15[12] && v19 == v18 )
              goto LABEL_51;
          }
        }
        v20 = *(_DWORD *)&v41[v11 + 64] == *(_DWORD *)&v41[v11 + 16];
      }
      if ( !v20 )
        return 1;
      v16 = *(v15 - 4);
      if ( *v15 != v16 )
        return 1;
      v17 = &v41[v11 + 80];
      v18 = *(_DWORD *)&v41[v11 + 80];
      if ( v18 != v15[12] || *v15 != v18 )
        return 1;
      goto LABEL_51;
    }
    if ( v47 )
    {
      if ( (*(_BYTE *)(*(_DWORD *)(v51[4] + 4 * *(_DWORD *)(v13 + 4)) + 5) & 2) == 0 )
        return 1;
      v21 = &v44[v11 / 4];
      v44[v49] = v12;
    }
    else
    {
      v22 = *(_DWORD *)(v13 + 72);
      if ( v22 == -1 )
        return 1;
      v23 = *(_DWORD **)(v51[6] + 4 * v22);
      if ( *v23 != 542113795 )
        return 1;
      v24 = v23[2];
      v25 = v51[4];
      v50 = *(_DWORD **)(v11 + v24);
      v26 = *(_DWORD *)(v10 + 4 * (_DWORD)v50);
      if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v26 + 4)) + 5) & 2) == 0 )
        return 1;
      if ( *(_DWORD *)(v26 + 16) != v49 )
        return 1;
      v21 = &v44[v11 / 4];
      v27 = *(_DWORD *)(v10 + 4 * *(_DWORD *)((char *)&v44[v11 / 4] + v24 + v45));
      if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v27 + 4)) + 5) & 1) == 0 || *(double *)(v27 + 32) != -1.0 )
        return 1;
      *v21 = v50;
    }
    v14 = (_DWORD *)*v21;
    v15 = &v41[v11 + 48];
    v20 = *(_DWORD *)&v41[v11 + 48] == *v21;
    v50 = (_DWORD *)*v21;
    if ( !v20 )
      goto LABEL_46;
    v16 = *(v15 - 4);
    if ( *(_DWORD *)&v41[v11 + 64] != v16 )
      goto LABEL_46;
    v17 = &v41[v11 + 80];
    v18 = *(_DWORD *)&v41[v11 + 80];
    if ( v18 != v15[12] || *(_DWORD *)&v41[v11 + 64] != v18 )
      goto LABEL_46;
LABEL_51:
    v20 = v48 == 0;
    v44[v11 / 4 + 3] = v16;
    if ( !v20 && v18 != *((_DWORD *)v17 + 8) )
      return 1;
    v10 = v51[5];
    if ( *(_DWORD *)(*(_DWORD *)(v10 + 4 * v16) + 16) != v49 )
      return 1;
    ++v49;
  }
  while ( v49 < 3 );
  for ( j = 0; j < v46; *v29 = 0 )
    v29 = (_DWORD *)v40[j++];
  v30 = (_DWORD *)sub_681186(116);
  if ( v30 )
    v31 = (char *)sub_680CEC(v30);
  else
    v31 = 0;
  if ( !v31 )
    return -2147024882;
  v32 = v51;
  v39 = *(_DWORD *)(v51[64] + 12);
  if ( a2 )
    v33 = sub_6811D1(v31, 1925185539, 6, v39, 0);
  else
    v33 = sub_6811D1(v31, 1926234115, 9, v39, 0);
  v34 = v33;
  if ( v33 >= 0 )
  {
    v48 = sub_680D22(v31, v32[64]);
    if ( v48 >= 0 )
    {
      v35 = v51;
      qmemcpy(*((void **)v31 + 4), *(const void **)(v51[64] + 16), 4 * *(_DWORD *)(v51[64] + 12));
      v36 = 3;
      v50 = v43;
      do
      {
        *(_DWORD *)(v36 * 4 + *((_DWORD *)v31 + 2) - 12) = **(_DWORD **)(v35[64] + 8);
        *(_DWORD *)(v36 * 4 + *((_DWORD *)v31 + 2)) = v44[v36];
        if ( !a2 )
          *(_DWORD *)(v36 * 4 + *((_DWORD *)v31 + 2) + 12) = v50[v36];
        ++v36;
      }
      while ( v36 < 6 );
      v37 = v35 + 63;
      v38 = *(void **)(v35[6] + 4 * v35[63]);
      if ( v38 )
      {
        sub_66238F(v38, 1);
        v35 = v51;
      }
      *(_DWORD *)(v35[6] + 4 * *v37) = v31;
    }
    else
    {
      sub_66238F(v31, 1);
    }
    return v48;
  }
  else
  {
    sub_66238F(v31, 1);
    return v34;
  }
}
