// Function: FUN_0049e7b0 @ 0049e7b0
// Size (bytes): 312


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049e7b0(float param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  if (*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) ==
      *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
    fVar3 = ((float10)*(double *)(&DAT_007c7a48 + (int)param_1 * 0x464) - (float10)_DAT_0059ea60) *
            (float10)_DAT_0059e7d8;
    param_1 = (float)fVar3;
    if ((float10)DAT_0059e440 <= fVar3) {
      if (_DAT_0059e43c < param_1) {
        param_1 = 1.0;
      }
    }
    else {
      param_1 = 0.0;
    }
    FUN_00543440(param_2,param_3,param_4,param_5,0xff000000);
    if (DAT_0059e440 < param_1) {
      uVar2 = 0xffff0000;
      if (param_1 <= _DAT_0059e8cc) {
        if (_DAT_0059e450 < param_1) {
          uVar2 = 0xffffff00;
        }
      }
      else {
        uVar2 = 0xff00ff00;
      }
      uVar1 = __ftol(param_5,uVar2);
      FUN_00543440(param_2,param_3,uVar1,param_5,uVar2);
      return;
    }
  }
  else {
    FUN_00543440(param_2,param_3,param_4,param_5,0xff00ff00);
  }
  return;
}


