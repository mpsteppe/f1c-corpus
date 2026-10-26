int __stdcall sub_5E5AF0(int a1, char a2)
{
  int result; // eax

  if ( a2 )
  {
    result = a1 | dword_FB2318;
    dword_FB2318 |= a1;
  }
  else
  {
    result = ~a1;
    dword_FB2318 &= ~a1;
  }
  return result;
}
