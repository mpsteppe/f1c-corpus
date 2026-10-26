// Function: FUN_004cefe0 @ 004cefe0
// Size (bytes): 48


void __thiscall FUN_004cefe0(int param_1,int param_2,undefined4 param_3)

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
    FUN_004cd8d0(param_3);
  }
  return;
}


