double __stdcall sub_52C390(char *String)
{
  double result; // st7

  if ( !_strcmpi(String, aBest) )
    return 0.035;
  if ( !_strcmpi(String, aNice) )
    return 0.34999999;
  if ( !_strcmpi(String, aClear) )
    return 0.60000002;
  if ( !_strcmpi(String, aOvercast) )
    return 0.64999998;
  if ( !_strcmpi(String, aDrizzle) )
    return 0.73000002;
  if ( !_strcmpi(String, aRain_0) )
    return 0.85000002;
  if ( !_strcmpi(String, aMonsoon) )
    return 0.96999997;
  result = atof(String) * 0.0099999998;
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
