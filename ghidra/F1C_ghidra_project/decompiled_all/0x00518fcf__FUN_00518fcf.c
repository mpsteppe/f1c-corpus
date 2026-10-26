// Function: FUN_00518fcf @ 00518fcf
// Strings:  [unknown critical chunk]


void FUN_00518fcf(int param_1,int param_2,undefined4 param_3)

{
  FUN_00517fd0(param_1,(byte *)(param_1 + 0x10c));
  if (((*(byte *)(param_1 + 0x10c) & 0x20) == 0) &&
     (FUN_0051189c(param_1,"unknown critical chunk"), param_2 == 0)) {
    return;
  }
  if ((*(uint *)(param_1 + 0x58) & 4) != 0) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 8;
  }
  FUN_00518828(param_1,param_3);
  return;
}


