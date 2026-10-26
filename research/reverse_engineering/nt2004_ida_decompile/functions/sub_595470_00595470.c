int __stdcall sub_595470(int a1, int a2)
{
  int result; // eax

  if ( a2 )
  {
    result = a1 | dword_7E8D60;
    dword_7E8D60 |= a1;
  }
  else
  {
    result = ~a1;
    dword_7E8D60 &= ~a1;
  }
  return result;
}
