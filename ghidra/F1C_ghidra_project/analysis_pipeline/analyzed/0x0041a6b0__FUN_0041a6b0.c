// Function: FUN_0041a6b0 @ 0041a6b0
// Size (bytes): 107


void FUN_0041a6b0(void)

{
  undefined1 auStack_20 [32];
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    if (DAT_005eb10c != (int *)0x0) {
      (**(code **)(*DAT_005eb10c + 0xc))();
    }
    FUN_004186a0();
    FUN_004144f0(0x113,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(auStack_20);
  }
  return;
}


