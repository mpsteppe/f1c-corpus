// Function: FUN_00472510 @ 00472510
// Size (bytes): 84


undefined4 __fastcall FUN_00472510(int param_1)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  *(undefined4 *)(param_1 + 0x324) = DAT_007d0410;
  *(undefined4 **)(param_1 + 800) = &DAT_007cffcc;
  uVar1 = FUN_00487010(DAT_007cffcc);
  FUN_0058815f(local_20,uVar1);
  FUN_004af220();
  FUN_0048b810(local_20);
  return 0;
}


