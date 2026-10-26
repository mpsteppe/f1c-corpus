// Function: FUN_00549110 @ 00549110
// Size (bytes): 85


undefined4 FUN_00549110(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_00549110(*(int *)(param_1 + 0x44));
  }
  if ((*(int *)(param_1 + 0x40) != 0) && (*(int *)(param_1 + 0x4c) != 0)) {
    FUN_00549110(*(int *)(param_1 + 0x4c));
  }
  iVar1 = FUN_0054a770();
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  FUN_0054a710();
  FUN_00587bcf(param_1);
  return 0;
}


