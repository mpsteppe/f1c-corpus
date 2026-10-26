const CHAR *__thiscall sub_616930(_DWORD *this, char *String2)
{
  int v2; // eax
  const CHAR *result; // eax

  v2 = sub_616840(this, String2);
  if ( !v2 )
    return 0;
  result = *(const CHAR **)(v2 + 20);
  if ( !result )
    return WindowName;
  return result;
}
