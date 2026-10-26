int __thiscall sub_405170(_DWORD *this)
{
  CHAR *v2; // eax
  const char *v3; // edi
  int result; // eax
  CHAR *v5; // edx

  v2 = (CHAR *)this[15];
  if ( !v2 )
    v2 = &byte_629120;
  v3 = v2;
  result = 0;
  if ( strlen(v3) )
  {
    v5 = (CHAR *)this[15];
    if ( !v5 )
      v5 = &byte_629120;
    return sub_4CD9C0(v5, 1);
  }
  return result;
}
