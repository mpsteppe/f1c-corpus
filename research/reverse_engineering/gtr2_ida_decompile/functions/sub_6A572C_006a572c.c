int __thiscall sub_6A572C(_DWORD *this, int a2, _DWORD *a3, int a4, unsigned int a5, int a6, unsigned int a7)
{
  unsigned int v7; // edx
  _DWORD **v9; // edi
  _DWORD *v10; // eax
  unsigned int v11; // ecx
  double *v12; // ecx
  _DWORD *v13; // edi
  int v14; // eax
  unsigned int v15; // ecx
  int *v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // eax
  unsigned int *v19; // edi
  int v20; // esi
  _DWORD *v21; // eax
  double *v22; // eax
  int v23; // eax
  int v24; // esi
  int v25; // eax
  _DWORD *v26; // eax
  int v27; // ecx
  bool v28; // cf
  unsigned int v29; // esi
  unsigned int i; // esi
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  double **v34; // esi
  int result; // eax
  double *v36; // eax
  int v37; // esi
  _DWORD *v38; // edi
  unsigned int v39; // ecx
  int v40; // esi
  _DWORD *v41; // ecx
  int v42; // eax
  int v43; // edx
  unsigned int v44; // ecx
  int v45; // eax
  _DWORD *v46; // eax
  _DWORD *v47; // ecx
  int v48; // eax
  unsigned int v49; // ecx
  double *v50; // eax
  int v51; // edx
  int v52; // ecx
  unsigned int v53; // eax
  int *v54; // ecx
  int v55; // esi
  bool v56; // zf
  int v57; // eax
  unsigned int v58; // ecx
  double *v59; // eax
  void **v60; // esi
  _DWORD *v61; // eax
  char *v62; // eax
  unsigned int v63; // esi
  int v64; // eax
  _DWORD *v65; // edx
  int v66; // [esp-4h] [ebp-60h]
  char *v67; // [esp+0h] [ebp-5Ch]
  int v68; // [esp+4h] [ebp-58h]
  char *v69; // [esp+4h] [ebp-58h]
  int v70[10]; // [esp+14h] [ebp-48h] BYREF
  int v71[4]; // [esp+3Ch] [ebp-20h] BYREF
  double *v72; // [esp+4Ch] [ebp-10h]
  _DWORD **v73; // [esp+50h] [ebp-Ch]
  double *k; // [esp+54h] [ebp-8h]
  int j; // [esp+58h] [ebp-4h]
  int v76; // [esp+74h] [ebp+18h]
  int v77; // [esp+78h] [ebp+1Ch]
  _DWORD *v78; // [esp+78h] [ebp+1Ch]
  int v79; // [esp+78h] [ebp+1Ch]

  v7 = a5;
  j = 0;
  memset(v70, 0, 0x18u);
  if ( a5 + a7 )
  {
    v9 = (_DWORD **)(a6 - 4 * a5);
    v73 = v9;
    do
    {
      if ( j >= v7 )
        v10 = *v9;
      else
        v10 = *(_DWORD **)(a4 + 4 * j);
      if ( v10 )
      {
        v11 = *v10 & 0xFFF00000;
        if ( v11 )
        {
          if ( v10[9] != 1
            && (v11 != 1610612736
             && v11 != 1615855616
             && v11 != 1621098496
             && v11 != 1626341376
             && v11 != 285212672
             && v11 != 1925185536
             && v11 != 1926234112
             || j >= v7) )
          {
            v12 = (double *)v10[1];
            k = 0;
            v72 = v12;
            if ( v12 )
            {
              v13 = (_DWORD *)v10[2];
              do
              {
                v14 = *(_DWORD *)(this[5] + 4 * *v13);
                if ( *(_DWORD *)(v14 + 4) == this[32] )
                {
                  v15 = *(unsigned __int8 *)(v14 + 109);
                  if ( v15 > 5 )
                    break;
                  if ( *(_BYTE *)(v14 + 108) == 3 )
                  {
                    v16 = &v70[v15];
                    if ( j < a5 )
                    {
                      v18 = *(_DWORD *)(v14 + 16) + 1;
                      if ( v18 > *v16 )
                        *v16 = v18;
                    }
                    else
                    {
                      v17 = *(_DWORD *)(v14 + 16) + 1;
                      if ( v17 > *v16 && *(_DWORD *)(v14 + 60) )
                        *v16 = v17;
                    }
                  }
                }
                k = (double *)((char *)k + 1);
                ++v13;
              }
              while ( k < v72 );
              v7 = a5;
              v9 = v73;
            }
          }
        }
      }
      ++j;
      v73 = ++v9;
    }
    while ( j < a5 + a7 );
  }
  j = 0;
  if ( this[15] )
  {
    v19 = (unsigned int *)v70;
    v72 = (double *)(a2 - (_DWORD)v70);
    do
    {
      v20 = *v19;
      if ( *v19 )
      {
        v21 = (_DWORD *)sub_681186(116);
        if ( v21 )
          v22 = (double *)sub_680CEC(v21);
        else
          v22 = 0;
        k = v22;
        if ( !v22 )
          return -2147024882;
        v23 = sub_6811D1((char *)v22, v20 & 0xFFFFF | 0x72100000, v20, v20, 0);
        if ( v23 < 0 )
        {
LABEL_54:
          v37 = v23;
          goto LABEL_57;
        }
        v24 = 0;
        if ( *v19 )
        {
          while ( 1 )
          {
            v25 = sub_681AAA(this, this[34], j, v24, 0.0);
            v71[v24] = v25;
            if ( v25 == -1 )
              break;
            *(_DWORD *)(*((_DWORD *)k + 4) + 4 * v24) = v25;
            v26 = *(_DWORD **)(this[5] + 4 * v25);
            v27 = j;
            v26[15] = 0;
            v26[14] = -1;
            v28 = ++v24 < *v19;
            v26[27] = (v27 << 8) | 3;
            if ( !v28 )
              goto LABEL_42;
          }
LABEL_55:
          v37 = -2147024882;
LABEL_57:
          sub_66238F(k, 1);
          return v37;
        }
LABEL_42:
        v29 = *v19;
        v23 = sub_6A52C6(this, a4, a5, 3, j, *v19, (int)v71);
        if ( v23 < 0 )
          goto LABEL_54;
        v23 = sub_6A541D(this, a6, a7, 3, j, v29, (int)v71);
        if ( v23 < 0 )
          goto LABEL_54;
        for ( i = 0; i < *v19; *(_DWORD *)(*((_DWORD *)k + 2) + 4 * i++) = v31 )
        {
          v31 = sub_681AAA(this, this[32], j, i, 0.0);
          v70[i + 6] = v31;
          if ( v31 == -1 )
            goto LABEL_55;
          v32 = *(_DWORD *)(this[5] + 4 * v31);
          v33 = j;
          *(_DWORD *)(v32 + 60) = 0;
          *(_DWORD *)(v32 + 108) = (v33 << 8) | 3;
        }
        v34 = (double **)((char *)v19 + (_DWORD)v72);
        if ( *(unsigned int *)((char *)v19 + (_DWORD)v72) )
        {
          sub_686791(
            (int)this,
            0,
            4516,
            "cannot read from a texcoord which was used as input in a sampler",
            (unsigned __int8)this[50]);
          v37 = -2147467259;
          goto LABEL_57;
        }
        result = sub_681997((int)this, k);
        if ( result < 0 )
          return result;
        *v34 = k;
      }
      ++j;
      ++v19;
    }
    while ( (unsigned int)j < this[15] );
  }
  v76 = 1;
  while ( 1 )
  {
    j = 0;
    if ( a5 )
      break;
LABEL_122:
    if ( (unsigned int)++v76 >= 3 )
    {
      for ( j = 0; (unsigned int)j < this[15]; ++j )
      {
        v60 = (void **)(a2 + 4 * j);
        if ( !*v60 )
        {
          v61 = (_DWORD *)sub_681186(116);
          if ( v61 )
            v62 = (char *)sub_680CEC(v61);
          else
            v62 = 0;
          *v60 = v62;
          if ( !v62 )
            return -2147024882;
          sub_6811D1(v62, 0, 0, 0, 0);
          sub_681997((int)this, *v60);
        }
      }
      v63 = 0;
      for ( *a3 = this[15]; v63 < a5; ++v63 )
      {
        v64 = a4 + 4 * v63;
        v65 = *(_DWORD **)v64;
        if ( *(_DWORD *)v64 && v65[9] != 1 && *v65 )
        {
          *(_DWORD *)(a2 + 4 * (*a3)++) = *(_DWORD *)v64;
          *(_DWORD *)(*(_DWORD *)v64 + 36) = 1;
        }
      }
      return 0;
    }
  }
  v36 = (double *)(a4 - 4 * a5);
  for ( k = v36; ; v36 = k )
  {
    if ( (unsigned int)j >= 0x200 )
    {
      sub_686791((int)this, 0, 4514, "program too big");
      return -2147467259;
    }
    v38 = j >= a5 ? *(_DWORD **)v36 : *(_DWORD **)(a4 + 4 * j);
    if ( v38 )
    {
      if ( v38[9] != 1 )
      {
        v39 = *v38 & 0xFFF00000;
        if ( v39 == 1610612736
          || v39 == 1615855616
          || v39 == 1621098496
          || v39 == 1626341376
          || v39 == 285212672
          || v39 == 1925185536
          || v39 == 1926234112 )
        {
          break;
        }
      }
    }
LABEL_121:
    ++j;
    k = (double *)((char *)k + 4);
    if ( j >= a5 )
      goto LABEL_122;
  }
  v40 = *v38 & 0xFFFFF;
  if ( v39 == 285212672 )
    v40 = 0;
  v41 = (_DWORD *)v38[2];
  v42 = this[5];
  v43 = *(_DWORD *)(v42 + 4 * v41[v40]);
  if ( v40 )
    v40 = *(_DWORD *)(v42 + 4 * *v41);
  v56 = *(_DWORD *)(v43 + 4) == this[32];
  v72 = *(double **)(v43 + 4);
  if ( v56 && (unsigned __int16)this[50] != 260 && v76 == 1 )
  {
    v44 = *(unsigned __int8 *)(v43 + 109);
    v77 = v44;
    if ( v44 >= 6 )
      goto LABEL_122;
    if ( v40 )
    {
      v45 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(v40 + 4));
      if ( (*(_WORD *)(v45 + 4) & 0x840) != 0 )
      {
        if ( v44 != *(_DWORD *)(v40 + 12) )
        {
          v68 = (unsigned __int8)this[50];
          if ( (*(_BYTE *)(v45 + 5) & 8) != 0 )
            v67 = "cannot bind sampler to user specified stage. In ps_1_%i, samplers must be bound to the same stage as their TEXCOORD";
          else
            v67 = "cannot bind sampler to sampler array. In ps_1_%i, samplers must be bound to the same stage as their TEXCOORD";
          v66 = 4515;
          goto LABEL_130;
        }
      }
      else
      {
        *(_DWORD *)(v40 + 12) = v44;
      }
    }
    v46 = &this[v44 + 265];
    if ( *v46 != -1 || (v47 = (_DWORD *)(a2 + 4 * v44), v56 = *v47 == 0, v73 = (_DWORD **)v47, !v56) )
    {
      v68 = (unsigned __int8)this[50];
      v67 = "cannot read from same texcoord. In ps_1_%i, each sampler must have a unique TEXCOORD";
      v66 = 4516;
LABEL_130:
      sub_686791((int)this, v38[15], v66, v67, v68);
      return -2147467259;
    }
    if ( v40 )
    {
      this[v77 + 259] = *(_DWORD *)(v40 + 4);
      *v46 = *(_DWORD *)v38[2];
      v48 = sub_681AAA(this, *(_DWORD *)(v40 + 4), *(_DWORD *)(v40 + 12), *(_DWORD *)(v40 + 16), *(double *)(v40 + 32));
      v49 = 0;
      if ( (*v38 & 0xFFFFF) != 0 )
      {
        do
          *(_DWORD *)(v38[2] + 4 * v49++) = v48;
        while ( v49 < (*v38 & 0xFFFFFu) );
      }
      v72 = *(double **)(this[5] + 4 * v48);
      sub_6815D6(v72, v40);
      v50 = v72;
      *((_DWORD *)v72 + 3) = v77;
      v47 = v73;
      *(_DWORD *)(v40 + 64) = 1;
      *((_DWORD *)v50 + 16) = 0;
    }
    *v47 = v38;
    goto LABEL_120;
  }
  if ( v76 != 2 )
    goto LABEL_121;
  if ( !v40 )
    goto LABEL_104;
  v51 = *(_DWORD *)(v40 + 4);
  v52 = *(_DWORD *)(this[4] + 4 * v51);
  v53 = *(_DWORD *)(v40 + 12);
  v73 = (_DWORD **)v52;
  if ( v53 >= 6 )
    goto LABEL_122;
  if ( (*(_WORD *)(v52 + 4) & 0x840) == 0 )
  {
LABEL_104:
    v53 = 0;
    v56 = this[19] == 0;
    if ( this[19] )
    {
      v78 = this + 265;
      do
      {
        if ( !*(_DWORD *)(a2 + 4 * v53) && (*v78 == *(_DWORD *)v38[2] || *v78 == -1) )
          break;
        ++v78;
        ++v53;
      }
      while ( v53 < this[19] );
      v56 = v53 == this[19];
    }
    if ( v56 )
    {
      sub_686791((int)this, 0, 4519, "too many texture loads and reads from texcoords");
      return -2147467259;
    }
    v79 = v53;
    if ( v40 )
    {
      if ( (unsigned __int16)this[50] == 260 || v72 == (double *)this[32] )
      {
        this[v53 + 259] = *(_DWORD *)(v40 + 4);
        this[v53 + 265] = *(_DWORD *)v38[2];
      }
      v57 = sub_681AAA(this, *(_DWORD *)(v40 + 4), *(_DWORD *)(v40 + 12), *(_DWORD *)(v40 + 16), *(double *)(v40 + 32));
      v58 = 0;
      if ( (*v38 & 0xFFFFF) != 0 )
      {
        do
          *(_DWORD *)(v38[2] + 4 * v58++) = v57;
        while ( v58 < (*v38 & 0xFFFFFu) );
      }
      v72 = *(double **)(this[5] + 4 * v57);
      sub_6815D6(v72, v40);
      v59 = v72;
      *((_DWORD *)v72 + 3) = v79;
      *(_DWORD *)(v40 + 64) = 1;
      *((_DWORD *)v59 + 16) = 0;
      v53 = v79;
    }
    goto LABEL_119;
  }
  v54 = &this[v53 + 265];
  v55 = *v54;
  if ( *v54 == -1 )
  {
    if ( !*(_DWORD *)(a2 + 4 * v53) )
    {
      this[v53 + 259] = v51;
      *v54 = *(_DWORD *)v38[2];
LABEL_119:
      *(_DWORD *)(a2 + 4 * v53) = v38;
LABEL_120:
      *(_DWORD *)(*(_DWORD *)(a4 + 4 * j) + 36) = 1;
      goto LABEL_121;
    }
    v55 = -1;
  }
  if ( v55 == *(_DWORD *)v38[2] )
  {
    if ( *(_DWORD *)(a2 + 4 * v53) )
    {
      sub_686791(
        (int)this,
        0,
        4518,
        "cannot perform texture lookup twice from a user bound or similar array access sampler in ps_1_%i",
        (unsigned __int8)this[50]);
      return -2147467259;
    }
    goto LABEL_119;
  }
  if ( (*((_BYTE *)v73 + 5) & 8) != 0 )
    v69 = "conflicting user defined sampler bindings. If two samplers have the same user binding, they cannot both be use"
          "d in the same shader";
  else
    v69 = "conflicting sampler array bindings";
  sub_686791((int)this, 0, 4517, v69);
  return -2147467259;
}
