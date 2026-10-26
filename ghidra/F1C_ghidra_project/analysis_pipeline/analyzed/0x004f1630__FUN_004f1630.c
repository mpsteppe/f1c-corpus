// Function: FUN_004f1630 @ 004f1630
// Size (bytes): 30


undefined1 * __fastcall FUN_004f1630(int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined4 *)FUN_004d7570(*(undefined4 *)(param_1 + 0x3970));
  puVar2 = (undefined1 *)*puVar1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  return puVar2;
}


