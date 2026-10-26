// Function: FUN_0054b770 @ 0054b770
// Size (bytes): 473


void __fastcall FUN_0054b770(int param_1)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float local_80 [4];
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_40 [64];
  
  if (*(int *)(param_1 + 0x40) == 0) {
    if ((*(byte *)(param_1 + 0x3c) & 1) != 0) {
      puVar4 = (undefined4 *)(param_1 + 0xd4);
      puVar6 = (undefined4 *)(param_1 + 0x114);
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
    }
  }
  else {
    (**(code **)(*DAT_008b8f24 + 8))
              (DAT_008b8f24,param_1 + 0xd4,*(int *)(param_1 + 0x40) + 0x114,param_1 + 0x114);
  }
  uVar1 = *(uint *)(param_1 + 0x3c);
  iVar2 = 0x10;
  if ((uVar1 & 0x4000) != 0) {
    pfVar3 = (float *)(param_1 + 0xd4);
    pfVar5 = local_80;
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar5 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      pfVar5 = pfVar5 + 1;
    }
    local_80[0] = local_80[0] * *(float *)(param_1 + 0x194);
    local_80[1] = local_80[1] * *(float *)(param_1 + 0x194);
    local_80[2] = local_80[2] * *(float *)(param_1 + 0x194);
    fStack_70 = fStack_70 * *(float *)(param_1 + 0x198);
    fStack_6c = fStack_6c * *(float *)(param_1 + 0x198);
    fStack_68 = fStack_68 * *(float *)(param_1 + 0x198);
    fStack_60 = fStack_60 * *(float *)(param_1 + 0x19c);
    fStack_5c = fStack_5c * *(float *)(param_1 + 0x19c);
    fStack_58 = fStack_58 * *(float *)(param_1 + 0x19c);
    if (*(int *)(param_1 + 0x40) != 0) {
      if ((uVar1 & 1) != 0) {
        (**(code **)(*DAT_008b8f24 + 8))(DAT_008b8f24,local_80,param_1 + 0x94,auStack_40);
        (**(code **)(*DAT_008b8f24 + 8))
                  (DAT_008b8f24,auStack_40,*(int *)(param_1 + 0x40) + 0x114,param_1 + 0x1a0);
        return;
      }
      (**(code **)(*DAT_008b8f24 + 8))
                (DAT_008b8f24,local_80,*(int *)(param_1 + 0x40) + 0x114,param_1 + 0x1a0);
      return;
    }
    if ((uVar1 & 1) != 0) {
      (**(code **)(*DAT_008b8f24 + 8))(DAT_008b8f24,local_80,param_1 + 0x94,param_1 + 0x1a0);
      return;
    }
    pfVar3 = local_80;
    pfVar5 = (float *)(param_1 + 0x1a0);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar5 = *pfVar3;
      pfVar3 = pfVar3 + 1;
      pfVar5 = pfVar5 + 1;
    }
    return;
  }
  puVar4 = (undefined4 *)(param_1 + 0x114);
  puVar6 = (undefined4 *)(param_1 + 0x1a0);
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}


