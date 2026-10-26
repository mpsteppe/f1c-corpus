// Function: FUN_00431d40 @ 00431d40
// Size (bytes): 103


undefined4 * __fastcall FUN_00431d40(undefined4 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = operator_new(0x50);
  *param_1 = puVar1;
  *puVar1 = 0;
  param_1[1] = 0x50;
  puVar1 = operator_new(0x50);
  param_1[2] = puVar1;
  *puVar1 = 0;
  param_1[3] = 0x50;
  puVar1 = operator_new(0x80);
  param_1[4] = puVar1;
  *puVar1 = 0;
  param_1[5] = 0x80;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return param_1;
}


