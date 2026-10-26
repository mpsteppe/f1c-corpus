int __thiscall sub_46C6E0(_BYTE *this, int a2)
{
  int result; // eax

  result = a2 + (*this & 0x7F);
  if ( result > 127 )
    result = 127;
  *this ^= (result ^ *this) & 0x7F;
  return result;
}
