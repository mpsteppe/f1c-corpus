// Function: FUN_0044aae0 @ 0044aae0
// Size (bytes): 456


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044aae0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  float10 fVar1;
  undefined1 local_28 [16];
  double local_18;
  double local_10;
  
  FUN_004484c0(param_1,param_2);
  fVar1 = (float10)FUN_004484f0();
  local_18 = (double)fVar1;
  FUN_004484c0(param_2,param_3);
  fVar1 = (float10)FUN_004484f0();
  local_10 = (double)fVar1;
  FUN_004484c0(param_3,param_1);
  fVar1 = (float10)FUN_004484f0();
  if (((local_10 <= local_18) && (fVar1 <= (float10)local_18)) && (_DAT_0059ef38 < local_18)) {
    FUN_00448480(param_1,param_2);
    FUN_0044aae0(param_1,local_28,param_3,param_4,param_5);
    FUN_0044aae0(local_28,param_2,param_3,param_4,param_5);
    return;
  }
  if (((local_18 <= local_10) && (fVar1 <= (float10)local_10)) && (_DAT_0059ef38 < local_10)) {
    FUN_00448480(param_2,param_3);
    FUN_0044aae0(param_1,param_2,local_28,param_4,param_5);
    FUN_0044aae0(param_1,local_28,param_3,param_4,param_5);
    return;
  }
  if ((((float10)local_18 <= fVar1) && ((float10)local_10 <= fVar1)) &&
     ((float10)_DAT_0059ef38 < fVar1)) {
    FUN_00448480(param_3,param_1);
    FUN_0044aae0(param_1,param_2,local_28,param_4,param_5);
    FUN_0044aae0(local_28,param_2,param_3,param_4,param_5);
    return;
  }
  FUN_004493a0(param_1,param_2,param_3,param_4,0);
  return;
}


