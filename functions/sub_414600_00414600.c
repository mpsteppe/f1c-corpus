int __thiscall sub_414600(const char **this, char a2)
{
  const char *v3; // eax
  char v4; // bl
  const char *v5; // ecx
  const char *v6; // ecx
  const char *v7; // eax
  _BYTE v9[128]; // [esp+Ch] [ebp-100h] BYREF
  char v10[128]; // [esp+8Ch] [ebp-80h] BYREF

  v3 = *this;
  v4 = 0;
  if ( !*this )
    v3 = &byte_5EA438;
  v5 = (const char *)dword_5EC470;
  if ( !dword_5EC470 )
    v5 = &byte_5EA438;
  StringFormatWithBufferOverflowCheck(v10, "%spws%s_", v5, v3);
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aFb);
  if ( FilePathExtensionCheck(v9, this + 4) )
    DriverNameIDLookup(this + 4, this[2], 0, 1, 1);
  else
    v4 = 1;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aFe);
  if ( FilePathExtensionCheck(v9, this + 9) )
    DriverNameIDLookup(this + 9, this[2], 0, 1, 0);
  else
    v4 = 1;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aSb);
  if ( FilePathExtensionCheck(v9, this + 14) )
    DriverNameIDLookup(this + 14, this[2], 0, 0, 1);
  else
    v4 = 1;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aSe);
  if ( FilePathExtensionCheck(v9, this + 19) )
    DriverNameIDLookup(this + 19, this[2], 0, 0, 0);
  else
    v4 = 1;
  v6 = *this;
  if ( !*this )
    v6 = &byte_5EA438;
  v7 = (const char *)dword_5EC470;
  if ( !dword_5EC470 )
    v7 = &byte_5EA438;
  StringFormatWithBufferOverflowCheck(v10, "%stv%s_", v7, v6);
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aFb);
  if ( FilePathExtensionCheck(v9, this + 24) )
    DriverNameIDLookup(this + 24, this[2], 1, 1, 1);
  else
    v4 = 1;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aFe);
  if ( FilePathExtensionCheck(v9, this + 29) )
    DriverNameIDLookup(this + 29, this[2], 1, 1, 0);
  else
    v4 = 1;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aSb);
  if ( FilePathExtensionCheck(v9, this + 34) )
    DriverNameIDLookup(this + 34, this[2], 1, 0, 1);
  else
    v4 = 1;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v10, aSe);
  if ( FilePathExtensionCheck(v9, this + 39) )
    DriverNameIDLookup(this + 39, this[2], 1, 0, 0);
  else
    v4 = 1;
  if ( !a2 || v4 )
    return 0;
  TextFormatStructInitializer(this);
  return 1;
}
