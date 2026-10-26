int __fastcall sub_536910(int a1, int a2)
{
  BOOL v3; // ebx
  int v4; // eax
  size_t v5; // edi
  int v6; // edx
  int v7; // eax
  int result; // eax

  v3 = 0;
  if ( a1 && *(_BYTE *)(a1 + 92) == 119 )
  {
    *(_DWORD *)(a1 + 4) = 0;
    while ( 1 )
    {
      v4 = *(_DWORD *)(a1 + 16);
      v5 = 0x4000 - v4;
      if ( v4 != 0x4000 )
      {
        if ( sub_5BF5A6(*(void **)(a1 + 72), 1u, v5, *(FILE **)(a1 + 64)) != v5 )
        {
          result = -1;
          *(_DWORD *)(a1 + 56) = -1;
          return result;
        }
        v6 = *(_DWORD *)(a1 + 72);
        *(_DWORD *)(a1 + 16) = 0x4000;
        *(_DWORD *)(a1 + 12) = v6;
      }
      if ( !v3 )
      {
        v7 = sub_5374C0(a1, a2);
        *(_DWORD *)(a1 + 56) = v7;
        if ( !v5 && v7 == -5 )
          *(_DWORD *)(a1 + 56) = 0;
        v3 = *(_DWORD *)(a1 + 16) || *(_DWORD *)(a1 + 56) == 1;
        if ( *(_DWORD *)(a1 + 56) < 2u )
          continue;
      }
      return *(_DWORD *)(a1 + 56) != 1 ? *(_DWORD *)(a1 + 56) : 0;
    }
  }
  return -2;
}
