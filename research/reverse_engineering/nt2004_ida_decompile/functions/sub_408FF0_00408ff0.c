char __thiscall sub_408FF0(_BYTE *this)
{
  char result; // al
  void *v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      sub_4060C0(*(_DWORD *)this);
      return sub_5BE8AE(v2);
    }
  }
  return result;
}
