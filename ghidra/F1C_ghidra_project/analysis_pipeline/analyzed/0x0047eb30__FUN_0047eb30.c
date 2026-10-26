// Function: FUN_0047eb30 @ 0047eb30
// Size (bytes): 51


int __thiscall FUN_0047eb30(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 0xec) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0xec));
  }
  FUN_00488b30();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


