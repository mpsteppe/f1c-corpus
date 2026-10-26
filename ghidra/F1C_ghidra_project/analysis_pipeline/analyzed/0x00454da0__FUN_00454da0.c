// Function: FUN_00454da0 @ 00454da0
// Size (bytes): 1105


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00454da0(int param_1,float param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  float fVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x1b20) == 2) {
    *(undefined4 *)(param_1 + 0x2410) = *(undefined4 *)(param_1 + 0x1b48);
  }
  else {
    fVar1 = _DAT_007d12c8 * param_2 * _DAT_0059e5fc;
    if (*(int *)(param_1 + 0x1b44) == 0) {
      if (*(int *)(param_1 + 0x1b70) == 0) {
        *(float *)(param_1 + 0x2410) = *(float *)(param_1 + 0x2410) - fVar1;
      }
      else {
        *(float *)(param_1 + 0x2410) = *(float *)(param_1 + 0x2410) - fVar1 * _DAT_0059e8a4;
      }
      if (*(float *)(param_1 + 0x2410) < DAT_0059e440) {
        *(undefined4 *)(param_1 + 0x2410) = 0;
      }
    }
    else {
      fVar1 = fVar1 + *(float *)(param_1 + 0x2410);
      *(float *)(param_1 + 0x2410) = fVar1;
      if (_DAT_0059e43c < fVar1) {
        *(undefined4 *)(param_1 + 0x2410) = 0x3f800000;
      }
    }
  }
  *param_4 = *(undefined4 *)(param_1 + 0x2410);
  if (*(int *)(param_1 + 0x1b4c) == 2) {
    *(undefined4 *)(param_1 + 0x2414) = *(undefined4 *)(param_1 + 0x1b74);
  }
  else {
    fVar1 = _DAT_007d12ec * param_2 * _DAT_0059e5fc;
    if (*(int *)(param_1 + 0x1b70) == 0) {
      fVar1 = *(float *)(param_1 + 0x2414) - fVar1;
      *(float *)(param_1 + 0x2414) = fVar1;
      if (fVar1 < DAT_0059e440) {
        *(undefined4 *)(param_1 + 0x2414) = 0;
      }
    }
    else {
      fVar1 = fVar1 + *(float *)(param_1 + 0x2414);
      *(float *)(param_1 + 0x2414) = fVar1;
      if (_DAT_0059e43c < fVar1) {
        *(undefined4 *)(param_1 + 0x2414) = 0x3f800000;
      }
    }
  }
  *param_5 = *(undefined4 *)(param_1 + 0x2414);
  if (*(int *)(param_1 + 0x21d4) == 2) {
    *(undefined4 *)(param_1 + 0x2418) = *(undefined4 *)(param_1 + 0x21fc);
  }
  else {
    fVar1 = _DAT_007d12ec * param_2 * _DAT_0059e5fc;
    if (*(int *)(param_1 + 0x21f8) == 0) {
      fVar1 = *(float *)(param_1 + 0x2418) - fVar1;
      *(float *)(param_1 + 0x2418) = fVar1;
      if (fVar1 < DAT_0059e440) {
        *(undefined4 *)(param_1 + 0x2418) = 0;
      }
    }
    else {
      fVar1 = fVar1 + *(float *)(param_1 + 0x2418);
      *(float *)(param_1 + 0x2418) = fVar1;
      if (_DAT_0059e43c < fVar1) {
        *(undefined4 *)(param_1 + 0x2418) = 0x3f800000;
      }
    }
  }
  *param_6 = *(undefined4 *)(param_1 + 0x2418);
  if ((*(int *)(param_1 + 0x1b78) == 2) && (*(int *)(param_1 + 0x1ba4) == 2)) {
    if (*(float *)(param_1 + 0x1ba0) <= DAT_0059e440) {
      *(undefined4 *)(param_1 + 0x241c) = *(undefined4 *)(param_1 + 0x1bcc);
    }
    else {
      *(float *)(param_1 + 0x241c) = -*(float *)(param_1 + 0x1ba0);
    }
  }
  else {
    fVar2 = _DAT_007d12a4 * param_2 * _DAT_0059e5fc;
    fVar1 = *(float *)(param_1 + 0x241c);
    if (*(int *)(param_1 + 0x1b9c) == 0) {
      if (*(int *)(param_1 + 0x1bc8) != 0) {
        if (fVar1 < DAT_0059e440) {
          *(float *)(param_1 + 0x241c) = _DAT_0059e478 * fVar2 + *(float *)(param_1 + 0x241c);
        }
        fVar2 = fVar2 + *(float *)(param_1 + 0x241c);
        *(float *)(param_1 + 0x241c) = fVar2;
        if (_DAT_0059e43c < fVar2) {
          *(undefined4 *)(param_1 + 0x241c) = 0x3f800000;
        }
        goto LAB_0045508f;
      }
    }
    else if (*(int *)(param_1 + 0x1bc8) == 0) {
      if (DAT_0059e440 < fVar1) {
        *(float *)(param_1 + 0x241c) = *(float *)(param_1 + 0x241c) - _DAT_0059e478 * fVar2;
      }
      fVar2 = *(float *)(param_1 + 0x241c) - fVar2;
      *(float *)(param_1 + 0x241c) = fVar2;
      if (fVar2 < _DAT_0059e670) {
        *(undefined4 *)(param_1 + 0x241c) = 0xbf800000;
      }
      goto LAB_0045508f;
    }
    if (fVar1 <= DAT_0059e440) {
      fVar2 = fVar2 + *(float *)(param_1 + 0x241c);
      *(float *)(param_1 + 0x241c) = fVar2;
      if (fVar2 <= DAT_0059e440) goto LAB_0045508f;
    }
    else {
      fVar2 = *(float *)(param_1 + 0x241c) - fVar2;
      *(float *)(param_1 + 0x241c) = fVar2;
      if (DAT_0059e440 <= fVar2) goto LAB_0045508f;
    }
    *(undefined4 *)(param_1 + 0x241c) = 0;
  }
LAB_0045508f:
  *param_3 = *(undefined4 *)(param_1 + 0x241c);
  if (*(char *)(param_1 + 0x2428) != '\0') {
    *(undefined4 *)(param_1 + 0x2424) = 0xfffffffe;
    if (*(int *)(param_1 + 0x20f0) == 0) {
      if (*(int *)(param_1 + 0x20c4) == 0) {
        if (*(int *)(param_1 + 0x2098) == 0) {
          if (*(int *)(param_1 + 0x206c) == 0) {
            if (*(int *)(param_1 + 0x2040) == 0) {
              if (*(int *)(param_1 + 0x2014) == 0) {
                if (*(int *)(param_1 + 0x1fe8) == 0) {
                  if (*(int *)(param_1 + 0x1fbc) != 0) {
                    *(undefined4 *)(param_1 + 0x2424) = 0xffffffff;
                  }
                }
                else {
                  *(undefined4 *)(param_1 + 0x2424) = 1;
                }
              }
              else {
                *(undefined4 *)(param_1 + 0x2424) = 2;
              }
            }
            else {
              *(undefined4 *)(param_1 + 0x2424) = 3;
            }
          }
          else {
            *(undefined4 *)(param_1 + 0x2424) = 4;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x2424) = 5;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x2424) = 6;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x2424) = 7;
    }
    if ((*(int *)(param_1 + 0x2424) == -2) && (DAT_007d1370 == '\x01')) {
      *(undefined4 *)(param_1 + 0x2424) = 0;
    }
  }
  *param_8 = *(undefined4 *)(param_1 + 0x2424);
  if (*(int *)(param_1 + 0x1c54) == 2) {
    *(undefined4 *)(param_1 + 0x2420) = *(undefined4 *)(param_1 + 0x1c7c);
  }
  else {
    if (*(int *)(param_1 + 0x1c78) != 0) {
      *(undefined4 *)(param_1 + 0x2420) = 0x3f800000;
      *param_7 = 0x3f800000;
      return;
    }
    fVar1 = *(float *)(param_1 + 0x2420) - _DAT_007d1310 * param_2 * _DAT_0059e5fc;
    *(float *)(param_1 + 0x2420) = fVar1;
    if (fVar1 < DAT_0059e440) {
      *(undefined4 *)(param_1 + 0x2420) = 0;
      *param_7 = 0;
      return;
    }
  }
  *param_7 = *(undefined4 *)(param_1 + 0x2420);
  return;
}


