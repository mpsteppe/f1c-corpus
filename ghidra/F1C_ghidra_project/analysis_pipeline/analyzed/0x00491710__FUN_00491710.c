// Function: FUN_00491710 @ 00491710
// Size (bytes): 47


undefined4 * __thiscall FUN_00491710(undefined4 *param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x4c);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00490b00(param_2);
    *param_1 = uVar2;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


