// Function: FUN_00512114 @ 00512114
// Size (bytes): 26


uint FUN_00512114(int param_1,int param_2,uint param_3)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    return *(uint *)(param_2 + 8) & param_3;
  }
  return 0;
}


