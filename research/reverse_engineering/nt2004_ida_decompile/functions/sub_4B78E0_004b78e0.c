int __thiscall sub_4B78E0(_DWORD *this, char a2)
{
  bool v3; // sf
  int v4; // eax
  int result; // eax

  do
  {
    if ( a2 )
    {
      v3 = --this[19] < 0;
      if ( v3 )
        this[19] = 11;
    }
    else
    {
      v4 = this[19] + 1;
      v3 = this[19] - 11 < 0;
      this[19] = v4;
      if ( v3 == __OFSUB__(v4, 12) )
        this[19] = 0;
    }
    result = sub_4C0BF0(this[19]);
  }
  while ( result <= 1 );
  return result;
}
