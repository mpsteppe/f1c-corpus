// Function: FUN_004f0dd0 @ 004f0dd0
// Size (bytes): 356


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f0dd0(int *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  bool bVar4;
  float local_14;
  float local_8;
  
  if ((DAT_007c56ac == '\0') || (DAT_008ab6e4 == 2)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  local_14 = *(float *)(*param_1 + 0x1058);
  fVar1 = (float)param_1[0xd50] * _DAT_0059e99c;
  if (bVar4) {
    local_8 = SQRT((float)param_1[0xd3d] * (float)param_1[0xd3d] +
                   (float)param_1[0xd3c] * (float)param_1[0xd3c] +
                   (float)param_1[0xd3b] * (float)param_1[0xd3b]) * _DAT_0059f128 * _DAT_005acd3c *
              SQRT((float)param_1[0xd3d] * (float)param_1[0xd3d] +
                   (float)param_1[0xd3c] * (float)param_1[0xd3c] +
                   (float)param_1[0xd3b] * (float)param_1[0xd3b]) * _DAT_0059f128 * _DAT_005acd3c;
  }
  else {
    local_8 = 0.0;
  }
  uVar3 = _rand();
  uVar3 = uVar3 & 0x80000001;
  bVar4 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar4 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
  }
  fVar2 = _DAT_0059e670;
  if (bVar4) {
    fVar2 = _DAT_0059e43c;
  }
  local_14 = (float)_DAT_008afe98 * ((local_8 * _DAT_0059e8b4 * fVar2 + fVar1) - local_14) +
             local_14;
  if (_DAT_005ad22c <= local_14) {
    if (_DAT_0059e8b4 < local_14) {
      local_14 = 0.3;
    }
  }
  else {
    local_14 = -0.3;
  }
  FUN_004e0c90(local_14);
  return;
}


