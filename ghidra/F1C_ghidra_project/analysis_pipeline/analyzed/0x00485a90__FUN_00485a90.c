// Function: FUN_00485a90 @ 00485a90
// Size (bytes): 70


int __thiscall FUN_00485a90(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0x184) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x184));
  }
  if (*(int *)(param_1 + 0x17c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x17c));
  }
  FUN_00468610();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


