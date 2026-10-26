int __thiscall sub_414A90(const char **this)
{
  const char *v2; // edi
  const char *v3; // edx
  const char *v4; // ecx
  const char *v5; // eax
  const char *v6; // edi
  const char *v7; // edx
  const char *v8; // ecx
  const char *v9; // eax
  _BYTE v11[128]; // [esp+8h] [ebp-100h] BYREF
  char v12[128]; // [esp+88h] [ebp-80h] BYREF

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
  v4 = (const char *)dword_5EC428;
  if ( !dword_5EC428 )
    v4 = &byte_5EA438;
  v5 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v5 = &byte_5EA438;
  StringFormatWithBufferOverflowCheck(v12, "%s%s%s\\pws%s_", v5, v4, v3, v2);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, "TB");
  if ( FilePathExtensionCheck((int)v11, (int)(this + 3)) )
    sub_417640(this + 3, this[2], 0, 1);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, "TE");
  if ( FilePathExtensionCheck((int)v11, (int)(this + 8)) )
    sub_417640(this + 8, this[2], 0, 0);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, (const char *)&off_5C23CC);
  if ( FilePathExtensionCheck((int)v11, (int)(this + 13)) )
    sub_417AF0(this + 13, this[2], 0, 1);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, (const char *)&off_5C23C8);
  if ( FilePathExtensionCheck((int)v11, (int)(this + 18)) )
    sub_417AF0(this + 18, this[2], 0, 0);
  v6 = *this;
  if ( *this )
  {
    v7 = *this;
  }
  else
  {
    v6 = &byte_5EA438;
    v7 = &byte_5EA438;
  }
  v8 = (const char *)dword_5EC428;
  if ( !dword_5EC428 )
    v8 = &byte_5EA438;
  v9 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v9 = &byte_5EA438;
  StringFormatWithBufferOverflowCheck(v12, "%s%s%s\\tv%s_", v9, v8, v7, v6);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, "TB");
  if ( FilePathExtensionCheck((int)v11, (int)(this + 23)) )
    sub_417640(this + 23, this[2], 1, 1);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, "TE");
  if ( FilePathExtensionCheck((int)v11, (int)(this + 28)) )
    sub_417640(this + 28, this[2], 1, 0);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, (const char *)&off_5C23CC);
  if ( FilePathExtensionCheck((int)v11, (int)(this + 33)) )
    sub_417AF0(this + 33, this[2], 1, 1);
  StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, (const char *)&off_5C23C8);
  if ( FilePathExtensionCheck((int)v11, (int)(this + 38)) )
    sub_417AF0(this + 38, this[2], 1, 0);
  return 0;
}
