// Function: FUN_004039c0 @ 004039c0
// Size (bytes): 219


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004039c0(float *param_1,float param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = (int)param_2;
  pfVar5 = param_1;
  bVar7 = param_2 == 0.0;
  param_2 = 0.0;
  if (bVar7) {
    return 0;
  }
  fVar2 = *param_1 - *(float *)(iVar6 + 0x94);
  fVar4 = param_1[1] - *(float *)(iVar6 + 0x98);
  fVar3 = param_1[2] - *(float *)(iVar6 + 0x9c);
  param_1 = (float *)(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
  if (*(int *)(iVar6 + 0x110) != 0) {
    while (((param_2 = param_2 + *(float *)(iVar6 + 0x3c), param_2 <= _DAT_0059e470 &&
            (iVar1 = *(int *)(iVar6 + 0x110), iVar1 != 0)) &&
           (fVar2 = *pfVar5 - *(float *)(iVar1 + 0x94), fVar4 = pfVar5[1] - *(float *)(iVar1 + 0x98)
           , fVar3 = pfVar5[2] - *(float *)(iVar1 + 0x9c),
           fVar2 = fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3, fVar2 < (float)param_1))) {
      iVar6 = iVar1;
      param_1 = (float *)fVar2;
      if (*(int *)(iVar1 + 0x110) == 0) {
        return iVar1;
      }
    }
  }
  return iVar6;
}


