unsigned int __thiscall sub_5B5BE0(unsigned int *this, int a2)
{
  unsigned int v2; // eax
  unsigned int result; // eax

  v2 = *this;
  if ( a2 )
    result = v2 | 0x800;
  else
    result = v2 & 0xFFFFF7FF;
  *this = result;
  return result;
}
