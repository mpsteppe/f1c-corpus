// Function: FUN_005569f0 @ 005569f0
// Size (bytes): 275


void __thiscall FUN_005569f0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  FUN_00551760();
  FUN_0054b570(param_2,param_3);
  if (*(int *)(param_2 + 0x1ac) == 0) {
    FUN_0054d9f0();
  }
  if ((*(uint *)(param_3 + 0x14) & 0x20000000) == 0) {
    (**(code **)(*DAT_008b8f24 + 4))
              (DAT_008b8f24,*(int *)(param_1 + 0x204) + 0xdc,param_3 + 0xe8,param_1 + 0x1a0);
    *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | 0x20000000;
  }
  FUN_0054d7a0(param_2,param_3 + 0xe8,0);
  uVar1 = *(uint *)(param_3 + 0x14);
  if (((uVar1 & 4) != 0) && ((uVar1 & 8) == 0)) {
    *(uint *)(param_3 + 0x14) = uVar1 | 8;
    iVar3 = param_3 + 0x1c;
    iVar2 = 8;
    do {
      (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,iVar3,iVar3 + 0x60,param_1 + 0x1a0);
      iVar3 = iVar3 + 0xc;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((*(uint *)(param_3 + 0x14) & 5) != 0) {
    if ((*(uint *)(param_3 + 0x14) & 0x20) == 0) {
      if ((**(uint **)(param_3 + 0x11c) & 0x100) != 0) {
        FUN_0055ed10(param_1,param_3,param_1 + 0x114);
      }
      if ((*(uint *)(param_3 + 0x14) & 0x100000) != 0) {
        FUN_0055d5c0(param_2,0);
      }
    }
    FUN_00556d60(param_3,param_2);
  }
  return;
}


