bool __thiscall sub_4CE6E0(_DWORD *this, char a2)
{
  int v3; // eax

  if ( this[2427] == 5 )
  {
    v3 = this[3408];
  }
  else
  {
    if ( this[2427] != 6 )
      return 1;
    v3 = this[2361];
  }
  return ((1 << a2) & v3) != 0;
}
