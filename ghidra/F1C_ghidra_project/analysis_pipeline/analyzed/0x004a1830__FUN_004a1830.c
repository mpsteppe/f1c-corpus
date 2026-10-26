// Function: FUN_004a1830 @ 004a1830
// Size (bytes): 151


undefined4 FUN_004a1830(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD dwMilliseconds;
  tagMSG local_1c;
  
  iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  while( true ) {
    if (iVar1 == 0) {
      if ((DAT_007ce2e4 == '\0') && (dwMilliseconds = FUN_004b1780(), -1 < (int)dwMilliseconds)) {
        Sleep(dwMilliseconds);
      }
      return 0;
    }
    BVar2 = GetMessageA(&local_1c,(HWND)0x0,0,0);
    if (BVar2 == 0) break;
    TranslateMessage(&local_1c);
    DispatchMessageA(&local_1c);
    iVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  }
  return 0xffffffff;
}


