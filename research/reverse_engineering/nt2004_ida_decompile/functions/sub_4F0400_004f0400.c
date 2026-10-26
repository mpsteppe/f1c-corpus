int sub_4F0400()
{
  int result; // eax

  if ( (byte_7D6BCD & 1) != 0 )
  {
    ++dword_7D6BC8;
    return 1;
  }
  else
  {
    byte_7D6BCD |= 1u;
    rand();
    result = 1;
    dword_7D6BC8 = 1;
  }
  return result;
}
