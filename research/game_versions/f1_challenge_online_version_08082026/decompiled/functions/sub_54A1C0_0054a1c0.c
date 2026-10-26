int __stdcall sub_54A1C0(int a1, int a2)
{
  int result; // eax

  if ( a2 )
  {
    result = a1 | dword_8B8EE0;
    dword_8B8EE0 |= a1;
  }
  else
  {
    result = ~a1;
    dword_8B8EE0 &= ~a1;
  }
  return result;
}
