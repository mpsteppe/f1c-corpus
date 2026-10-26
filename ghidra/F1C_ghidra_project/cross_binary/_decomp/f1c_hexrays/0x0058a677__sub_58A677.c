// f1c  0x0058a677  size=94
int __stdcall sub_58A677(int a1, int a2, int a3, int (*a4)(void))
{
  int result; // eax

  while ( --a3 >= 0 )
  {
    a1 -= a2;
    result = a4();
  }
  return result;
}
