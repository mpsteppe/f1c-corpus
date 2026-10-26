unsigned int __thiscall sub_5E5190(unsigned int *this, char a2)
{
  unsigned int v2; // eax
  unsigned int result; // eax

  v2 = *this;
  if ( a2 )
    result = v2 | 8;
  else
    result = v2 & 0xFFFFFFF7;
  *this = result;
  return result;
}
