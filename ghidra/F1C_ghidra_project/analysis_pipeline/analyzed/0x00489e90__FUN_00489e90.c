// Function: FUN_00489e90 @ 00489e90
// Size (bytes): 68


void __fastcall FUN_00489e90(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x150) = 0;
  if (*(int *)(param_1 + 0x160) != 0) {
    uVar1 = __ftol();
    *(undefined4 *)(param_1 + 0x150) = uVar1;
  }
  return;
}


