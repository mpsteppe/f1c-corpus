char *__thiscall sub_59C5F0(char *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `eh vector destructor iterator'(this, 0x134u, *((_DWORD *)this - 1), sub_59C2B0);
    if ( (a2 & 1) != 0 )
      j_j__free(this - 4);
    return this - 4;
  }
  else
  {
    sub_59C2B0(this);
    if ( (a2 & 1) != 0 )
      j__free(this);
    return this;
  }
}
