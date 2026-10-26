int __thiscall sub_5667B0(const char **this, int a2, signed int a3)
{
  signed int v5; // ecx
  signed int v6; // eax

  if ( *this )
  {
    v5 = strlen(*this);
    if ( a2 < 0 )
      return -1;
    v6 = a3;
    if ( a3 > v5 )
      return -1;
    do
    {
      (*this)[v6 - (a3 - a2)] = (*this)[v6];
      ++v6;
    }
    while ( v6 <= v5 );
  }
  else if ( a2 || a3 )
  {
    return -1;
  }
  return 0;
}
