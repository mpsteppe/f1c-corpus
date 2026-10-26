double __cdecl atof(const char *String)
{
  _BYTE v4[24]; // [esp+4h] [ebp-18h] BYREF

  while ( (int)SrcSizeInBytes <= 1
        ? *((_BYTE *)off_625680 + 2 * *(unsigned __int8 *)String) & 8
        : _isctype(*(unsigned __int8 *)String, 8) )
    ++String;
  strlen(String);
  return *(double *)(_fltin2(v4, String) + 16);
}
