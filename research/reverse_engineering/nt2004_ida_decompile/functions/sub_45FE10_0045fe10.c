char __thiscall sub_45FE10(_DWORD *this, int a2)
{
  int v2; // eax
  _DWORD *i; // ecx

  v2 = 0;
  for ( i = this + 1629; *i != a2; ++i )
  {
    if ( ++v2 >= 48 )
      return 0;
  }
  return 1;
}
