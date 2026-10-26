// Function: FUN_005684a0 @ 005684a0
// Size (bytes): 156


undefined1 __thiscall FUN_005684a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined1 uVar5;
  uint local_4;
  
  uVar5 = 0;
  if ((param_2 != 0) && (iVar2 = FUN_00568220(param_2), -1 < iVar2)) {
    local_4 = 0;
    uVar5 = 0;
    do {
      iVar3 = *(int *)(param_1 + local_4 * 4);
      while (iVar1 = iVar3, iVar1 != 0) {
        iVar3 = FUN_0049adb0();
        while (iVar3 != 0) {
          iVar3 = FUN_0049adb0();
          iVar4 = FUN_004979d0();
          if (iVar4 == iVar2) {
            FUN_00568320(extraout_ECX);
            uVar5 = 1;
          }
        }
        iVar3 = FUN_0055bfc0();
        iVar4 = FUN_004979d0();
        if (iVar4 == iVar2) {
          FUN_00568320(iVar1);
          uVar5 = 1;
        }
      }
      local_4 = local_4 + 1;
    } while (local_4 < 9);
  }
  return uVar5;
}


