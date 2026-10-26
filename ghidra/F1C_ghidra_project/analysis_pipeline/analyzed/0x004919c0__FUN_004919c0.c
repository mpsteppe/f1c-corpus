// Function: FUN_004919c0 @ 004919c0
// Size (bytes): 113


undefined4 __thiscall
FUN_004919c0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar2 = FUN_00490940(param_4,param_5);
  iVar1 = *param_1;
  uVar3 = 0;
  if (iVar2 != 0) {
    piVar4 = operator_new(0xc);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      *piVar4 = iVar2;
      piVar4[1] = 0;
      *(undefined1 *)(piVar4 + 2) = 0;
    }
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(int *)(iVar1 + 0xc) = (int)piVar4;
      *(int **)(iVar1 + 0x14) = piVar4;
      *(int **)(iVar1 + 0x10) = piVar4;
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
      return 1;
    }
    *(int **)(*(int *)(iVar1 + 0x10) + 4) = piVar4;
    *(int **)(iVar1 + 0x10) = piVar4;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
    uVar3 = 1;
  }
  return uVar3;
}


