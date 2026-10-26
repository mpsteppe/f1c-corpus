const CHAR *__thiscall sub_4DF000(_DWORD *this)
{
  int v1; // eax
  const CHAR *result; // eax

  v1 = this[6];
  if ( !v1 )
    return 0;
  result = *(const CHAR **)(v1 + 36);
  if ( !result )
    return WindowName;
  return result;
}
