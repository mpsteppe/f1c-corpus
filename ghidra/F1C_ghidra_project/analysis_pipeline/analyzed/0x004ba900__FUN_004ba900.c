// Function: FUN_004ba900 @ 004ba900
// Size (bytes): 65


int * __thiscall FUN_004ba900(int *param_1,byte param_2)

{
  int iVar1;
  
  if (((char)param_1[3] != '\0') && (iVar1 = *param_1, iVar1 != 0)) {
    if (*(int *)(iVar1 + 4) != 0) {
      FUN_00587bcf(*(int *)(iVar1 + 4));
    }
    FUN_00587bcf(iVar1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


