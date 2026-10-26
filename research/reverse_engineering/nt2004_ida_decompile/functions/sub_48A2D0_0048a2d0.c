int __stdcall sub_48A2D0(int a1)
{
  int result; // eax

  if ( a1 == 1 )
    result = dword_7697F0 + 1;
  else
    result = dword_7697F0 - 1;
  if ( result >= 0 )
  {
    if ( result > 2 )
      result = 0;
  }
  else
  {
    result = 2;
  }
  dword_7697F0 = result;
  if ( result >= dword_7697F8 )
  {
    if ( result > dword_7697FC )
      dword_7697F0 = dword_7697FC;
  }
  else
  {
    dword_7697F0 = dword_7697F8;
  }
  return result;
}
