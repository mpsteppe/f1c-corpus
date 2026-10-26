// f1c  0x00586f70  size=47
char __thiscall sub_586F70(int *this, unsigned int a2, char a3)
{
  char result; // al
  unsigned int v4; // edx
  int v5; // ecx

  result = 1 << (a2 & 7);
  v4 = a2 >> 3;
  v5 = *this;
  if ( a3 )
  {
    *(_BYTE *)(v4 + v5) |= result;
  }
  else
  {
    result = ~result;
    *(_BYTE *)(v4 + v5) &= result;
  }
  return result;
}
