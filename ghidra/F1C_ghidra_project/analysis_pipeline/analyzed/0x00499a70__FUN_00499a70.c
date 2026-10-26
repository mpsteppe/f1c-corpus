// Function: FUN_00499a70 @ 00499a70
// Size (bytes): 52


undefined4 __thiscall FUN_00499a70(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  
  if (param_2 == param_1) {
    return 0xffffffff;
  }
  puVar1 = (undefined1 *)*param_2;
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00566650(puVar1);
  param_1[2] = param_2[2];
  return 0;
}


