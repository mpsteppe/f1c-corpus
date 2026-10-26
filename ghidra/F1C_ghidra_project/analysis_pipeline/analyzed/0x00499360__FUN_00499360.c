// Function: FUN_00499360 @ 00499360
// Size (bytes): 109


int __thiscall FUN_00499360(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_2 + 0x9c) = param_1;
  FUN_004869e0(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 4));
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar1 = FUN_00486320();
    while (iVar1 != 0) {
      FUN_00486320();
      iVar1 = FUN_00486320();
    }
    FUN_00486330(param_2);
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    return param_2;
  }
  *(int *)(param_1 + 0x44) = param_2;
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  return param_2;
}


