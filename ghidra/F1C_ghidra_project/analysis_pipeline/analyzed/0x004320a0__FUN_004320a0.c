// Function: FUN_004320a0 @ 004320a0
// Size (bytes): 38


undefined4 * __fastcall FUN_004320a0(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x40);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_00431d40();
    *param_1 = uVar2;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


