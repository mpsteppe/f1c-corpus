int __stdcall sub_42C8E0(int a1)
{
  int result; // eax

  dword_91E084 = (int)&unk_9204A0 + 22616 * a1;
  result = 0;
  while ( (_UNKNOWN *)*(&dword_91E088 + result) != (_UNKNOWN *)((char *)&unk_9204A0 + 22616 * a1) )
  {
    if ( ++result >= 104 )
      return result;
  }
  dword_91E080 = result;
  return result;
}
