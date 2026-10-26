// Function: FUN_00472630 @ 00472630
// Size (bytes): 141


undefined4 __fastcall FUN_00472630(int param_1)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  *(undefined4 *)(param_1 + 0x324) = DAT_007d0410;
  *(undefined4 **)(param_1 + 800) = &DAT_007cffa8;
  uVar1 = FUN_00487010(DAT_007cffa8);
  FUN_0058815f(local_20,uVar1);
  FUN_004ae9f0();
  if (DAT_005ec4a8 < **(int **)(param_1 + 800) + -1) {
    *(undefined4 *)(param_1 + 0x310) = 2;
    FUN_0048b810(local_20);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x310) = 0;
  FUN_0048b810(local_20);
  return 0;
}


