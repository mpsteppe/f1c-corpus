// Function: FUN_004a0690 @ 004a0690
// Size (bytes): 74


undefined4 FUN_004a0690(void)

{
  undefined1 *puVar1;
  
  FUN_004c2810();
  puVar1 = DAT_007ce5ec;
  if (DAT_007ce5ec == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_004c55b0(puVar1);
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  FUN_004a09f0();
  return 0;
}


