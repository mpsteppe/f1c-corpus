int __stdcall sub_42DB60(int a1)
{
  int result; // eax

  dword_75AAC4 = (int)&unk_62BF68 + 25304 * a1;
  result = 0;
  while ( (_UNKNOWN *)dword_75AAD0[result] != (_UNKNOWN *)((char *)&unk_62BF68 + 25304 * a1) )
  {
    if ( ++result >= 48 )
      return result;
  }
  dword_75AAC0 = result;
  return result;
}
