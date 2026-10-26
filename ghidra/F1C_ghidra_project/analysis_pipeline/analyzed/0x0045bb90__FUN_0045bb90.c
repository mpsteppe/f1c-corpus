// Function: FUN_0045bb90 @ 0045bb90
// Size (bytes): 41


undefined4 * __fastcall FUN_0045bb90(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x32c);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0045bb40();
    *param_1 = uVar2;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


