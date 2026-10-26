// Function: FUN_00562d20 @ 00562d20
// Size (bytes): 102


undefined4 __fastcall FUN_00562d20(int param_1)

{
  SOCKET SVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    iVar3 = 0;
    while( true ) {
      SVar1 = socket(2,2,0x11);
      *(SOCKET *)(iVar3 + *(int *)(param_1 + 8)) = SVar1;
      if (*(int *)(*(int *)(param_1 + 8) + iVar3) == -1) break;
      *(undefined4 *)(*(int *)(param_1 + 8) + iVar3 + 4) = 0;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*(int *)(param_1 + 8) + 8 + iVar3) = 0;
      iVar3 = iVar3 + 0x1c;
      if (*(int *)(param_1 + 0x6c) <= iVar2) {
        return 0;
      }
    }
    if (iVar2 == 0) {
      return 1;
    }
    *(int *)(param_1 + 0x6c) = iVar2;
  }
  return 0;
}


