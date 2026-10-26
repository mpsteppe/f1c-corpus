int __thiscall sub_6666AE(int this, unsigned int a2, _DWORD *a3, _DWORD *a4, int *a5, unsigned int a6)
{
  unsigned int v7; // esi
  unsigned int v8; // eax
  bool v9; // zf
  void *v11; // edx
  unsigned int i; // ecx
  int v13; // eax
  _DWORD *v14; // edx
  int m; // esi
  int v16; // eax
  bool v17; // zf
  int v18; // ecx
  unsigned int v19; // eax
  int j; // edx
  unsigned int v21; // eax
  int v22; // ecx
  unsigned int v23; // ecx
  int v24; // ecx
  unsigned int k; // eax
  int v26; // edx
  char *v27; // edx
  unsigned int n; // eax
  int v29; // edi
  __int64 v31; // [esp-8h] [ebp-2Ch]
  double v32; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v33[12]; // [esp+14h] [ebp-10h] BYREF
  void *Block; // [esp+20h] [ebp-4h]
  unsigned int v35; // [esp+3Ch] [ebp+18h]

  v7 = 0;
  v8 = 1;
  v9 = a6 == 0;
  Block = 0;
  *(_DWORD *)&v33[8] = 1;
  *(_DWORD *)&v33[4] = 1;
  if ( a6 )
  {
    do
    {
      if ( sub_6640D2((_DWORD *)this, a4[v7], &v32) < 0 )
        break;
      if ( v32 != 0.0 )
        *(_DWORD *)&v33[8] = 0;
      if ( v32 != 1.0 )
        *(_DWORD *)&v33[4] = 0;
      ++v7;
    }
    while ( v7 < a6 );
    v8 = 1;
    v9 = v7 == a6;
  }
  if ( v9 && *(_QWORD *)&v33[4] )
  {
    v11 = operator new(4 * a6);
    Block = v11;
    if ( v11 )
    {
      for ( i = 0; i < a6; ++i )
      {
        if ( *(_DWORD *)&v33[8] )
          v13 = *(_DWORD *)(this + 36);
        else
          v13 = *(_DWORD *)(this + 32);
        *((_DWORD *)v11 + i) = v13;
      }
      m = sub_6624CC(a3, a6);
      if ( m < 0 )
        goto LABEL_69;
      v16 = sub_6641F3((_DWORD *)this, a2, a6 & 0xFFFFF | 0x10000000, (int)a3, v14, 0);
      goto LABEL_67;
    }
LABEL_58:
    m = -2147024882;
    goto LABEL_69;
  }
  v17 = a6 == 1;
  if ( a6 > 1 )
  {
    do
    {
      if ( *a5 != a5[v8] )
        break;
      ++v8;
    }
    while ( v8 < a6 );
    v17 = v8 == a6;
  }
  if ( !v17 || sub_6640D2((_DWORD *)this, *a5, (double *)v33) < 0 )
    goto LABEL_57;
  *(_DWORD *)&v33[8] = (__int64)*(double *)v33;
  if ( fabs(*(double *)v33 - (double)*(int *)&v33[8]) < 0.000001 )
  {
    v18 = 0;
    v19 = abs32(*(int *)&v33[8]);
    v35 = v19;
    for ( j = 0; v19; v19 >>= 1 )
    {
      ++v18;
      j += v19 & 1;
    }
    v21 = (v18 != 0 ? v18 - 1 : 0) + (j != 0 ? j - 1 : 0);
    if ( *(int *)&v33[8] < 0 )
      v21 += a6;
    v22 = *(_DWORD *)(this + 8);
    if ( (*(_BYTE *)(v22 + 108) & 0x40) != 0 && (*(_BYTE *)(this + 20) & 0x20) != 0 )
    {
      v23 = a6 + 1;
    }
    else
    {
      v24 = *(_DWORD *)(v22 + 100);
      if ( !v24 )
        v24 = 1;
      v23 = 2 * a6 * v24 + 1;
    }
    if ( v21 <= v23 )
    {
      Block = operator new(4 * a6);
      if ( !Block )
        goto LABEL_58;
      for ( k = 0; k < a6; ++k )
        *((_DWORD *)Block + k) = *(_DWORD *)(this + 32);
      m = sub_6624CC(a3, a6);
      if ( m < 0 )
        goto LABEL_69;
      *(_DWORD *)&v33[4] = a6 & 0xFFFFF;
      m = sub_6641F3((_DWORD *)this, a2, a6 & 0xFFFFF | 0x10000000, (int)a3, Block, 0);
      if ( m < 0 )
        goto LABEL_69;
      if ( v35 )
      {
        m = sub_6624CC(Block, a6);
        if ( m >= v26 )
        {
          HIDWORD(v31) = v26;
          LODWORD(v31) = v26;
          for ( m = sub_6641F3((_DWORD *)this, a2, a6 & 0xFFFFF | 0x10000000, (int)Block, a4, v31);
                m >= 0;
                m = sub_6641F3(
                      (_DWORD *)this,
                      a2,
                      *(_DWORD *)&v33[4] | 0x20500000,
                      (int)Block,
                      Block,
                      (unsigned int)Block | 0x400000000LL) )
          {
            if ( (v35 & 1) != 0 )
            {
              m = sub_6641F3((_DWORD *)this, a2, *(_DWORD *)&v33[4] | 0x20500000, (int)a3, a3, (unsigned int)Block);
              if ( m < 0 )
                break;
            }
            v35 >>= 1;
            if ( !v35 )
              goto LABEL_50;
          }
        }
        goto LABEL_69;
      }
LABEL_50:
      if ( *(int *)&v33[8] < 0 )
      {
        v16 = sub_6641F3((_DWORD *)this, a2, *(_DWORD *)&v33[4] | 0x10300000, (int)a3, a3, 0);
        goto LABEL_67;
      }
LABEL_68:
      m = 0;
      goto LABEL_69;
    }
    goto LABEL_57;
  }
  if ( fabs(fabs(*(long double *)v33) - 0.5) >= 0.000001 )
  {
LABEL_57:
    Block = operator new(8 * a6);
    if ( !Block )
      goto LABEL_58;
    v27 = (char *)Block;
    for ( n = 0; n < 2; ++n )
    {
      *(_DWORD *)&v33[4 * n] = v27;
      v27 += 4 * a6;
    }
    m = sub_6624CC(*(void **)v33, a6);
    if ( m < 0 )
      goto LABEL_69;
    m = sub_6624CC(*(void **)&v33[4], a6);
    if ( m < 0 )
      goto LABEL_69;
    m = sub_6624CC(a3, a6);
    if ( m < 0 )
      goto LABEL_69;
    v29 = a6 & 0xFFFFF;
    m = sub_6641F3((_DWORD *)this, a2, v29 | 0x10600000, *(int *)v33, a4, 0);
    if ( m < 0 )
      goto LABEL_69;
    m = sub_6641F3((_DWORD *)this, a2, v29 | 0x20500000, *(int *)&v33[4], a5, *(unsigned int *)v33);
    if ( m < 0 )
      goto LABEL_69;
    v16 = sub_6641F3((_DWORD *)this, a2, v29 | 0x10500000, (int)a3, *(_DWORD **)&v33[4], 0x400000000LL);
    goto LABEL_67;
  }
  m = sub_6624CC(a3, a6);
  if ( m < 0 )
    goto LABEL_69;
  m = sub_6641F3((_DWORD *)this, a2, a6 & 0xFFFFF | 0x10700000, (int)a3, a4, 0x400000000LL);
  if ( m < 0 )
    goto LABEL_69;
  if ( *(double *)v33 < 0.0 )
    goto LABEL_68;
  v16 = sub_6641F3((_DWORD *)this, a2, a6 & 0xFFFFF | 0x10300000, (int)a3, a3, 0x400000000LL);
LABEL_67:
  m = v16;
  if ( v16 >= 0 )
    goto LABEL_68;
LABEL_69:
  j__free(Block);
  return m;
}
