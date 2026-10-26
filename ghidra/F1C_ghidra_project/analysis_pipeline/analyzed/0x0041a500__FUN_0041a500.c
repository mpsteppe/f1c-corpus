// Function: FUN_0041a500 @ 0041a500
// Size (bytes): 432


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041a500(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  param_1 = param_1 - (float)_DAT_008afea0;
  if (_DAT_0059e81c <= param_1) {
    return;
  }
  fVar1 = (float)_DAT_008afe98 + param_1;
  if (fVar1 < _DAT_0059e81c) {
    if (_DAT_0059e818 <= param_1) {
      return;
    }
    if (fVar1 < _DAT_0059e818) {
      if (_DAT_0059e814 <= param_1) {
        return;
      }
      if (fVar1 < _DAT_0059e814) {
        if (_DAT_0059e810 <= param_1) {
          return;
        }
        if (fVar1 < _DAT_0059e810) {
          if (_DAT_0059e80c <= param_1) {
            return;
          }
          if (fVar1 < _DAT_0059e80c) {
            if (_DAT_0059e808 <= param_1) {
              return;
            }
            if (fVar1 < _DAT_0059e808) {
              if (param_1 < DAT_0059e440 == (param_1 == DAT_0059e440)) {
                return;
              }
              if (DAT_005eb10c != (int *)0x0) {
                (**(code **)(*DAT_005eb10c + 0xc))();
              }
              FUN_004186a0();
              return;
            }
            uVar2 = 0x116;
          }
          else {
            uVar2 = 0x117;
          }
        }
        else {
          uVar2 = 0x114;
        }
      }
      else {
        uVar2 = 0x115;
      }
    }
    else {
      uVar2 = 0x22;
    }
  }
  else {
    uVar2 = 0x23;
  }
  FUN_004144d0();
  FUN_004144f0(uVar2,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
  FUN_00418560(local_20);
  return;
}


