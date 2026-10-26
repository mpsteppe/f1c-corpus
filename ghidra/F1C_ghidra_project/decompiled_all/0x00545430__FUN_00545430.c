// Function: FUN_00545430 @ 00545430
// Strings:  [Could not create light]


undefined4 FUN_00545430(int *param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  pvVar1 = operator_new(0x70);
  if (pvVar1 != (void *)0x0) {
    iVar2 = FUN_0055d230();
    if (iVar2 != 0) {
      iVar3 = FUN_0055d2a0(param_2,param_3);
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      FUN_005454d0(iVar2,param_3);
      if (param_1 != (int *)0x0) {
        *param_1 = iVar2;
      }
      return 0;
    }
  }
  FUN_0053c590(0xffffffff,s_Could_not_create_light_005dbe30);
  return 0xffffffff;
}


