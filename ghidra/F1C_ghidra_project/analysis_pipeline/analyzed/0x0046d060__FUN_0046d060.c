// Function: FUN_0046d060 @ 0046d060
// Size (bytes): 93


void FUN_0046d060(void)

{
  undefined1 *puVar1;
  int in_stack_00000068;
  
  FUN_005881c0();
  FUN_0042e320();
  puVar1 = DAT_007ce668;
  if (DAT_007ce668 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0042fd00(puVar1,0);
  FUN_004b0770(1);
  FUN_0042ddd0();
  if (in_stack_00000068 != 0) {
    FUN_00587bcf(in_stack_00000068);
  }
  return;
}


