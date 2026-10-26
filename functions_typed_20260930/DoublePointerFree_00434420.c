char __thiscall sub_434420(_BYTE *this)
{
  char result; // al
  LPVOID *v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(LPVOID **)this;
    if ( *(_DWORD *)this )
    {
      if ( *v2 )
        FreeWrapper_7bcf(*v2);
      return FreeWrapper_7bcf(v2);
    }
  }
  return result;
}

