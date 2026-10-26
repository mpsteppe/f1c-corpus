char *__cdecl _strcats(char *Destination, int a2)
{
  int v2; // edi
  const char **v3; // esi
  char *result; // eax

  v2 = a2;
  if ( a2 > 0 )
  {
    v3 = (const char **)&a2;
    do
    {
      result = strcat(Destination, *++v3);
      --v2;
    }
    while ( v2 );
  }
  return result;
}
