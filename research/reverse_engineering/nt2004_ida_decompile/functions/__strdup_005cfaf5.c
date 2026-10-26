char *__cdecl _strdup(const char *Source)
{
  size_t v1; // eax
  char *v2; // eax

  if ( Source && (v1 = strlen(Source), (v2 = (char *)malloc(v1 + 1)) != 0) )
    return strcpy(v2, Source);
  else
    return 0;
}
