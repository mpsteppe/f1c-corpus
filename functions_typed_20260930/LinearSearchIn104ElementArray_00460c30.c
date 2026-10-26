int __thiscall sub_460C30(_DWORD *this, int a2)
{
  int result; // eax
  _DWORD *i; // ecx

  result = 0;
  for ( i = this + 3974; a2 != *i; ++i )
  {
    if ( ++result >= 104 )
      return 63;
  }
  return result;
}

