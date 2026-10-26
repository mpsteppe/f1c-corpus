int __stdcall sub_5302D0(char *String1)
{
  int v1; // esi
  int v2; // eax
  const char *v3; // eax

  if ( !String1 || !sub_53A250(0) || !sub_616630("Qualifying") )
    return 104;
  v1 = 0;
  while ( 1 )
  {
    v2 = sub_616610(v1);
    if ( v2 )
    {
      v3 = (const char *)sub_6165E0(v2);
      if ( !_stricmp(String1, v3) )
        break;
    }
    if ( ++v1 >= 104 )
      return 104;
  }
  return v1 + 1;
}
