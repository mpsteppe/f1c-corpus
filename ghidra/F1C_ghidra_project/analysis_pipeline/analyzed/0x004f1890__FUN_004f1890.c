// Function: FUN_004f1890 @ 004f1890
// Size (bytes): 33


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f1890(int param_1,float param_2)

{
  *(float *)(param_1 + 0x3978) = param_2;
  if (*(int *)(param_1 + 0x32bc) == 0) {
    _DAT_007c75c4 = (double)param_2;
  }
  return;
}


