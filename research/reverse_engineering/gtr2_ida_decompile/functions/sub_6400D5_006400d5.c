_DWORD *__cdecl sub_6400D5(int a1)
{
  unsigned int v1; // kr00_4
  int v2; // eax
  int v3; // ecx
  unsigned int v4; // esi
  char *j; // ebx
  bool i; // cf
  _DWORD *v7; // eax
  int v8; // edx
  _DWORD *v9; // ecx
  int v10; // edx
  int v11; // edi
  int v12; // ecx
  int *v14; // edx
  int v15; // ecx
  int v16; // esi
  unsigned int v17; // ebx
  _BYTE *v18; // edi
  bool v19; // zf
  unsigned int v20; // ebx
  _BYTE *v21; // edi
  int v22; // ebx
  _DWORD *v23; // ecx
  int v24; // edi
  _DWORD *v25; // edx
  int v26; // [esp+0h] [ebp-14h]
  int v27; // [esp+0h] [ebp-14h]
  signed int v28; // [esp+4h] [ebp-10h]
  _DWORD *v29; // [esp+8h] [ebp-Ch]
  unsigned int v30; // [esp+Ch] [ebp-8h]
  int v31; // [esp+Ch] [ebp-8h]
  char *v32; // [esp+10h] [ebp-4h]
  int v33; // [esp+10h] [ebp-4h]
  char *v34; // [esp+1Ch] [ebp+8h]
  char v35; // [esp+1Fh] [ebp+Bh]

  v1 = __readeflags();
  v2 = *(_DWORD *)__ROR4__(off_16C6DFC, 255);
  __writeeflags(v1);
  v28 = (a1 + 23) & 0xFFFFFFF0;
  v3 = (v28 >> 4) - 1;
  v32 = (char *)lpMem + 20 * v2;
  if ( v3 >= 32 )
  {
    v4 = 0;
    v30 = 0xFFFFFFFF >> ((v28 >> 4) - 33);
  }
  else
  {
    v4 = 0xFFFFFFFF >> v3;
    v30 = -1;
  }
  j = (char *)dword_FBB4B0;
  for ( i = dword_FBB4B0 < (unsigned int)lpMem + 20 * v2; ; i = j < v32 )
  {
    v34 = j;
    if ( !i || v4 & *(_DWORD *)j | v30 & *((_DWORD *)j + 1) )
      break;
    j += 20;
  }
  if ( j == v32 )
  {
    for ( j = (char *)lpMem; ; j += 20 )
    {
      v34 = j;
      if ( (unsigned int)j >= dword_FBB4B0 || v4 & *(_DWORD *)j | v30 & *((_DWORD *)j + 1) )
        break;
    }
    if ( j == (char *)dword_FBB4B0 )
    {
      while ( j < v32 && !*((_DWORD *)j + 2) )
      {
        j += 20;
        v34 = j;
      }
      if ( j == v32 )
      {
        for ( j = (char *)lpMem; ; j += 20 )
        {
          v34 = j;
          if ( (unsigned int)j >= dword_FBB4B0 || *((_DWORD *)j + 2) )
            break;
        }
        if ( j == (char *)dword_FBB4B0 )
        {
          j = __sbh_alloc_new_region();
          v34 = j;
          if ( !j )
            return 0;
        }
      }
      **((_DWORD **)j + 4) = __sbh_alloc_new_group(j);
      if ( **((_DWORD **)j + 4) == -1 )
        return 0;
    }
  }
  dword_FBB4B0 = (int)j;
  v7 = (_DWORD *)*((_DWORD *)j + 4);
  v8 = *v7;
  v33 = *v7;
  if ( *v7 == -1 || !(v4 & v7[v8 + 17] | v30 & v7[v8 + 49]) )
  {
    v33 = 0;
    v9 = v7 + 17;
    if ( !(v4 & v7[17] | v30 & v7[49]) )
    {
      do
      {
        v10 = v30 & v9[33];
        ++v33;
        ++v9;
      }
      while ( !(v4 & *v9 | v10) );
    }
    v8 = v33;
  }
  v29 = &v7[129 * v8 + 81];
  v11 = 0;
  v12 = v4 & v7[v8 + 17];
  if ( !v12 )
  {
    v12 = v30 & v7[v8 + 49];
    v11 = 32;
  }
  while ( v12 >= 0 )
  {
    v12 *= 2;
    ++v11;
  }
  v14 = (int *)v29[2 * v11 + 1];
  v15 = *v14 - v28;
  v16 = (v15 >> 4) - 1;
  v31 = v15;
  if ( v16 > 63 )
    v16 = 63;
  if ( v16 == v11 )
    goto LABEL_55;
  if ( v14[1] != v14[2] )
    goto LABEL_45;
  if ( v11 >= 32 )
  {
    v20 = 0x80000000 >> (v11 - 32);
    v21 = (char *)v7 + v11 + 4;
    v22 = ~v20;
    v7[v33 + 49] &= v22;
    v19 = (*v21)-- == 1;
    v27 = v22;
    if ( v19 )
    {
      j = v34;
      *((_DWORD *)v34 + 1) &= v27;
      goto LABEL_45;
    }
  }
  else
  {
    v17 = 0x80000000 >> v11;
    v18 = (char *)v7 + v11 + 4;
    v26 = ~v17;
    v7[v33 + 17] &= ~v17;
    v19 = (*v18)-- == 1;
    if ( v19 )
    {
      j = v34;
      *(_DWORD *)v34 &= v26;
      goto LABEL_45;
    }
  }
  j = v34;
LABEL_45:
  *(_DWORD *)(v14[2] + 4) = v14[1];
  *(_DWORD *)(v14[1] + 8) = v14[2];
  if ( v15 )
  {
    v23 = &v29[2 * v16];
    v24 = v23[1];
    v14[2] = (int)v23;
    v14[1] = v24;
    v23[1] = v14;
    *(_DWORD *)(v14[1] + 8) = v14;
    if ( v14[1] == v14[2] )
    {
      v35 = *((_BYTE *)v7 + v16 + 4);
      *((_BYTE *)v7 + v16 + 4) = v35 + 1;
      if ( v16 >= 32 )
      {
        if ( !v35 )
          *((_DWORD *)j + 1) |= 0x80000000 >> (v16 - 32);
        v7[v33 + 49] |= 0x80000000 >> (v16 - 32);
      }
      else
      {
        if ( !v35 )
          *(_DWORD *)j |= 0x80000000 >> v16;
        v7[v33 + 17] |= 0x80000000 >> v16;
      }
    }
    v15 = v31;
LABEL_55:
    if ( v15 )
    {
      *v14 = v15;
      *(int *)((char *)v14 + v15 - 4) = v15;
    }
    goto LABEL_58;
  }
  v15 = 0;
LABEL_58:
  v25 = (int *)((char *)v14 + v15);
  *v25 = v28 + 1;
  *(_DWORD *)((char *)v25 + v28 - 4) = v28 + 1;
  v19 = (*v29)++ == 0;
  if ( v19 && j == (char *)dword_FBB4A0 && v33 == dword_FBB4B8 )
    dword_FBB4A0 = 0;
  *v7 = v33;
  return v25 + 1;
}
