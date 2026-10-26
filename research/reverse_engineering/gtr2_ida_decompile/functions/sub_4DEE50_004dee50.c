const CHAR *__thiscall sub_4DEE50(_DWORD *this)
{
  int v1; // eax
  const CHAR *result; // eax

  v1 = this[147];
  if ( v1 <= 1 )
    return 0;
  result = *(const CHAR **)(this[v1 + 138] + 36);
  if ( !result )
    return WindowName;
  return result;
}
