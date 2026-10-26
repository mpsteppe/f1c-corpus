// Function: FUN_00443af0 @ 00443af0
// Size (bytes): 118


undefined4 __thiscall FUN_00443af0(int param_1,double param_2)

{
  double dVar1;
  
  if (*(int *)(param_1 + 0x1e14) == 1) {
    if (*(double *)(param_1 + 0x3d0) <= param_2) {
      return 0;
    }
    if (*(double *)(param_1 + 0x834) <= param_2) {
      return 0;
    }
  }
  else if (*(int *)(param_1 + 0x1e14) == 2) {
    if (*(double *)(param_1 + 0x3d0) <= param_2) {
      return 0;
    }
    dVar1 = *(double *)(param_1 + 0x834);
    goto LAB_00443b4e;
  }
  if (*(double *)(param_1 + 0xc98) <= param_2) {
    return 0;
  }
  dVar1 = *(double *)(param_1 + 0x10fc);
LAB_00443b4e:
  if (dVar1 <= param_2) {
    return 0;
  }
  return 1;
}


