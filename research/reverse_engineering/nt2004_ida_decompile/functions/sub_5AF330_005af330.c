int __thiscall sub_5AF330(char *this, int a2)
{
  if ( (*(_BYTE *)(a2 + 32) & 8) != 0 )
  {
    if ( sub_5AF520((int)this, a2) )
      return -1;
  }
  else if ( sub_5AFBB0(this, a2) )
  {
    return -1;
  }
  return 0;
}
