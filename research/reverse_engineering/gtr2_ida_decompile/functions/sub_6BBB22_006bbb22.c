int __thiscall sub_6BBB22(_DWORD *this, int a2, unsigned int a3, int a4, int a5, char a6)
{
  unsigned int v6; // ebx
  bool v8; // zf
  _DWORD *v9; // eax
  int v10; // edx
  unsigned int v11; // edi
  int v12; // ecx
  unsigned int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // edi
  int v17; // eax
  int v18; // ebx
  int v19; // ebx
  char *i; // ebx
  char v21; // bl
  unsigned int v22; // eax
  int *v23; // ebx
  char *v24; // eax
  bool v25; // cf
  int v26; // eax
  int v27; // edx
  int v28; // edi
  int v29; // ecx
  void *v30; // eax
  unsigned int v31; // ecx
  int v32; // eax
  int v33; // edx
  int v34; // edx
  char *v35; // edi
  int v36; // ecx
  unsigned int v37; // eax
  int v38; // edx
  int *v39; // eax
  int v40; // eax
  unsigned int j; // edx
  int v42; // edx
  unsigned int v43; // edi
  _DWORD *v44; // edx
  int v45; // ebx
  unsigned int k; // ecx
  int v47; // eax
  unsigned int m; // ecx
  int v49; // eax
  int v50; // edi
  int v51; // eax
  int v52; // eax
  void *v53; // edx
  int v54; // eax
  unsigned int v55; // ecx
  int *v56; // edi
  unsigned int n; // edx
  int v58; // eax
  int v59; // ecx
  int v60; // ecx
  int v62; // [esp-4h] [ebp-28h]
  void *v63; // [esp+Ch] [ebp-18h]
  int v64; // [esp+10h] [ebp-14h] BYREF
  void *v65; // [esp+14h] [ebp-10h]
  char *String; // [esp+18h] [ebp-Ch]
  void *Block; // [esp+1Ch] [ebp-8h]
  int v68; // [esp+20h] [ebp-4h]
  int v69; // [esp+30h] [ebp+Ch]

  v6 = 0;
  v8 = this[1] == 0;
  v65 = 0;
  v63 = 0;
  if ( !v8 )
  {
    do
    {
      v9 = *(_DWORD **)(this[4] + 4 * v6);
      v10 = v9[1];
      v9[4] = 0;
      if ( (v10 & 0x400) == 0 )
      {
        v11 = 0;
        for ( v9[2] = 0; v11 < this[2]; ++v11 )
        {
          v12 = *(_DWORD *)(this[5] + 4 * v11);
          if ( *(_DWORD *)(v12 + 4) == v6 )
          {
            v13 = *(_DWORD *)(v12 + 12) + 1;
            if ( v13 > v9[2] )
              v9[2] = v13;
          }
        }
        if ( (v10 & 0x100) != 0 && (v10 & 0x800) == 0 )
          v9[1] = v10 & 0xFFFFFFBF;
        v14 = v9[1];
        if ( (v14 & 0x10) != 0 && (v14 & 0xA00) == 0 )
          v9[1] = v14 & 0xFFFFFFBF;
        v15 = v9[1];
        if ( (v15 & 0x80u) != 0 && (v15 & 0x800) == 0 && v9[2] == 1 )
          v9[1] = v15 & 0xFFFFFFBF;
      }
      ++v6;
    }
    while ( v6 < this[1] );
  }
  Block = operator new(8 * a3);
  if ( !Block )
    goto LABEL_131;
  v68 = 0;
  memset(Block, 0, 8 * a3);
  if ( this[1] )
  {
    while ( 1 )
    {
      v16 = *(_DWORD *)(this[4] + 4 * v68);
      v17 = *(_DWORD *)(v16 + 4);
      if ( (a4 & v17) == a4 && (v17 & a5) == 0 && (v17 & 0x40) != 0 && (v17 & 0x800) != 0 && *(_DWORD *)(v16 + 8) )
      {
        v62 = v68;
        *(_DWORD *)(v16 + 16) = -1;
        v18 = sub_6BBA7B(this, *(_BYTE **)v16, &v64, a6, v62);
        if ( v18 < 0 )
          goto LABEL_150;
        v19 = v64;
        if ( v64 )
        {
          if ( a6 == sub_635155(*(char *)v64) )
          {
            String = (char *)(v19 + 1);
            if ( isdigit(*(char *)(v19 + 1)) )
            {
              for ( i = (char *)(v19 + 2); isdigit(*i); ++i )
                ;
              v21 = *i;
              if ( !v21 || v21 == 59 )
                *(_DWORD *)(v16 + 16) = j__atol(String);
            }
          }
        }
        if ( *(_DWORD *)(v16 + 16) >= a3 )
        {
          v38 = 0;
          if ( !this[2] )
            goto LABEL_72;
          v39 = (int *)this[5];
          v69 = this[2];
          do
          {
            if ( *(_DWORD *)(*v39 + 4) == v68 )
              v38 = *v39;
            ++v39;
            --v69;
          }
          while ( v69 );
          if ( v38 )
            v40 = *(_DWORD *)(v38 + 96);
          else
LABEL_72:
            v40 = 0;
          sub_686791(
            (int)this,
            v40,
            4509,
            "invalid register semantic '%s', or variable must be bound to multiple register banks (%c register binding required)",
            *(const char **)v16,
            a6);
          goto LABEL_142;
        }
        String = 0;
        if ( *(_DWORD *)(v16 + 8) )
          break;
      }
LABEL_42:
      if ( (unsigned int)++v68 >= this[1] )
        goto LABEL_43;
    }
    while ( 1 )
    {
      v22 = (unsigned int)&String[*(_DWORD *)(v16 + 16)];
      if ( v22 >= a3 )
        break;
      v23 = (int *)((char *)Block + 8 * v22);
      if ( *v23 )
        sub_686791(
          (int)this,
          0,
          4500,
          "overlapping register semantics not yet implemented '%c%u'",
          a6,
          &String[*(_DWORD *)(v16 + 16)]);
      *v23 = v68;
      v24 = String;
      v23[1] = (int)String;
      v25 = (unsigned int)++v24 < *(_DWORD *)(v16 + 8);
      String = v24;
      if ( !v25 )
        goto LABEL_42;
    }
    if ( a6 == 98 )
      goto LABEL_139;
    if ( a6 == 99 )
      goto LABEL_135;
    if ( a6 != 105 )
    {
      if ( a6 == 115 )
      {
        sub_686791((int)this, 0, 4510, "maximum sampler register index exceeded");
      }
      else if ( a6 == 118 )
      {
LABEL_133:
        sub_686791((int)this, 0, 4506, "maximum input register index exceeded");
      }
      goto LABEL_142;
    }
LABEL_130:
    sub_686791((int)this, 0, 4551, "maximum iterator register index exceeded - Try reducing number of loops");
    goto LABEL_142;
  }
LABEL_43:
  v26 = this[1];
  v68 = 0;
  if ( v26 )
  {
    v27 = this[4];
    v28 = v26;
    do
    {
      v29 = *(_DWORD *)(*(_DWORD *)v27 + 4);
      if ( (a4 & v29) == a4
        && (v29 & a5) == 0
        && (v29 & 0x40) != 0
        && (v29 & 0x800) == 0
        && *(_DWORD *)(*(_DWORD *)v27 + 8) )
      {
        ++v68;
      }
      v27 += 4;
      --v28;
    }
    while ( v28 );
  }
  v30 = operator new(4 * v68);
  v31 = 0;
  v65 = v30;
  if ( !v30 )
  {
LABEL_131:
    v18 = -2147024882;
    goto LABEL_150;
  }
  v8 = this[1] == 0;
  v68 = 0;
  if ( !v8 )
  {
    do
    {
      v32 = *(_DWORD *)(this[4] + 4 * v31);
      v33 = *(_DWORD *)(v32 + 4);
      if ( (a4 & v33) == a4 && (v33 & a5) == 0 && (v33 & 0x40) != 0 && (v33 & 0x800) == 0 && *(_DWORD *)(v32 + 8) )
      {
        v34 = v68++;
        *((_DWORD *)v65 + v34) = v31;
      }
      ++v31;
    }
    while ( v31 < this[1] );
  }
  v35 = (char *)v65;
  sub_682274((int (__stdcall *)(int, int, int))sub_6BB047, (int *)v65, v68, (int)this);
  v64 = 0;
  if ( v68 )
  {
    String = v35;
    while ( 1 )
    {
      v36 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)String);
      v37 = 0;
      if ( a3 )
      {
        do
        {
          while ( v37 < a3 && *((_DWORD *)Block + 2 * v37) )
            ++v37;
          for ( j = v37; j < a3; ++j )
          {
            if ( *((_DWORD *)Block + 2 * j) )
              break;
          }
          if ( j - v37 >= *(_DWORD *)(v36 + 8) )
            break;
          v37 = j;
        }
        while ( j < a3 );
      }
      v42 = *(_DWORD *)(v36 + 8);
      if ( v42 + v37 > a3 )
        break;
      v43 = 0;
      if ( v42 )
      {
        v44 = (char *)Block + 8 * v37;
        do
        {
          v45 = *(_DWORD *)String;
          v44[1] = v43;
          *v44 = v45;
          ++v43;
          v44 += 2;
        }
        while ( v43 < *(_DWORD *)(v36 + 8) );
      }
      ++v64;
      String += 4;
      *(_DWORD *)(v36 + 16) = v37;
      if ( v64 >= (unsigned int)v68 )
        goto LABEL_94;
    }
    switch ( a6 )
    {
      case 'v':
        goto LABEL_133;
      case 'c':
        goto LABEL_135;
      case 's':
        goto LABEL_137;
      case 'b':
        goto LABEL_139;
    }
    if ( a6 != 105 )
      goto LABEL_142;
    goto LABEL_130;
  }
LABEL_94:
  for ( k = 0; k < this[2]; ++k )
  {
    v47 = *(_DWORD *)(this[5] + 4 * k);
    *(_DWORD *)(v47 + 12) += *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v47 + 4)) + 16);
  }
  for ( m = 0; m < this[1]; *(_DWORD *)(v49 + 16) = 0 )
  {
    v49 = *(_DWORD *)(this[4] + 4 * m);
    *(_DWORD *)(v49 + 8) += *(_DWORD *)(v49 + 16);
    ++m;
  }
  v8 = this[1] == 0;
  v68 = 0;
  if ( v8 )
  {
LABEL_117:
    if ( a2 != -1 )
    {
      for ( n = 0; n < this[2]; ++n )
      {
        v58 = *(_DWORD *)(this[5] + 4 * n);
        v59 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v58 + 4)) + 4);
        if ( (a4 & v59) != a4 || (v59 & a5) != 0 )
          continue;
        if ( (v59 & 0x100) == 0 )
        {
          *(_DWORD *)(v58 + 4) = a2;
          continue;
        }
        if ( (v59 & 0x40000) != 0 )
        {
          v60 = this[97];
        }
        else
        {
          if ( (v59 & 0x800) != 0 )
            continue;
          v60 = this[30];
        }
        *(_DWORD *)(v58 + 4) = v60;
      }
      *(_DWORD *)(*(_DWORD *)(this[4] + 4 * a2) + 16) = 0;
      *(_DWORD *)(*(_DWORD *)(this[4] + 4 * a2) + 8) = a3;
      if ( a2 == this[31] )
      {
        *(_DWORD *)(*(_DWORD *)(this[4] + 4 * this[30]) + 16) = 0;
        *(_DWORD *)(*(_DWORD *)(this[4] + 4 * this[30]) + 8) = a3;
      }
    }
    v18 = 0;
    goto LABEL_150;
  }
  while ( 1 )
  {
    v50 = *(_DWORD *)(this[4] + 4 * v68);
    v51 = *(_DWORD *)(v50 + 4);
    if ( (a4 & v51) != a4 )
      goto LABEL_116;
    if ( (v51 & a5) != 0 )
      goto LABEL_116;
    if ( (v51 & 0x40) != 0 )
      goto LABEL_116;
    if ( (v51 & 0x800) != 0 )
      goto LABEL_116;
    v52 = *(_DWORD *)(v50 + 8);
    if ( !v52 )
      goto LABEL_116;
    v53 = operator new(4 * v52);
    v63 = v53;
    if ( !v53 )
      goto LABEL_131;
    memset(v53, 0xFFu, 4 * *(_DWORD *)(v50 + 8));
    v8 = this[2] == 0;
    String = 0;
    if ( !v8 )
      break;
LABEL_115:
    j__free(v53);
    v63 = 0;
LABEL_116:
    if ( (unsigned int)++v68 >= this[1] )
      goto LABEL_117;
  }
  while ( 1 )
  {
    v54 = *(_DWORD *)(this[5] + 4 * (_DWORD)String);
    if ( *(_DWORD *)(v54 + 4) != v68 )
      goto LABEL_114;
    if ( *((_DWORD *)v53 + *(_DWORD *)(v54 + 12)) != -1 )
      goto LABEL_113;
    v55 = 0;
    if ( !a3 )
      break;
    do
    {
      if ( !*((_DWORD *)Block + 2 * v55) )
        break;
      ++v55;
    }
    while ( v55 < a3 );
    if ( v55 >= a3 )
      break;
    v56 = (int *)((char *)Block + 8 * v55);
    *v56 = v68;
    v56[1] = *(_DWORD *)(v54 + 12);
    *((_DWORD *)v53 + *(_DWORD *)(v54 + 12)) = v55;
LABEL_113:
    *(_DWORD *)(v54 + 12) = *((_DWORD *)v53 + *(_DWORD *)(v54 + 12));
LABEL_114:
    if ( (unsigned int)++String >= this[2] )
      goto LABEL_115;
  }
  switch ( a6 )
  {
    case 'v':
      goto LABEL_133;
    case 'c':
LABEL_135:
      sub_686791(
        (int)this,
        0,
        4507,
        "maximum constant register index exceeded - Try reducing number of constants referenced");
      break;
    case 's':
LABEL_137:
      sub_686791((int)this, 0, 4546, "maximum sampler register index exceeded");
      break;
    case 'b':
LABEL_139:
      sub_686791(
        (int)this,
        0,
        4550,
        "maximum boolean register index exceeded - Try reducing number of constant branches");
      break;
    case 'i':
      sub_686791(
        (int)this,
        0,
        4551,
        "maximum iterator register index exceeded - Try reducing number of loops and depth of loops");
      break;
  }
LABEL_142:
  v18 = -2147467259;
LABEL_150:
  j__free(Block);
  j__free(v65);
  j__free(v63);
  return v18;
}
