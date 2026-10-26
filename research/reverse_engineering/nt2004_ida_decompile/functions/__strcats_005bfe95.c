char *__cdecl _strcats(char *Destination, int a2)
{
  int v2; // edi
  int *v3; // esi
  char *result; // eax
  const char *v5; // [esp-8h] [ebp-Ch]

  v2 = a2;
  if ( a2 > 0 )
  {
    v3 = &a2;
    do
    {
      v5 = (const char *)v3[1];
      ++v3;
      result = strcat(Destination, v5);
      --v2;
    }
    while ( v2 );
  }
  return result;
}
