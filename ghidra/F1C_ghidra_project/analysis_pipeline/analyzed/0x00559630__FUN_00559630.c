// Function: FUN_00559630 @ 00559630
// Size (bytes): 175


int __thiscall FUN_00559630(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = iVar1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
    if ((*(int *)(iVar2 + 0x14) == param_2) && (*(int *)(iVar2 + 0x18) == param_3)) {
      return iVar2;
    }
  }
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 0x1c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      iVar1 = iVar2;
    }
    pvVar3 = operator_new(0x20);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_00559330();
    }
    *(undefined4 *)(iVar1 + 0x1c) = uVar4;
    FUN_00559390(param_2,param_3);
    return extraout_ECX_01;
  }
  pvVar3 = operator_new(0x20);
  if (pvVar3 != (void *)0x0) {
    uVar4 = FUN_00559330();
    *(undefined4 *)(param_1 + 8) = uVar4;
    FUN_00559390(param_2,param_3);
    return extraout_ECX;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_00559390(param_2,param_3);
  return extraout_ECX_00;
}


