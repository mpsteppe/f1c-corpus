int __thiscall sub_6C94AF(_DWORD *this)
{
  int v2; // ecx
  int v3; // esi
  _DWORD *v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // ecx
  bool v7; // zf
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // esi
  size_t v11; // edi
  _DWORD *v12; // eax
  int v13; // ecx
  size_t v14; // edx
  size_t v15; // ecx
  size_t v16; // edx
  size_t v17; // ecx
  _DWORD *v18; // edi
  unsigned int v19; // edx
  unsigned int v20; // ecx
  _DWORD *v21; // edi
  int v22; // eax
  unsigned int v23; // ebx
  _DWORD *v24; // eax
  int v25; // ecx
  _DWORD *v26; // ecx
  _DWORD *v27; // esi
  int v28; // ecx
  int v29; // esi
  unsigned int v30; // ecx
  unsigned int v31; // esi
  int v32; // ecx
  int v33; // eax
  unsigned int v34; // eax
  _DWORD *v35; // edx
  int v36; // eax
  unsigned int v37; // ebx
  char *v38; // edi
  char *v39; // ebx
  int v40; // eax
  int v41; // ecx
  _DWORD *v42; // edx
  char *v43; // ecx
  size_t v44; // edx
  int v45; // eax
  int v46; // edx
  const char *v47; // eax
  unsigned int v48; // ecx
  int v49; // edx
  char *v50; // eax
  unsigned int v51; // esi
  size_t v52; // eax
  int v53; // ecx
  int v54; // eax
  __int16 v55; // ax
  _DWORD *v56; // ecx
  _DWORD *v57; // eax
  int v58; // eax
  int v59; // eax
  __int16 v60; // dx
  unsigned int v61; // esi
  char *v62; // ebx
  unsigned int v63; // esi
  _DWORD *v64; // eax
  _DWORD *v65; // edi
  int v66; // esi
  double *v67; // eax
  size_t v68; // esi
  char *v69; // edx
  _DWORD *v70; // edi
  int v71; // ebx
  double *v72; // eax
  double v73; // st7
  size_t v74; // esi
  unsigned int v75; // ecx
  char *v76; // esi
  _DWORD *v77; // edi
  int v78; // ecx
  double *v79; // eax
  _DWORD *v80; // ebx
  unsigned int v81; // eax
  unsigned int v82; // edi
  int v83; // eax
  int v85; // [esp-4h] [ebp-18Ch]
  char v86[256]; // [esp+Ch] [ebp-17Ch] BYREF
  void *v87[3]; // [esp+10Ch] [ebp-7Ch] BYREF
  _DWORD v88[7]; // [esp+118h] [ebp-70h] BYREF
  unsigned int v89; // [esp+134h] [ebp-54h]
  int v90[4]; // [esp+138h] [ebp-50h] BYREF
  void *v91; // [esp+148h] [ebp-40h]
  void *v92; // [esp+14Ch] [ebp-3Ch]
  void *v93; // [esp+150h] [ebp-38h]
  size_t v94; // [esp+154h] [ebp-34h]
  int v95; // [esp+158h] [ebp-30h]
  void *Block; // [esp+15Ch] [ebp-2Ch]
  _DWORD *v97; // [esp+160h] [ebp-28h]
  void *v98; // [esp+164h] [ebp-24h]
  size_t Size; // [esp+168h] [ebp-20h]
  unsigned int v100; // [esp+16Ch] [ebp-1Ch]
  unsigned int v101; // [esp+170h] [ebp-18h]
  char *v102; // [esp+174h] [ebp-14h]
  char *v103; // [esp+178h] [ebp-10h]
  void *v104; // [esp+17Ch] [ebp-Ch]
  unsigned int i; // [esp+180h] [ebp-8h]
  unsigned int j; // [esp+184h] [ebp-4h]

  v85 = this[86] != 0 ? 1179535686 : 1111577667;
  v95 = (int)this;
  sub_6801F7(v90, v85);
  memset(v88, 0, sizeof(v88));
  v88[2] = this[50];
  v2 = this[51];
  v88[0] = 28;
  v88[5] = v2;
  Block = 0;
  v104 = 0;
  v91 = 0;
  v93 = 0;
  v92 = 0;
  v98 = 0;
  v3 = sub_68024C(v90, (char *)v88, 0x1Cu, 1, 0);
  if ( v3 < 0 )
    goto LABEL_161;
  v4 = (_DWORD *)v95;
  v5 = 0;
  v6 = 0;
  v7 = *(_DWORD *)(v95 + 8) == 0;
  v102 = 0;
  j = 0;
  if ( !v7 )
  {
    v103 = *(char **)(v95 + 20);
    v101 = *(_DWORD *)(v95 + 8);
    do
    {
      v8 = *(_DWORD *)v103;
      i = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v95 + 16) + 4 * *(_DWORD *)(*(_DWORD *)v103 + 4)) + 4);
      if ( (i & 0x200) != 0 && (i & 0x100) == 0 )
      {
        v9 = *(_DWORD *)(v8 + 12);
        if ( (i & 0x80u) == 0 )
        {
          if ( (i & 0x2000) != 0 )
          {
            if ( (unsigned int)v102 <= v9 )
              v102 = (char *)(v9 + 1);
          }
          else if ( (i & 0x40000) != 0 )
          {
            if ( j <= v9 )
              j = v9 + 1;
          }
          else if ( v6 <= v9 )
          {
            v6 = v9 + 1;
          }
        }
        else if ( v5 <= v9 )
        {
          v5 = v9 + 1;
        }
      }
      v103 += 4;
      --v101;
    }
    while ( v101 );
  }
  Size = (size_t)&v102[v6];
  v103 = &v102[v5 + v6];
  v10 = (unsigned int)&v102[v6 + j + v5];
  v11 = 4 * v10;
  v104 = operator new(4 * v10);
  if ( !v104 )
    goto LABEL_159;
  v98 = operator new(v11);
  if ( !v98 )
    goto LABEL_159;
  i = 0;
  memset(v104, 0, v11);
  if ( v4[2] )
  {
    do
    {
      v12 = *(_DWORD **)(v4[5] + 4 * i);
      if ( v12[24] )
      {
        if ( v12[2] == -1 )
        {
          v13 = *(_DWORD *)(*(_DWORD *)(v4[4] + 4 * v12[1]) + 4);
          if ( (v13 & 0x200) != 0 && (v13 & 0x100) == 0 )
          {
            if ( (v13 & 0x80u) == 0 )
            {
              if ( (v13 & 0x2000) != 0 )
              {
                v14 = 0;
              }
              else
              {
                v14 = (size_t)v103;
                if ( (v13 & 0x40000) == 0 )
                  v14 = (size_t)v102;
              }
            }
            else
            {
              v14 = Size;
            }
            v15 = v14 + v12[3];
            v16 = v15 - (v12[28] >> 2);
            v17 = v15 + 1;
            while ( v17 > v16 )
            {
              --v17;
              v18 = (char *)v104 + 4 * v17;
              if ( *v18 )
                break;
              *v18 = v12;
            }
          }
        }
      }
      ++i;
    }
    while ( i < v4[2] );
  }
  v19 = 0;
  v20 = 0;
  v101 = 0;
  if ( v10 )
  {
    do
    {
      v21 = v104;
      v22 = *((_DWORD *)v104 + v20);
      if ( v22 )
      {
        v23 = v101++;
        *((_DWORD *)v104 + v23) = v22;
      }
      ++v20;
    }
    while ( v20 < v10 );
  }
  else
  {
    v21 = v104;
  }
  v24 = 0;
  v100 = 0;
  if ( v101 )
  {
    do
    {
      if ( !v24
        || (v25 = v21[v19], *(_DWORD *)(v25 + 4) != v24[1])
        || *(_DWORD *)(v25 + 96) != v24[24]
        || *(_DWORD *)(v21[v19] + 12) - (*(_DWORD *)(v21[v19] + 112) >> 2) != v24[3] - (v24[28] >> 2) )
      {
        v24 = (_DWORD *)v21[v19];
        if ( v24 )
        {
          v26 = (_DWORD *)v24[24];
          if ( v26[1] == 6 )
          {
            v27 = (_DWORD *)v26[5];
            if ( v27 )
            {
              if ( v27[1] == 3 )
              {
                v28 = v26[6];
                if ( v28 )
                {
                  if ( *(_DWORD *)(v28 + 4) == 11 && v27[4] == 9 && v27[6] )
                  {
                    v29 = v100++;
                    *((_DWORD *)v98 + v29) = v19;
                  }
                }
              }
            }
          }
        }
      }
      ++v19;
    }
    while ( v19 < v101 );
  }
  v30 = 0;
  for ( i = 0; v30 < v100; i = v30 )
  {
    j = *((_DWORD *)v98 + v30);
    v103 = (char *)v21[j];
    v31 = 0;
    Size = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v103 + 24) + 20) + 24);
    if ( v30 )
    {
      while ( 1 )
      {
        v32 = v21[*((_DWORD *)v98 + v31)];
        v33 = strcmp((const char *)Size, *(const char **)(*(_DWORD *)(*(_DWORD *)(v32 + 96) + 20) + 24));
        if ( v33 < 0 || v33 <= 0 && *((_DWORD *)v103 + 1) < *(_DWORD *)(v32 + 4) )
          break;
        if ( ++v31 >= i )
          break;
        v21 = v104;
      }
      v30 = i;
      if ( i > v31 )
      {
        v34 = i;
        do
        {
          v35 = v98;
          *((_DWORD *)v98 + v34) = *((_DWORD *)v98 + v34 - 1);
          --v34;
        }
        while ( v34 > v31 );
        v35[v31] = j;
      }
      v21 = v104;
    }
    ++v30;
  }
  v36 = (*(int (__thiscall **)(int))(*(_DWORD *)v95 + 140))(v95);
  v37 = v100 + v36;
  if ( !(v100 + v36) )
  {
LABEL_151:
    v3 = (*(int (__thiscall **)(int, int *, void *, unsigned int))(*(_DWORD *)v95 + 144))(v95, v90, Block, v100);
    if ( v3 >= 0 )
    {
      v80 = (_DWORD *)v95;
      memset(v87, 0, sizeof(v87));
      v3 = sub_646152(*(_DWORD *)(v95 + 264), 0, v87);
      if ( v3 >= 0 )
      {
        v3 = sub_68024C(v90, (char *)v87[0], 0xFFFFFFFF, 5, &v88[6]);
        if ( v3 >= 0 )
        {
          v3 = sub_68024C(v90, "Microsoft (R) D3DX9 Shader Compiler 5.04.00.2904", 0xFFFFFFFF, 5, &v88[1]);
          if ( v3 >= 0 )
          {
            v81 = sub_680385(v90);
            v82 = v81;
            if ( v81 > 0x8000 )
            {
              sub_686791((int)v80, 0, 4548, "constant table info exceeds maximum comment size");
              v3 = -2147467259;
            }
            else
            {
              v3 = sub_6C5921((int)v80, v81);
              if ( v3 >= 0 )
              {
                memcpy((void *)(v80[67] + 4 * v82 + 4), (const void *)(v80[67] + 4), 4 * v80[68] - 4);
                v3 = sub_680391(v90, (int *)(v80[67] + 4), v82);
                if ( v3 >= 0 )
                {
                  v80[68] += v82;
                  v83 = v80[68];
                  v80[72] += v82;
                  v80[71] = v83;
                  v3 = 0;
                }
              }
            }
          }
        }
      }
    }
    goto LABEL_161;
  }
  Block = operator new(20 * v37);
  if ( !Block )
  {
LABEL_159:
    v3 = -2147024882;
    goto LABEL_161;
  }
  memset(Block, 0, 4 * ((20 * v37) >> 2));
  v3 = sub_68024C(v90, (char *)Block, 20 * v37, 1, &v88[4]);
  if ( v3 < 0 )
    goto LABEL_161;
  i = 0;
  v88[3] = v37;
  if ( !v100 )
    goto LABEL_151;
  v38 = (char *)v98;
  v39 = (char *)Block + 4;
  v103 = (char *)v98;
  v102 = (char *)Block + 4;
  while ( 1 )
  {
    v40 = *((_DWORD *)v104 + *(_DWORD *)v38);
    v41 = *(_DWORD *)(v40 + 96);
    v42 = *(_DWORD **)(v41 + 24);
    v43 = *(char **)(*(_DWORD *)(v41 + 20) + 24);
    v97 = v42;
    v7 = *(_DWORD *)(v95 + 344) == 0;
    v44 = *(_DWORD *)(*(_DWORD *)(v95 + 16) + 4 * *(_DWORD *)(v40 + 4));
    v94 = v44;
    if ( v7 )
    {
      v45 = sub_68024C(v90, v43, 0xFFFFFFFF, 7, (_DWORD *)v39 - 1);
    }
    else
    {
      v46 = *(_DWORD *)(v44 + 4);
      v47 = "c_%s";
      if ( (v46 & 0x2000) != 0 )
      {
        sub_632041((int)v86, 255, "b_%s", v43);
      }
      else if ( (v46 & 0x40000) != 0 )
      {
        sub_632041((int)v86, 255, "i_%s", v43);
      }
      else
      {
        if ( (v46 & 0x80u) != 0 )
          v47 = "s_%s";
        sub_632041((int)v86, 255, v47, v43);
      }
      v86[254] = 0;
      v45 = sub_68024C(v90, v86, 0xFFFFFFFF, 6, (_DWORD *)v39 - 1);
    }
    v3 = v45;
    if ( v45 < 0 )
      goto LABEL_161;
    v48 = *(_DWORD *)v38 + 1;
    v49 = 1;
    if ( v48 < v101 )
    {
      v50 = (char *)v104 + 4 * *(_DWORD *)v38;
      v51 = *(_DWORD *)(*(_DWORD *)v50 + 4);
      v52 = (size_t)(v50 + 4);
      v89 = v51;
      j = v48;
      Size = v52;
      do
      {
        if ( v89 != *(_DWORD *)(*(_DWORD *)v52 + 4) )
          break;
        if ( *(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38) + 96) != *(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38 + v49)
                                                                               + 96) )
          break;
        v53 = *((_DWORD *)v104 + *(_DWORD *)v38 + v49);
        if ( *(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38) + 12)
           - (*(_DWORD *)(*((_DWORD *)v104 + *(_DWORD *)v38) + 112) >> 2) != *(_DWORD *)(v53 + 12)
                                                                           - (*(_DWORD *)(v53 + 112) >> 2) )
          break;
        v52 = Size + 4;
        ++v49;
        ++j;
        Size += 4;
      }
      while ( j < v101 );
    }
    v54 = *(_DWORD *)(v94 + 4);
    if ( (v54 & 0x80u) == 0 )
      v55 = (v54 & 0x2000) != 0 ? 0 : ((v54 & 0x40000) == 0) + 1;
    else
      v55 = 3;
    v56 = v104;
    *(_WORD *)v39 = v55;
    *((_WORD *)v39 + 1) = *(_WORD *)(v56[*(_DWORD *)v38] + 12) - (*(_DWORD *)(v56[*(_DWORD *)v38] + 112) >> 2);
    v57 = v97;
    *((_WORD *)v39 + 2) = v49;
    v58 = v57[8];
    if ( v58 )
    {
      v3 = sub_6C5628(
             v90,
             v58,
             (void *)1,
             (unsigned int)&unk_E00000 & *(_DWORD *)(v56[*(_DWORD *)v38] + 60),
             (_DWORD *)v39 + 2);
      if ( v3 < 0 )
        goto LABEL_161;
    }
    if ( v97[12] )
    {
      v3 = (*(int (__thiscall **)(int, _DWORD *, char *))(*(_DWORD *)v95 + 148))(v95, v97, v39 - 4);
      if ( v3 < 0 )
        goto LABEL_161;
    }
    v59 = v97[13];
    if ( v59 )
    {
      v60 = *(_WORD *)v39;
      if ( *(_WORD *)v39 == 1 )
      {
        v61 = (v59 + 3) & 0xFFFFFFFC;
        Size = 4 * v61;
        v92 = operator new(4 * v61);
        if ( !v92 )
          goto LABEL_159;
        v62 = (char *)v92;
        memset(v92, 0, Size);
        v63 = v61 >> 2;
        if ( v63 )
        {
          v64 = v62 + 8;
          do
          {
            *v64 = 1;
            v64 += 4;
            --v63;
          }
          while ( v63 );
        }
        v65 = v97;
        for ( j = 0; j < v65[13]; ++j )
        {
          v66 = 4 * j;
          v67 = *(double **)(4 * j + v65[14]);
          if ( v67 )
          {
            if ( *(_DWORD *)v67 )
            {
              if ( *(_DWORD *)v67 == 1 || *(_DWORD *)v67 == 2 )
              {
                *(_DWORD *)&v62[v66] = *((_DWORD *)v67 + 2);
              }
              else if ( *(_DWORD *)v67 == 3 )
              {
                v65 = v97;
                *(_DWORD *)&v62[v66] = (__int64)v67[1];
              }
            }
            else
            {
              *(_DWORD *)&v62[v66] = *((_DWORD *)v67 + 2) != 0;
            }
          }
        }
        v3 = sub_68024C(v90, v62, Size, 11, (_DWORD *)v102 + 3);
        if ( v3 < 0 )
          goto LABEL_161;
        v92 = 0;
        goto LABEL_149;
      }
      if ( v60 == 2 )
      {
        v68 = 4 * ((v59 + 3) & 0xFFFFFFFC);
        v94 = v68;
        v91 = operator new(v68);
        if ( !v91 )
          goto LABEL_159;
        v69 = (char *)v91;
        memset(v91, 0, v68);
        v70 = v97;
        v71 = 0;
        if ( v97[13] )
        {
          while ( 2 )
          {
            v72 = *(double **)(4 * v71 + v70[14]);
            if ( !v72 )
              goto LABEL_135;
            if ( *(_DWORD *)v72 )
            {
              switch ( *(_DWORD *)v72 )
              {
                case 1:
                  v73 = (double)*((int *)v72 + 2);
                  break;
                case 2:
                  v89 = *((_DWORD *)v72 + 2);
                  v73 = (double)v89;
                  break;
                case 3:
                  v73 = v72[1];
                  break;
                default:
LABEL_135:
                  if ( (unsigned int)++v71 >= v70[13] )
                    goto LABEL_136;
                  continue;
              }
            }
            else if ( *((_DWORD *)v72 + 2) )
            {
              v73 = 1.0;
            }
            else
            {
              v73 = 0.0;
            }
            break;
          }
          *(float *)&v69[4 * v71] = v73;
          goto LABEL_135;
        }
LABEL_136:
        v3 = sub_68024C(v90, v69, v94, 11, (_DWORD *)v102 + 3);
        if ( v3 < 0 )
          goto LABEL_161;
        v91 = 0;
LABEL_149:
        v39 = v102;
        v38 = v103;
        goto LABEL_150;
      }
      if ( !v60 )
        break;
    }
LABEL_150:
    ++i;
    v38 += 4;
    v39 += 20;
    v103 = v38;
    v102 = v39;
    if ( i >= v100 )
      goto LABEL_151;
  }
  v94 = 4 * v97[5];
  v74 = v94;
  v93 = operator new(v94);
  if ( !v93 )
    goto LABEL_159;
  v75 = v74;
  v76 = (char *)v93;
  memset(v93, 0, v75);
  v77 = v97;
  v7 = v97[5] == 0;
  j = 0;
  if ( !v7 )
  {
    do
    {
      v78 = 4 * j;
      v79 = *(double **)(4 * j + v77[15]);
      if ( v79 )
      {
        if ( *(_DWORD *)v79 <= 2u )
        {
          *(_DWORD *)&v76[v78] = *((_DWORD *)v79 + 2) != 0;
        }
        else if ( *(_DWORD *)v79 == 3 )
        {
          *(_DWORD *)&v76[v78] = v79[1] != 0.0;
        }
      }
      ++j;
    }
    while ( j < v77[5] );
  }
  v3 = sub_68024C(v90, v76, v94, 11, (_DWORD *)v102 + 3);
  if ( v3 >= 0 )
  {
    v93 = 0;
    goto LABEL_149;
  }
LABEL_161:
  j__free(Block);
  j__free(v104);
  j__free(v91);
  j__free(v93);
  j__free(v92);
  j__free(v98);
  sub_680214(v90);
  return v3;
}
