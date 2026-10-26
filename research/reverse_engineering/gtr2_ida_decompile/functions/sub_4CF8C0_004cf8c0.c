const CHAR *__thiscall sub_4CF8C0(_DWORD *this)
{
  int v1; // eax
  const CHAR *result; // eax

  v1 = this[61];
  if ( !v1 )
    return 0;
  result = *(const CHAR **)(v1 + 64);
  if ( !result )
    return WindowName;
  return result;
}
