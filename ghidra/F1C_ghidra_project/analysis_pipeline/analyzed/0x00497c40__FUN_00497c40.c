// Function: FUN_00497c40 @ 00497c40
// Size (bytes): 187


undefined4 __thiscall FUN_00497c40(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  iVar5 = 0;
  iVar3 = *(int *)(param_1 + 0x104);
  if (*(int *)(param_1 + 0x104) != 0) {
    while( true ) {
      iVar4 = iVar3;
      puVar2 = *(undefined1 **)(iVar4 + 4);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(puVar2,param_2);
      if (iVar3 == 0) break;
      iVar3 = *(int *)(iVar4 + 0x10);
      iVar5 = iVar4;
      if (*(int *)(iVar4 + 0x10) == 0) {
        return 0;
      }
    }
    if (iVar5 == 0) {
      *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar4 + 0x10);
    }
    else {
      *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
    }
    FUN_00494fd0(*(undefined4 *)(iVar4 + 0xc));
    *(undefined4 *)(iVar4 + 0xc) = 0;
    if (*(int *)(iVar4 + 0xc) != 0) {
      FUN_00542e50();
      iVar3 = *(int *)(iVar4 + 0xc);
      if (iVar3 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar3);
      }
    }
    if (*(int *)(iVar4 + 4) != 0) {
      FUN_00587bcf(*(int *)(iVar4 + 4));
    }
    FUN_00587bcf(iVar4);
    uVar1 = 1;
  }
  return uVar1;
}


