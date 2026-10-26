// Function: FUN_004b69a0 @ 004b69a0
// Size (bytes): 45


void __fastcall FUN_004b69a0(int param_1)

{
  *(int *)(param_1 + 0x9b8) = (*(int *)(param_1 + 0x9b8) + 1) % *(int *)(param_1 + 0x9b4);
  FUN_004b4e10();
  return;
}


