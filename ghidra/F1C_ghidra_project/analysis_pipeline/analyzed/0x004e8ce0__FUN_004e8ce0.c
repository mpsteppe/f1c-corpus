// Function: FUN_004e8ce0 @ 004e8ce0
// Size (bytes): 1044


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall
FUN_004e8ce0(int param_1,float param_2,float *param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  float local_30;
  float local_2c;
  int local_24;
  int local_20;
  int local_1c;
  
  fVar2 = ABS(param_4) * *(float *)(param_1 + 0x3cfc);
  fVar4 = (float10)FUN_005895a2((double)fVar2);
  local_24 = (int)ROUND((float)fVar4);
  if (local_24 < 0) {
    local_30 = *(float *)(param_1 + 0x3d00);
  }
  else {
    if (0xd < local_24) {
      local_24 = 0xd;
    }
    local_30 = *(float *)(param_1 + 0x3d00 + local_24 * 4);
    local_30 = (fVar2 - (float)local_24) * (*(float *)(param_1 + 0x3d04 + local_24 * 4) - local_30)
               + local_30;
  }
  if (_DAT_0059e6fc < local_30) {
    local_30 = _DAT_0059e6fc;
  }
  local_2c = local_30 - _DAT_0059e46c;
  if (DAT_0059e440 <= local_2c) {
    local_30 = local_30 + _DAT_0059e46c;
  }
  else {
    local_2c = 0.0;
    local_30 = 8.0;
  }
  do {
    while( true ) {
      fVar3 = local_2c * local_2c;
      fVar2 = fVar3 * *(float *)(param_1 + 0x3a70) -
              (fVar3 * param_2 + param_3[1]) * *(float *)(param_1 + 0x3514);
      fVar3 = (fVar3 * param_4 - *param_3) * *(float *)(param_1 + 0x3514);
      if (DAT_0059e440 <= fVar3) {
        fVar2 = fVar2 * *(float *)(param_1 + 0x3c7c);
        fVar4 = (float10)FUN_005895a2((double)fVar2);
        local_24 = (int)ROUND((float)fVar4);
        if (local_24 < 0) {
          fVar1 = *(float *)(param_1 + 0x3c80);
        }
        else {
          if (0xd < local_24) {
            local_24 = 0xd;
          }
          fVar1 = *(float *)(param_1 + 0x3c80 + local_24 * 4);
          fVar1 = (fVar2 - (float)local_24) * (*(float *)(param_1 + 0x3c84 + local_24 * 4) - fVar1)
                  + fVar1;
        }
        fVar3 = fVar1 - fVar3;
      }
      else {
        fVar2 = fVar2 * *(float *)(param_1 + 0x3c3c);
        fVar4 = (float10)FUN_005895a2((double)fVar2);
        local_24 = (int)ROUND((float)fVar4);
        if (local_24 < 0) {
          fVar3 = *(float *)(param_1 + 0x3c40) + fVar3;
        }
        else {
          if (0xd < local_24) {
            local_24 = 0xd;
          }
          fVar1 = *(float *)(param_1 + 0x3c40 + local_24 * 4);
          fVar3 = (fVar2 - (float)local_24) * (*(float *)(param_1 + 0x3c44 + local_24 * 4) - fVar1)
                  + fVar1 + fVar3;
        }
      }
      fVar1 = local_30 * local_30;
      fVar2 = fVar1 * *(float *)(param_1 + 0x3a70) -
              (fVar1 * param_2 + param_3[1]) * *(float *)(param_1 + 0x3514);
      fVar1 = (fVar1 * param_4 - *param_3) * *(float *)(param_1 + 0x3514);
      if (DAT_0059e440 <= fVar1) {
        fVar2 = fVar2 * *(float *)(param_1 + 0x3c7c);
        fVar4 = (float10)FUN_005895a2((double)fVar2);
        local_1c = (int)ROUND((float)fVar4);
        if (local_1c < 0) {
          fVar4 = (float10)*(float *)(param_1 + 0x3c80);
        }
        else {
          if (0xd < local_1c) {
            local_1c = 0xd;
          }
          fVar4 = (float10)*(float *)(param_1 + 0x3c80 + local_1c * 4);
          fVar4 = ((float10)fVar2 - (float10)local_1c) *
                  ((float10)*(float *)(param_1 + 0x3c84 + local_1c * 4) - fVar4) + fVar4;
        }
        fVar4 = fVar4 - (float10)fVar1;
      }
      else {
        fVar2 = fVar2 * *(float *)(param_1 + 0x3c3c);
        fVar4 = (float10)FUN_005895a2((double)fVar2);
        local_20 = (int)ROUND((float)fVar4);
        if (local_20 < 0) {
          fVar4 = (float10)*(float *)(param_1 + 0x3c40) + (float10)fVar1;
        }
        else {
          if (0xd < local_20) {
            local_20 = 0xd;
          }
          fVar4 = (float10)*(float *)(param_1 + 0x3c40 + local_20 * 4);
          fVar4 = ((float10)fVar2 - (float10)local_20) *
                  ((float10)*(float *)(param_1 + 0x3c44 + local_20 * 4) - fVar4) + fVar4 +
                  (float10)fVar1;
        }
      }
      fVar5 = (float10)fVar3;
      if (fVar4 * fVar5 < (float10)DAT_0059e440 != (fVar4 * fVar5 == (float10)DAT_0059e440)) {
        if (fVar5 - fVar4 != (float10)DAT_0059e440) {
          return ((float10)local_30 - (float10)local_2c) * ((float10)fVar3 / (fVar5 - fVar4)) +
                 (float10)local_2c;
        }
        return ((float10)local_30 - (float10)local_2c) * (float10)_DAT_0059e450 + (float10)local_2c;
      }
      if (fVar5 < (float10)DAT_0059e440) break;
      if (fVar5 < fVar4) goto LAB_004e9091;
LAB_004e9008:
      if (_DAT_0059e6fc <= local_30) {
LAB_004e9091:
        return (float10)_DAT_0059e6fc;
      }
      local_30 = local_30 + param_5;
      if (_DAT_0059e6fc < local_30) {
        local_30 = 128.0;
      }
    }
    if (fVar5 < fVar4) goto LAB_004e9008;
    if (local_2c < DAT_0059e440 != (local_2c == DAT_0059e440)) {
      return (float10)DAT_0059e440;
    }
    fVar2 = local_2c - param_5;
    local_30 = local_2c;
    local_2c = fVar2;
    if (fVar2 < DAT_0059e440) {
      local_2c = 0.0;
    }
  } while( true );
}


