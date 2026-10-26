// Function: FUN_00485b20 @ 00485b20
// Size (bytes): 70


int __thiscall FUN_00485b20(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0x17c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x17c));
  }
  if (*(int *)(param_1 + 0x174) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x174));
  }
  FUN_00489440();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


