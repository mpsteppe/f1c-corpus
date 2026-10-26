int __fastcall sub_5365D0(int a1, int a2)
{
  int v3; // edi
  unsigned int v4; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  char v8; // cl
  __int16 v9; // ax
  unsigned __int16 v10; // ax
  int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edx
  BOOL v15; // ebp
  unsigned int v16; // ecx
  int v17; // eax
  int v18; // edi
  int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  unsigned int v23; // ecx
  unsigned __int8 *v24; // edx
  int v25; // ecx
  int v26; // eax
  _DWORD *v27; // ecx
  _DWORD *v29; // ecx
  int v30; // eax
  unsigned __int8 v32; // [esp+1Ch] [ebp-4h]

  v3 = 0;
  while ( 1 )
  {
    v4 = *(_DWORD *)(a1 + 106);
    if ( v4 < 0x106 )
    {
      TextBufferDecompressor((char *)a1);
      v4 = *(_DWORD *)(a1 + 106);
      if ( v4 < 0x106 && !a2 )
        return 0;
      if ( !v4 )
        break;
    }
    if ( v4 >= 3 )
    {
      v5 = *(_DWORD *)(a1 + 98);
      v6 = *(_DWORD *)(a1 + 58);
      v7 = *(_DWORD *)(a1 + 74)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 46) + v5 + 2)
          ^ (*(_DWORD *)(a1 + 62) << *(_DWORD *)(a1 + 78)));
      HIWORD(v3) = 0;
      *(_DWORD *)(a1 + 62) = v7;
      LOWORD(v3) = *(_WORD *)(v6 + 2 * v7);
      *(_WORD *)(*(_DWORD *)(a1 + 54) + 2 * (v5 & *(_DWORD *)(a1 + 42))) = v3;
      *(_WORD *)(*(_DWORD *)(a1 + 58) + 2 * *(_DWORD *)(a1 + 62)) = *(_WORD *)(a1 + 98);
    }
    if ( v3 && *(_DWORD *)(a1 + 98) - v3 <= (unsigned int)(*(_DWORD *)(a1 + 34) - 262) && *(_DWORD *)(a1 + 126) != 2 )
      *(_DWORD *)(a1 + 86) = ZlibDeflateLongestMatch(a1, v3);
    if ( *(_DWORD *)(a1 + 86) < 3u )
    {
      v32 = *(_BYTE *)(*(_DWORD *)(a1 + 98) + *(_DWORD *)(a1 + 46));
      *(_WORD *)(*(_DWORD *)(a1 + 5783) + 2 * *(_DWORD *)(a1 + 5779)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5771) + (*(_DWORD *)(a1 + 5779))++) = v32;
      ++*(_WORD *)(a1 + 4 * v32 + 138);
      v15 = *(_DWORD *)(a1 + 5779) == *(_DWORD *)(a1 + 5775) - 1;
      --*(_DWORD *)(a1 + 106);
    }
    else
    {
      v8 = *(_DWORD *)(a1 + 86);
      v9 = *(_WORD *)(a1 + 98) - *(_WORD *)(a1 + 102);
      *(_WORD *)(*(_DWORD *)(a1 + 5783) + 2 * *(_DWORD *)(a1 + 5779)) = v9;
      v10 = v9 - 1;
      *(_BYTE *)(*(_DWORD *)(a1 + 5771) + (*(_DWORD *)(a1 + 5779))++) = v8 - 3;
      v11 = (unsigned __int8)byte_5B84F8[(unsigned __int8)(v8 - 3)];
      ++*(_WORD *)(a1 + 4 * v11 + 1166);
      if ( v10 >= 0x100u )
        v12 = (unsigned __int8)byte_5B83F8[v10 >> 7];
      else
        v12 = (unsigned __int8)byte_5B82F8[v10];
      ++*(_WORD *)(a1 + 4 * v12 + 2430);
      v13 = *(_DWORD *)(a1 + 86);
      v14 = *(_DWORD *)(a1 + 118);
      v15 = *(_DWORD *)(a1 + 5779) == *(_DWORD *)(a1 + 5775) - 1;
      v16 = *(_DWORD *)(a1 + 106) - v13;
      *(_DWORD *)(a1 + 106) = v16;
      if ( v13 > v14 || v16 < 3 )
      {
        v23 = v13 + *(_DWORD *)(a1 + 98);
        v24 = (unsigned __int8 *)(v23 + *(_DWORD *)(a1 + 46));
        *(_DWORD *)(a1 + 98) = v23;
        v25 = *(_DWORD *)(a1 + 78);
        *(_DWORD *)(a1 + 86) = 0;
        v26 = *v24;
        *(_DWORD *)(a1 + 62) = v26;
        *(_DWORD *)(a1 + 62) = *(_DWORD *)(a1 + 74) & (v24[1] ^ (v26 << v25));
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 86) = v13 - 1;
      do
      {
        v17 = *(_DWORD *)(a1 + 46);
        v18 = *(_DWORD *)(a1 + 62);
        v19 = *(_DWORD *)(a1 + 98) + 1;
        *(_DWORD *)(a1 + 98) = v19;
        v20 = *(_DWORD *)(a1 + 58);
        v21 = *(_DWORD *)(a1 + 74) & ((v18 << *(_DWORD *)(a1 + 78)) ^ *(unsigned __int8 *)(v19 + v17 + 2));
        HIWORD(v3) = 0;
        *(_DWORD *)(a1 + 62) = v21;
        LOWORD(v3) = *(_WORD *)(v20 + 2 * v21);
        *(_WORD *)(*(_DWORD *)(a1 + 54) + 2 * (*(_DWORD *)(a1 + 42) & v19)) = v3;
        *(_WORD *)(*(_DWORD *)(a1 + 58) + 2 * *(_DWORD *)(a1 + 62)) = *(_WORD *)(a1 + 98);
        v22 = *(_DWORD *)(a1 + 86) - 1;
        *(_DWORD *)(a1 + 86) = v22;
      }
      while ( v22 );
    }
    ++*(_DWORD *)(a1 + 98);
LABEL_24:
    if ( v15 )
    {
      HuffmanBitStreamEncoder(*(_DWORD *)(a1 + 98) - *(_DWORD *)(a1 + 82), 0);
      v27 = *(_DWORD **)a1;
      *(_DWORD *)(a1 + 82) = *(_DWORD *)(a1 + 98);
      BufferCopyWithSizeTracking(v27);
      if ( !*(_DWORD *)(*(_DWORD *)a1 + 16) )
        return 0;
    }
  }
  HuffmanBitStreamEncoder(*(_DWORD *)(a1 + 98) - *(_DWORD *)(a1 + 82), a2 == 4);
  v29 = *(_DWORD **)a1;
  *(_DWORD *)(a1 + 82) = *(_DWORD *)(a1 + 98);
  BufferCopyWithSizeTracking(v29);
  v30 = 0;
  if ( !*(_DWORD *)(*(_DWORD *)a1 + 16) )
    return a2 != 4 ? 0 : 2;
  LOBYTE(v30) = a2 == 4;
  return 2 * v30 + 1;
}
