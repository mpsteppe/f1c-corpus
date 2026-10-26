// Function: FUN_00559200 @ 00559200
// Size (bytes): 168


int __thiscall FUN_00559200(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  pvVar2 = operator_new(0x6c);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00557410();
  }
  iVar4 = FUN_00557480(param_3);
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 0x148);
    if (iVar4 == 0) {
      *(int *)(param_1 + 0x148) = iVar3;
    }
    else {
      for (iVar1 = *(int *)(iVar4 + 0x68); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x68)) {
        iVar4 = iVar1;
      }
      *(int *)(iVar4 + 0x68) = iVar3;
      *(int *)(iVar3 + 100) = iVar4;
    }
    *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0x144) + 1;
    if (param_2 != (int *)0x0) {
      *param_2 = iVar3;
    }
    iVar3 = FUN_00543fa0();
    return -(uint)(iVar3 != 0);
  }
  if (iVar3 != 0) {
    FUN_00557470();
    FUN_00587bcf(iVar3);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  return -1;
}


