// Function: FUN_004582c0 @ 004582c0
// Size (bytes): 27


undefined4 __fastcall FUN_004582c0(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    *(undefined1 *)(param_1 + 7) = 1;
    uVar1 = FUN_00457d00();
    return uVar1;
  }
  return 0;
}


