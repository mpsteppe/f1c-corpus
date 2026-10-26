char __thiscall sub_436F20(_BYTE *this)
{
  char result; // al
  LPVOID *v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(LPVOID **)this;
    if ( *(_DWORD *)this )
    {
      sub_435A40(*(_DWORD **)this);
      if ( v2[5] )
        sub_5BE8AE(v2[5]);
      if ( v2[2] )
        sub_5BE8AE(v2[2]);
      if ( *v2 )
        sub_5BE8AE(*v2);
      return sub_5BE8AE(v2);
    }
  }
  return result;
}
