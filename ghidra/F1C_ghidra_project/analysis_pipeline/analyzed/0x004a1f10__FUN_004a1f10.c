// Function: FUN_004a1f10 @ 004a1f10
// Size (bytes): 59


undefined4 __fastcall FUN_004a1f10(int param_1)

{
  undefined1 *puVar1;
  
  FUN_00566cf0(&DAT_005c30b4);
  puVar1 = *(undefined1 **)(param_1 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00566cf0(puVar1);
  FUN_00566cf0(&DAT_005c30b4);
  return 1;
}


