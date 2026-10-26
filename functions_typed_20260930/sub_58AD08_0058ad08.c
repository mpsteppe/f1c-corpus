int __cdecl sub_58AD08(int a1)
{
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  unsigned int v6; // eax
  int v7; // edx
  _BYTE *i; // ecx
  int v9; // ecx
  _DWORD *v10; // ebx
  int v11; // esi
  _BYTE *v12; // eax
  _BYTE *v13; // ecx
  bool v14; // zf
  int v15; // eax
  int v16; // ecx
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  LONG v19; // [esp+14h] [ebp-4h]
  unsigned int v20; // [esp+20h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 16);
  v17 = v2;
  if ( *(int *)(a1 + 4) < 0 )
    *(_DWORD *)(a1 + 4) = 0;
  v3 = sub_58C724(v2, 0, 1u);
  v19 = v3;
  if ( v3 < 0 )
    return -1;
  v4 = *(_DWORD *)(a1 + 12);
  if ( (v4 & 0x108) == 0 )
    return v3 - *(_DWORD *)(a1 + 4);
  v6 = *(_DWORD *)a1;
  v7 = *(_DWORD *)(a1 + 8);
  v18 = *(_DWORD *)a1 - v7;
  if ( (v4 & 3) != 0 )
  {
    if ( *(char *)(dword_8D4920[v2 >> 5] + 36 * (v2 & 0x1F) + 4) < 0 )
    {
      for ( i = *(_BYTE **)(a1 + 8); (unsigned int)i < v6; ++i )
      {
        if ( *i == 10 )
          ++v18;
      }
    }
    goto LABEL_16;
  }
  if ( (v4 & 0x80u) == 0 )
  {
    *(_DWORD *)TLSOffsetGetter() = 22;
    return -1;
  }
LABEL_16:
  if ( !v19 )
    return v18;
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 )
  {
    v9 = *(_DWORD *)(a1 + 4);
    if ( v9 )
    {
      v20 = v9 + v6 - v7;
      v10 = (_DWORD *)(4 * (v2 >> 5) + 9259296);
      v11 = 36 * (v2 & 0x1F);
      if ( *(char *)(v11 + *v10 + 4) < 0 )
      {
        if ( sub_58C724(v17, 0, 2u) == v19 )
        {
          v12 = *(_BYTE **)(a1 + 8);
          v13 = &v12[v20];
          while ( v12 < v13 )
          {
            if ( *v12 == 10 )
              ++v20;
            ++v12;
          }
          v14 = (*(_BYTE *)(a1 + 13) & 0x20) == 0;
        }
        else
        {
          sub_58C724(v17, v19, 0);
          v15 = 512;
          if ( v20 > 0x200 || (v16 = *(_DWORD *)(a1 + 12), (v16 & 8) == 0) || (v16 & 0x400) != 0 )
            v15 = *(_DWORD *)(a1 + 24);
          v20 = v15;
          v14 = (*(_BYTE *)(v11 + *v10 + 4) & 4) == 0;
        }
        if ( !v14 )
          ++v20;
      }
      v19 -= v20;
    }
    else
    {
      v18 = 0;
    }
  }
  return v19 + v18;
}

