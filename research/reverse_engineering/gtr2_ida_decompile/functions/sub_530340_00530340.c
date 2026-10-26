double __stdcall sub_530340(char *String1)
{
  int v1; // edi
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  const char *v4; // eax
  double result; // st7
  char *v6; // eax

  if ( !String1 || !sub_53A250(0) || !sub_616630("Qualifying") )
    return -1.0;
  v1 = 0;
  while ( 1 )
  {
    v2 = (_DWORD *)sub_616610(v1);
    v3 = v2;
    if ( v2 )
    {
      v4 = (const char *)sub_6165E0(v2);
      if ( !_stricmp(String1, v4) )
        break;
    }
    if ( ++v1 >= 104 )
      return -1.0;
  }
  v6 = sub_48D380(v3);
  result = atof(v6);
  if ( result < 10.0 )
    return -1.0;
  return result;
}
