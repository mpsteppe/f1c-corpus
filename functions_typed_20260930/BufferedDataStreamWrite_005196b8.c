int __cdecl sub_5196B8(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // esi
  int result; // eax
  unsigned int v7; // [esp+10h] [ebp+8h]

  v5 = a1[96];
  if ( !*(_BYTE *)(v5 + 48) )
  {
    result = (*(int (__cdecl **)(_DWORD *, int))(a1[97] + 12))(a1, v5 + 8);
    if ( !result )
      return result;
    *(_BYTE *)(v5 + 48) = 1;
  }
  v7 = a1[69];
  (*(void (__cdecl **)(_DWORD *, int, int, _DWORD, int, int, int))(a1[98] + 4))(a1, v5 + 8, v5 + 52, a1[69], a2, a3, a4);
  result = v7;
  if ( *(_DWORD *)(v5 + 52) >= v7 )
  {
    *(_BYTE *)(v5 + 48) = 0;
    *(_DWORD *)(v5 + 52) = 0;
  }
  return result;
}

