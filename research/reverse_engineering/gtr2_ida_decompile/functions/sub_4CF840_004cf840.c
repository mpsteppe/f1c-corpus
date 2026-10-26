const CHAR *__thiscall sub_4CF840(_DWORD *this)
{
  int v1; // eax
  const CHAR *result; // eax

  v1 = this[61];
  if ( !v1 )
    return 0;
  result = *(const CHAR **)(v1 + 24);
  if ( !result )
    return WindowName;
  return result;
}
