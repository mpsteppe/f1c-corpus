// Function: FUN_00471440 @ 00471440
// Size (bytes): 68


undefined4 __fastcall FUN_00471440(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_20 [32];
  
  iVar1 = DAT_007d0410 * 9;
  *(undefined4 **)(param_1 + 800) = &DAT_007cee88 + iVar1;
  uVar2 = FUN_00487010((&DAT_007cee88)[iVar1]);
  FUN_0058815f(local_20,uVar2);
  FUN_0048b810(local_20);
  return 0;
}


