// f1c  0x004a0d30  size=30
char __stdcall sub_4A0D30(char a1)
{
  char result; // al

  result = a1;
  if ( byte_7CE254 != a1 )
  {
    byte_7CE254 = a1;
    dword_7CE250 = 0;
  }
  return result;
}
