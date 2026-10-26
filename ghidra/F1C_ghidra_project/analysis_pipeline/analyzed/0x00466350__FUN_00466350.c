// Function: FUN_00466350 @ 00466350
// Size (bytes): 768


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00466350(int *param_1)

{
  float10 fVar1;
  float10 fVar2;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (param_1[0x3b] == 0) {
    return;
  }
  local_10 = 0;
  local_24 = 0.0;
  local_20 = 0.0;
  local_28 = 0.0;
  local_14 = 0;
  local_18 = 0;
  FUN_00498730();
  FUN_00498880(&local_8,&local_c);
  local_4 = local_8 - param_1[0x41];
  local_1c = (float)(local_c - param_1[0x42]);
  FUN_00542420(&local_10,&local_24,&local_20,&local_28,&local_14,&local_18);
  local_28 = (float)param_1[0x48];
  fVar1 = (float10)local_28;
  local_24 = (float)param_1[0x46];
  local_20 = (float)param_1[0x47];
  if (*(char *)((int)param_1 + 0xf5) != '\0') {
    if (((char)param_1[0x3d] != '\0') && (DAT_007d0398 != 0)) {
      FUN_0054b3f0((float)local_4 * _DAT_0059f200,0,-((float)(int)local_1c * _DAT_0059f200));
      fVar1 = (float10)local_28;
      goto LAB_004665d7;
    }
    if (*(char *)((int)param_1 + 0xf5) != '\0') {
      param_1[0x3e] = (int)((float)param_1[0x3e] - (float)(int)local_1c * _DAT_0059e87c);
      if (DAT_007d0398 == 0) {
        local_1c = (float)param_1[0x3f];
        if ((float)param_1[0x40] <= (float)param_1[0x3e]) {
          if (local_1c < (float)param_1[0x3e]) {
            param_1[0x3e] = (int)local_1c;
          }
        }
        else {
          param_1[0x3e] = param_1[0x40];
        }
      }
      else {
        local_1c = (float)param_1[0x3f] + (float)param_1[0x3f];
        if ((float)param_1[0x40] * _DAT_0059e84c <= (float)param_1[0x3e]) {
          if (local_1c < (float)param_1[0x3e]) {
            param_1[0x3e] = (int)local_1c;
          }
        }
        else {
          param_1[0x3e] = (int)((float)param_1[0x40] * _DAT_0059e84c);
        }
      }
      goto LAB_004665d7;
    }
  }
  if ((char)param_1[0x3d] != '\0') {
    fVar1 = fVar1 - (float10)(int)local_1c * (float10)_DAT_0059f1fc;
    local_28 = (float)fVar1;
    if (DAT_007d0398 == 0) {
      if ((float10)_DAT_0059f1f8 <= fVar1) {
        if (fVar1 <= (float10)_DAT_0059f1f4) goto LAB_004665d7;
        fVar1 = (float10)_DAT_0059f1f4;
      }
      else {
        fVar1 = (float10)_DAT_0059f1f8;
      }
    }
    else {
      if ((float10)_DAT_0059e888 < fVar1) {
        do {
          fVar1 = fVar1 - (float10)_DAT_0059e888;
        } while ((float10)_DAT_0059e888 < fVar1);
        local_28 = (float)fVar1;
      }
      if ((float10)_DAT_0059f1f0 <= fVar1) goto LAB_004665d7;
      do {
        fVar1 = fVar1 + (float10)_DAT_0059e888;
      } while (fVar1 < (float10)_DAT_0059f1f0);
    }
    local_28 = (float)fVar1;
  }
LAB_004665d7:
  fVar2 = (float10)fsin(fVar1);
  local_24 = (float)(fVar2 * (float10)(float)param_1[0x3e]);
  fVar1 = (float10)fcos(fVar1);
  local_20 = (float)(fVar1 * (float10)(float)param_1[0x3e]);
  FUN_00541cd0(local_10,local_24,local_20,local_28,local_14,local_18);
  param_1[0x46] = (int)local_24;
  param_1[0x47] = (int)local_20;
  param_1[0x48] = (int)local_28;
  param_1[0x42] = local_c;
  (**(code **)(*param_1 + 0x2c))(1);
  return;
}


