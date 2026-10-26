// Function: FUN_004ba8c0 @ 004ba8c0
// Size (bytes): 60


int * __thiscall FUN_004ba8c0(int *param_1,byte param_2)

{
  int iVar1;
  
  if (((char)param_1[2] != '\0') && (iVar1 = *param_1, iVar1 != 0)) {
    FUN_004b0170();
    FUN_00587bcf(iVar1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


