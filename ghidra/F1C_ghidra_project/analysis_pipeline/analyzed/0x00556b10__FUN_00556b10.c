// Function: FUN_00556b10 @ 00556b10
// Size (bytes): 442


void __thiscall FUN_00556b10(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if ((*(byte *)(param_1 + 0x3c) & 0x10) == 0) {
    FUN_0054d7a0(param_2,param_3 + 0xdc,0);
    if ((*(byte *)(param_3 + 0x14) & 4) != 0) {
      FUN_0054d910(param_2,param_3 + 0x1c);
    }
  }
  else {
    if ((*(uint *)(param_3 + 0x14) & 0x20000000) == 0) {
      (**(code **)(*DAT_008b8f24 + 4))
                (DAT_008b8f24,*(int *)(param_1 + 0x204) + 0xdc,param_3 + 0xe8,param_1 + 0x1a0);
      *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | 0x20000000;
    }
    FUN_0054d7a0(param_2,param_3 + 0xe8,0);
    uVar2 = *(uint *)(param_3 + 0x14);
    if ((uVar2 & 4) != 0) {
      if ((uVar2 & 8) == 0) {
        *(uint *)(param_3 + 0x14) = uVar2 | 8;
        iVar4 = param_3 + 0x1c;
        iVar3 = 8;
        do {
          (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,iVar4,iVar4 + 0x60,param_1 + 0x1a0);
          iVar4 = iVar4 + 0xc;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      FUN_0054d910(param_2,param_3 + 0x7c);
    }
  }
  uVar2 = *(uint *)(param_3 + 0x14);
  if ((uVar2 & 5) != 0) {
    if ((*(byte *)(param_1 + 0x3c) & 0x10) == 0) {
      if ((uVar2 & 0x10000000) != 0) {
        iVar4 = 0;
        if (0 < *(int *)(param_3 + 0x118)) {
          iVar3 = 0;
          do {
            puVar1 = (uint *)(*(int *)(param_3 + 0x11c) + 0x38 + iVar3);
            *puVar1 = *puVar1 | 0x400;
            FUN_0055d720(param_2,1);
            iVar4 = iVar4 + 1;
            iVar3 = iVar3 + 0x40;
          } while (iVar4 < *(int *)(param_3 + 0x118));
        }
        *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) & 0xefffffff;
      }
    }
    else if (((uVar2 & 0x20) == 0) && ((uVar2 & 0x2000000) == 0)) {
      if ((**(uint **)(param_3 + 0x11c) & 0x100) != 0) {
        FUN_0055ed10(param_1,param_3,param_1 + 0x114);
      }
      if ((*(uint *)(param_3 + 0x14) & 0x100000) != 0) {
        FUN_0055d5c0(param_2,0);
        FUN_00556d60(param_3,param_2);
        return;
      }
    }
    FUN_00556d60(param_3,param_2);
  }
  return;
}


