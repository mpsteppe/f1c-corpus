// Function: FUN_0048fc10 @ 0048fc10
// Size (bytes): 56


undefined4 __fastcall FUN_0048fc10(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x38] != 0) && (iVar1 = *(int *)(param_1[0x38] + 0x174), param_1[0x39] != iVar1)) {
    param_1[0x39] = iVar1;
    (**(code **)(*param_1 + 0x2c))(1);
  }
  (**(code **)(*param_1 + 0xa8))();
  return 0;
}


