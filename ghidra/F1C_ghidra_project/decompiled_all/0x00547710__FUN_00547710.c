// Function: FUN_00547710 @ 00547710
// Strings:  [ALREADY DELETED]


void __thiscall FUN_00547710(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 local_100 [256];
  
  iVar2 = FUN_005469c0();
  if ((iVar2 == 0) && (*(int *)(param_2 + 0x88) == 0)) {
    if (*(int *)(param_2 + 0x9c) == -1) {
      FUN_0058815f(local_100,s_ALREADY_DELETED_005dbe60);
    }
    uVar1 = *(uint *)(param_2 + 0x9c);
    if ((uVar1 & 0x20) == 0) {
      if ((uVar1 & 0x100) == 0) {
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
      }
      else {
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      }
    }
    else if ((uVar1 & 0x100) == 0) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    }
    else {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    }
    if (*(int *)(param_2 + 0xbc) != 0) {
      *(undefined4 *)(*(int *)(param_2 + 0xbc) + 0xc0) = *(undefined4 *)(param_2 + 0xc0);
    }
    if (*(int *)(param_2 + 0xc0) != 0) {
      *(undefined4 *)(*(int *)(param_2 + 0xc0) + 0xbc) = *(undefined4 *)(param_2 + 0xbc);
    }
    if (*(int *)(param_1 + 0x24) == param_2) {
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 0xc0);
    }
    FUN_00546370();
    FUN_00557470();
    FUN_00587bcf(param_2);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
  }
  return;
}


