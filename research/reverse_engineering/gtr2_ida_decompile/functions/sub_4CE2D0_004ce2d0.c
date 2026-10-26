const CHAR *__thiscall sub_4CE2D0(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  const CHAR *result; // eax

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
  result = *(const CHAR **)(v3 + 160);
  if ( !result )
    return WindowName;
  return result;
}
