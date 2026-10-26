int __fastcall sub_42F5A0(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 >= 64 )
    result = 64;
  dword_757C24 = result < 0 ? 0 : result;
  return result;
}
