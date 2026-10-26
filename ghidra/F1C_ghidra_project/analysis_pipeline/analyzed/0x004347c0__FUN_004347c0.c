// Function: FUN_004347c0 @ 004347c0
// Size (bytes): 85


void __fastcall FUN_004347c0(int param_1)

{
  if (*(char *)(param_1 + 2) == '\0') {
    FUN_004d8760(0xffffffff,0);
    FUN_004d8760(1,1);
    if (DAT_005eb10c != (int *)0x0) {
      (**(code **)(*DAT_005eb10c + 0xc))();
    }
    FUN_004186a0();
    FUN_0040d1b0(*(undefined4 *)(param_1 + 8),1);
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}


