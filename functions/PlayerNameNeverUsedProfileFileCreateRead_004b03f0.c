int __thiscall sub_4B03F0(_BYTE *this)
{
  char *v2; // eax
  const char *v3; // edx
  const char *v4; // eax
  int v5; // eax
  int v6; // edi
  char v8[4]; // [esp+8h] [ebp-124h] BYREF
  CHAR FileName[32]; // [esp+Ch] [ebp-120h] BYREF
  _BYTE v10[253]; // [esp+2Ch] [ebp-100h] BYREF
  __int16 v11; // [esp+129h] [ebp-3h]
  char v12; // [esp+12Bh] [ebp-1h]

  AllocateStructWithDefaultValues(v8);
  StringFormatWithBufferOverflowCheck(FileName, &off_5D1FF0, aPlr);
  v2 = (char *)dword_5EC440;
  if ( !dword_5EC440 )
    v2 = byte_5EA438;
  sub_565F80(FileName, 1, (int)v2, 1);
  sub_566380(2);
  v3 = (const char *)DirectoryEntryIterator(v8);
  if ( v3 )
  {
    v10[0] = byte_5EA438[0];
    memset(&v10[1], 0, 0xFCu);
    v11 = 0;
    v12 = 0;
    v4 = (const char *)dword_5EC440;
    if ( !dword_5EC440 )
      v4 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v10, "%s%s", v4, v3);
    v5 = StringCopyFileCheckDispatch(v10, 1);
  }
  else
  {
    TextFileReader(aPlayernameneve);
    v5 = PlayerNameNeverUsedProfileFileCreateRead(this);
    this[18856] = 1;
    this[18857] = 1;
  }
  v6 = v5;
  LinkedListDestructorWithChildCleanup(v8);
  return v6;
}
