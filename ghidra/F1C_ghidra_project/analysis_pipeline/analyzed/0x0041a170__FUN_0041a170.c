// Function: FUN_0041a170 @ 0041a170
// Size (bytes): 134


void FUN_0041a170(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_20 [32];
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    cVar1 = FUN_004c7bd0();
    if (cVar1 == '\0') {
      if (DAT_007c56a4 != 7) {
        return;
      }
      uVar2 = 0xc4;
    }
    else {
      uVar2 = 0x34;
    }
    FUN_004144d0();
    FUN_004144f0(uVar2,*(undefined4 *)(param_1 + 0x48a0),0xffffffff,0xffffffff,0xffffffff,0xc0000000
                 ,0xc0000000);
    FUN_00418560(local_20);
  }
  return;
}


