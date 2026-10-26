// Function: FUN_00485870 @ 00485870
// Size (bytes): 111


int __thiscall FUN_00485870(int param_1,byte param_2)

{
  FUN_00499b50();
  if (*(int *)(param_1 + 0x128) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x128));
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x120));
  }
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


