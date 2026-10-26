int __fastcall sub_563230(int a1, int a2)
{
  int v2; // esi
  int result; // eax
  _DWORD *i; // ecx

  v2 = *(_DWORD *)(a1 + 108);
  result = 0;
  if ( v2 <= 0 )
    return -1;
  for ( i = (_DWORD *)(*(_DWORD *)(a1 + 8) + 4); *i != a2; i += 7 )
  {
    if ( ++result >= v2 )
      return -1;
  }
  return result;
}
