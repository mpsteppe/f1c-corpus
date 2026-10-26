// Function: FUN_0055bc00 @ 0055bc00
// Size (bytes): 287


undefined4 __thiscall FUN_0055bc00(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  
  iVar3 = *(int *)(param_1 + 0x120);
  if (iVar3 != 0) {
    iVar4 = iVar3;
    for (iVar1 = *(int *)(iVar3 + 0x20); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
      if ((((*(int *)(iVar4 + 8) == param_2) && (*(int *)(iVar4 + 0xc) == param_3)) &&
          (*(int *)(iVar4 + 0x14) == param_4)) && (*(int *)(iVar4 + 0x18) == param_5)) {
        return 0xfffffffd;
      }
      iVar4 = iVar1;
    }
  }
  if (iVar3 == 0) {
    pvVar2 = operator_new(0x24);
    if (pvVar2 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0x120) = 0;
      uRam0000001c = 0;
    }
    else {
      iVar3 = FUN_0055baf0();
      *(int *)(param_1 + 0x120) = iVar3;
      *(undefined4 *)(iVar3 + 0x1c) = 0;
    }
  }
  else {
    for (iVar4 = *(int *)(iVar3 + 0x20); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x20)) {
      iVar3 = iVar4;
    }
    pvVar2 = operator_new(0x24);
    if (pvVar2 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_0055baf0();
    }
    *(int *)(iVar3 + 0x20) = iVar4;
    *(int *)(iVar4 + 0x1c) = iVar3;
  }
  if (param_4 == 6) {
    iVar3 = 0x10;
  }
  else if (param_4 == 5) {
    iVar3 = 0x10;
  }
  else if (param_4 == 7) {
    iVar3 = 0x18;
  }
  else {
    iVar3 = 0x20;
    if (param_4 != 8) {
      iVar3 = param_5;
    }
  }
  FUN_0055bb20(*(undefined4 *)(param_1 + 0x11c),param_2,param_3,iVar3,param_4,param_5);
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
  return 0;
}


