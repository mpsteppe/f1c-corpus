// Function: FUN_00563dc0 @ 00563dc0
// Size (bytes): 45


undefined4 __fastcall FUN_00563dc0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    iVar1 = 0;
    do {
      closesocket(*(SOCKET *)(*(int *)(param_1 + 8) + iVar1));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x1c;
    } while (iVar2 < *(int *)(param_1 + 0x6c));
  }
  return 0;
}


