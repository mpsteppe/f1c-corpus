char *__cdecl _strdup(const char *Source)
{
  int v1; // eax
  char *v2; // eax

  if ( Source && (v1 = sub_6354D0((int)Source), (v2 = (char *)malloc(v1 + 1)) != 0) )
    return strcpy(v2, Source);
  else
    return 0;
}
