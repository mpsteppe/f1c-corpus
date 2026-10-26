// Function: FUN_00474ab0 @ 00474ab0
// Size (bytes): 71


undefined4 __fastcall FUN_00474ab0(int param_1)

{
  undefined1 local_20 [32];
  
  *(undefined4 *)(param_1 + 0x324) = DAT_007d0410;
  *(undefined4 **)(param_1 + 800) = &DAT_007cfc8c;
  FUN_0058815f(local_20,&DAT_005c3280,DAT_007cfc8c);
  FUN_0048b810(local_20);
  return 0;
}


