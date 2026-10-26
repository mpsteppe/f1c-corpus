// Function: FUN_0040c7a0 @ 0040c7a0
// Size (bytes): 199


void __fastcall FUN_0040c7a0(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  if (*(int *)(param_1 + 0x38) != *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894)) {
    if (*(int *)(param_1 + 0x38) < 0) {
      puVar2 = &DAT_005ecdc8;
      do {
        FUN_004e0ed0(0);
        puVar2 = puVar2 + 0x48c0;
      } while ((int)puVar2 < 0x7c5bc8);
      if (DAT_007cfdc4 == 0) {
        uVar1 = (DAT_007cfcc8 != 0) - 1 & 2;
      }
      else if (DAT_007cfdc4 == 1) {
        uVar1 = 1;
      }
      else if (DAT_007cfdc4 == 2) {
        uVar1 = 3;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = FUN_0040c8d0();
      FUN_004e0ed0(0);
    }
    FUN_004e0ed0(uVar1);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894);
  }
  return;
}


