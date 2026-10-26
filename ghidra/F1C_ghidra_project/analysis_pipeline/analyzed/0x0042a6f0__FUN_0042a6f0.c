// Function: FUN_0042a6f0 @ 0042a6f0
// Size (bytes): 69


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042a6f0(int param_1)

{
  FUN_004bd760();
  if (*(char *)(param_1 + 0x4584) == '\0') {
    *(int *)(param_1 + 0x45e0) = *(int *)(param_1 + 0x45e0) + 1;
  }
  if (DAT_007c56a4 == 7) {
    *(undefined4 *)(param_1 + 0x4534) = 0;
  }
  *(float *)(param_1 + 0x447c) = (float)_DAT_008afea0 + _DAT_0059e46c;
  return;
}


