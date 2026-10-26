// Function: FUN_005532a0 @ 005532a0
// Size (bytes): 105


undefined4 * __fastcall FUN_005532a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  FUN_0053c2a0();
  *param_1 = 2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  puVar1 = operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = 0;
    puVar1[4] = 0;
    puVar1[3] = 0;
    puVar1[2] = 0;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[7] = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0;
    param_1[5] = puVar1;
    return param_1;
  }
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[5] = 0;
  return param_1;
}


