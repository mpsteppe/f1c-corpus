// Function: FUN_004ff0e0 @ 004ff0e0
// Size (bytes): 71


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004ff0e0(int param_1)

{
  undefined4 uVar1;
  
  if (*(float *)(param_1 + 0x20) == DAT_0059e440) {
    return 2;
  }
  if (*(float *)(param_1 + 0x24) == DAT_0059e440) {
    return 3;
  }
  uVar1 = 4;
  if (_DAT_0059e4e8 <= *(float *)(param_1 + 0x24)) {
    uVar1 = 5;
  }
  return uVar1;
}


