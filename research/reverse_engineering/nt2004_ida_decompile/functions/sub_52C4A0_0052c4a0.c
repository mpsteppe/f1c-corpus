double __stdcall sub_52C4A0(char *String)
{
  double result; // st7

  if ( !_strcmpi(String, off_60A208) )
    return 0.0;
  if ( !_strcmpi(String, aDamp) )
    return 0.25;
  if ( !_strcmpi(String, off_60A230) )
    return 0.5;
  if ( !_strcmpi(String, aSoaked) )
    return 0.75;
  if ( !_strcmpi(String, aMonsoon) )
    return 1.0;
  result = atof(String) * 0.0099999998;
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
