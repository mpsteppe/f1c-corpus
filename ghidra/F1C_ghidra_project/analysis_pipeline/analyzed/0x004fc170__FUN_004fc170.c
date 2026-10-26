// Function: FUN_004fc170 @ 004fc170
// Size (bytes): 261


void __thiscall FUN_004fc170(int *param_1,float param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_40 [16];
  
  uVar1 = (int)ROUND(param_2 * DAT_0059fec8) * 0x10101;
  if (param_1[0x10] != uVar1) {
    param_1[0x10] = uVar1;
    iVar3 = *param_1;
    if (iVar3 != 0) {
      local_40[0] = iVar3;
    }
    uVar5 = (uint)(iVar3 != 0);
    if (param_1[4] != 0) {
      local_40[uVar5] = param_1[4];
      uVar5 = uVar5 + 1;
    }
    iVar3 = param_1[0x12];
    iVar2 = 0;
    if (0 < iVar3) {
      do {
        if ((int)uVar5 < 0x10) {
          local_40[uVar5] = *(int *)(param_1[0x13] + iVar2 * 4);
          uVar5 = uVar5 + 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar3);
    }
    iVar3 = param_1[0x1f];
    iVar2 = 0;
    if (0 < iVar3) {
      do {
        if ((int)uVar5 < 0x10) {
          local_40[uVar5] = *(int *)(param_1[0x20] + iVar2 * 4);
          uVar5 = uVar5 + 1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar3);
    }
    param_2 = 0.0;
    if (0 < (int)uVar5) {
      do {
        iVar3 = FUN_0054c230(0);
        if (iVar3 != 0) {
          iVar2 = FUN_0054e100();
          iVar6 = 0;
          if (0 < iVar2) {
            do {
              iVar4 = FUN_0054e120(iVar6);
              iVar6 = iVar6 + 1;
              *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) & 0xff000000 | uVar1;
            } while (iVar6 < iVar2);
          }
          *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xefffffff;
        }
        param_2 = (float)((int)param_2 + 1);
      } while ((int)param_2 < (int)uVar5);
    }
  }
  return;
}


