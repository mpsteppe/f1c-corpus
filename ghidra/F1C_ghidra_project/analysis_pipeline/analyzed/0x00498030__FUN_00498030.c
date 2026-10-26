// Function: FUN_00498030 @ 00498030
// Size (bytes): 141


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00498030(int *param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 != (int *)0x0) {
    DAT_005cc9e0 = DAT_007cf2cc;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    if (DAT_007cf2cc <= _DAT_0059e43c) {
      if (DAT_007cf2cc < DAT_0059e440) {
        DAT_005cc9e0 = 0.0;
      }
    }
    else {
      DAT_005cc9e0 = 1.0;
    }
    (**(code **)(*param_1 + 4))(1,&local_c,&local_c,DAT_005cc9e0,0x3f800000,1);
  }
  return;
}


