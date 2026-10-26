// Function: FUN_00405b90 @ 00405b90
// Size (bytes): 470


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00405b90(int *param_1)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  float10 fVar10;
  float local_2c;
  float local_28;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  local_28 = (float)param_1[0x10];
  uVar1 = param_1[6];
  iVar2 = param_1[0x15];
  bVar9 = true;
  local_2c = 0.5;
  if (param_1[5] == 1) {
    iVar7 = (**(code **)(*param_1 + 0x1c))();
    bVar9 = iVar7 != 1;
  }
  fVar3 = (float)param_1[10] - *(float *)(iVar2 + 0x58);
  fVar4 = (float)param_1[0xb] - *(float *)(iVar2 + 0x5c);
  fVar5 = (float)param_1[0xc] - *(float *)(iVar2 + 0x60);
  fVar6 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar5 * fVar5);
  if ((uVar1 & 8) == 0) {
    fVar10 = (float10)FUN_00406020(fVar6);
    local_28 = (float)fVar10;
  }
  fStack_10 = _DAT_0059e43c;
  if (DAT_0059e440 < fVar6) {
    fStack_10 = _DAT_0059e43c / fVar6;
  }
  fStack_18 = fVar3 * fStack_10;
  fStack_14 = fVar4 * fStack_10;
  fStack_10 = fStack_10 * fVar5;
  fStack_c = fStack_18;
  fStack_8 = fStack_14;
  fStack_4 = fStack_10;
  if ((!bVar9) && ((uVar1 & 1) == 0)) {
    FUN_00405f80(&fStack_18);
  }
  if (((uVar1 & 4) == 0) || ((uVar1 & 8) == 0)) {
    fVar10 = (float10)FUN_00406060(&fStack_18);
    local_2c = (float)fVar10;
  }
  _AIL_set_sample_volume_levels_12
            (*(undefined4 *)(param_1[0x16] + 0x10),(_DAT_0059e43c - local_2c) * local_28,
             local_2c * local_28);
  _AIL_set_sample_playback_rate_8
            (*(undefined4 *)(param_1[0x16] + 0x10),
             (int)ROUND(*(float *)(param_1[0x15] + 0x8c) * (float)param_1[0x12] *
                        (float)param_1[0x11]));
  FUN_00406100();
  if (bVar9) {
    if ((uVar1 & 0x10) != 0) {
      DAT_008aae70 = DAT_008aae70 + 1;
      uVar8 = __ftol();
      _AIL_set_sample_position_8(*(undefined4 *)(param_1[0x16] + 0x10),uVar8);
      _AIL_resume_sample_4(*(undefined4 *)(param_1[0x16] + 0x10));
      return 0;
    }
    _AIL_start_sample_4(*(undefined4 *)(param_1[0x16] + 0x10));
  }
  return 0;
}


