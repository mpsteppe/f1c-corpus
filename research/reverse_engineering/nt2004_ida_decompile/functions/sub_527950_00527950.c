int __stdcall sub_527950(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
  {
    result = a1 - 1;
    if ( a1 == 1 )
    {
      dbl_6152F8 = 30.0;
    }
    else
    {
      result = a1 - 2;
      if ( a1 == 2 )
        dbl_6152F8 = 0.119999997317791;
    }
  }
  else
  {
    dbl_6152F8 = 1.0;
  }
  return result;
}
