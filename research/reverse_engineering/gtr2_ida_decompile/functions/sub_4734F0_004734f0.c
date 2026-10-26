char __thiscall sub_4734F0(_BYTE *this, char a2, char a3)
{
  int v4; // eax
  char v5; // cl

  v4 = 1 << a2;
  v5 = this[161];
  if ( a3 )
  {
    this[161] = v4 | v5;
  }
  else
  {
    LOBYTE(v4) = ~(_BYTE)v4;
    this[161] = v4 & v5;
  }
  return v4;
}
