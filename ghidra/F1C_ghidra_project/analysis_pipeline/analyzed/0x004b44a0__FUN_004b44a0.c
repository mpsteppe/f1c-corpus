// Function: FUN_004b44a0 @ 004b44a0
// Size (bytes): 48


undefined4 __fastcall FUN_004b44a0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00566e20();
  *(undefined4 *)(param_1 + 4) = uVar1;
  FUN_00566c00(param_1,4);
  FUN_00566c00(param_1 + 8,2);
  return 1;
}


