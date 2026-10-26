// Function: FUN_00545150 @ 00545150
// Size (bytes): 249


undefined4 __thiscall FUN_00545150(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x44) != 0) {
    FUN_00545150(*(int *)(param_2 + 0x44));
    *(undefined4 *)(param_2 + 0x44) = 0;
  }
  if ((*(int *)(param_2 + 0x40) != 0) && (*(int *)(param_2 + 0x4c) != 0)) {
    FUN_00545150(*(int *)(param_2 + 0x4c));
    *(undefined4 *)(param_2 + 0x4c) = 0;
  }
  iVar1 = FUN_0054a770();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_2 + 0x230) != 0) {
    FUN_00560e50();
    if (*(int *)(param_2 + 0x40) == 0) {
      FUN_005459d0(*(undefined4 *)(param_2 + 0x230));
    }
    else if (*(int *)(*(int *)(param_2 + 0x40) + 0x230) != 0) {
      FUN_00560f10(*(undefined4 *)(param_2 + 0x230));
    }
    iVar1 = *(int *)(param_2 + 0x230);
    if (iVar1 != 0) {
      FUN_00560c00();
      FUN_00587bcf(iVar1);
    }
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x14c)) {
    iVar2 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x150) + 0x10 + iVar2) == param_2) {
        *(undefined4 *)(*(int *)(param_1 + 0x150) + 0x10 + iVar2) = 0;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < *(int *)(param_1 + 0x14c));
  }
  FUN_005452b0(param_2);
  FUN_0054a710();
  FUN_00587bcf(param_2);
  return 0;
}


