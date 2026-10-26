// Function: FUN_005855e0 @ 005855e0
// Size (bytes): 149


undefined1 __fastcall FUN_005855e0(int param_1)

{
  undefined1 uVar1;
  DWORD DVar2;
  DWORD dwMilliseconds;
  undefined1 local_5;
  char *local_4;
  
  dwMilliseconds = 0;
  local_5 = 1;
  uVar1 = 1;
  if (*(int *)(param_1 + 4) != 0) {
    local_4 = (char *)(param_1 + 0x1c);
    if ((*(HANDLE *)(param_1 + 0x20) == (HANDLE)0x0) ||
       ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x20),*(DWORD *)(param_1 + 0x24)),
        DVar2 != 0 && (DVar2 != 0x80)))) {
      local_4 = (char *)0x0;
    }
    if (*local_4 == '\0') {
      do {
        dwMilliseconds = dwMilliseconds + 1;
        DVar2 = SuspendThread(*(HANDLE *)(param_1 + 4));
        if ((DVar2 != 0xffffffff) && (DVar2 != 0)) {
          *local_4 = '\x01';
          goto LAB_00585652;
        }
        Sleep(dwMilliseconds);
      } while ((int)dwMilliseconds < 0x32);
      local_5 = 0;
    }
LAB_00585652:
    uVar1 = local_5;
    if (*(HANDLE *)(param_1 + 0x20) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0x20));
    }
  }
  return uVar1;
}


