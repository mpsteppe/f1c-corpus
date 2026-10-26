// Function: FUN_004f8440 @ 004f8440
// Size (bytes): 883


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004f8440(int *param_1)

{
  int *piVar1;
  char cVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float local_24;
  float local_20;
  int *local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = (float)param_1[5] * (float)param_1[8] +
             (float)param_1[9] * (float)param_1[6] + (float)param_1[10] * (float)param_1[7] +
             (float)param_1[2];
  local_14 = (float)param_1[0xb] * (float)param_1[5] +
             (float)param_1[0xc] * (float)param_1[6] + (float)param_1[0xd] * (float)param_1[7] +
             (float)param_1[3];
  local_10 = (float)param_1[0xe] * (float)param_1[5] +
             (float)param_1[0xf] * (float)param_1[6] + (float)param_1[0x10] * (float)param_1[7] +
             (float)param_1[4];
  if ((float)param_1[0x27] != DAT_0059e440) {
    FUN_004f8850(0x1a,1,param_1[0x27],param_1[0x28],param_1 + 0x29);
  }
  if ((*(uint *)(*param_1 + 0x48bc) >> 1 & 1) != 0) {
    if ((char)param_1[0x2c] == '\0') {
      local_1c = param_1 + 0x1a6;
    }
    else {
      local_1c = param_1 + 0x195;
    }
    local_24 = 0.0;
    local_20 = ((float)param_1[0x23] - (float)param_1[0x21]) * (float)param_1[0x22];
    if (DAT_0059e440 < (float)param_1[0x23]) {
      if (DAT_0059e440 <= local_20) {
        if (_DAT_0059e43c < local_20) {
          local_20 = 1.0;
        }
      }
      else {
        local_20 = 0.0;
      }
      cVar2 = FUN_004c7bd0();
      if (cVar2 == '\0') {
        local_24 = (_DAT_005d67a0 * local_20 + _DAT_005d679c * (float)param_1[0x24] + _DAT_005d6798)
                   * _DAT_007cf35c * _DAT_007cf2f0;
      }
      else {
        local_24 = (_DAT_005d67ac * local_20 +
                    (float)param_1[0x24] * (float)param_1[0x24] * _DAT_005d67a8 + _DAT_005d67a4) *
                   _DAT_007cf2f0 * _DAT_007cf338;
      }
      if (DAT_0059e440 <= local_24) {
        if (_DAT_0059e43c < local_24) {
          local_24 = 1.0;
        }
      }
      else {
        local_24 = 0.0;
      }
    }
    FUN_004f6d90(param_1[0x23],&local_18,param_1 + 0x11,local_24);
    iVar4 = 5;
    do {
      piVar1 = *(int **)(local_1c[0x10] + iVar4 * 4);
      if ((char)param_1[iVar4 * 8 + 0x2d] == '\0') {
        if ((piVar1 != (int *)0x0) && (piVar1[5] == 1)) {
          (**(code **)(*piVar1 + 8))();
        }
      }
      else {
        if (piVar1 != (int *)0x0) {
          if (iVar4 == 0x2c) {
            param_1[399] = (int)(_DAT_007cf314 * local_24 * (float)param_1[399]);
            if (DAT_0059e440 <= (float)param_1[399]) {
              if (_DAT_0059e43c < (float)param_1[399]) {
                param_1[399] = 0x3f800000;
              }
            }
            else {
              param_1[399] = 0;
            }
          }
          if ((char)param_1[iVar4 * 8 + 0x31] == '\0') {
            iVar5 = param_1[(iVar4 + 6) * 8];
            pfVar3 = &local_18;
          }
          else {
            iVar5 = param_1[(iVar4 + 6) * 8];
            pfVar3 = &local_c;
            local_c = (float)param_1[8] * (float)param_1[iVar4 * 8 + 0x32] +
                      (float)param_1[9] * (float)param_1[iVar4 * 8 + 0x33] +
                      (float)param_1[10] * (float)param_1[iVar4 * 8 + 0x34] + (float)param_1[2];
            local_8 = (float)param_1[0xc] * (float)param_1[iVar4 * 8 + 0x33] +
                      (float)param_1[0xd] * (float)param_1[iVar4 * 8 + 0x34] +
                      (float)param_1[0xb] * (float)param_1[iVar4 * 8 + 0x32] + (float)param_1[3];
            local_4 = (float)param_1[0xf] * (float)param_1[iVar4 * 8 + 0x33] +
                      (float)param_1[0x10] * (float)param_1[iVar4 * 8 + 0x34] +
                      (float)param_1[0xe] * (float)param_1[iVar4 * 8 + 0x32] + (float)param_1[4];
          }
          (**(code **)(*piVar1 + 4))
                    (param_1[iVar4 * 8 + 0x2e],pfVar3,param_1 + 0x11,
                     DAT_007cf2cc * (float)param_1[iVar4 * 8 + 0x2f],iVar5,0);
        }
        *(undefined1 *)(param_1 + iVar4 * 8 + 0x2d) = 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x2d);
  }
  return;
}


