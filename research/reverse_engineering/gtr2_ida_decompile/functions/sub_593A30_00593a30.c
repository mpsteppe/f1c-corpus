double __stdcall sub_593A30(char *String2)
{
  unsigned int v1; // kr00_4
  __int32 v2; // esi
  const char *v3; // esi
  double result; // st7
  const char *v5; // [esp+0h] [ebp-8h] BYREF

  v5 = String2;
  v1 = __readeflags();
  v2 = dword_16C6CA8 - (*(_DWORD *)((char *)sub_59C330 + 1) + 1);
  __writeeflags(v1);
  v3 = (const char *)_InterlockedExchange((volatile __int32 *)&v5, v2);
  if ( !_stricmp(v3, v5) )
    return 0.0;
  if ( !_stricmp(v3, "Damp") )
    return 0.25;
  if ( !_stricmp(v3, off_6FE418) )
    return 0.5;
  if ( !_stricmp(v3, "Soaked") )
    return 0.75;
  if ( !_stricmp(v3, "Monsoon") )
    return 1.0;
  result = atof(v3) * 0.0099999998;
  if ( result < 0.0 )
    return 0.0;
  if ( result > 1.0 )
    return 1.0;
  return result;
}
