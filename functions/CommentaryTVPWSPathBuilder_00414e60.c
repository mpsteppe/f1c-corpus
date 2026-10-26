int __thiscall sub_414E60(const char **this)
{
  const char *v2; // edi
  const char *v3; // edx
  const char *v4; // ecx
  const char *v5; // eax
  _BYTE v7[128]; // [esp+8h] [ebp-100h] BYREF
  char v8[128]; // [esp+88h] [ebp-80h] BYREF

  v2 = *this;
  if ( *this )
  {
    v3 = *this;
  }
  else
  {
    v2 = &byte_5EA438;
    v3 = &byte_5EA438;
  }
  v4 = (const char *)dword_5EC420;
  if ( !dword_5EC420 )
    v4 = &byte_5EA438;
  v5 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v5 = &byte_5EA438;
  StringFormatWithBufferOverflowCheck(v8, "%s%s%s\\tv%s_", v5, v4, v3, v2);
  StringFormatWithBufferOverflowCheck(v7, "%s%s", v8, aCountryb);
  if ( FilePathExtensionCheck((int)v7, (int)(this + 3)) )
    TrackNameDisplayIDLookup(this + 3, this[2], 0, 1);
  StringFormatWithBufferOverflowCheck(v7, "%s%s", v8, aCountrye);
  if ( FilePathExtensionCheck((int)v7, (int)(this + 8)) )
    TrackNameDisplayIDLookup(this + 8, this[2], 0, 0);
  StringFormatWithBufferOverflowCheck(v7, "%s%s", v8, aCircuitb);
  if ( FilePathExtensionCheck((int)v7, (int)(this + 13)) )
    TrackNameDisplayIDLookup(this + 13, this[2], 1, 1);
  StringFormatWithBufferOverflowCheck(v7, "%s%s", v8, aCircuite);
  if ( FilePathExtensionCheck((int)v7, (int)(this + 18)) )
    TrackNameDisplayIDLookup(this + 18, this[2], 1, 0);
  return 0;
}
