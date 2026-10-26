// f1c  0x004fe0d0  size=266
double __stdcall sub_4FE0D0(int a1)
{
  double result; // st7

  if ( !sub_588410(a1, aBest) )
    return 0.030000001;
  if ( !sub_588410(a1, aNice) )
    return 0.30000001;
  if ( !sub_588410(a1, aClear_0) )
    return 0.60000002;
  if ( !sub_588410(a1, aOvercast) )
    return 0.64999998;
  if ( !sub_588410(a1, aDrizzle) )
    return 0.73000002;
  if ( !sub_588410(a1, aRain_0) )
    return 0.85000002;
  if ( !sub_588410(a1, aMonsoon) )
    return 0.96999997;
  result = sub_58850F(a1) * 0.0099999998;
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
