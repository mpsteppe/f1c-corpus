// Function: FUN_0044b090 @ 0044b090
// Size (bytes): 119


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0044b090(double *param_1,double *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  uint3 uVar3;
  
  fVar1 = param_3[3];
  fVar2 = param_3[3];
  fVar1 = ABS(((fVar1 * (float)param_1[1] + (float)param_1[4]) * fVar1 +
               (*param_3 * (float)*param_1 + fVar1 * (float)param_1[2] + (float)param_1[3]) *
               *param_3 + (float)param_1[5]) -
              ((fVar2 * (float)param_2[1] + (float)param_2[4]) * fVar2 +
               (*param_3 * (float)*param_2 + fVar2 * (float)param_2[2] + (float)param_2[3]) *
               *param_3 + (float)param_2[5]));
  fVar2 = (float)_DAT_0059ef40;
  uVar3 = (uint3)(CONCAT22((short)((uint)param_2 >> 0x10),
                           (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                           (ushort)(fVar1 == fVar2) << 0xe) >> 8);
  if (fVar1 < fVar2) {
    return CONCAT31(uVar3,1);
  }
  return (uint)uVar3 << 8;
}


