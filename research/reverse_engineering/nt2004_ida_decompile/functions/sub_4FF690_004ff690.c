int __thiscall sub_4FF690(_DWORD *this)
{
  int result; // eax

  sub_578600(&byte_629120);
  result = this[9];
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  if ( result )
  {
    result = sub_5BE8AE();
    this[9] = 0;
  }
  return result;
}
