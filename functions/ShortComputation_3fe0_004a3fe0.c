int __thiscall sub_4A3FE0(_DWORD *this)
{
  int result; // eax

  result = 0;
  this[30] = 0;
  this[33] = 0;
  if ( this[25] )
    return FlagFieldBitManipulation(0, 0, 1, 0);
  return result;
}
