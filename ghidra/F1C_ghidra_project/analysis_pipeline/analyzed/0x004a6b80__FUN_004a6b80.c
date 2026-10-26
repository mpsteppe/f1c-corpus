// Function: FUN_004a6b80 @ 004a6b80
// Size (bytes): 455


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a6b80(int *param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  bool bVar7;
  float local_18;
  float local_14;
  float local_10;
  
  if (param_1[5] != 0) {
    bVar7 = DAT_0059e440 < *(float *)(*param_1 + 0x39a0);
    pfVar5 = (float *)FUN_004e9630();
    pfVar1 = (float *)pfVar5[0x44];
    local_18 = *pfVar1 - *pfVar5;
    local_14 = pfVar1[1] - pfVar5[1];
    local_10 = pfVar1[2] - pfVar5[2];
    fVar4 = local_18 * local_18 + local_14 * local_14 + local_10 * local_10;
    if (fVar4 < DAT_0059e440 == (fVar4 == DAT_0059e440)) {
      fVar4 = _DAT_0059e43c / SQRT(fVar4);
      local_18 = local_18 * fVar4;
      local_14 = local_14 * fVar4;
      local_10 = local_10 * fVar4;
    }
    iVar2 = *param_1;
    iVar6 = 0;
    if (0 < DAT_005c329c) {
      do {
        if ((((iVar6 != param_1[1]) &&
             (iVar3 = (&DAT_007c54f0)[iVar6], *(char *)(iVar3 + 0x344c) != '\0')) &&
            (fVar4 = local_18 * *(float *)(iVar3 + 0x34f8) +
                     local_14 * *(float *)(iVar3 + 0x34fc) + local_10 * *(float *)(iVar3 + 0x3500),
            fVar4 != DAT_0059e440)) &&
           ((fVar4 = ((local_18 * *(float *)(iVar2 + 0x34e0) +
                      local_14 * *(float *)(iVar2 + 0x34e4) + local_10 * *(float *)(iVar2 + 0x34e8))
                     - (local_18 * *(float *)(iVar3 + 0x34e0) +
                       local_14 * *(float *)(iVar3 + 0x34e4) + local_10 * *(float *)(iVar3 + 0x34e8)
                       )) / fVar4, DAT_0059e440 < fVar4 && (fVar4 < _DAT_0059e918)))) {
          bVar7 = false;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_005c329c);
    }
    if (bVar7) {
      if (*(int *)(param_1[5] + 0x78) == 1) {
        FUN_004a4030();
        return;
      }
    }
    else if (*(int *)(param_1[5] + 0x78) == 2) {
      FUN_004a4000();
      return;
    }
  }
  return;
}


