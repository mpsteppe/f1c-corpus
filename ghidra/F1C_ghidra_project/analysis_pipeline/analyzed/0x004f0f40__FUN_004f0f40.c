// Function: FUN_004f0f40 @ 004f0f40
// Size (bytes): 477


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f0f40(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = (int)param_2;
  local_20 = 0.0;
  local_1c = 0.86;
  if (*(int *)(param_1 + 0x32bc) != 0) {
    local_1c = 0.5;
  }
  piVar5 = (int *)(param_1 + 0x3668);
  iVar6 = 4;
  fVar1 = DAT_0059e440;
  fVar2 = DAT_0059e440;
  local_18 = DAT_0059e440;
  local_14 = DAT_0059e440;
  local_10 = DAT_0059e440;
  do {
    if ((*piVar5 != 0) && ((float)*(int *)(*(int *)(*piVar5 + 0x54) + 0x34) == param_2)) {
      fVar3 = (local_1c - (float)piVar5[-0x26]) * (float)piVar5[-0x27] * _DAT_005ad230;
      if (local_20 < fVar3) {
        local_20 = fVar3;
      }
      if (DAT_0059e440 < fVar3) {
        fVar1 = fVar3 + fVar1;
        fVar2 = ((float)piVar5[-0x28] * _DAT_005ac988 +
                (_DAT_0059e9e4 - (float)piVar5[-0x26] * _DAT_0059e450)) * fVar3 + fVar2;
        local_18 = fVar3 * (float)piVar5[-0x37] + local_18;
        local_14 = fVar3 * (float)piVar5[-0x36] + local_14;
        local_10 = local_10 + fVar3 * (float)piVar5[-0x35];
      }
    }
    piVar5 = piVar5 + 0x3e;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if (local_20 <= _DAT_0059e600) {
    return;
  }
  fVar1 = _DAT_0059e43c / fVar1;
  local_18 = local_18 * fVar1;
  local_14 = local_14 * fVar1;
  local_10 = fVar1 * local_10;
  if (local_20 <= _DAT_0059e43c) {
    param_2 = local_20;
  }
  else {
    param_2 = 1.0;
  }
  local_c = local_18;
  local_8 = local_14;
  local_4 = local_10;
  FUN_004f8850(iVar4,2,param_2,fVar2 * fVar1,&local_18);
  return;
}


