// Function: FUN_004b54e0 @ 004b54e0
// Size (bytes): 325


void __thiscall FUN_004b54e0(int param_1,uint *param_2)

{
  uint uVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  piVar5 = *(int **)(param_1 + 0x20);
  uVar1 = param_2[2];
  uVar6 = *param_2 >> 0x12 & 0x3f;
  *(int **)(param_1 + 0x28) = piVar5;
  if (piVar5 != (int *)0x0) {
    iVar7 = *piVar5;
    while (iVar7 != 0) {
      if ((uVar6 == *(uint *)(iVar7 + 0x368)) && ((char)uVar1 == *(char *)(iVar7 + 0x36c)))
      goto LAB_004b560f;
      if (*(int *)(param_1 + 0x28) != 0) {
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 4);
      }
      if (*(int **)(param_1 + 0x28) == (int *)0x0) break;
      iVar7 = **(int **)(param_1 + 0x28);
    }
  }
  piVar5 = *(int **)(param_1 + 0x10);
  iVar7 = 0;
  *(int **)(param_1 + 0x18) = piVar5;
  if (piVar5 != (int *)0x0) {
    iVar7 = *piVar5;
    *(undefined1 *)(piVar5 + 2) = 0;
    cVar2 = FUN_004ba7a0(iVar7,1);
    if (cVar2 == '\0') {
      iVar7 = 0;
    }
  }
  if (iVar7 == 0) {
    pvVar3 = operator_new(4);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_004ba980(0);
    }
    FUN_004bad70(uVar4,0);
    iVar7 = FUN_004bae20();
  }
  thunk_FUN_00500170();
  *(undefined1 *)(iVar7 + 0x36c) = 0xff;
  *(undefined4 *)(iVar7 + 0x368) = 0;
  *(undefined4 *)(iVar7 + 0x370) = DAT_005acd24;
  *(uint *)(iVar7 + 0x368) = uVar6;
  *(char *)(iVar7 + 0x36c) = (char)uVar1;
  *(undefined4 *)(iVar7 + 0x370) = *(undefined4 *)(param_1 + 0x30);
  piVar5 = operator_new(0xc);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    *piVar5 = iVar7;
    piVar5[1] = 0;
    *(undefined1 *)(piVar5 + 2) = 0;
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    *(int **)(param_1 + 0x20) = piVar5;
    *(int **)(param_1 + 0x28) = piVar5;
  }
  else {
    *(int **)(*(int *)(param_1 + 0x24) + 4) = piVar5;
  }
  *(int **)(param_1 + 0x24) = piVar5;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
LAB_004b560f:
  FUN_004fffb0(*(undefined4 *)(param_1 + 0x30),param_2);
  return;
}


