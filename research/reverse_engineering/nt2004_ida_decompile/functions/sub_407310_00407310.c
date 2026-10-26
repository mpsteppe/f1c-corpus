CHAR *__thiscall sub_407310(_DWORD *this)
{
  const char *v2; // eax
  CHAR *result; // eax
  const char *v4; // eax
  const char *v5; // eax

  v2 = (const char *)this[4];
  if ( !v2 )
    v2 = &byte_629120;
  result = (CHAR *)strcmp(v2, &byte_629120);
  if ( result )
  {
    v4 = (const char *)this[4];
    if ( !v4 )
      v4 = &byte_629120;
    if ( strncmp(v4, asc_5FB910, 4u) )
      goto LABEL_11;
    v5 = (const char *)this[24];
    if ( !v5 )
      v5 = &byte_629120;
    if ( !strcmp(v5, &byte_629120) )
LABEL_11:
      result = (CHAR *)this[4];
    else
      result = (CHAR *)this[24];
    if ( !result )
      return &byte_629120;
  }
  return result;
}
