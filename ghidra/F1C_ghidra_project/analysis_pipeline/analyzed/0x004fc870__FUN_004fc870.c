// Function: FUN_004fc870 @ 004fc870
// Size (bytes): 145


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fc870(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined2 local_4;
  
  uVar1 = __ftol();
  *param_2 = uVar1;
  uVar1 = __ftol();
  param_2[1] = uVar1;
  uVar1 = __ftol();
  param_2[2] = uVar1;
  uVar1 = __ftol();
  param_2[3] = uVar1;
  local_4 = (undefined2)(int)ROUND(*(float *)(param_1 + 0x10) * _DAT_0059e6fc);
  param_2[4] = local_4;
  local_4 = (undefined2)(int)ROUND(*(float *)(param_1 + 0x14) * _DAT_0059e6fc);
  param_2[5] = local_4;
  return;
}


