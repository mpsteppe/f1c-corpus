double __stdcall sub_593940(char *String1)
{
  double result; // st7

  if ( !_stricmp(String1, "Best") )
    return 0.020000001;
  if ( !_stricmp(String1, "Nice") )
    return 0.2;
  if ( !_stricmp(String1, "Clear") )
    return 0.60000002;
  if ( !_stricmp(String1, "Drizzle") )
    return 0.73000002;
  if ( !_stricmp(String1, "Rain") )
    return 0.85000002;
  if ( !_stricmp(String1, "Monsoon") )
    return 0.96999997;
  result = atof(String1) * 0.0099999998;
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
