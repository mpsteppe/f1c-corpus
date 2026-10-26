int __cdecl sub_58C824(int a1)
{
  int v2; // esi
  __int64 v3; // rax
  int v4; // ebx
  unsigned int v6; // eax
  int v7; // edx
  int v8; // ecx
  _BYTE *i; // ecx
  int v10; // ecx
  _DWORD *v11; // ebx
  int v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // ecx
  bool v15; // zf
  int v16; // eax
  int v17; // ecx
  __int64 v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]
  unsigned int v21; // [esp+24h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 16);
  v19 = v2;
  if ( *(int *)(a1 + 4) < 0 )
    *(_DWORD *)(a1 + 4) = 0;
  v3 = sub_595F11(v2, 0, 0, 1u);
  v4 = v3;
  v18 = v3;
  if ( v3 < 0 )
    return -1;
  if ( (*(_WORD *)(a1 + 12) & 0x108) == 0 )
    return v3 - *(_DWORD *)(a1 + 4);
  v6 = *(_DWORD *)a1;
  v7 = *(_DWORD *)(a1 + 8);
  v20 = *(_DWORD *)a1 - v7;
  v8 = *(_DWORD *)(a1 + 12);
  if ( (v8 & 3) != 0 )
  {
    if ( *(char *)(dword_8D4920[v2 >> 5] + 36 * (v2 & 0x1F) + 4) < 0 )
    {
      for ( i = *(_BYTE **)(a1 + 8); (unsigned int)i < v6; ++i )
      {
        if ( *i == 10 )
          ++v20;
      }
    }
    v4 = v18;
    goto LABEL_17;
  }
  if ( (v8 & 0x80u) == 0 )
  {
    *(_DWORD *)TLSOffsetGetter() = 22;
    return -1;
  }
LABEL_17:
  if ( !(HIDWORD(v18) | v4) )
    return v20;
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 )
  {
    v10 = *(_DWORD *)(a1 + 4);
    if ( v10 )
    {
      v21 = v10 + v6 - v7;
      v11 = (_DWORD *)(4 * (v2 >> 5) + 9259296);
      v12 = 36 * (v2 & 0x1F);
      if ( *(char *)(v12 + *v11 + 4) < 0 )
      {
        if ( sub_595F11(v19, 0, 0, 2u) == v18 )
        {
          v13 = *(_BYTE **)(a1 + 8);
          v14 = &v13[v21];
          while ( v13 < v14 )
          {
            if ( *v13 == 10 )
              ++v21;
            ++v13;
          }
          v15 = (*(_BYTE *)(a1 + 13) & 0x20) == 0;
        }
        else
        {
          sub_595F11(v19, v18, HIDWORD(v18), 0);
          v16 = 512;
          if ( v21 > 0x200 || (v17 = *(_DWORD *)(a1 + 12), (v17 & 8) == 0) || (v17 & 0x400) != 0 )
            v16 = *(_DWORD *)(a1 + 24);
          v21 = v16;
          v15 = (*(_BYTE *)(v12 + *v11 + 4) & 4) == 0;
        }
        if ( !v15 )
          ++v21;
      }
      LODWORD(v18) = v18 - v21;
    }
    else
    {
      v20 = 0;
    }
  }
  return v18 + v20;
}

