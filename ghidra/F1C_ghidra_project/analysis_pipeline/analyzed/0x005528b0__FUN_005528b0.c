// Function: FUN_005528b0 @ 005528b0
// Size (bytes): 53


undefined4 __fastcall FUN_005528b0(int param_1)

{
  if ((*(uint *)(param_1 + 0x24) & 0x20000) != 0) {
    FUN_00540eb0(*(undefined4 *)(param_1 + 0xc));
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 0;
}


