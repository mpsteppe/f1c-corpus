// Function: FUN_00461fc0 @ 00461fc0
// Size (bytes): 41


undefined4 __fastcall FUN_00461fc0(int *param_1)

{
  int iVar1;
  
  if (*(int *)(*param_1 + 0x1b79c) != 0) {
    iVar1 = FUN_00563e70();
    if (iVar1 == 1) {
      return 1;
    }
    if ((iVar1 == 2) || (iVar1 == 3)) {
      return 2;
    }
  }
  return 0;
}


