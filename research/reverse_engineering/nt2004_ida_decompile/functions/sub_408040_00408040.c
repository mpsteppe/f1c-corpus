int __thiscall sub_408040(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax

  result = 0;
  if ( a2 )
  {
    result = a4;
    this[38] = 1008981770;
    this[39] = a3;
  }
  else
  {
    this[38] = 0;
    this[39] = 0;
  }
  this[37] = result;
  return result;
}
