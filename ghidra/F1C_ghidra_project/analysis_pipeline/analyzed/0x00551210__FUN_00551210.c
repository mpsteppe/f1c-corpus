// Function: FUN_00551210 @ 00551210
// Size (bytes): 370


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00551210(int param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  float *pfVar4;
  float *pfVar5;
  float local_1c;
  int local_14;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  if (*(float *)(iVar1 + 8) < param_3) {
    param_3 = *(float *)(iVar1 + 8);
  }
  iVar2 = __ftol();
  *(int *)(param_1 + 8) = iVar2;
  if (iVar2 < *(int *)(iVar1 + 0x14) + -1) {
    iVar2 = iVar2 + 1;
  }
  else if (iVar2 == *(int *)(iVar1 + 0x14)) {
    iVar2 = iVar2 + -1;
    *(int *)(param_1 + 8) = iVar2;
  }
  puVar3 = *(uint **)(param_1 + 0x18);
  local_14 = 0;
  if (0 < *(int *)(param_1 + 0x14)) {
    do {
      if ((*puVar3 & 0xff) < 0xff) {
        iVar1 = *(int *)((*puVar3 & 0xff) * 0x2c + 0x28 + *(int *)(*(int *)(param_1 + 0x1c) + 0x10))
        ;
        pfVar5 = (float *)(iVar2 * 0x20 + iVar1);
        pfVar4 = (float *)(*(int *)(param_1 + 8) * 0x20 + iVar1);
        if (*pfVar5 - *pfVar4 == (float)_DAT_0059e430) {
          local_1c = 0.0;
        }
        else {
          local_1c = (param_3 - *pfVar4) / (*pfVar5 - *pfVar4);
        }
        FUN_0053b490();
        FUN_0053b5b0(pfVar4 + 4,pfVar5 + 4,local_1c);
        FUN_0053b4c0(puVar3 + 1);
        puVar3[0xd] = (uint)((pfVar5[1] - pfVar4[1]) * local_1c + pfVar4[1]);
        puVar3[0xe] = (uint)((pfVar5[2] - pfVar4[2]) * local_1c + pfVar4[2]);
        puVar3[0xf] = (uint)((pfVar5[3] - pfVar4[3]) * local_1c + pfVar4[3]);
        FUN_0053b4a0();
      }
      puVar3 = puVar3 + 0x22;
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)(param_1 + 0x14));
  }
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10000;
  if (param_2 != 0) {
    FUN_0054b330(0x40,0x20,0);
  }
  return;
}


