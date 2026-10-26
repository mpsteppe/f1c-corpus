// Function: FUN_004707c0 @ 004707c0
// Size (bytes): 136


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004707c0(int param_1)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  *(float *)(param_1 + 0x324) = (float)DAT_007d0410;
  *(undefined **)(param_1 + 800) = &DAT_007d122c;
  if (_DAT_007d122c == DAT_0059e440) {
    uVar1 = FUN_00487010();
    FUN_0058815f(local_20,uVar1);
    FUN_0048b810();
    return 0;
  }
  FUN_0058815f(local_20,&DAT_005c6e50,(double)_DAT_007d122c);
  FUN_0048b810();
  return 0;
}


