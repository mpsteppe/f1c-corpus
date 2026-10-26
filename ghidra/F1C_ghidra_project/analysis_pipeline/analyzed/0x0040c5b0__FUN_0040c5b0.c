// Function: FUN_0040c5b0 @ 0040c5b0
// Size (bytes): 78


void __fastcall FUN_0040c5b0(int param_1)

{
  if (*(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894) !=
      *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
    switch(*(undefined4 *)(param_1 + 0xc)) {
    case 2:
      if (DAT_007cfcc8 != 0) {
        return;
      }
    case 0xffffffff:
    case 1:
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0xc);
      FUN_0040cde0(5,0);
    }
  }
  return;
}


