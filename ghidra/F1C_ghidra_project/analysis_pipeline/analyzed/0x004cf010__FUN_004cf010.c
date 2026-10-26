// Function: FUN_004cf010 @ 004cf010
// Size (bytes): 43


void __thiscall FUN_004cf010(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar2 = *(int *)(param_1 + 0x14);
    while (*(int *)(iVar2 + 4) != param_2) {
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x6c;
      if (*(int *)(param_1 + 0x10) <= iVar1) {
        return;
      }
    }
    FUN_004cb5e0();
  }
  return;
}


