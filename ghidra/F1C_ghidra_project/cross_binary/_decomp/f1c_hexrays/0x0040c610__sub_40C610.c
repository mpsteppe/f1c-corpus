// f1c  0x0040c610  size=60
int __thiscall sub_40C610(_DWORD *this)
{
  int result; // eax

  if ( dword_7CFCC8 )
  {
    result = 1;
    if ( this[3] == 1 )
    {
      this[5] = 1;
      return sub_40CDE0(2, 0);
    }
  }
  else
  {
    result = this[3];
    if ( result == 1 || result == 2 )
    {
      this[5] = result;
      return sub_40CDE0(0, 0);
    }
  }
  return result;
}
