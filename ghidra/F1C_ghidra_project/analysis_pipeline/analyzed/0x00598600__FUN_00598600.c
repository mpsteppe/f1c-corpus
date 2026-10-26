// Function: FUN_00598600 @ 00598600
// Size (bytes): 43


undefined4 FUN_00598600(char *param_1)

{
  size_t sVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if (param_1 != (char *)0x0) {
    sVar1 = _strlen(param_1);
    pvVar2 = _malloc(sVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0058fca0(pvVar2,param_1);
      return uVar3;
    }
  }
  return 0;
}


