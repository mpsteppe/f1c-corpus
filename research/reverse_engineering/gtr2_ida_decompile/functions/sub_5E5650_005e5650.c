unsigned int __thiscall sub_5E5650(unsigned int *this, char a2)
{
  unsigned int v2; // eax
  unsigned int result; // eax

  v2 = *this;
  if ( a2 )
    result = v2 | 0x20;
  else
    result = v2 & 0xFFFFFFDF;
  *this = result;
  return result;
}
