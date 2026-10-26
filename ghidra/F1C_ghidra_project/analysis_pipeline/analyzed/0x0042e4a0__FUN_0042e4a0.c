// Function: FUN_0042e4a0 @ 0042e4a0
// Size (bytes): 143


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e4a0(double *param_1,double *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)param_2 + 0x14);
  iVar2 = *(int *)((int)param_1 + 0x14);
  if (((double)iVar2 * param_1[1] + *param_1) * _DAT_0059e9f0 <
      (double)iVar1 * param_2[1] + *param_2) {
    do {
      if ((param_3 == '\0') || (iVar1 < 1)) {
        if (*(int *)(param_1 + 2) + -1 <= iVar2) {
          return;
        }
        *(int *)((int)param_1 + 0x14) = iVar2 + 1;
      }
      else {
        *(int *)((int)param_2 + 0x14) = iVar1 + -1;
      }
      iVar2 = *(int *)((int)param_1 + 0x14);
      iVar1 = *(int *)((int)param_2 + 0x14);
    } while (((double)iVar2 * param_1[1] + *param_1) * _DAT_0059e9f0 <
             (double)iVar1 * param_2[1] + *param_2);
  }
  return;
}


