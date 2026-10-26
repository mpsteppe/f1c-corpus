int __thiscall sub_5E7150(int *this, int a2)
{
  int v2; // eax

  LOBYTE(v2) = a2;
  if ( !a2 )
    v2 = *this;
  if ( (v2 & 4) != 0 )
    return this[32];
  if ( (v2 & 8) != 0 )
    return this[33];
  return 0;
}
