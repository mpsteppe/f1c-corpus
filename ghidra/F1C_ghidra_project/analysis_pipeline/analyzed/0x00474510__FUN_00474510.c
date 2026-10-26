// Function: FUN_00474510 @ 00474510
// Size (bytes): 74


undefined4 __fastcall FUN_00474510(int param_1)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  *(undefined4 *)(param_1 + 800) = DAT_007d0410;
  *(undefined4 **)(param_1 + 0x324) = &DAT_007cfde8;
  uVar1 = FUN_00487010(DAT_007cfde8);
  FUN_0058815f(local_20,uVar1);
  FUN_0048b810(local_20);
  return 0;
}


