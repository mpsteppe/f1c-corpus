int __cdecl sub_58F050(int a1, int a2, int a3)
{
  int v3; // esi
  int result; // eax
  int v5; // edi
  _DWORD *v6; // ecx
  int v7; // edx

  v3 = *(_BYTE *)(a2 + 4) & 0xF;
  result = 1;
  v5 = 0;
  v6 = (_DWORD *)(a2 + (((v3 + 2) * *(unsigned __int8 *)(a2 + 5) + 15) & 0xFFFFFFFC));
  if ( (*(_BYTE *)(a2 + 4) & 0xF) != 0 )
  {
    while ( 1 )
    {
      v7 = *(unsigned __int8 *)(a1 + v5 + 8);
      if ( *(_BYTE *)(a1 + v5 + 8) )
      {
        if ( v7 != 255 && v7 != 254 && (*(_DWORD *)(a3 + 4 * v7) & *v6) == 0 )
          break;
      }
      ++v5;
      ++v6;
      if ( v5 >= v3 )
        return result;
    }
    return 0;
  }
  return result;
}
