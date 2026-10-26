// Function: FUN_00466300 @ 00466300
// Size (bytes): 63


undefined1 __fastcall FUN_00466300(int param_1)

{
  *(undefined4 *)(param_1 + 0x124) = 0xbf800000;
  FUN_0048e8d0();
  FUN_004988a0(2);
  FUN_00466350();
  FUN_00466650();
  if (*(int *)(param_1 + 0xec) != 0) {
    FUN_00541ca0(1);
  }
  return 0;
}


