// Function: FUN_00551480 @ 00551480
// Size (bytes): 23


void __fastcall FUN_00551480(int param_1)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffff9fff | 0x1000;
  FUN_00556330();
  return;
}


