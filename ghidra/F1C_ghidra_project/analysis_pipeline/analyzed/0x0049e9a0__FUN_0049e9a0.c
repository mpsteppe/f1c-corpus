// Function: FUN_0049e9a0 @ 0049e9a0
// Size (bytes): 107


undefined4 __thiscall FUN_0049e9a0(int param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x60);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0054fe10();
  }
  *(int *)(param_1 + 0xc) = iVar2;
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) | 1;
    iVar2 = FUN_00550080(param_2,0,0x804);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 0xc);
      if (iVar2 != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar2);
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return *(undefined4 *)(param_1 + 0xc);
}


