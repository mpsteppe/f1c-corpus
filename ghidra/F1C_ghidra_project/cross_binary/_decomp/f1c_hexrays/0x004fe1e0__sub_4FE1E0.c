// f1c  0x004fe1e0  size=200
double __stdcall sub_4FE1E0(int a1)
{
  double result; // st7

  if ( !sub_588410(a1, &off_5C6E98) )
    return 0.0;
  if ( !sub_588410(a1, aDamp) )
    return 0.25;
  if ( !sub_588410(a1, &off_5C7234) )
    return 0.5;
  if ( !sub_588410(a1, aSoaked) )
    return 0.75;
  if ( !sub_588410(a1, aMonsoon) )
    return 1.0;
  result = sub_58850F(a1) * 0.0099999998;
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
