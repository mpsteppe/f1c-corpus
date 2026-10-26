// Function: FUN_004f1120 @ 004f1120
// Size (bytes): 439


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f1120(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_20 = 0.0;
  piVar4 = (int *)(param_1 + 0x3668);
  iVar5 = 4;
  fVar1 = DAT_0059e440;
  fVar2 = DAT_0059e440;
  local_18 = DAT_0059e440;
  local_14 = DAT_0059e440;
  local_10 = DAT_0059e440;
  do {
    if ((*piVar4 != 0) && (*(int *)(*(int *)(*piVar4 + 0x54) + 0x30) == param_2)) {
      fVar3 = param_3;
      if (_DAT_0059ec20 < param_3) {
        fVar3 = _DAT_0059ec20;
      }
      fVar3 = fVar3 * (float)piVar4[-0x27] * _DAT_005ad234;
      if (local_20 < fVar3) {
        local_20 = fVar3;
      }
      fVar1 = fVar3 + fVar1;
      fVar2 = (param_3 * _DAT_005ac988 + _DAT_0059e8cc) * fVar3 + fVar2;
      local_18 = fVar3 * (float)piVar4[-0x37] + local_18;
      local_14 = fVar3 * (float)piVar4[-0x36] + local_14;
      local_10 = local_10 + fVar3 * (float)piVar4[-0x35];
    }
    piVar4 = piVar4 + 0x3e;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (local_20 <= _DAT_0059e600) {
    return;
  }
  fVar1 = _DAT_0059e43c / fVar1;
  local_18 = local_18 * fVar1;
  local_14 = local_14 * fVar1;
  local_10 = fVar1 * local_10;
  if (local_20 <= _DAT_0059e43c) {
    param_3 = local_20;
  }
  else {
    param_3 = 1.0;
  }
  local_c = local_18;
  local_8 = local_14;
  local_4 = local_10;
  FUN_004f8850(param_2,1,param_3,fVar2 * fVar1,&local_18);
  return;
}


