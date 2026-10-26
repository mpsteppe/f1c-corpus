// Function: FUN_00464fd0 @ 00464fd0
// Size (bytes): 41


undefined4 * __fastcall FUN_00464fd0(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xe5d0);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00464c10();
    *param_1 = uVar2;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


