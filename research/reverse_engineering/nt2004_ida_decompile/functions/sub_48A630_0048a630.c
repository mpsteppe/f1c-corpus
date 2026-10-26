int __stdcall sub_48A630(int a1)
{
  int result; // eax

  result = dword_600F50;
  if ( (unsigned int)dword_600F50 >= 4 )
  {
    dword_600F54 = -1;
  }
  else
  {
    if ( a1 == 1 )
      result = dword_600F54 + 1;
    else
      result = dword_600F54 - 1;
    dword_600F54 = result;
    if ( result >= 0 )
    {
      if ( dword_600F54 > 2 )
        dword_600F54 = 0;
    }
    else
    {
      dword_600F54 = 2;
    }
  }
  return result;
}
