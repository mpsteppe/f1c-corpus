// Function: FUN_005878a0 @ 005878a0
// Size (bytes): 131


undefined1 __thiscall FUN_005878a0(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_00587880();
  if ((param_2 <= iVar1) && (0 < iVar1)) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x414) + 0x58))();
    if (iVar1 != 0) {
      FUN_00586800(0,0xd,0,1,*(undefined4 *)(param_1 + 0x40c));
      FUN_00586a00(param_1,*(undefined4 *)(param_1 + 0x400));
      (**(code **)(**(int **)(iVar1 + 0x48) + 0xc))(*(undefined4 *)(param_1 + 0x410));
      iVar1 = FUN_00585380(iVar1);
      if (iVar1 == 0) {
        uVar2 = 1;
      }
    }
    FUN_005879f0();
    return uVar2;
  }
  return 0;
}


