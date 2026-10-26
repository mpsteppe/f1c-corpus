// Function: FUN_004d4870 @ 004d4870
// Size (bytes): 49


int __fastcall FUN_004d4870(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    if (PTR_FUN_005d43c4 != (undefined *)0x0) {
      iVar1 = (*(code *)PTR_FUN_005d43c4)();
      *(int *)(param_1 + 4) = iVar1;
      if (iVar1 != 0) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}


