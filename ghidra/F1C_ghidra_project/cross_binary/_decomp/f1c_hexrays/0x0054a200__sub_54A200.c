// f1c  0x0054a200  size=50
int __stdcall sub_54A200(int a1, int a2)
{
  int result; // eax

  if ( a2 )
  {
    result = a1 | dword_8B8E34;
    dword_8B8E34 |= a1;
  }
  else
  {
    result = ~a1;
    dword_8B8E34 &= ~a1;
  }
  return result;
}
