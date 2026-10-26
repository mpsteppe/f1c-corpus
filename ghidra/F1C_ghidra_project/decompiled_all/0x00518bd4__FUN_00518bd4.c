// Function: FUN_00518bd4 @ 00518bd4
// Strings:  [Incorrect IEND chunk length, No image in file]


void FUN_00518bd4(int param_1,int param_2,int param_3)

{
  if ((((*(uint *)(param_1 + 0x58) & 1) == 0) || ((*(uint *)(param_1 + 0x58) & 4) == 0)) &&
     (FUN_00511869(param_1,"No image in file"), param_2 == 0)) {
    return;
  }
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) | 0x18;
  if (param_3 != 0) {
    FUN_00511887(param_1,"Incorrect IEND chunk length");
  }
  FUN_00518828(param_1,param_3);
  return;
}


