// Function: FUN_0054ba00 @ 0054ba00
// Size (bytes): 158


void __thiscall FUN_0054ba00(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_2 + 0x48) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x48) + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x48) = *(undefined4 *)(param_2 + 0x48);
  }
  if (param_2 == *(int *)(DAT_008b8f28 + 0x108)) {
    *(undefined4 *)(DAT_008b8f28 + 0x108) = *(undefined4 *)(param_2 + 0x4c);
  }
  if (param_3 != 0) {
    FUN_00544c50(param_2);
  }
  iVar1 = *(int *)(param_1 + 0x44);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x44) = param_2;
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
  *(int *)(param_2 + 0x40) = param_1;
  if ((*(int *)(param_2 + 0x230) != 0) && (*(int *)(param_1 + 0x230) != 0)) {
    FUN_00560eb0(*(int *)(param_2 + 0x230));
  }
  return;
}


