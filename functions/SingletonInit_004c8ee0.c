int __thiscall sub_4C8EE0(void *this)
{
  int result; // eax

  if ( (byte_8AC4DC & 1) != 0 )
  {
    ++dword_8AC4D8;
    return 1;
  }
  else
  {
    byte_8AC4DC |= 1u;
    RandLCGRandomNumberGenerator(this);
    result = 1;
    dword_8AC4D8 = 1;
  }
  return result;
}
