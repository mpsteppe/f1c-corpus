// Function: FUN_00456010 @ 00456010
// Size (bytes): 37


void FUN_00456010(void)

{
  undefined4 uVar1;
  
  if (DAT_007cd1fc == '\0') {
    uVar1 = FUN_005896ee(0);
    FUN_005884e0(uVar1);
    DAT_007cd1fc = '\x01';
  }
  _rand();
  return;
}


