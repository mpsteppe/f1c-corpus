int __stdcall sub_5B5120(int a1, char a2, char a3, int a4)
{
  int result; // eax

  result = 0;
  if ( a1 == 6 )
    return (a4 >> 3) & 0x1F | (8 * (a3 & 0xFC | (32 * (a2 & 0xF8))));
  if ( a1 == 5 )
    return (a4 >> 3) & 0x1F | (4 * (a3 & 0xF8 | (32 * (a2 & 0xF8))));
  return result;
}
