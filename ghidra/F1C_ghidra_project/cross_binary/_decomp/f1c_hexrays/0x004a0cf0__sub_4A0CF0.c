// f1c  0x004a0cf0  size=30
char sub_4A0CF0()
{
  char result; // al

  result = byte_7CE254;
  if ( !byte_7CE254 )
  {
    result = sub_4A0250();
    dword_7CE258 = 0;
  }
  return result;
}
