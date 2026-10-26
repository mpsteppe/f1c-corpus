int __thiscall sub_6AA1A9(_DWORD *this, int **a2, unsigned int a3, int a4, unsigned int a5)
{
  int *v6; // edx
  int v7; // ecx
  int v8; // esi
  _DWORD *v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  bool v12; // cf
  _DWORD *v13; // esi
  int *v14; // ecx
  double *v15; // eax
  bool v16; // zf
  int v17; // edx
  _DWORD *v18; // eax
  unsigned int v19; // esi
  unsigned int v20; // eax
  int v21; // ecx
  unsigned int v22; // esi
  int v23; // eax
  int v24; // eax
  _DWORD *v25; // eax
  char *v26; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // esi
  int v31; // edi
  int v32; // eax
  unsigned int v33; // esi
  unsigned int v34; // edx
  int v35; // ecx
  int v36; // eax
  double *v37; // edx
  int v38; // eax
  int v39; // eax
  double *v40; // eax
  int v41; // ecx
  int **v42; // edx
  unsigned int j; // eax
  int v44; // eax
  int v45; // eax
  int v46; // esi
  int v47; // ecx
  int v48; // ecx
  void **v49; // edi
  void *v50; // eax
  unsigned int k; // edi
  void *v52; // ecx
  int v54; // [esp-Ch] [ebp-A4h]
  int v55; // [esp+0h] [ebp-98h]
  char *v56; // [esp+0h] [ebp-98h]
  int v57; // [esp+0h] [ebp-98h]
  char *v58; // [esp+4h] [ebp-94h]
  _DWORD v59[3]; // [esp+14h] [ebp-84h] BYREF
  _DWORD v60[12]; // [esp+20h] [ebp-78h] BYREF
  _DWORD v61[3]; // [esp+50h] [ebp-48h] BYREF
  char ArgList[4]; // [esp+5Ch] [ebp-3Ch] BYREF
  _DWORD v63[3]; // [esp+60h] [ebp-38h] BYREF
  int v64; // [esp+6Ch] [ebp-2Ch]
  unsigned int v65; // [esp+70h] [ebp-28h]
  double *v66; // [esp+74h] [ebp-24h]
  unsigned int v67; // [esp+78h] [ebp-20h]
  int v68; // [esp+7Ch] [ebp-1Ch]
  _DWORD *v69; // [esp+80h] [ebp-18h]
  int **v70; // [esp+84h] [ebp-14h]
  _DWORD *v71; // [esp+88h] [ebp-10h]
  _DWORD *v72; // [esp+8Ch] [ebp-Ch]
  unsigned int v73; // [esp+90h] [ebp-8h]
  unsigned int i; // [esp+94h] [ebp-4h]

  v65 = 0;
  memset(v61, 0, sizeof(v61));
  if ( !a3 )
  {
LABEL_83:
    v30 = 0;
    goto LABEL_84;
  }
  v70 = a2;
  while ( 1 )
  {
    v6 = *v70;
    if ( *v70 )
    {
      v7 = *v6 & 0xFFFFF;
      v8 = v7;
      if ( (*v6 & 0xFFF00000) == 0x60000000 )
        v7 = 1;
      if ( v7 == a5 && (*v6 & 0xFFF00000) != 0x11000000 )
      {
        v73 = 0;
        i = 0;
        if ( !a5 )
          break;
        v72 = (_DWORD *)(v6[2] + 4 * v8);
        do
        {
          v9 = (_DWORD *)sub_6A9A7C(this, this[139], this[136], (int)v72, 1u, 0);
          v10 = i;
          v71 = v9;
          v60[i + 9] = v9;
          if ( v9 && *v9 == 1342177283 )
          {
            sub_6A9B74(this, this[139], this[136], v71, &v63[v10], &v60[v10 + 3], &v59[v10], 0, 0);
            v69 = &v60[v10];
            sub_6A9B74(this, a4, 4u, v71, &v60[v10], &v60[v10 + 6], ArgList, 1, 0);
            if ( !v59[v10] || *v69 != v60[0] || !*(_DWORD *)ArgList )
              v73 = 1;
          }
          else
          {
            v73 = 1;
          }
          ++i;
          ++v72;
        }
        while ( i < a5 );
        if ( !v73 )
          break;
      }
    }
LABEL_82:
    ++v65;
    ++v70;
    if ( v65 >= a3 )
      goto LABEL_83;
  }
  i = 0;
  if ( !a5 )
  {
LABEL_61:
    for ( i = 0; i < a5; ++i )
    {
      v71 = 0;
      v31 = v61[i];
      v69 = (_DWORD *)v60[i + 9];
      v72 = (_DWORD *)v59[i];
      v32 = 4 * v60[i + 3];
      v33 = 12;
      v67 = 4 * v60[i + 6];
      v68 = v32;
      do
      {
        v34 = v67;
        *(_DWORD *)(v33 + *(_DWORD *)(v31 + 8) - 12) = *(_DWORD *)(v68 + v69[2]);
        *(_DWORD *)(v33 + *(_DWORD *)(v31 + 8)) = *(_DWORD *)(v34 + v69[2]);
        v35 = this[5];
        v36 = *(_DWORD *)(v31 + 8);
        v37 = *(double **)(v35 + 4 * *(_DWORD *)(v36 + v33 - 12));
        v38 = *(_DWORD *)(v35 + 4 * *(_DWORD *)(v33 + v36));
        v54 = this[32];
        v73 = (unsigned int)v37;
        v64 = v38;
        v39 = sub_681AAA(this, v54, 0, 0, 0.0);
        v66 = *(double **)(this[5] + 4 * v39);
        *(_DWORD *)(v33 + *(_DWORD *)(v31 + 8)) = v39;
        sub_6815D6((double *)v73, *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v33 + v72[2] - 12)));
        v64 = *(_DWORD *)(v64 + 60);
        sub_6815D6(
          v66,
          *(_DWORD *)(this[5]
                    + 4 * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)ArgList + 8) + 4 * (**(_DWORD **)ArgList & 0xFFFFF))));
        v40 = v66;
        *((_DWORD *)v66 + 4) = v71;
        *((_DWORD *)v40 + 15) = v64;
        if ( **v70 == 1926234115 && i == a5 - 1 )
          *(_DWORD *)(v33 + *(_DWORD *)(v31 + 8) + 12) = *(_DWORD *)(v33 + (*v70)[2] + 12);
        v71 = (_DWORD *)((char *)v71 + 1);
        v68 += 4;
        v67 += 4;
        v33 += 4;
      }
      while ( v33 < 0x18 );
    }
    v41 = v60[a5 + 11];
    v42 = v70;
    for ( j = 0; j < 0x10; j += 4 )
      *(_DWORD *)(j + *(_DWORD *)(v41 + 16)) = *(_DWORD *)(j + (*v42)[4]);
    v44 = 0;
    if ( a5 )
    {
      while ( !*(_DWORD *)(a4 + 4 * v63[v44]) )
      {
        if ( ++v44 >= a5 )
          goto LABEL_73;
      }
      goto LABEL_90;
    }
LABEL_73:
    v45 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*v42)[2]);
    v46 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(v45 + 4));
    v47 = *(_DWORD *)(v46 + 4);
    if ( (v47 & 0x80u) == 0 )
    {
      sub_686791((int)this, 0, 4812, "internal error: unexpected argument type");
      goto LABEL_90;
    }
    v16 = (v47 & 0x840) == 0;
    v48 = *(_DWORD *)&ArgList[4 * a5];
    if ( v16 )
    {
      *(_DWORD *)(v45 + 12) = v48;
    }
    else if ( v48 != *(_DWORD *)(v45 + 12) )
    {
      if ( (*(_BYTE *)(v46 + 5) & 8) != 0 )
        v56 = "cannot bind sampler to user specified stage, sampler must be bound to %i";
      else
        v56 = "cannot bind sampler to sampler array, sampler must be bound to %i";
      sub_686791((int)this, a2[v65][15], 4515, v56, *(_DWORD *)&ArgList[4 * a5]);
      goto LABEL_90;
    }
    i = 0;
    if ( a5 )
    {
      while ( 1 )
      {
        v49 = (void **)&v61[i];
        v50 = *v49;
        *(_DWORD *)(a4 + 4 * v63[i]) = *v49;
        v30 = sub_681997((int)this, v50);
        if ( v30 < 0 )
          goto LABEL_84;
        *v70 = 0;
        *v49 = 0;
        if ( ++i >= a5 )
          goto LABEL_82;
      }
    }
    goto LABEL_82;
  }
  while ( 1 )
  {
    v11 = this[19];
    v12 = v11 < this[137];
    v68 = v11;
    if ( v12 )
      break;
LABEL_37:
    if ( i )
    {
      v20 = *(_DWORD *)&ArgList[4 * i];
      if ( v20 <= v60[0] || v63[i] != v20 + 1 )
      {
        sub_686791(
          (int)this,
          0,
          4525,
          "unable to match texm* because source inputs are not in appropriate texture coordinates. See ps_1_% assembly re"
          "ference for more information",
          (unsigned __int8)this[50]);
        goto LABEL_90;
      }
    }
    v21 = this[5];
    v22 = i;
    v23 = *(_DWORD *)(v60[i + 9] + 8);
    if ( *(_DWORD *)(*(_DWORD *)(v21 + 4 * *(_DWORD *)(v23 + 4 * v60[i + 3])) + 60) )
    {
      v58 = "cannot match to texm* because texm* cannot have source modifiers on input texcoord";
      v57 = 4526;
LABEL_94:
      sub_686791((int)this, 0, v57, v58);
      goto LABEL_90;
    }
    v24 = *(_DWORD *)(*(_DWORD *)(v21 + 4 * *(_DWORD *)(v23 + 4 * v60[i + 6])) + 60);
    if ( v24 && v24 != 393216 )
    {
      v58 = "cannot match to texm* because texm* can only have bx2 modifier on input texload";
      v57 = 4527;
      goto LABEL_94;
    }
    v25 = (_DWORD *)sub_681186(116);
    if ( v25 )
      v26 = (char *)sub_680CEC(v25);
    else
      v26 = 0;
    v61[v22] = v26;
    if ( !v26 )
    {
      v30 = -2147024882;
      goto LABEL_84;
    }
    if ( i != a5 - 1 )
    {
      v55 = 0;
      v29 = a5 != 3 ? 1914699779 : 1916796931;
      goto LABEL_58;
    }
    v27 = **v70;
    if ( v27 == 1926234115 )
    {
      if ( a5 != 3 )
        goto LABEL_96;
      v28 = sub_6811D1(v26, 1923088387, 9, 4, 0);
      goto LABEL_59;
    }
    if ( v27 == 1925185539 )
    {
      if ( a5 != 3 )
      {
LABEL_96:
        v30 = 1;
        goto LABEL_84;
      }
      v28 = sub_6811D1(v26, 1922039811, 6, 4, 0);
      goto LABEL_59;
    }
    v55 = 4;
    if ( a5 != 1 )
    {
      v29 = a5 != 3 ? 1915748355 : 1917845507;
LABEL_58:
      v28 = sub_6811D1(v26, v29, 6, v55, 0);
      goto LABEL_59;
    }
    v28 = sub_6811D1(v26, 1924136963, 6, 4, 0);
LABEL_59:
    v30 = v28;
    if ( v28 < 0 )
      goto LABEL_84;
    if ( ++i >= a5 )
      goto LABEL_61;
  }
  v71 = (_DWORD *)(this[140] + 4 * v11);
  while ( 1 )
  {
    v13 = (_DWORD *)*v71;
    v72 = (_DWORD *)*v71;
    if ( !v72 )
      goto LABEL_36;
    v14 = *v70;
    if ( !*v70 || !*v13 )
      goto LABEL_36;
    v15 = (double *)(*v14 & 0xFFFFF);
    v16 = *v14 == 1926234115;
    v67 = v14[1];
    if ( v16 )
      v67 = 6;
    v73 = (unsigned int)v15;
    if ( (unsigned int)v15 < v67 )
      break;
LABEL_35:
    v11 = v68;
LABEL_36:
    ++v71;
    v12 = ++v11 < this[137];
    v68 = v11;
    if ( !v12 )
      goto LABEL_37;
  }
  v69 = (_DWORD *)v13[1];
  while ( 1 )
  {
    v66 = 0;
    if ( v69 )
      break;
LABEL_34:
    if ( ++v73 >= v67 )
      goto LABEL_35;
  }
  v17 = *(_DWORD *)(v14[2] + 4 * v73);
  v18 = (_DWORD *)v13[2];
  while ( *v18 != v17 )
  {
    v13 = v72;
    if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v18) + 56) == v17 )
      break;
    v19 = v72[1];
    v66 = (double *)((char *)v66 + 1);
    ++v18;
    v12 = (unsigned int)v66 < v19;
    v69 = (_DWORD *)v19;
    v13 = v72;
    if ( !v12 )
      goto LABEL_34;
  }
  sub_686791((int)this, v13[15], 4524, "unable to match texm because computed texcoord is used in shader");
LABEL_90:
  v30 = -2147467259;
LABEL_84:
  for ( k = 0; k < 3; ++k )
  {
    v52 = (void *)v61[k];
    if ( v52 )
      sub_66238F(v52, 1);
  }
  return v30;
}
