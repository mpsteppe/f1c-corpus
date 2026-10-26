// Function: FUN_00472930 @ 00472930
// Size (bytes): 84


undefined4 __fastcall FUN_00472930(int param_1)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  *(undefined4 *)(param_1 + 0x324) = DAT_007d0410;
  *(undefined4 **)(param_1 + 800) = &DAT_007cff60;
  uVar1 = FUN_00487010(DAT_007cff60);
  FUN_0058815f(local_20,uVar1);
  FUN_004ae490();
  FUN_0048b810(local_20);
  return 0;
}


