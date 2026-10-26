char __thiscall sub_4EDA70(_BYTE *this)
{
  char result; // al
  int v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      if ( *(_DWORD *)(v2 + 24) )
        sub_592C40(*(_DWORD *)(v2 + 24));
      if ( *(_DWORD *)(v2 + 16) )
        sub_5BE8AE(*(LPVOID *)(v2 + 16));
      if ( *(_DWORD *)(v2 + 8) )
        sub_5BE8AE(*(LPVOID *)(v2 + 8));
      if ( *(_DWORD *)v2 )
        sub_5BE8AE(*(LPVOID *)v2);
      return sub_5BE8AE((LPVOID)v2);
    }
  }
  return result;
}
