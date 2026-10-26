int __fastcall sub_5BD0D0(char a1)
{
  int result; // eax

  result = 5;
  if ( (a1 & 2) != 0 )
    result = 9;
  if ( (a1 & 8) != 0 )
    result += 4;
  if ( (a1 & 0x10) != 0 )
    result += 2;
  if ( (a1 & 0x20) != 0 )
    result += 2;
  return result;
}
