// f1c  0x00464a10  size=43
int __thiscall sub_464A10(_BYTE *this, int a2)
{
  int result; // eax

  result = a2 + (*this & 0x7F);
  if ( result > 127 )
    result = 127;
  *this ^= (result ^ *this) & 0x7F;
  return result;
}
