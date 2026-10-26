char __thiscall sub_4DBC90(_BYTE *this)
{
  char result; // al
  LPVOID *v2; // esi

  result = this[12];
  if ( result )
  {
    v2 = *(LPVOID **)this;
    if ( *(_DWORD *)this )
    {
      if ( v2[1] )
        sub_5BE8AE(v2[1]);
      return sub_5BE8AE(v2);
    }
  }
  return result;
}
