int __stdcall sub_5E5B30(int a1, char a2)
{
  int result; // eax

  if ( a2 )
  {
    result = a1 | dword_FB2750;
    dword_FB2750 |= a1;
  }
  else
  {
    result = ~a1;
    dword_FB2750 &= ~a1;
  }
  return result;
}
