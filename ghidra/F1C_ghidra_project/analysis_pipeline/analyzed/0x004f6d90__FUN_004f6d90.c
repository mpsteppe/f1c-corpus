// Function: FUN_004f6d90 @ 004f6d90
// Size (bytes): 361


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004f6d90(int *param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  float unaff_EBX;
  int iVar1;
  float unaff_EBP;
  float *pfVar2;
  int iVar3;
  float fVar4;
  
  iVar1 = 0;
  if (0 < *param_1) {
    pfVar2 = (float *)(param_1 + 1);
    while ((pfVar2[1] < param_2 || (param_2 < *pfVar2))) {
      (**(code **)(**(int **)(param_1[0x10] + iVar1 * 4) + 8))();
      iVar1 = iVar1 + 1;
      pfVar2 = pfVar2 + 3;
      if (*param_1 <= iVar1) {
        return;
      }
    }
    iVar3 = iVar1 + 1;
    if ((iVar3 == *param_1) || (param_2 < (float)param_1[iVar3 * 3 + 1])) {
      (**(code **)(**(int **)(param_1[0x10] + iVar1 * 4) + 4))
                (2,param_3,param_4,param_5,param_2 * (float)param_1[iVar3 * 3],0);
      if (iVar3 < *param_1) {
        do {
          (**(code **)(**(int **)(param_1[0x10] + iVar3 * 4) + 8))();
          iVar3 = iVar3 + 1;
        } while (iVar3 < *param_1);
      }
    }
    else {
      fVar4 = param_2 * (float)param_1[iVar3 * 3];
      (**(code **)(**(int **)(param_1[0x10] + iVar1 * 4) + 4))
                (2,param_3,param_4,
                 SQRT(_DAT_0059e43c -
                      (param_2 - (float)param_1[iVar3 * 3 + 1]) /
                      ((float)param_1[iVar1 * 3 + 2] - (float)param_1[iVar3 * 3 + 1])) * param_5,
                 fVar4,0);
      iVar1 = iVar1 + 2;
      (**(code **)(**(int **)(param_1[0x10] + iVar3 * 4) + 4))
                (2,param_3,param_4,SQRT(fVar4) * unaff_EBX,unaff_EBP * (float)param_1[iVar1 * 3],0);
      if (iVar1 < *param_1) {
        do {
          (**(code **)(**(int **)(param_1[0x10] + iVar1 * 4) + 8))();
          iVar1 = iVar1 + 1;
        } while (iVar1 < *param_1);
        return;
      }
    }
  }
  return;
}


