int __thiscall sub_4A46C0(_DWORD *this, int a2)
{
  const char *v2; // esi
  const char *v3; // eax
  int result; // eax

  v2 = *(const char **)(a2 + 20);
  if ( !v2 )
    v2 = &byte_629120;
  v3 = (const char *)this[5];
  if ( !v3 )
    v3 = &byte_629120;
  result = strcmp(v3, v2);
  if ( result )
    return -(result < 0) - ((result < 0) - 1) < 0;
  return result;
}
