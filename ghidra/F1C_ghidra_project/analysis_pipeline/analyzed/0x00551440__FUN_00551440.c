// Function: FUN_00551440 @ 00551440
// Size (bytes): 51


void __fastcall FUN_00551440(int param_1)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffe2fff | 0x2000;
  FUN_00551390(0,0);
  FUN_005563e0();
  FUN_00556440();
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


