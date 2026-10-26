// Function: FUN_00467340 @ 00467340
// Size (bytes): 96


void __thiscall FUN_00467340(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 800) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 800) + 0x14);
    if (param_2 == 1) {
      iVar1 = iVar1 + 1;
    }
    else {
      iVar1 = iVar1 + -1;
    }
    if (*(int *)(param_1 + 0x32c) != 4) {
      FUN_0042eaa0(*(int *)(param_1 + 0x32c),*(undefined4 *)(param_1 + 0x328),iVar1);
      FUN_004673b0();
      return;
    }
    FUN_0042eb60(*(undefined4 *)(param_1 + 0x324),iVar1);
    FUN_004673b0();
  }
  return;
}


