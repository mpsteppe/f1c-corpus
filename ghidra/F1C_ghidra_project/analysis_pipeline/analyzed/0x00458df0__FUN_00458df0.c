// Function: FUN_00458df0 @ 00458df0
// Size (bytes): 540


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00458df0(int param_1,float *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float fVar7;
  float10 fVar8;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar7 = param_6;
  pfVar6 = param_2;
  local_c = *(undefined4 *)(param_1 + 0x18);
  local_8 = *(undefined4 *)(param_1 + 0x1c);
  local_4 = *(undefined4 *)(param_1 + 0x20);
  if (*(char *)(param_1 + 0xa0) != '\0') {
    *(undefined1 *)(param_1 + 0xa0) = 0;
  }
  if (*(int *)(param_1 + 0xb0) != 0) {
    FUN_00459070(param_2,param_4,param_6);
  }
  fVar1 = *(float *)(param_1 + 0xc) + *pfVar6;
  fVar2 = *(float *)(param_1 + 0x10) + pfVar6[1];
  fVar3 = *(float *)(param_1 + 0x14) + pfVar6[2];
  local_24 = fVar1;
  local_20 = fVar2;
  local_1c = fVar3;
  if ((*(byte *)(param_1 + 0x74) & 1) != 0) {
    FUN_00456040(&param_6,&param_2);
    fVar4 = _DAT_0059e6a4 / SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
    fVar5 = _DAT_0059e84c;
    if ((_DAT_0059e84c <= fVar4) && (fVar5 = fVar4, _DAT_0059e43c < fVar4)) {
      fVar5 = _DAT_0059e43c;
    }
    *(float *)(param_1 + 0x38) = param_6 * fVar5;
    *(float *)(param_1 + 0x3c) = fVar5 * (float)param_2;
  }
  fVar2 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (fVar2 < DAT_0059e440 == (fVar2 == DAT_0059e440)) {
    fVar2 = _DAT_0059e43c / SQRT(fVar2);
    local_24 = fVar1 * fVar2;
    local_20 = local_20 * fVar2;
    local_1c = fVar2 * local_1c;
  }
  fVar8 = (float10)FUN_00588570();
  local_18 = (float)fVar8;
  if ((local_24 == DAT_0059e440) && (local_1c == DAT_0059e440)) {
    local_14 = 0.0;
  }
  else {
    fVar8 = (float10)fpatan(-(float10)local_24,-(float10)local_1c);
    local_14 = (float)((float10)_DAT_0059efa4 - fVar8);
  }
  local_10 = 0.0;
  if (DAT_0059e440 < *(float *)(param_1 + 0xa4)) {
    FUN_004584c0(&local_18,&local_c,&local_24,fVar7);
    local_18 = local_24;
    local_14 = local_20;
    local_10 = local_1c;
  }
  FUN_00456130(&local_18);
  return 0;
}


