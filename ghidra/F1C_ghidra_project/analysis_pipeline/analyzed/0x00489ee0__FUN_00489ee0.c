// Function: FUN_00489ee0 @ 00489ee0
// Size (bytes): 81


void __fastcall FUN_00489ee0(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x14c) = 0;
  if ((*(int *)(param_1 + 0x160) != 0) && (DAT_0059e440 < (float)*(int *)(param_1 + 0x154))) {
    uVar1 = __ftol();
    *(undefined4 *)(param_1 + 0x14c) = uVar1;
  }
  return;
}


