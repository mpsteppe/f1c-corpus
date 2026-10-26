// Function: FUN_004fb2e0 @ 004fb2e0
// Size (bytes): 742


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fb2e0(float *param_1)

{
  float *pfVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar2 = param_1[0x43];
  if (((fVar2 != 0.0) && (pfVar3 = (float *)param_1[0x44], pfVar3 != (float *)0x0)) &&
     (pfVar3[0x44] != 0.0)) {
    fVar8 = -param_1[0x2b];
    pfVar1 = param_1 + 0x25;
    fVar4 = *pfVar1;
    fVar5 = param_1[0x27];
    fVar6 = param_1[0x29];
    fVar7 = fVar8 * pfVar3[0x29] + fVar6 * pfVar3[0x2b];
    if (((float)_DAT_005ad280 < fVar7) && (fVar7 < (float)_DAT_005ad278)) {
      if (pfVar3 == param_1) {
        param_1[0x2c] = 0.0;
        return;
      }
      param_1[0x2c] = 999999.0;
      return;
    }
    fVar7 = pfVar3[0x29] / -pfVar3[0x2b];
    fVar7 = (fVar7 * pfVar3[0x25] + ((fVar5 - pfVar3[0x27]) - fVar7 * fVar4)) /
            (fVar7 * fVar8 - fVar6);
    fVar8 = fVar8 * fVar7 + fVar4;
    fVar6 = fVar7 * fVar6 + fVar5;
    fVar7 = fVar8 - pfVar3[0x25];
    fVar9 = fVar6 - pfVar3[0x27];
    fVar7 = SQRT(fVar7 * fVar7 + fVar9 * fVar9);
    fVar8 = fVar8 - fVar4;
    fVar6 = fVar6 - fVar5;
    fVar4 = SQRT(fVar8 * fVar8 + fVar6 * fVar6);
    if (pfVar3 == param_1) {
      param_1[0x2c] = 0.0;
    }
    else {
      if (fVar7 <= fVar4) {
        fVar4 = fVar7;
      }
      param_1[0x2c] = fVar4;
    }
    pfVar3 = (float *)param_1[0x45];
    if (pfVar3 != (float *)0x0) {
      fVar4 = *(float *)((int)fVar2 + 0x94);
      fVar6 = -*(float *)((int)fVar2 + 0xac);
      fVar5 = *(float *)((int)fVar2 + 0x9c);
      fVar2 = *(float *)((int)fVar2 + 0xa4);
      fVar8 = fVar6 * param_1[0x29] + fVar2 * param_1[0x2b];
      if ((fVar8 <= (float)_DAT_005ad280) || ((float)_DAT_005ad278 <= fVar8)) {
        fVar8 = (*pfVar3 - *pfVar1) / -(pfVar3[2] - param_1[0x27]);
        fVar8 = (fVar8 * *pfVar1 + ((fVar5 - param_1[0x27]) - fVar8 * fVar4)) /
                (fVar8 * fVar6 - fVar2);
        fVar6 = fVar6 * fVar8 + fVar4;
        fVar2 = fVar8 * fVar2 + fVar5;
        fVar8 = fVar6 - *pfVar1;
        fVar7 = fVar2 - param_1[0x27];
        fVar8 = SQRT(fVar8 * fVar8 + fVar7 * fVar7);
        fVar6 = fVar6 - fVar4;
        fVar2 = fVar2 - fVar5;
        fVar2 = SQRT(fVar6 * fVar6 + fVar2 * fVar2);
        if (pfVar3 != param_1) {
          if (fVar8 <= fVar2) {
            fVar2 = fVar8;
          }
          param_1[0x2d] = fVar2;
          return;
        }
      }
      else if (pfVar3 != param_1) {
        param_1[0x2d] = 3.4028235e+38;
        return;
      }
      param_1[0x2d] = 0.0;
    }
  }
  return;
}


