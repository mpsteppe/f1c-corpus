// Function: FUN_005474d0 @ 005474d0
// Size (bytes): 409


undefined4 __thiscall
FUN_005474d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,char *param_5,
            char *param_6)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar1 = false;
  iVar2 = FUN_00548890(param_2);
  if ((iVar2 != 0) && ((param_4 & 0x100) == 0)) {
    *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + 1;
    return 0;
  }
  pvVar3 = operator_new(0xc4);
  if (pvVar3 != (void *)0x0) {
    iVar5 = FUN_00546250();
  }
  FUN_00546330(param_2,param_1);
  iVar2 = *(int *)(iVar5 + 0xa4);
  *(int *)(iVar5 + 0xa4) = iVar2 + 1;
  if ((param_6 != (char *)0x0) && (*param_6 != '\0')) {
    bVar1 = true;
    *(int *)(iVar5 + 0xa4) = iVar2 + 2;
  }
  iVar2 = *(int *)(iVar5 + 0xa4);
  piVar4 = operator_new(iVar2 * 0x94 + 4);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = iVar2;
    piVar4 = piVar4 + 1;
    if (-1 < iVar2 + -1) {
      do {
        FUN_0054fb90();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  *(int **)(iVar5 + 0xa8) = piVar4;
  if ((param_5 == (char *)0x0) || (*param_5 == '\0')) {
    iVar2 = FUN_00547100(0);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  else {
    FUN_0054fc10(param_5);
    iVar2 = FUN_00546f30(0);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  if (bVar1) {
    FUN_0054fc10(param_6);
    iVar2 = FUN_00546f70(1);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  *(uint *)(*(int *)(iVar5 + 0xa8) + 0x40) = param_4;
  *(undefined4 *)(iVar5 + 0x9c) = param_3;
  FUN_00547670(iVar5);
  *(uint *)(iVar5 + 0x9c) = *(uint *)(iVar5 + 0x9c) | 3;
  return 0;
}


