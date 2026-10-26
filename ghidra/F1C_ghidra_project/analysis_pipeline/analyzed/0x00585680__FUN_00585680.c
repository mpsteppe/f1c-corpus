// Function: FUN_00585680 @ 00585680
// Size (bytes): 240


undefined1 __fastcall FUN_00585680(int param_1)

{
  DWORD DVar1;
  DWORD dwMilliseconds;
  float10 fVar2;
  undefined1 local_5;
  char *local_4;
  
  local_5 = 1;
  if (*(HANDLE *)(param_1 + 0xd4) != (HANDLE)0x0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0xd4),*(DWORD *)(param_1 + 0xd8));
  }
  fVar2 = (float10)FUN_00583680();
  FUN_00583660((float)fVar2);
  if (*(HANDLE *)(param_1 + 0xd4) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xd4));
  }
  if (*(int *)(param_1 + 4) == 0) {
    return 1;
  }
  local_4 = (char *)(param_1 + 0x1c);
  dwMilliseconds = 0;
  if ((*(HANDLE *)(param_1 + 0x20) == (HANDLE)0x0) ||
     ((DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x20),*(DWORD *)(param_1 + 0x24)),
      DVar1 != 0 && (DVar1 != 0x80)))) {
    local_4 = (char *)0x0;
  }
  if (*local_4 != '\0') {
    do {
      dwMilliseconds = dwMilliseconds + 1;
      DVar1 = ResumeThread(*(HANDLE *)(param_1 + 4));
      if ((DVar1 == 0) || (DVar1 == 1)) {
        *local_4 = '\0';
        goto LAB_00585743;
      }
      Sleep(dwMilliseconds);
    } while ((int)dwMilliseconds < 0x32);
    local_5 = 0;
  }
LAB_00585743:
  if (*(HANDLE *)(param_1 + 0x20) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0x20));
  }
  return local_5;
}


