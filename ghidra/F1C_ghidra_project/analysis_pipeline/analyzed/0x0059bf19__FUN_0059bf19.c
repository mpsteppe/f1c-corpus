// Function: FUN_0059bf19 @ 0059bf19
// Size (bytes): 61


undefined4 * __thiscall FUN_0059bf19(undefined4 *param_1,undefined4 *param_2)

{
  size_t sVar1;
  void *pvVar2;
  
  *param_1 = &PTR_FUN_005b9dc0;
  sVar1 = _strlen((char *)*param_2);
  pvVar2 = operator_new(sVar1 + 1);
  param_1[1] = pvVar2;
  if (pvVar2 != (void *)0x0) {
    FUN_0058fca0(pvVar2,*param_2);
  }
  param_1[2] = 1;
  return param_1;
}


