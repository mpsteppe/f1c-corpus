// Function: FUN_00447f30 @ 00447f30
// Size (bytes): 487


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00447f30(double *param_1,float *param_2)

{
  double dVar1;
  int iVar2;
  double *pdVar3;
  double *pdVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float10 fVar7;
  double local_38;
  double local_30;
  double local_28;
  
  *param_2 = (float)param_1[0xc];
  puVar6 = *(undefined4 **)(param_1 + 0x2be);
  pdVar4 = &local_38;
  for (iVar2 = 6; puVar6 = puVar6 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pdVar4 = *puVar6;
    pdVar4 = (double *)((int)pdVar4 + 4);
  }
  param_2[1] = (float)local_38;
  param_2[2] = (float)local_30;
  param_2[3] = (float)local_28;
  iVar2 = *(int *)(param_1 + 0x2be);
  fVar7 = (float10)fpatan(-((float10)*(double *)(iVar2 + 0x1c) * (float10)*(double *)(iVar2 + 100) +
                           (float10)*(double *)(iVar2 + 0x34) * (float10)*(double *)(iVar2 + 0x6c) +
                           (float10)*(double *)(iVar2 + 0x4c) * (float10)*(double *)(iVar2 + 0x74)),
                          -((float10)*(double *)(iVar2 + 0x44) * (float10)*(double *)(iVar2 + 0x6c)
                           + (float10)*(double *)(iVar2 + 0x5c) * (float10)*(double *)(iVar2 + 0x74)
                             + (float10)*(double *)(iVar2 + 0x2c) *
                               (float10)*(double *)(iVar2 + 100)));
  param_2[4] = (float)fVar7;
  iVar2 = *(int *)(param_1 + 0x2be);
  FUN_004388d0(iVar2 + 0x134,&local_38);
  fVar7 = (float10)*(double *)(iVar2 + 0xb4);
  param_2[5] = (float)((float10)local_38 * fVar7);
  param_2[6] = (float)((float10)local_30 * fVar7);
  param_2[7] = (float)((float10)local_28 * fVar7);
  pdVar4 = param_1 + 0x2de;
  param_2[8] = (float)((float10)*(double *)((int)param_1 + 0x1c5c) * (float10)_DAT_0059ea38);
  iVar2 = 4;
  param_2[9] = (float)((float10)param_1[0x3c7] * (float10)_DAT_0059ea38);
  param_2[10] = (float)param_1[9];
  param_2[0xb] = (float)param_1[1];
  param_2[0xc] = (float)param_1[10];
  param_2[0xd] = (float)param_1[2];
  param_2[0xe] = (float)param_1[8];
  param_2[0xf] = (float)*param_1;
  param_2[0x10] = (float)((float10)_DAT_0059e420 - (float10)param_1[4]);
  param_2[0x11] =
       (float)(((float10)_DAT_0059e420 - (float10)param_1[4]) *
              ((float10)_DAT_0059e420 - (float10)param_1[3]));
  param_2[0x36] = (float)*(int *)(param_1 + 0x3de);
  param_2[0x37] = (float)*(double *)((int)param_1 + 0x1d8c);
  param_2[0x38] = (float)*(double *)((int)param_1 + 0x1d4c);
  pdVar3 = (double *)((int)param_1 + 0x474);
  pfVar5 = param_2 + 0x14;
  do {
    pfVar5[-2] = (float)*(double *)((int)pdVar3 + -300);
    pfVar5[-1] = (float)*pdVar3;
    dVar1 = _DAT_0059e430;
    if (_DAT_0059e430 <= *pdVar4) {
      dVar1 = *pdVar4;
    }
    *pfVar5 = (float)dVar1;
    pdVar4 = pdVar4 + 1;
    pfVar5[1] = (float)*(double *)((int)pdVar3 + 0x164);
    iVar2 = iVar2 + -1;
    pfVar5[2] = (float)*(double *)((int)pdVar3 + 0x16c);
    pfVar5[3] = (float)*(double *)((int)pdVar3 + 0x174);
    pfVar5[4] = (float)*(double *)((int)pdVar3 + 0x18c);
    pfVar5[5] = (float)*(double *)((int)pdVar3 + 0x1ac);
    pfVar5[6] = (float)*(double *)((int)pdVar3 + 0x134);
    pdVar3 = (double *)((int)pdVar3 + 0x464);
    pfVar5 = pfVar5 + 9;
  } while (iVar2 != 0);
  return;
}


