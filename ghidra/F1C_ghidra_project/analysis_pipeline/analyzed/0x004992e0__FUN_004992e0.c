// Function: FUN_004992e0 @ 004992e0
// Size (bytes): 127


void __thiscall FUN_004992e0(int param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 != 0) && (*(int *)(param_1 + 0x4c) = param_2, param_3 != '\0')) {
    iVar2 = *(int *)(param_1 + 0x50);
    iVar1 = *(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 0xc);
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + 1;
    }
    iVar2 = *(int *)(iVar2 + 8) - *(int *)(iVar2 + 4);
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + 1;
    }
    FUN_0049acc0((iVar1 / 2 - *(int *)(param_1 + 0xc)) -
                 *(int *)(*(int *)(param_2 + 0xc) + 0x1c) / 2,
                 (iVar2 / 2 - *(int *)(param_1 + 4)) - *(int *)(*(int *)(param_2 + 0xc) + 0x20) / 2)
    ;
  }
  return;
}


