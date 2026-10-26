double __stdcall sub_52C570(char *String)
{
  if ( !_strcmpi(String, off_615604) )
    return 32.5;
  if ( !_strcmpi(String, aWarm) )
    return 26.25;
  if ( !_strcmpi(String, aMedium) )
    return 20.0;
  if ( !_strcmpi(String, aCool) )
    return 13.75;
  if ( _strcmpi(String, aCold) )
    return atof(String);
  return 7.5;
}
