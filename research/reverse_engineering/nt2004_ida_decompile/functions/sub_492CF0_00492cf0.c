char __thiscall sub_492CF0(_BYTE *this)
{
  char result; // al
  LPVOID *v2; // esi

  result = this[12];
  if ( result )
  {
    v2 = *(LPVOID **)this;
    if ( *(_DWORD *)this )
    {
      if ( *v2 )
        sub_5BE8AE(*v2);
      return sub_5BE8AE(v2);
    }
  }
  return result;
}
