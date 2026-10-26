const CHAR *__thiscall sub_410A10(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  const CHAR *result; // eax

  v1 = this[13];
  if ( !v1 )
  {
    v2 = this[2];
    if ( !v2 )
      return 0;
    v1 = (*(int (**)(void))(*(_DWORD *)v2 + 24))();
    if ( !v1 )
      return 0;
  }
  result = *(const CHAR **)(v1 + 4);
  if ( !result )
    return WindowName;
  return result;
}
