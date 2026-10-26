int __thiscall sub_5DD280(int *this, int a2)
{
  int result; // eax

  if ( a2 == 16 )
  {
    result = *this | 4;
    this[64] = 16;
    *this = result;
  }
  else
  {
    result = *this | 4;
    if ( a2 == 32 )
      this[64] = 32;
    else
      this[64] = a2 == 64 ? 64 : 8;
    *this = result;
  }
  return result;
}
