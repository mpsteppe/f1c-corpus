unsigned int __thiscall sub_5B5990(unsigned int *this, int a2)
{
  unsigned int v2; // eax
  unsigned int result; // eax

  v2 = *this;
  if ( a2 )
    result = v2 | 0x80;
  else
    result = v2 & 0xFFFFFF7F;
  *this = result;
  return result;
}
