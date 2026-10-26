unsigned int __thiscall sub_5E5B70(unsigned int *this, unsigned int a2)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 == 4096 )
  {
    *this = *this & 0xFFFFCFFF | 0x1000;
  }
  else if ( a2 == 0x2000 )
  {
    result = *this & 0xFFFFCFFF | 0x2000;
    *this = result;
  }
  return result;
}
