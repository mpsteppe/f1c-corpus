int __stdcall sub_595430(int a1, int a2)
{
  int result; // eax

  if ( a2 )
  {
    result = a1 | dword_7E8E10;
    dword_7E8E10 |= a1;
  }
  else
  {
    result = ~a1;
    dword_7E8E10 &= ~a1;
  }
  return result;
}
