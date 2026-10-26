int __fastcall sub_59D450(int a1, int a2, int a3)
{
  int result; // eax

  result = a3;
  if ( a3 )
  {
    result = a3 - 2;
    if ( a3 == 2 )
    {
      result = dword_7F5E70 - a2;
      dword_7F5E74 = dword_7F5E70 - a2;
    }
    else
    {
      dword_7F5E74 += a2;
    }
  }
  else
  {
    dword_7F5E74 = a2;
  }
  return result;
}
