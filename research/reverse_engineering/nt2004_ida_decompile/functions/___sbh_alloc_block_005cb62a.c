_DWORD *__cdecl __sbh_alloc_block(int a1)
{
  int v1; // ecx
  unsigned int v2; // esi
  char *i; // ebx
  bool v4; // zf
  bool v5; // zf
  bool v6; // zf
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // ecx
  int *v14; // edx
  int v15; // ecx
  int v16; // esi
  unsigned int v17; // ebx
  _BYTE *v18; // edi
  unsigned int v19; // ebx
  _BYTE *v20; // edi
  int v21; // ebx
  _DWORD *v22; // ecx
  char v23; // cl
  _DWORD *v24; // edx
  int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+Ch] [ebp-14h]
  signed int v27; // [esp+10h] [ebp-10h]
  unsigned int v28; // [esp+14h] [ebp-Ch]
  _DWORD *v29; // [esp+14h] [ebp-Ch]
  unsigned int v30; // [esp+18h] [ebp-8h]
  int v31; // [esp+18h] [ebp-8h]
  char *v32; // [esp+1Ch] [ebp-4h]
  int v33; // [esp+1Ch] [ebp-4h]
  char *v34; // [esp+28h] [ebp+8h]

  v32 = (char *)lpMem + 20 * dword_8003B8;
  v27 = (a1 + 23) & 0xFFFFFFF0;
  v1 = (v27 >> 4) - 1;
  if ( v1 >= 32 )
  {
    v2 = 0;
    v28 = 0;
    v30 = 0xFFFFFFFF >> ((v27 >> 4) - 33);
  }
  else
  {
    v2 = 0xFFFFFFFF >> v1;
    v30 = -1;
    v28 = 0xFFFFFFFF >> v1;
  }
  i = (char *)dword_8003B0;
  v34 = (char *)dword_8003B0;
  if ( dword_8003B0 < (unsigned int)lpMem + 20 * dword_8003B8 )
  {
    do
    {
      if ( v2 & *(_DWORD *)i | v30 & *((_DWORD *)i + 1) )
        break;
      i += 20;
      v34 = i;
    }
    while ( i < v32 );
  }
  if ( i == v32 )
  {
    for ( i = (char *)lpMem; ; i += 20 )
    {
      v4 = i == (char *)dword_8003B0;
      v34 = i;
      if ( (unsigned int)i >= dword_8003B0 )
        break;
      if ( v2 & *(_DWORD *)i | v30 & *((_DWORD *)i + 1) )
      {
        v4 = i == (char *)dword_8003B0;
        break;
      }
    }
    if ( v4 )
    {
      while ( 1 )
      {
        v5 = i == v32;
        if ( i >= v32 )
          break;
        if ( *((_DWORD *)i + 2) )
        {
          v5 = i == v32;
          break;
        }
        i += 20;
        v34 = i;
      }
      if ( v5 )
      {
        for ( i = (char *)lpMem; ; i += 20 )
        {
          v6 = i == (char *)dword_8003B0;
          v34 = i;
          if ( (unsigned int)i >= dword_8003B0 )
            break;
          if ( *((_DWORD *)i + 2) )
          {
            v6 = i == (char *)dword_8003B0;
            break;
          }
        }
        if ( v6 )
        {
          i = (char *)__sbh_alloc_new_region();
          v34 = i;
          if ( !i )
            return 0;
        }
      }
      **((_DWORD **)i + 4) = __sbh_alloc_new_group(i);
      if ( **((_DWORD **)i + 4) == -1 )
        return 0;
    }
  }
  dword_8003B0 = (int)i;
  v8 = (_DWORD *)*((_DWORD *)i + 4);
  v9 = *v8;
  v33 = *v8;
  if ( *v8 == -1 || !(v2 & v8[v9 + 17] | v30 & v8[v9 + 49]) )
  {
    v33 = 0;
    v10 = v8 + 17;
    v2 = v28;
    if ( !(v28 & v8[17] | v30 & v8[49]) )
    {
      do
      {
        v11 = v10[33];
        ++v33;
        ++v10;
      }
      while ( !(*v10 & v28 | v30 & v11) );
    }
    v9 = v33;
  }
  v12 = 0;
  v29 = &v8[129 * v9 + 81];
  v13 = v2 & v8[v9 + 17];
  if ( !v13 )
  {
    v13 = v30 & v8[v9 + 49];
    v12 = 32;
  }
  while ( v13 >= 0 )
  {
    v13 *= 2;
    ++v12;
  }
  v14 = (int *)v29[2 * v12 + 1];
  v31 = *v14 - v27;
  v15 = v31;
  v16 = (v31 >> 4) - 1;
  if ( v16 > 63 )
    v16 = 63;
  if ( v16 == v12 )
    goto LABEL_57;
  if ( v14[1] != v14[2] )
    goto LABEL_47;
  if ( v12 >= 32 )
  {
    v19 = 0x80000000 >> (v12 - 32);
    v20 = (char *)v8 + v12 + 4;
    v21 = ~v19;
    v8[v33 + 49] &= v21;
    v4 = (*v20)-- == 1;
    v26 = v21;
    if ( v4 )
    {
      i = v34;
      *((_DWORD *)v34 + 1) &= v26;
      goto LABEL_47;
    }
  }
  else
  {
    v17 = 0x80000000 >> v12;
    v18 = (char *)v8 + v12 + 4;
    v25 = ~v17;
    v8[v33 + 17] &= ~v17;
    v4 = (*v18)-- == 1;
    if ( v4 )
    {
      i = v34;
      *(_DWORD *)v34 &= v25;
      goto LABEL_47;
    }
  }
  i = v34;
LABEL_47:
  *(_DWORD *)(v14[2] + 4) = v14[1];
  *(_DWORD *)(v14[1] + 8) = v14[2];
  if ( v31 )
  {
    v22 = &v29[2 * v16];
    v14[1] = v22[1];
    v14[2] = (int)v22;
    v22[1] = v14;
    *(_DWORD *)(v14[1] + 8) = v14;
    if ( v14[1] == v14[2] )
    {
      v23 = *((_BYTE *)v8 + v16 + 4);
      if ( v16 >= 32 )
      {
        *((_BYTE *)v8 + v16 + 4) = v23 + 1;
        if ( !v23 )
          *((_DWORD *)i + 1) |= 0x80000000 >> (v16 - 32);
        v8[v33 + 49] |= 0x80000000 >> (v16 - 32);
      }
      else
      {
        *((_BYTE *)v8 + v16 + 4) = v23 + 1;
        if ( !v23 )
          *(_DWORD *)i |= 0x80000000 >> v16;
        v8[v33 + 17] |= 0x80000000 >> v16;
      }
    }
    v15 = v31;
LABEL_57:
    if ( v15 )
    {
      *v14 = v15;
      *(int *)((char *)v14 + v15 - 4) = v15;
    }
    goto LABEL_60;
  }
  v15 = 0;
LABEL_60:
  v24 = (int *)((char *)v14 + v15);
  *v24 = v27 + 1;
  *(_DWORD *)((char *)v24 + v27 - 4) = v27 + 1;
  v4 = (*v29)++ == 0;
  if ( v4 && i == dword_8003B4 && v33 == dword_8003AC )
    dword_8003B4 = 0;
  *v8 = v33;
  return v24 + 1;
}
