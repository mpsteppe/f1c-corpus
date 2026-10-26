unsigned int __cdecl sub_5886A7(char *a1, unsigned int a2, int a3, int a4)
{
  int v4; // edi
  unsigned int v5; // ebx
  unsigned int v8; // eax
  unsigned int v9; // edi
  DWORD v10; // edi
  DWORD v11; // eax
  int v12; // eax
  int v13; // [esp+24h] [ebp+14h]

  v4 = a3 * a2;
  v5 = a3 * a2;
  if ( !(a3 * a2) )
    return 0;
  if ( (*(_WORD *)(a4 + 12) & 0x10C) != 0 )
    v13 = *(_DWORD *)(a4 + 24);
  else
    v13 = 4096;
  while ( 1 )
  {
    if ( (*(_DWORD *)(a4 + 12) & 0x108) != 0 )
    {
      v8 = *(_DWORD *)(a4 + 4);
      if ( v8 )
      {
        v9 = v5;
        if ( v5 >= v8 )
          v9 = *(_DWORD *)(a4 + 4);
        MemoryCopy_cc00(*(_DWORD *)a4, a1, v9);
        *(_DWORD *)(a4 + 4) -= v9;
        *(_DWORD *)a4 += v9;
        v5 -= v9;
        a1 += v9;
LABEL_19:
        v4 = a3 * a2;
        goto LABEL_23;
      }
    }
    if ( v5 >= v13 )
      break;
    if ( sub_58CF35(*a1, a4) == -1 )
      goto LABEL_26;
    ++a1;
    --v5;
    v13 = *(_DWORD *)(a4 + 24);
    if ( v13 <= 0 )
      v13 = 1;
LABEL_23:
    if ( !v5 )
      return a3;
  }
  if ( (*(_DWORD *)(a4 + 12) & 0x108) == 0 || !BufferFlushWrite(a4) )
  {
    if ( v13 )
      v10 = v5 - v5 % v13;
    else
      v10 = v5;
    v11 = sub_58E22B(*(_DWORD *)(a4 + 16), a1, v10);
    if ( v11 == -1 || (a1 += v11, v5 -= v11, v11 < v10) )
    {
      *(_DWORD *)(a4 + 12) |= 0x20u;
      v12 = a3 * a2;
      return (v12 - v5) / a2;
    }
    goto LABEL_19;
  }
LABEL_26:
  v12 = v4;
  return (v12 - v5) / a2;
}

