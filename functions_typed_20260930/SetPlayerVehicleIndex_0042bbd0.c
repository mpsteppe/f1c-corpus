int __stdcall sub_42BBD0(int a1)
{
  int result; // eax

  dword_7C54E0 = (int)&stru_5EC6D8 + 18624 * a1;
  result = 0;
  while ( (_UNKNOWN *)dword_7C54F0[result] != (_UNKNOWN *)((char *)&stru_5EC6D8 + 18624 * a1) )
  {
    if ( ++result >= 104 )
      return result;
  }
  dword_7C54DC = result;
  return result;
}

