// Function: FUN_004a3820 @ 004a3820
// Size (bytes): 240


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a3820(int param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_64;
  float afStack_60 [13];
  undefined4 local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;
  
  local_2c = 0;
  local_28 = *param_2 - _DAT_005acaf4;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_14 = 0;
  local_4 = 0;
  local_18 = *param_2 * _DAT_0059e450;
  local_10 = *param_2 * _DAT_0059e7f8;
  local_c = *param_2 * _DAT_0059e450;
  local_64 = 0;
  local_8 = *param_2 * _DAT_0059e7fc;
  if (0 < *(int *)(param_1 + 0xc)) {
    param_2 = (float *)0x0;
    do {
      iVar4 = *(int *)(param_1 + 0x10) + (int)param_2;
      iVar5 = 0;
      if (0 < *(int *)(*(int *)(param_1 + 0x10) + 0x70 + (int)param_2)) {
        iVar3 = 0;
        do {
          iVar1 = *(int *)(iVar4 + 0x74);
          iVar2 = iVar1 + iVar3;
          FUN_004a1fd0(afStack_60[*(int *)(iVar1 + 0x18 + iVar3)],
                       (*(float *)(iVar2 + 0x10) - *(float *)(iVar2 + 0xc)) +
                       afStack_60[*(int *)(iVar1 + 0x18 + iVar3)]);
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 0x1c;
        } while (iVar5 < *(int *)(iVar4 + 0x70));
      }
      local_64 = local_64 + 1;
      param_2 = (float *)((int)param_2 + 0x78);
    } while (local_64 < *(int *)(param_1 + 0xc));
  }
  return;
}


