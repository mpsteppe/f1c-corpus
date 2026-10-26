// Function: FUN_00585470 @ 00585470
// Size (bytes): 211


void __fastcall FUN_00585470(LPVOID param_1)

{
  DWORD DVar1;
  undefined1 *puVar2;
  HANDLE hThread;
  int iVar3;
  
  iVar3 = 0;
  do {
    if ((*(int *)((int)param_1 + iVar3 * 0x28 + 4) == 0) && (iVar3 == 0)) {
      puVar2 = (undefined1 *)((int)param_1 + 0xc);
      if ((*(HANDLE *)((int)param_1 + 0x10) == (HANDLE)0x0) ||
         ((DVar1 = WaitForSingleObject(*(HANDLE *)((int)param_1 + 0x10),
                                       *(DWORD *)((int)param_1 + 0x14)), DVar1 != 0 &&
          (DVar1 != 0x80)))) {
        puVar2 = (undefined1 *)0x0;
      }
      *puVar2 = 0;
      if (*(HANDLE *)((int)param_1 + 0x10) != (HANDLE)0x0) {
        ReleaseMutex(*(HANDLE *)((int)param_1 + 0x10));
      }
      puVar2 = (undefined1 *)((int)param_1 + 0x1c);
      if ((*(HANDLE *)((int)param_1 + 0x20) == (HANDLE)0x0) ||
         ((DVar1 = WaitForSingleObject(*(HANDLE *)((int)param_1 + 0x20),
                                       *(DWORD *)((int)param_1 + 0x24)), DVar1 != 0 &&
          (DVar1 != 0x80)))) {
        puVar2 = (undefined1 *)0x0;
      }
      *puVar2 = 1;
      if (*(HANDLE *)((int)param_1 + 0x20) != (HANDLE)0x0) {
        ReleaseMutex(*(HANDLE *)((int)param_1 + 0x20));
      }
      hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00583d90,param_1,4,
                             (LPDWORD)((int)param_1 + 8));
      *(HANDLE *)((int)param_1 + 4) = hThread;
      if (hThread != (HANDLE)0x0) {
        SetThreadPriority(hThread,1);
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 1);
  return;
}


