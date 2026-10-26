// Function: FUN_00448f00 @ 00448f00
// Size (bytes): 178


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00448f00(int param_1,int param_2)

{
  double *pdVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  do {
    pfVar2 = *(float **)(param_1 + iVar7 * 8);
    if (iVar7 == 2) {
      iVar6 = 0;
    }
    else {
      iVar6 = iVar7 + 1;
    }
    pfVar3 = *(float **)(param_1 + iVar6 * 8);
    iVar6 = 2;
    if (iVar7 != 0) {
      iVar6 = iVar7 + -1;
    }
    pfVar4 = *(float **)(param_1 + iVar6 * 8);
    pdVar1 = (double *)(param_2 + iVar7 * 0x18);
    *pdVar1 = (double)(pfVar2[3] - pfVar3[3]);
    fVar5 = *pfVar3 - *pfVar2;
    pdVar1[1] = (double)fVar5;
    fVar5 = *pfVar2 * (float)*pdVar1 + fVar5 * pfVar2[3];
    pdVar1[2] = (double)fVar5;
    if (*pfVar4 * (float)*pdVar1 + pfVar4[3] * (float)pdVar1[1] < fVar5) {
      *pdVar1 = -*pdVar1;
      pdVar1[1] = -pdVar1[1];
      pdVar1[2] = -pdVar1[2];
    }
    iVar7 = iVar7 + 1;
    pdVar1[2] = SQRT(pdVar1[1] * pdVar1[1] + *pdVar1 * *pdVar1) * _DAT_0059ea08 + pdVar1[2];
  } while (iVar7 < 3);
  return;
}


