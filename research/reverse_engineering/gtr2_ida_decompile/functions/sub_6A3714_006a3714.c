int __thiscall sub_6A3714(int *this)
{
  int v2; // edx
  int v3; // ecx
  int v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int *v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // edx
  _DWORD *v13; // eax
  int v14; // edi
  int v15; // eax
  unsigned int v16; // edx
  int *v17; // eax
  int v18; // ecx
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // edi
  void *v22; // ecx
  int v23; // eax
  int v24; // eax
  unsigned int v25; // eax
  int v26; // ecx
  int *v27; // ecx
  bool v28; // cf
  unsigned int v29; // eax
  int v30; // eax
  _DWORD *v31; // eax
  int v32; // eax
  unsigned int v33; // eax
  _DWORD *v34; // eax
  char *v35; // edi
  unsigned int i; // eax
  unsigned int v38; // [esp+1Ch] [ebp-20h]
  int v39; // [esp+20h] [ebp-1Ch]
  int v40; // [esp+24h] [ebp-18h]
  unsigned int v41; // [esp+28h] [ebp-14h]
  char *v42; // [esp+2Ch] [ebp-10h]
  int v43; // [esp+2Ch] [ebp-10h]
  _DWORD *v44; // [esp+2Ch] [ebp-10h]
  unsigned int v45; // [esp+30h] [ebp-Ch]
  unsigned int v46; // [esp+34h] [ebp-8h]
  int v47; // [esp+38h] [ebp-4h]
  int v48; // [esp+38h] [ebp-4h]
  int v49; // [esp+38h] [ebp-4h]

  v46 = 0;
  if ( this[2] )
  {
    v2 = this[34];
    v3 = this[5];
    v4 = this[2];
    do
    {
      if ( v2 == *(_DWORD *)(*(_DWORD *)v3 + 4) )
      {
        v5 = *(_DWORD *)(*(_DWORD *)v3 + 12);
        if ( v5 >= v46 )
          v46 = v5 + 1;
      }
      v3 += 4;
      --v4;
    }
    while ( v4 );
  }
  v6 = this[137];
  v38 = v6;
  v41 = this[19];
  if ( v41 >= v6 )
  {
LABEL_68:
    for ( i = this[19]; i < v6; ++i )
      **(_DWORD **)(this[140] + 4 * i) = 0;
    return 0;
  }
  while ( 1 )
  {
    v7 = *(unsigned int **)(this[140] + 4 * v41);
    if ( !v7 )
      goto LABEL_67;
    v8 = *v7;
    if ( !*v7 )
      goto LABEL_67;
    v9 = v8 & 0xFFFFF;
    v45 = v8 & 0xFFFFF;
    if ( (v8 & 0xFFF00000) == 0x70100000 )
    {
      v10 = (_DWORD *)v7[2];
      v11 = this[5];
      v12 = this[4];
      if ( (*(_BYTE *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 4 * *v10) + 4)) + 5) & 2) != 0
        && (*(_BYTE *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 4 * v10[v45]) + 4)) + 5) & 2) != 0 )
      {
        v9 = v45;
        if ( (*(_BYTE *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 4 * v10[2 * v45]) + 4)) + 5) & 2) != 0 )
        {
          v13 = (_DWORD *)sub_681186(116);
          if ( v13 )
            v42 = (char *)sub_680CEC(v13);
          else
            v42 = 0;
          if ( !v42 )
            return -2147024882;
          v47 = sub_6811D1(v42, v45 & 0xFFFFF | 0x10000000, v45, v45, 0);
          if ( v47 < 0 )
            return v47;
          v47 = sub_680D22(v42, (int)v7);
          if ( v47 < 0 )
            return v47;
          v48 = 0;
          if ( v45 )
          {
            while ( 1 )
            {
              v14 = 4 * v48;
              v15 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(4 * v48 + v7[4]));
              *(_DWORD *)(4 * v48 + *((_DWORD *)v42 + 2)) = *(_DWORD *)(4 * v48 + v7[2]);
              *(_DWORD *)(v14 + *((_DWORD *)v42 + 4)) = sub_681AAA(this, this[34], v46, *(_DWORD *)(v15 + 16), 0.0);
              *(_DWORD *)(v14 + v7[2]) = *(_DWORD *)(v14 + *((_DWORD *)v42 + 4));
              if ( *(_DWORD *)(4 * v48 + *((_DWORD *)v42 + 4)) == -1 )
                return -2147024882;
              if ( ++v48 >= v45 )
              {
                v9 = v45;
                break;
              }
            }
          }
          ++v46;
          if ( (unsigned int)this[137] >= 0x200 )
            return -2147024882;
          v47 = sub_681997((int)this, v42);
          if ( v47 < 0 )
            return v47;
          *(_DWORD *)(this[140] + 4 * this[137]++) = v42;
        }
      }
      else
      {
        v9 = v45;
      }
    }
    if ( (*v7 & 0xFFF00000) == 0x30000000 && (unsigned __int16)this[50] != 260 )
      break;
LABEL_59:
    v34 = (_DWORD *)sub_681186(116);
    if ( v34 )
      v35 = (char *)sub_680CEC(v34);
    else
      v35 = 0;
    if ( !v35 )
      return -2147024882;
    v47 = sub_681430(v35, v7);
    if ( v47 < 0 )
      return v47;
    if ( (unsigned int)this[137] >= 0x200 )
      return -2147024882;
    v47 = sub_681997((int)this, v35);
    if ( v47 < 0 )
      return v47;
    *(_DWORD *)(this[140] + 4 * this[137]++) = v35;
    v6 = v38;
LABEL_67:
    if ( ++v41 >= v6 )
      goto LABEL_68;
  }
  v16 = 1;
  if ( v9 <= 1 )
  {
LABEL_34:
    v20 = (_DWORD *)sub_681186(116);
    if ( v20 )
      v21 = sub_680CEC(v20);
    else
      v21 = 0;
    if ( !v21 )
      return -2147024882;
    v47 = sub_681997((int)this, v21);
    v22 = v21;
    if ( v47 < 0 )
      goto LABEL_71;
    v47 = sub_6811D1((char *)v21, 1882193921, 3, 1, 0);
    if ( v47 < 0 )
      return v47;
    v47 = sub_680D22(v21, (int)v7);
    if ( v47 < 0 )
      return v47;
    *(_DWORD *)v21[2] = *(_DWORD *)v7[2];
    *(_DWORD *)(v21[2] + 4) = sub_681AAA(this, this[30], 0, 0, -1.0);
    *(_DWORD *)(v21[2] + 8) = sub_681AAA(this, this[30], 0, 0, 0.5);
    v23 = v21[2];
    if ( *(_DWORD *)(v23 + 4) == -1 )
      return -2147024882;
    if ( *(_DWORD *)(v23 + 8) == -1 )
      return -2147024882;
    *(_DWORD *)v21[4] = sub_681AAA(this, this[34], v46, 3, 0.0);
    if ( *(_DWORD *)v21[4] == -1 )
      return -2147024882;
    v24 = 0;
    v49 = 0;
    if ( v45 )
    {
      v40 = 8 * v45;
      v43 = 4 * v45;
      do
      {
        *(_DWORD *)(v7[2] + 4 * v24) = *(_DWORD *)v21[4];
        v25 = v7[2];
        v26 = v43;
        v43 += 4;
        v27 = (int *)(v25 + v26);
        v39 = *v27;
        *v27 = *(_DWORD *)(v25 + v40);
        *(_DWORD *)(v40 + v7[2]) = v39;
        v24 = v49 + 1;
        v28 = ++v49 < v45;
        v40 += 4;
      }
      while ( v28 );
    }
    v29 = this[137];
    ++v46;
    if ( v29 >= 0x200 )
      return -2147024882;
    *(_DWORD *)(this[140] + 4 * v29) = v21;
    v30 = *this;
    ++this[137];
    if ( (*(int (__thiscall **)(int *, _DWORD *, _DWORD))(v30 + 32))(this, v21, 0) )
    {
      v31 = (_DWORD *)sub_681186(116);
      if ( v31 )
      {
        v44 = sub_680CEC(v31);
        v32 = sub_681997((int)this, v44);
      }
      else
      {
        v44 = 0;
        v32 = sub_681997((int)this, 0);
      }
      v22 = v44;
      v47 = v32;
      if ( v32 < 0 )
      {
        if ( !v44 )
          return v47;
LABEL_71:
        sub_66238F(v22, 1);
        return v47;
      }
      if ( !v44 )
        return -2147024882;
      v47 = sub_6811D1((char *)v44, 541065217, 2, 1, 0);
      if ( v47 < 0 )
        return v47;
      v47 = sub_680D22(v44, (int)v7);
      if ( v47 < 0 )
        return v47;
      *(_DWORD *)v44[4] = *(_DWORD *)v21[4];
      *(_DWORD *)v44[2] = *(_DWORD *)(v21[2] + 8);
      *(_DWORD *)v21[4] = sub_681AAA(this, this[34], 0, 3, 0.0);
      *(_DWORD *)(v44[2] + 4) = *(_DWORD *)v21[4];
      v21[1] = 2;
      *v21 = 542113793;
      v33 = this[137];
      if ( v33 >= 0x200 )
        return -2147024882;
      *(_DWORD *)(this[140] + 4 * v33) = v44;
      ++this[137];
    }
    this[275] = 1;
    *v7 = v45 & 0xFFFFF | 0x70F00000;
    goto LABEL_59;
  }
  v17 = (int *)v7[2];
  v18 = *v17;
  v19 = v17 + 1;
  while ( v18 == *v19 )
  {
    ++v16;
    ++v19;
    if ( v16 >= v9 )
      goto LABEL_34;
  }
  sub_686791(
    (int)this,
    v7[15],
    4554,
    "unable to emulate vector conditionals in ps_1_%i shader model",
    (unsigned __int8)this[50]);
  return -2147467259;
}
