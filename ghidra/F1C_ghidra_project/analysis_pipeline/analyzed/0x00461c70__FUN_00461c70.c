// Function: FUN_00461c70 @ 00461c70
// Size (bytes): 42


undefined4 * __fastcall FUN_00461c70(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x1ce60);
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0045d530(param_1);
    *param_1 = uVar2;
    return param_1;
  }
  *param_1 = 0;
  return param_1;
}


