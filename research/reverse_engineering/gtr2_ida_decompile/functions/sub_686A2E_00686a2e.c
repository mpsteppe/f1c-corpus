int __fastcall sub_686A2E(int a1, int a2, unsigned int a3, unsigned int a4, int a5)
{
  int result; // eax

  result = sub_68688F(a3, a2, a4, a5);
  if ( !result )
  {
    if ( a4 <= a3 )
      return a4 < a3;
    else
      return -1;
  }
  return result;
}
