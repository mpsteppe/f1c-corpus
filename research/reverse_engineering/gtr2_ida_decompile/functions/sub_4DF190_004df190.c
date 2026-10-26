const CHAR *__thiscall sub_4DF190(_DWORD *this)
{
  const CHAR **v1; // eax
  const CHAR *result; // eax

  v1 = (const CHAR **)this[92];
  if ( !v1 )
    return 0;
  result = *v1;
  if ( !result )
    return WindowName;
  return result;
}
