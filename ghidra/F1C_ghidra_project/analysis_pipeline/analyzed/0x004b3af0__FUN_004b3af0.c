// Function: FUN_004b3af0 @ 004b3af0
// Size (bytes): 64


undefined4 __fastcall FUN_004b3af0(int param_1)

{
  if (*(int *)(param_1 + 0x6c00c) == *(int *)(param_1 + 0x6c004)) {
    *(undefined4 *)(param_1 + 0x6c00c) = *(undefined4 *)(param_1 + 0x6c008);
    return 0;
  }
  FUN_004b3a90(*(int *)(param_1 + 0x6c00c));
  *(int *)(param_1 + 0x6c00c) = *(int *)(param_1 + 0x6c00c) + 0x1b0;
  return 1;
}


