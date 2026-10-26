// Function: FUN_004732d0 @ 004732d0
// Size (bytes): 86


undefined4 __fastcall FUN_004732d0(int param_1)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  *(undefined4 *)(param_1 + 0x324) = DAT_007d0410;
  *(undefined4 **)(param_1 + 800) = &DAT_007d0158;
  FUN_004adf10();
  uVar1 = FUN_00487010(**(undefined4 **)(param_1 + 800));
  FUN_0058815f(local_20,uVar1);
  FUN_0048b810(local_20);
  return 0;
}


