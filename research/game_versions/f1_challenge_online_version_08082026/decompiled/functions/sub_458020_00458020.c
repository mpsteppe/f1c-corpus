int __thiscall sub_458020(int *this)
{
  int result; // eax

  result = *this;
  if ( *this )
  {
    result = sub_587BCF((LPVOID)(result - 4));
    *this = 0;
  }
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  return result;
}
