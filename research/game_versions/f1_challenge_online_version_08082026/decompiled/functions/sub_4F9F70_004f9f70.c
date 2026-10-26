int __stdcall sub_4F9F70(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
  {
    result = a1 - 1;
    if ( a1 == 1 )
    {
      dbl_5D6D70 = 30.0;
    }
    else
    {
      result = a1 - 2;
      if ( a1 == 2 )
        dbl_5D6D70 = 0.119999997317791;
    }
  }
  else
  {
    dbl_5D6D70 = 1.0;
  }
  return result;
}
