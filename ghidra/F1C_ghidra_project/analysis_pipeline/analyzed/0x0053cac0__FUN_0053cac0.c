// Function: FUN_0053cac0 @ 0053cac0
// Size (bytes): 47


int FUN_0053cac0(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  
  pvVar1 = operator_new(0x30);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005473d0();
  }
  *param_1 = uVar2;
  iVar3 = FUN_00547400(0);
  return -(uint)(iVar3 != 0);
}


