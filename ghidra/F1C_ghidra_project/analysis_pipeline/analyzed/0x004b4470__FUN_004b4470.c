// Function: FUN_004b4470 @ 004b4470
// Size (bytes): 48


undefined4 __fastcall FUN_004b4470(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00566e20();
  *(undefined4 *)(param_1 + 4) = uVar1;
  FUN_00566bd0(param_1,4);
  FUN_00566bd0(param_1 + 8,2);
  return 1;
}


