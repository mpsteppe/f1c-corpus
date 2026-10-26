// Function: FUN_0041a0c0 @ 0041a0c0
// Size (bytes): 145


void FUN_0041a0c0(int param_1)

{
  undefined1 local_20 [32];
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    FUN_00418a20(0x108);
    if (param_1 != *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
      FUN_004144d0();
      FUN_004144f0(0x108,*(undefined4 *)(&DAT_005f0f74 + param_1 * 0x48c0),0xffffffff,0xffffffff,
                   0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
    }
  }
  return;
}


