int __thiscall sub_69631A(_DWORD *this, _DWORD *a2, int a3, unsigned int *a4, _DWORD *a5)
{
  unsigned int v5; // ebx
  int v6; // eax
  unsigned int v7; // edx
  int v8; // ecx
  int v9; // ecx
  const char *v11; // eax
  unsigned int v12; // eax
  int v13; // ecx
  const char **v14; // edi
  const char **v15; // edi
  int *v16; // esi
  int v17; // ebx
  int *v18; // edi
  _DWORD *v19; // esi
  unsigned int v20; // eax
  int v21; // ecx
  int v22; // ecx
  bool v23; // zf
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  unsigned int v28; // ecx
  unsigned int *v29; // eax
  int v30; // eax
  unsigned int v31; // ecx
  unsigned int *v32; // eax
  _DWORD *v33; // eax
  int *v34; // eax
  int **v35; // ebx
  int *v36; // eax
  int *v37; // ecx
  int v38; // esi
  int v39; // edx
  int *v40; // ecx
  int *v41; // eax
  int v42; // eax
  _DWORD *v43; // eax
  const char *v44; // edi
  _DWORD *v45; // esi
  int v46; // edi
  unsigned int v47; // edi
  int v48; // ebx
  int *v49; // eax
  int *v50; // ecx
  int v51; // edx
  int v52; // edx
  int v53; // esi
  _DWORD *v54; // eax
  _DWORD *v55; // esi
  _DWORD *v56; // eax
  int *v57; // esi
  char *v58; // edi
  _DWORD *v59; // eax
  _DWORD *v60; // eax
  _DWORD *v61; // eax
  _DWORD *v62; // ebx
  _DWORD *v63; // eax
  _DWORD *v64; // eax
  _DWORD *v65; // eax
  _DWORD *v66; // esi
  _DWORD *v67; // eax
  _DWORD *v68; // esi
  _DWORD *v69; // eax
  _DWORD *v70; // eax
  _DWORD *v71; // eax
  _DWORD v72[4]; // [esp+4h] [ebp-160h] BYREF
  int v73; // [esp+14h] [ebp-150h]
  _DWORD v74[10]; // [esp+1Ch] [ebp-148h] BYREF
  char v75; // [esp+44h] [ebp-120h] BYREF
  _DWORD v76[9]; // [esp+B8h] [ebp-ACh] BYREF
  _DWORD v77[14]; // [esp+DCh] [ebp-88h] BYREF
  _DWORD v78[5]; // [esp+114h] [ebp-50h] BYREF
  _DWORD v79[5]; // [esp+128h] [ebp-3Ch] BYREF
  int v80[5]; // [esp+13Ch] [ebp-28h] BYREF
  _DWORD *v81; // [esp+150h] [ebp-14h]
  const char *v82; // [esp+154h] [ebp-10h]
  int *v83; // [esp+158h] [ebp-Ch]
  unsigned int v84; // [esp+15Ch] [ebp-8h]
  unsigned int v85; // [esp+160h] [ebp-4h]
  int v86; // [esp+170h] [ebp+Ch]
  _DWORD *v87; // [esp+170h] [ebp+Ch]

  v5 = 0;
  v81 = this;
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  v6 = a3;
  v7 = 0;
  if ( a3 )
  {
    do
    {
      v8 = *(_DWORD *)(v6 + 8);
      if ( !v8 )
        break;
      if ( *(_DWORD *)(v8 + 4) != 13 )
        break;
      v9 = *(_DWORD *)(v8 + 16);
      if ( !v9 )
        break;
      if ( *(_DWORD *)(v9 + 4) != 9 )
        break;
      v6 = *(_DWORD *)(v6 + 12);
      ++v7;
    }
    while ( v6 );
    if ( v6 || v7 > 4 )
      return 1;
  }
  v11 = (const char *)a2[2];
  v85 = 94;
  v82 = v11;
  while ( 1 )
  {
    v12 = (v5 + v85) >> 1;
    v13 = strcmp(v82, (&off_73D424)[41 * v12]);
    if ( v13 <= 0 )
      break;
    v5 = v12 + 1;
LABEL_19:
    if ( v5 >= v85 )
      goto LABEL_29;
  }
  if ( v13 < 0 )
  {
    v85 = (v5 + v85) >> 1;
    goto LABEL_19;
  }
  v5 = (v5 + v85) >> 1;
  v85 = v12 + 1;
  if ( v12 )
  {
    v14 = (const char **)((char *)&unk_73D380 + 164 * v12);
    do
    {
      if ( strcmp(v82, *v14) )
        break;
      --v5;
      v14 -= 41;
    }
    while ( v5 );
  }
  if ( v85 < 0x5E )
  {
    v15 = (const char **)&(&off_73D424)[41 * v85];
    do
    {
      if ( strcmp(v82, *v15) )
        break;
      ++v85;
      v15 += 41;
    }
    while ( v85 < 0x5E );
  }
LABEL_29:
  if ( v5 == v85 )
    return 1;
  v82 = (const char *)v5;
  if ( v5 >= v85 )
    goto LABEL_92;
  v83 = &dword_73D420[41 * v5];
  while ( 2 )
  {
    memset(v78, 255, sizeof(v78));
    v80[0] = 30;
    v80[1] = 30;
    v80[2] = 30;
    v16 = v83;
    v80[3] = 30;
    v80[4] = 30;
    v79[0] = 5;
    v79[1] = 5;
    v79[2] = 5;
    v79[3] = 5;
    v79[4] = 5;
    sub_67F2AD(v77);
    sub_67F2AD(v76);
    v17 = a3;
    v84 = 1;
    if ( !a3 )
      break;
    v18 = v16 + 11;
    while ( 2 )
    {
      if ( v84 < 5 && *(v18 - 2) )
      {
        v19 = *(_DWORD **)(*(_DWORD *)(v17 + 8) + 16);
        v20 = v79[*v18];
        if ( v20 == 5 || !v20 && ((v21 = v19[4], v21 == 1) || v21 == 2) )
        {
          v24 = *v18;
          v79[v24] = v19[4];
          v77[v24 + 9] = v18[1];
        }
        else
        {
          v22 = v19[4];
          if ( v22 )
          {
            v23 = v22 == v20;
            goto LABEL_44;
          }
          if ( v20 >= 2 )
          {
            v23 = v20 == 2;
LABEL_44:
            if ( !v23 )
              break;
          }
        }
        v25 = v18[2];
        if ( v80[v25] == 30 )
        {
          v26 = v25;
          v80[v26] = v19[5];
          v77[v26 + 9] = v18[3];
        }
        else
        {
          v77[5] = v80[v25];
          v76[5] = v19[5];
          if ( sub_6956A9((int)v77, (int)v76, &v80[v18[2]]) < 0 )
            break;
        }
        if ( v19[4] )
        {
          v27 = v18[4];
          if ( v27 >= 0 )
          {
            if ( v19[6] < (unsigned int)v27 )
              break;
          }
          else
          {
            v28 = v19[6];
            v29 = &v78[~v27];
            if ( *v29 > v28 )
              *v29 = v28;
          }
          v30 = v18[5];
          if ( v30 >= 0 )
          {
            if ( v19[7] < (unsigned int)v30 )
              break;
          }
          else
          {
            v31 = v19[7];
            v32 = &v78[~v30];
            if ( *v32 > v31 )
              *v32 = v31;
          }
        }
        if ( (*(_BYTE *)(v18 - 1) & 0x20) != 0 && sub_6950BD(v81, v19) )
          break;
        v17 = *(_DWORD *)(v17 + 12);
        ++v84;
        v18 += 8;
        if ( !v17 )
          break;
        continue;
      }
      break;
    }
    if ( v17 || (v16 = v83, v84 < 5) && v83[8 * v84 + 1] )
    {
LABEL_91:
      ++v82;
      v83 += 41;
      if ( (unsigned int)v82 >= v85 )
        goto LABEL_92;
      continue;
    }
    break;
  }
  if ( v16[2] )
  {
    v33 = &v79[v16[3]];
    if ( *v33 == 5 )
      *v33 = *(_DWORD *)v16[4];
    v34 = &v80[v16[5]];
    if ( *v34 == 30 )
      *v34 = *(_DWORD *)v16[6];
  }
  v84 = 0;
  v35 = (int **)(v83 + 6);
  while ( 2 )
  {
    v36 = *(v35 - 2);
    v37 = &v79[v84];
    v38 = *v37;
    if ( *v37 == 5 )
    {
      if ( v36 )
        *v37 = *v36;
    }
    else
    {
      if ( !v38 && ((v39 = *v36, *v36 == 1) || v39 == 2) )
      {
        *v37 = v39;
      }
      else
      {
        while ( *v36 != 5 && v38 != *v36 )
          ++v36;
      }
      if ( *v36 == 5 )
        break;
    }
    v40 = &v80[v84];
    v41 = *v35;
    if ( *v40 == 30 )
    {
      if ( v41 )
      {
        v42 = *v41;
        goto LABEL_86;
      }
    }
    else
    {
      while ( *v41 != 30 && *v40 != *v41 )
        ++v41;
      if ( *v41 == 30 )
      {
        v42 = **v35;
LABEL_86:
        *v40 = v42;
      }
    }
    v43 = &v78[v84];
    if ( *v43 == -1 )
      *v43 = 1;
    ++v84;
    v35 += 8;
    if ( v84 < 5 )
      continue;
    break;
  }
  if ( v84 != 5 )
    goto LABEL_91;
LABEL_92:
  v44 = v82;
  if ( v82 == (const char *)v85 )
    return 1;
  if ( a4 )
  {
    v45 = v72;
    v46 = 5;
    do
    {
      sub_67F2AD(v45);
      v45 += 9;
      --v46;
    }
    while ( v46 );
    v47 = 0;
    v48 = 41 * (_DWORD)v82;
    v49 = v74;
    v50 = (int *)((char *)&unk_73D43C + 164 * (_DWORD)v82);
    do
    {
      if ( !*(v50 - 6) )
        break;
      v86 = *(v50 - 5);
      if ( v86 )
      {
        *(v49 - 2) = v79[*(v50 - 4)];
        *(v49 - 1) = v80[*(v50 - 2)];
        v51 = *v50;
        if ( *v50 < 0 )
          v51 = v78[~v51];
        *v49 = v51;
        v52 = v50[1];
        if ( v52 < 0 )
          v52 = v78[~v52];
        v53 = v86 & 0xC00;
        v49[1] = v52;
        v49[2] = v53;
        if ( !v47 || (v86 & 0x20) == 0 )
          v49[2] = v53 | 0x200;
      }
      ++v47;
      v50 += 8;
      v49 += 9;
    }
    while ( v47 < 5 );
    if ( (v73 == 1 || v73 == 2) && v74[1] == 1 && v74[0] == 1 )
      v73 = 0;
    v54 = (_DWORD *)sub_65B229(64);
    if ( v54 )
    {
      v55 = sub_67F351(v54);
      v85 = (unsigned int)v55;
    }
    else
    {
      v85 = 0;
      v55 = 0;
    }
    if ( v55 )
    {
      if ( !dword_73D428[v48] || (v56 = sub_67FD01(v72), (v55[8] = v56) != 0) )
      {
        v57 = v55 + 9;
        v83 = v57;
        v84 = 1;
        v58 = &v75;
        v87 = (_UNKNOWN **)((char *)&off_73D444 + v48 * 4);
        do
        {
          if ( !*v87 )
            break;
          v59 = (_DWORD *)sub_65B229(20);
          if ( v59 )
            v60 = sub_67ED1B(v59, 0, 0, (int)"Decls");
          else
            v60 = 0;
          *v57 = (int)v60;
          if ( !v60 )
            return -2147024882;
          v61 = (_DWORD *)sub_65B229(48);
          v62 = v61 ? sub_67F0EF(v61, 1, 0, 0, 0) : 0;
          if ( !v62 )
            return -2147024882;
          *(_DWORD *)(*v83 + 8) = v62;
          v63 = (_DWORD *)sub_65B229(48);
          v64 = v63 ? sub_67EF22(v63, a2) : 0;
          v62[5] = v64;
          if ( !v64 )
            return -2147024882;
          v64[6] = *v87;
          v65 = (_DWORD *)sub_65B229(64);
          v66 = v65 ? sub_67F449(v65) : 0;
          if ( !v66 )
            return -2147024882;
          v62[6] = v66;
          v66[4] = -1;
          v66[5] = *(_DWORD *)v58 * *((_DWORD *)v58 - 1);
          v66[6] = 2;
          v66[7] = v87[1];
          v67 = sub_67FD01((_DWORD *)v58 - 7);
          v66[8] = v67;
          if ( !v67 )
            return -2147024882;
          v87 += 8;
          v57 = (int *)(*v83 + 12);
          ++v84;
          v58 += 36;
          v83 = v57;
        }
        while ( v84 < 5 );
        v44 = v82;
        *a4 = v85;
        goto LABEL_145;
      }
    }
    return -2147024882;
  }
  else
  {
LABEL_145:
    v68 = 0;
    if ( a5 )
    {
      v69 = (_DWORD *)sub_65B229(20);
      if ( v69 )
        v68 = sub_67ED1B(v69, 0, 0, (int)"Values");
      if ( !v68 )
        return -2147024882;
      v70 = (_DWORD *)sub_65B229(64);
      v71 = v70 ? sub_67F780(v70, 2, dword_73D420[41 * (_DWORD)v44], a2) : 0;
      v68[2] = v71;
      if ( !v71 )
        return -2147024882;
      *a5 = v68;
    }
    return 0;
  }
}
