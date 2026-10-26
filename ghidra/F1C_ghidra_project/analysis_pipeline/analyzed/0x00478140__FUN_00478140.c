// Function: FUN_00478140 @ 00478140
// Size (bytes): 51


int __thiscall FUN_00478140(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0xe8) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0xe8));
  }
  FUN_00485eb0();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


