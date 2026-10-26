int __cdecl sub_58F810(int a1, int a2, int a3)
{
  int v3; // esi
  int v5; // eax
  _DWORD *v6; // edi
  int v7; // eax
  int v8; // ecx
  unsigned __int8 *i; // edx

  v3 = *(char *)(a1 + 7) >> 4;
  if ( !v3 )
    return 1;
  v5 = (*(unsigned __int8 *)(a2 + 4) >> 2) + 3;
  LOBYTE(v5) = v5 & 0xFC;
  v6 = (_DWORD *)(v5 + a2 + 8);
  v7 = 2 * *(unsigned __int8 *)(a1 + 6) + 3;
  LOBYTE(v7) = v7 & 0xFC;
  v8 = 0;
  if ( v3 > 0 )
  {
    for ( i = (unsigned __int8 *)(((3 * ((*(_BYTE *)(a1 + 7) & 0xF) + 1)) & 0xFFFFFFFC) + v7 + a1 + 13);
          *v6 && (*v6 & *(_DWORD *)(a3 + 4 * *i)) == 0;
          i += 3 )
    {
      ++v8;
      ++v6;
      if ( v8 >= v3 )
        return 0;
    }
    return 1;
  }
  return 0;
}
