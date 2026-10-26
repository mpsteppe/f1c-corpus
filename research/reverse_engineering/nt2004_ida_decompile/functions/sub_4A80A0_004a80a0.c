_DWORD *__stdcall sub_4A80A0(_DWORD *a1, char *String2)
{
  const char *v2; // eax
  _DWORD *result; // eax
  int *v4; // eax
  int v5; // eax
  int v6; // eax
  int *v7; // eax

  if ( !a1 || !String2 )
    return 0;
  v2 = (const char *)a1[2];
  if ( !v2 )
    v2 = &byte_629120;
  if ( !_strcmpi(v2, String2) )
    return a1;
  v4 = (int *)a1[7];
  a1[9] = v4;
  if ( !v4 )
    return 0;
  v5 = *v4;
  if ( !v5 )
    return 0;
  while ( 1 )
  {
    result = (_DWORD *)sub_4A80A0(v5, String2);
    if ( result )
      break;
    v6 = a1[9];
    if ( v6 )
      a1[9] = *(_DWORD *)(v6 + 4);
    v7 = (int *)a1[9];
    if ( v7 )
    {
      v5 = *v7;
      if ( v5 )
        continue;
    }
    return 0;
  }
  return result;
}
