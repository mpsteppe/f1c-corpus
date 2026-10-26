char __thiscall sub_4EDB70(_BYTE *this)
{
  char result; // al
  int v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
    {
      if ( *(_DWORD *)(v2 + 40) )
      {
        sub_592310(*(_DWORD *)(v2 + 40));
        *(_DWORD *)(v2 + 40) = 0;
      }
      if ( *(_DWORD *)(v2 + 28) )
        sub_5BE8AE(*(LPVOID *)(v2 + 28));
      if ( *(_DWORD *)(v2 + 12) )
        sub_5BE8AE(*(LPVOID *)(v2 + 12));
      if ( *(_DWORD *)v2 )
        sub_5BE8AE(*(LPVOID *)v2);
      return sub_5BE8AE((LPVOID)v2);
    }
  }
  return result;
}
