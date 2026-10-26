// Function: FUN_004baac0 @ 004baac0
// Size (bytes): 93


undefined4 * __thiscall FUN_004baac0(undefined4 *param_1,char param_2)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = -(uint)(param_2 != '\0') & 0x20;
  pvVar2 = operator_new((uVar1 + 0x20) * 0xc);
  if (pvVar2 == (void *)0x0) {
    *param_1 = 0;
    return param_1;
  }
  iVar3 = uVar1 + 0x20;
  do {
    FUN_004b4450();
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = pvVar2;
  return param_1;
}


