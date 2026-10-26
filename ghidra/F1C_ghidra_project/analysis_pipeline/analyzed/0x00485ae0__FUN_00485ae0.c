// Function: FUN_00485ae0 @ 00485ae0
// Size (bytes): 51


int __thiscall FUN_00485ae0(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0x174) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x174));
  }
  FUN_00489440();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


