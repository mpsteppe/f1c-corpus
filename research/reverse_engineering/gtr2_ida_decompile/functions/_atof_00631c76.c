double __cdecl atof(const char *String)
{
  _BYTE v3[24]; // [esp+4h] [ebp-18h] BYREF

  while ( isspace(*(unsigned __int8 *)String) )
    ++String;
  sub_6354D0(String);
  return *(double *)(_fltin2(v3, String) + 16);
}
