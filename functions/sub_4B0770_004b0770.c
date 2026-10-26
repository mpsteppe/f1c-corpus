int __thiscall sub_4B0770(int *this, int a2)
{
  char *v3; // ecx
  _DWORD v5[7]; // [esp+Ch] [ebp-11Ch] BYREF
  CHAR FileName[256]; // [esp+28h] [ebp-100h] BYREF

  sub_568620(256);
  StringCopyWithBufferRealloc(FileName);
  v3 = &byte_5EA438[strlen(byte_5EA438)];
  if ( v3 > byte_5EA438 )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= byte_5EA438 )
        goto LABEL_6;
    }
    *v3 = 0;
  }
LABEL_6:
  sub_5665B0(aTmp);
  ToggleFileReadOnlyAttributeViaWin32API(FileName, 128);
  ToggleFileReadOnlyAttributeViaWin32API(byte_5EA438, 128);
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_20, 1766) )
    DebugLogWrite(&dword_8AD25C, aAttemptingToSa);
  ZeroInitSmallStruct(v5);
  sub_566940(byte_5EA438, 0, 1, 1);
  if ( v5[0] )
    LinkedListDispatchWithVTableCalls(this, (int)v5, (int)asc_5D2018);
  ConditionalFileHandleCloseWithFlagDispatch(v5);
  SettingsFileInit(this);
  ConfigFileParser(&dword_7C73E8, (int)this);
  FileDeleteWithErrorHandling(FileName);
  MoveFileAWrapperWithErrorHandling(byte_5EA438, FileName);
  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_20, 1789) )
    DebugLogWrite(&dword_8AD25C, aRetcodeDForRen);
  SubCallWithConditionalFieldFree(v5);
  return 0;
}
