char __thiscall sub_42D210(_BYTE *this, char a2)
{
  char result; // al
  int v3; // eax
  char v4; // cl

  result = a2;
  this[16] = a2;
  if ( !a2 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, aPaused, byte_5EC4CC) )
    {
      v3 = 0;
      do
      {
        v4 = aPaused[v3];
        byte_5EC4CC[v3++] = v4;
      }
      while ( v4 );
    }
    return ShortComputation_bde0(byte_5EC4CC, 0);
  }
  return result;
}
