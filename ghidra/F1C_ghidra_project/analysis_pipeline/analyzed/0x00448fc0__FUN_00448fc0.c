// Function: FUN_00448fc0 @ 00448fc0
// Size (bytes): 59


int FUN_00448fc0(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  uint3 uVar3;
  double *pdVar4;
  int iVar5;
  
  iVar5 = 0;
  pdVar4 = (double *)(param_1 + 0x10);
  do {
    fVar1 = param_2[3] * (float)pdVar4[-1] + *param_2 * (float)pdVar4[-2];
    fVar2 = (float)*pdVar4;
    param_1 = CONCAT22((short)((uint)param_1 >> 0x10),
                       (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                       (ushort)(fVar1 == fVar2) << 0xe);
    uVar3 = (uint3)((uint)param_1 >> 8);
    if (fVar1 < fVar2 != (fVar1 == fVar2)) {
      return (uint)uVar3 << 8;
    }
    iVar5 = iVar5 + 1;
    pdVar4 = pdVar4 + 3;
  } while (iVar5 < 3);
  return CONCAT31(uVar3,1);
}


