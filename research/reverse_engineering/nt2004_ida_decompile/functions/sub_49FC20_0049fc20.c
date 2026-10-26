CHAR *__thiscall sub_49FC20(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  CHAR *result; // eax

  v2 = a2;
  v3 = this[36];
  if ( a2 < 0 || !v3 )
    return 0;
  while ( v2 )
  {
    v3 = *(_DWORD *)(v3 + 140);
    --v2;
    if ( !v3 )
      return 0;
  }
  result = *(CHAR **)(v3 + 160);
  if ( !result )
    return &byte_629120;
  return result;
}
