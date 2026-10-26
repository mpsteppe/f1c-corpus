char *__thiscall sub_489A10(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  char *result; // eax

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
  result = *(char **)(v3 + 176);
  if ( !result )
    return byte_5EA438;
  return result;
}

