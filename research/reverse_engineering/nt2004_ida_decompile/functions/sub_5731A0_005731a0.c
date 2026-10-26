char *__thiscall sub_5731A0(char *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    `eh vector destructor iterator'(this, 0x28u, *((_DWORD *)this - 1), (void (__thiscall *)(void *))sub_56AC20);
    if ( (a2 & 1) != 0 )
      sub_5BE8AE();
    return this - 4;
  }
  else
  {
    sub_56AC20(this);
    if ( (a2 & 1) != 0 )
      sub_5BE8AE();
    return this;
  }
}
