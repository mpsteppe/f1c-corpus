char *__cdecl __lc_lctostr(char *Destination, char *Source)
{
  char *result; // eax

  strcpy(Destination, Source);
  if ( Source[64] )
    _strcats(Destination, 2);
  result = Source + 128;
  if ( Source[128] )
    return _strcats(Destination, 2);
  return result;
}
