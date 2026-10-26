// f1c  0x004a56b0  size=76
int __thiscall sub_4A56B0(_DWORD *this, char a2)
{
  int result; // eax

  result = 0;
  if ( a2 )
  {
    result = 2;
    if ( this[74] != 2 )
    {
      this[74] = 2;
      result = 1;
      this[75] = 1;
      this[76] = 1;
    }
  }
  else
  {
    this[74] = 1;
    this[75] = 0;
    this[76] = 0;
  }
  return result;
}
