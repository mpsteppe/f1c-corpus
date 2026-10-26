unsigned int __thiscall sub_600E20(unsigned int *this, char a2)
{
  unsigned int v2; // eax
  unsigned int result; // eax

  v2 = *this;
  if ( a2 )
    result = v2 | 2;
  else
    result = v2 & 0xFFFFFFFD;
  *this = result;
  return result;
}
