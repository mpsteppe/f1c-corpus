// f1c  0x0054a580  size=47
int __fastcall sub_54A580(int a1, int a2, int a3)
{
  int result; // eax

  result = a3;
  if ( a3 )
  {
    result = a3 - 2;
    if ( a3 == 2 )
    {
      result = dword_8B8F38 - a2;
      dword_8B8F3C = dword_8B8F38 - a2;
    }
    else
    {
      dword_8B8F3C += a2;
    }
  }
  else
  {
    dword_8B8F3C = a2;
  }
  return result;
}
