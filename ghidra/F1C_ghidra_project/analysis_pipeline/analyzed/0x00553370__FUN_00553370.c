// Function: FUN_00553370 @ 00553370
// Size (bytes): 675


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00553370(uint *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == 1) {
    *param_1 = *param_1 & 0xfffffffd | 1;
    if (param_1[6] == 0) {
      pvVar3 = operator_new(0x180);
      param_1[6] = (uint)pvVar3;
    }
    if (param_1[5] == 0) {
      puVar5 = operator_new(0x24);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5[5] = 0;
        puVar5[4] = 0;
        puVar5[3] = 0;
        puVar5[2] = 0;
        puVar5[1] = 0;
        *puVar5 = 0;
        puVar5[7] = 0;
        puVar5[6] = 0;
        puVar5[8] = 0;
      }
      param_1[5] = (uint)puVar5;
    }
    else {
      FUN_00540eb0(param_1[5]);
    }
    *(undefined4 *)param_1[5] = 0x22;
    *(undefined4 *)(param_1[5] + 0xc) = 0x10;
    *(undefined4 *)(param_1[5] + 4) = 0x142;
    *(undefined4 *)(param_1[5] + 8) = 0x18;
    iVar4 = FUN_00540df0(param_1[5]);
    if (iVar4 != 0) {
      return 0xffffffff;
    }
    if (0 < (int)param_1[1]) {
      iVar4 = FUN_00540f00(param_1[5],0x60,0,0);
      iVar7 = 0;
      if (0 < (int)param_1[1]) {
        iVar6 = 0;
        puVar5 = (undefined4 *)(iVar4 + 8);
        do {
          puVar5[-2] = *(undefined4 *)(iVar6 + param_1[6]);
          puVar5[-1] = *(undefined4 *)(iVar6 + 4 + param_1[6]);
          *puVar5 = *(undefined4 *)(iVar6 + 8 + param_1[6]);
          puVar5[2] = *(undefined4 *)(iVar6 + 0x10 + param_1[6]);
          puVar5[3] = *(undefined4 *)(iVar6 + 0x14 + param_1[6]);
          puVar5[1] = *(undefined4 *)(iVar6 + 0xc + param_1[6]);
          iVar7 = iVar7 + 1;
          iVar6 = iVar6 + 0x18;
          puVar5 = puVar5 + 6;
        } while (iVar7 < (int)param_1[1]);
      }
      FUN_00540f90(param_1[5]);
      return 0;
    }
  }
  else if (param_2 == 2) {
    *param_1 = *param_1 & 0xfffffffe | 2;
    if (param_1[6] == 0) {
      pvVar3 = operator_new(0x1c0);
      param_1[6] = (uint)pvVar3;
    }
    if (param_1[5] == 0) {
      puVar5 = operator_new(0x24);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5[5] = 0;
        puVar5[4] = 0;
        puVar5[3] = 0;
        puVar5[2] = 0;
        puVar5[1] = 0;
        *puVar5 = 0;
        puVar5[7] = 0;
        puVar5[6] = 0;
        puVar5[8] = 0;
      }
      param_1[5] = (uint)puVar5;
    }
    else {
      FUN_00540eb0(param_1[5]);
    }
    *(undefined4 *)param_1[5] = 0x22;
    *(undefined4 *)(param_1[5] + 0xc) = 0x10;
    *(undefined4 *)(param_1[5] + 4) = 0x144;
    *(undefined4 *)(param_1[5] + 8) = 0x1c;
    iVar4 = FUN_00540df0(param_1[5]);
    if (iVar4 != 0) {
      return 0xffffffff;
    }
    if (0 < (int)param_1[1]) {
      iVar4 = FUN_00540f00(param_1[5],0x60,0,0);
      fVar2 = _DAT_008b8cf4;
      fVar1 = _DAT_008b8cf0 * (float)DAT_008b8dd4;
      iVar7 = 0;
      if (0 < (int)param_1[1]) {
        puVar5 = (undefined4 *)(iVar4 + 8);
        iVar4 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar5[-2] = fVar2 * *(float *)(iVar4 + param_1[6]) + fVar1;
          puVar5[-1] = *(undefined4 *)(iVar4 + 4 + param_1[6]);
          *puVar5 = *(undefined4 *)(iVar4 + 8 + param_1[6]);
          puVar5[1] = *(undefined4 *)(iVar4 + 0xc + param_1[6]);
          puVar5[3] = *(undefined4 *)(iVar4 + 0x14 + param_1[6]);
          puVar5[4] = *(undefined4 *)(iVar4 + 0x18 + param_1[6]);
          puVar5[2] = *(undefined4 *)(iVar4 + 0x10 + param_1[6]);
          puVar5 = puVar5 + 7;
          iVar4 = iVar4 + 0x1c;
        } while (iVar7 < (int)param_1[1]);
      }
      FUN_00540f90(param_1[5]);
    }
  }
  return 0;
}


