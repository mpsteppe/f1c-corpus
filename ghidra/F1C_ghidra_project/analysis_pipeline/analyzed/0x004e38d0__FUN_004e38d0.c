// Function: FUN_004e38d0 @ 004e38d0
// Size (bytes): 102


void __fastcall FUN_004e38d0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xba8) < 0) {
    *(undefined4 *)(param_1 + 0xba8) = 0;
  }
  else if (0xb < *(int *)(param_1 + 0xba8)) {
    *(undefined4 *)(param_1 + 0xba8) = 0xb;
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xba8)) {
    do {
      FUN_004ded20();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0xba8));
  }
  *(undefined4 *)(param_1 + 0xba8) = 0;
  return;
}


