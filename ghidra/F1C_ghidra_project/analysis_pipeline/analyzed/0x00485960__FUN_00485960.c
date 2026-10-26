// Function: FUN_00485960 @ 00485960
// Size (bytes): 111


int __thiscall FUN_00485960(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0x160) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x160));
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x158));
  }
  if (*(int *)(param_1 + 0x150) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x150));
  }
  FUN_00499b50();
  FUN_00499b50();
  FUN_00485eb0();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


