// Function: FUN_00599ed6 @ 00599ed6
// Size (bytes): 328


uint __thiscall FUN_00599ed6(int param_1,uint param_2)

{
  uint uVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int local_14;
  undefined4 *local_10;
  int local_c;
  undefined4 local_8;
  
  if ((short)param_2 == -1) {
    return 0;
  }
  uVar1 = **(uint **)(param_1 + 0x20);
  if ((uVar1 != 0) && (uVar1 < uVar1 + **(int **)(param_1 + 0x30) * 2)) {
    psVar3 = (short *)FUN_0059a43c();
    *psVar3 = (short)param_2;
    return param_2 & 0xffff;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    return 0xffff;
  }
  if (*(int *)(param_1 + 0x38) == 0) {
    sVar2 = FUN_0059bbaf(param_2,*(int *)(param_1 + 0x50));
LAB_00599fcf:
    if (sVar2 != -1) {
      return param_2;
    }
  }
  else {
    local_8 = param_2;
    FUN_00599348(0,DAT_005b9c38);
    FUN_005992ef(8,0);
    iVar4 = *(int *)(param_1 + 0x44);
    FUN_00599534();
    iVar5 = *(int *)(param_1 + 0x44);
    local_c = *(int *)(iVar4 + 4);
    FUN_00599534();
    iVar4 = (**(code **)(**(int **)(param_1 + 0x38) + 0x14))
                      (param_1 + 0x40,&local_8,(int)&local_8 + 2,&local_10,
                       *(undefined4 *)(iVar5 + 4),
                       -(uint)(local_c != 0) & *(int *)(iVar4 + 8) + local_c,&local_14);
    if (iVar4 != 0) {
      if (iVar4 != 1) {
        if (iVar4 != 3) {
          return 0xffff;
        }
        sVar2 = FUN_0059bbaf(local_8,*(undefined4 *)(param_1 + 0x50));
        goto LAB_00599fcf;
      }
      if (local_10 == &local_8) {
        return 0xffff;
      }
    }
    iVar4 = *(int *)(param_1 + 0x44);
    FUN_00599534();
    iVar5 = local_14 - *(int *)(iVar4 + 4);
    iVar4 = *(int *)(param_1 + 0x44);
    FUN_00599534();
    iVar4 = FUN_00588678(*(undefined4 *)(iVar4 + 4),1,iVar5,*(undefined4 *)(param_1 + 0x50));
    if (iVar4 == iVar5) {
      return param_2;
    }
  }
  return 0xffff;
}


