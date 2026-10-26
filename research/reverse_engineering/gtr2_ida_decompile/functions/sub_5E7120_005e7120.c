int __thiscall sub_5E7120(int *this, int a2)
{
  int v2; // eax

  LOBYTE(v2) = a2;
  if ( !a2 )
    v2 = *this;
  if ( (v2 & 1) != 0 )
    return this[30];
  if ( (v2 & 2) != 0 )
    return this[31];
  return 0;
}
