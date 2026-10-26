int __thiscall sub_42D370(char *this)
{
  const char *v3; // eax
  const char *v4; // eax
  char *v5; // eax
  int i; // eax
  char *v7; // eax
  int j; // eax
  _BYTE v9[256]; // [esp+4h] [ebp-100h] BYREF

  *(_DWORD *)this = 1;
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_11, 360) )
    DebugLogWrite(&dword_8AD25C, aEnteredGameEnt);
  if ( OSMan_Enter(&unk_7CE2A4) )
    return 1;
  if ( GameFileLoader(this) )
    return 1;
  if ( VidMan_Enter(&unk_8AFE18) )
    return 1;
  SpecialFX_Enter(&dword_8ACEA0);
  DynMan_Enter();
  PlayerFile_Enter(&byte_7CE498);
  v3 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v3 = &byte_5EA438;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v3, (const char *)dword_7D0434);
  if ( !(unsigned __int8)AudioFileLoadDecode(v9, 0) )
  {
    StringCopyWithBufferRealloc(aF12002Gdb);
    v4 = (const char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v4 = &byte_5EA438;
    StringFormatWithBufferOverflowCheck(v9, "%s%s", v4, (const char *)dword_7D0434);
    AudioFileLoadDecode(v9, 0);
  }
  v5 = (char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v5 = &byte_5EA438;
  sub_565F80(aRcd, 1, (int)v5, 0);
  for ( i = DirectoryEntryIterator(&unk_8AD3B0); i; i = DirectoryEntryIterator(&unk_8AD3B0) )
  {
    AudioFileLoadDecode(i, 0);
    LinkedListNodePeek(&unk_8AD3B0);
  }
  v7 = (char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v7 = &byte_5EA438;
  sub_565F80(aPit, 1, (int)v7, 0);
  for ( j = DirectoryEntryIterator(&unk_8AD3B0); j; j = DirectoryEntryIterator(&unk_8AD3B0) )
  {
    AudioFileLoadDecode(j, 0);
    LinkedListNodePeek(&unk_8AD3B0);
  }
  if ( Sound_Enter(&byte_8AC494) )
    return 1;
  if ( HWInput_Enter(&ppvOut) )
    return 1;
  EmptyStub_0170(&unk_7CE24D);
  EmptyStub_0170(&dword_8AB6E4);
  OnScreen_Enter(&dword_7CE048);
  EmptyStub_0170(&dword_8ACEE0);
  sub_463E20(&dword_7CD25C);
  return 0;
}
