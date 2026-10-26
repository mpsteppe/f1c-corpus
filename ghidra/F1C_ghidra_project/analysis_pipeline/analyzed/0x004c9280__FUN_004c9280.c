// Function: FUN_004c9280 @ 004c9280
// Size (bytes): 43


undefined4 __thiscall FUN_004c9280(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == *(int *)(param_1 + 0x1c)) {
    piVar1 = (int *)FUN_004c9260();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x1c))();
      if (iVar2 != 2) {
        return 1;
      }
    }
  }
  return 0;
}


