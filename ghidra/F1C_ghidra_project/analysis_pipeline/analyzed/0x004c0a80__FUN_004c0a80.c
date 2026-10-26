// Function: FUN_004c0a80 @ 004c0a80
// Size (bytes): 44


int __fastcall FUN_004c0a80(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined1 **)(param_1 + 8);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_004c3f80(puVar1);
  iVar2 = FUN_004c4080();
  if (iVar2 != 0) {
    return iVar2 + 0x7c;
  }
  return 0;
}


