// Function: FUN_0058de2c @ 0058de2c
// Size (bytes): 304


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0058de2c(int param_1,int param_2,double param_3,double *param_4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  
  dVar1 = (double)CONCAT44(param_2,param_1);
  if ((double)CONCAT44(param_2,param_1) < _DAT_005b8cc8) {
    dVar1 = -dVar1;
  }
  dVar2 = _DAT_005e7718;
  if (param_3._4_4_ == 0x7ff00000) {
    if (param_3._0_4_ != 0) {
LAB_0058deb7:
      if (param_2 == 0x7ff00000) {
        if (param_1 != 0) {
          return 0;
        }
        if (_DAT_005b8cc8 < param_3) goto LAB_0058df52;
        if (param_3 < _DAT_005b8cc8) goto LAB_0058dee9;
      }
      else {
        if (param_2 != -0x100000) {
          return 0;
        }
        if (param_1 != 0) {
          return 0;
        }
        iVar3 = FUN_0058df5c(param_3);
        if (_DAT_005b8cc8 < param_3) {
          dVar2 = _DAT_005e7718;
          if (iVar3 == 1) {
            dVar2 = -_DAT_005e7718;
          }
          goto LAB_0058df52;
        }
        if (param_3 < _DAT_005b8cc8) {
          dVar2 = _DAT_005e7738;
          if (iVar3 != 1) {
            dVar2 = 0.0;
          }
          goto LAB_0058df52;
        }
      }
      dVar2 = 1.0;
      goto LAB_0058df52;
    }
    if (_DAT_005b8c80 < dVar1) goto LAB_0058df52;
    if (_DAT_005b8c80 <= dVar1) {
LAB_0058de7c:
      *param_4 = _DAT_005e7720;
      return 1;
    }
  }
  else {
    if ((param_3._4_4_ != -0x100000) || (param_3._0_4_ != 0)) goto LAB_0058deb7;
    if (dVar1 <= _DAT_005b8c80) {
      if (_DAT_005b8c80 <= dVar1) goto LAB_0058de7c;
      goto LAB_0058df52;
    }
  }
LAB_0058dee9:
  dVar2 = 0.0;
LAB_0058df52:
  *param_4 = dVar2;
  return 0;
}


