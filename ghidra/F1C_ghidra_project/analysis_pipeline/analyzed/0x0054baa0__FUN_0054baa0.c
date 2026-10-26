// Function: FUN_0054baa0 @ 0054baa0
// Size (bytes): 155


void __thiscall FUN_0054baa0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x48) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x48) + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x48) = *(undefined4 *)(param_2 + 0x48);
  }
  if (*(int *)(param_1 + 0x44) == param_2) {
    iVar1 = *(int *)(param_2 + 0x4c);
    *(int *)(param_1 + 0x44) = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x48) = 0;
    }
  }
  if (DAT_008b8f28 != 0) {
    iVar1 = *(int *)(DAT_008b8f28 + 0x108);
    iVar2 = 0;
    if (iVar1 == 0) {
      *(int *)(DAT_008b8f28 + 0x108) = param_2;
    }
    else {
      iVar2 = iVar1;
      for (iVar1 = *(int *)(iVar1 + 0x4c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
        iVar2 = iVar1;
      }
      *(int *)(iVar2 + 0x4c) = param_2;
    }
    *(int *)(param_2 + 0x48) = iVar2;
    *(undefined4 *)(param_2 + 0x4c) = 0;
  }
  if (((*(int *)(param_2 + 0x230) != 0) && (*(int *)(param_2 + 0x40) != 0)) &&
     (*(int *)(*(int *)(param_2 + 0x40) + 0x230) != 0)) {
    FUN_00560f40(*(int *)(param_2 + 0x230));
  }
  *(undefined4 *)(param_2 + 0x40) = 0;
  return;
}


