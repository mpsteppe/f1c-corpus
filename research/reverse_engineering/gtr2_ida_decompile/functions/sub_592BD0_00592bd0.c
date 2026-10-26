double __thiscall sub_592BD0(char *String2, char *String1)
{
  unsigned int v2; // kr00_4
  __int32 v3; // ecx
  const char *v6; // [esp+0h] [ebp-8h] BYREF

  v6 = String2;
  v2 = __readeflags();
  v3 = dword_16C6F0C + 1989651252;
  __writeeflags(v2);
  _InterlockedExchange((volatile __int32 *)&v6, v3);
  if ( !_stricmp(String1, v6) )
    return 32.5;
  if ( !_stricmp(String1, "Warm") )
    return 26.25;
  if ( !_stricmp(String1, "Medium") )
    return 20.0;
  if ( !_stricmp(String1, "Cool") )
    return 13.75;
  if ( !_stricmp(String1, "Cold") )
    return 7.5;
  return atof(String1);
}
