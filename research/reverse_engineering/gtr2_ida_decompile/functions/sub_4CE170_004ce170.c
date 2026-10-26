const CHAR *__thiscall sub_4CE170(_DWORD *this)
{
  int v1; // edx
  int v2; // eax
  const CHAR *result; // eax

  v1 = this[146];
  if ( v1 < 0 )
    return 0;
  v2 = this[36];
  if ( !v2 )
    return 0;
  while ( v1 > 0 )
  {
    v2 = *(_DWORD *)(v2 + 140);
    --v1;
    if ( !v2 )
      return 0;
  }
  result = *(const CHAR **)(v2 + 160);
  if ( !result )
    return WindowName;
  return result;
}
