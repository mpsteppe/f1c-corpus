char *__thiscall sub_53FCEB(char *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `eh vector destructor iterator'(this, 0xCu, *((_DWORD *)this - 1), sub_53FA25);
    if ( (a2 & 1) != 0 )
      sub_5BE8AE();
    return this - 4;
  }
  else
  {
    sub_5BE8AE();
    if ( (a2 & 1) != 0 )
      sub_5BE8AE();
    return this;
  }
}
