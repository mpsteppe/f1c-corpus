// Function: FUN_00599495 @ 00599495
// Size (bytes): 39


int __fastcall FUN_00599495(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_00587d02(*(int *)(param_1 + 0x50));
    if (iVar1 == 0) {
      FUN_005994bc(0,2);
      return param_1;
    }
  }
  return 0;
}


