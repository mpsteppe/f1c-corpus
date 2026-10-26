unsigned int __thiscall sub_52FBB0(_BYTE *this, unsigned int a2, char a3)
{
  unsigned int result; // eax

  result = a2;
  if ( a2 <= 8 )
    this[a2] = a3;
  return result;
}
