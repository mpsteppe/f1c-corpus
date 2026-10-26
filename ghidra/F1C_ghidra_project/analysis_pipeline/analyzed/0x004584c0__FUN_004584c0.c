// Function: FUN_004584c0 @ 004584c0
// Size (bytes): 274


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004584c0(int param_1,float *param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *extraout_ECX;
  float *extraout_EDX;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  FUN_00455f90();
  FUN_00455f90();
  FUN_00455f90();
  FUN_00455f90();
  fVar1 = *param_2;
  fVar2 = *param_3;
  fVar3 = *extraout_EDX;
  fVar4 = *extraout_ECX;
  FUN_00455fd0();
  FUN_00455fd0();
  fVar1 = ABS(fVar3 - fVar4) + ABS(fVar1 - fVar2);
  param_5 = fVar1 * *(float *)(param_1 + 0xa4) * param_5;
  if ((fVar1 < param_5 == (fVar1 == param_5)) && (fVar1 < DAT_0059e440 == (fVar1 == DAT_0059e440)))
  {
    param_2 = (float *)(param_5 / fVar1);
    if (_DAT_0059e43c < (float)param_2) {
      param_2 = (float *)0x3f800000;
    }
    FUN_00567030();
    FUN_00567030();
    FUN_00567580(local_20,local_30,param_2);
    FUN_00567010();
    return;
  }
  *param_4 = *param_2;
  param_4[1] = param_2[1];
  param_4[2] = param_2[2];
  return;
}


