// Function: FUN_00598e9e @ 00598e9e
// Size (bytes): 310


int __thiscall FUN_00598e9e(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int local_14;
  char *local_10;
  int local_c;
  char local_5;
  
  if (param_2 == -1) {
    return 0;
  }
  uVar1 = **(uint **)(param_1 + 0x20);
  cVar4 = (char)param_2;
  if ((uVar1 != 0) && (uVar1 < **(int **)(param_1 + 0x30) + uVar1)) {
    pcVar2 = (char *)FUN_00599485();
    *pcVar2 = cVar4;
    return param_2;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    return -1;
  }
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar3 = FUN_00589898((int)cVar4,*(int *)(param_1 + 0x50));
joined_r0x00598f89:
    if (iVar3 != -1) {
      return param_2;
    }
  }
  else {
    local_5 = cVar4;
    FUN_00599348(0,DAT_005b9c38);
    FUN_005992ef(8,0);
    iVar3 = *(int *)(param_1 + 0x44);
    FUN_00599534();
    iVar5 = *(int *)(param_1 + 0x44);
    local_c = *(int *)(iVar3 + 4);
    FUN_00599534();
    iVar3 = (**(code **)(**(int **)(param_1 + 0x38) + 0x14))
                      (param_1 + 0x40,&local_5,&stack0xfffffffc,&local_10,*(undefined4 *)(iVar5 + 4)
                       ,-(uint)(local_c != 0) & *(int *)(iVar3 + 8) + local_c,&local_14);
    if (iVar3 != 0) {
      if (iVar3 != 1) {
        if (iVar3 != 3) {
          return -1;
        }
        iVar3 = FUN_00589898((int)local_5,*(undefined4 *)(param_1 + 0x50));
        goto joined_r0x00598f89;
      }
      if (local_10 == &local_5) {
        return -1;
      }
    }
    iVar3 = *(int *)(param_1 + 0x44);
    FUN_00599534();
    iVar5 = local_14 - *(int *)(iVar3 + 4);
    iVar3 = *(int *)(param_1 + 0x44);
    FUN_00599534();
    iVar3 = FUN_00588678(*(undefined4 *)(iVar3 + 4),1,iVar5,*(undefined4 *)(param_1 + 0x50));
    if (iVar3 == iVar5) {
      return param_2;
    }
  }
  return -1;
}


