// Function: FUN_0057edd0 @ 0057edd0
// Size (bytes): 163


void __fastcall FUN_0057edd0(int param_1)

{
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  undefined1 local_10 [4];
  u_long local_c;
  
  if ((*(HANDLE *)(param_1 + 0xb10) != (HANDLE)0x0) &&
     ((DVar3 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xb10),*(DWORD *)(param_1 + 0xb14)),
      DVar3 == 0 || (DVar3 == 0x80)))) {
    local_c = htonl(0);
    htons(0);
    FUN_0057b9f0(local_10);
    for (piVar1 = *(int **)(param_1 + 0xb00); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      if (((u_long *)*piVar1 != (u_long *)0x0) && (*(u_long *)*piVar1 == local_c)) {
        iVar2 = *piVar1;
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 4) = 0;
          *(undefined4 *)(iVar2 + 8) = 0;
          *(undefined4 *)(iVar2 + 0xc) = 0;
        }
        break;
      }
    }
    if (*(HANDLE *)(param_1 + 0xb10) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0xb10));
    }
  }
  return;
}


