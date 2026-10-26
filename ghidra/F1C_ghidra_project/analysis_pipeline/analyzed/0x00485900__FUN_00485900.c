// Function: FUN_00485900 @ 00485900
// Size (bytes): 92


int __thiscall FUN_00485900(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0x154) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x154));
  }
  FUN_00499b50();
  if (*(int *)(param_1 + 0x118) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x118));
  }
  FUN_00499b50();
  FUN_00485eb0();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


