char __thiscall sub_45E5F0(_DWORD *this, int a2)
{
  int v2; // eax
  _DWORD *i; // ecx

  v2 = 0;
  for ( i = this + 3974; *i != a2; ++i )
  {
    if ( ++v2 >= 104 )
      return 0;
  }
  return 1;
}

