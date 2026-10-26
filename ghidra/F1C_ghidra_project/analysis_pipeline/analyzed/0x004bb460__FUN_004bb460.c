// Function: FUN_004bb460 @ 004bb460
// Size (bytes): 41


int __thiscall FUN_004bb460(int param_1,byte param_2)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 4));
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


