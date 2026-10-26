int __thiscall sub_557480(const CHAR *this, int a2)
{
  if ( (*(_BYTE *)(a2 + 32) & 8) != 0 )
  {
    if ( sub_557670(a2) )
      return -1;
  }
  else if ( sub_557CE0(this, a2) )
  {
    return -1;
  }
  return 0;
}
