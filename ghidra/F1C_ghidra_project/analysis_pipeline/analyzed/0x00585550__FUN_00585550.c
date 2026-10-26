// Function: FUN_00585550 @ 00585550
// Size (bytes): 137


void __fastcall FUN_00585550(int param_1)

{
  char cVar1;
  DWORD DVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    cVar1 = FUN_00585680();
    if (cVar1 != '\0') break;
    Sleep(0xfa);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 10);
  if (*(int *)(param_1 + 4) != 0) {
    puVar3 = (undefined1 *)(param_1 + 0xc);
    if ((*(HANDLE *)(param_1 + 0x10) == (HANDLE)0x0) ||
       ((DVar2 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x10),*(DWORD *)(param_1 + 0x14)),
        DVar2 != 0 && (DVar2 != 0x80)))) {
      puVar3 = (undefined1 *)0x0;
    }
    *puVar3 = 1;
    if (*(HANDLE *)(param_1 + 0x10) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0x10));
    }
    WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
    CloseHandle(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}


