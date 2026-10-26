// Function: FUN_0044a880 @ 0044a880
// Size (bytes): 422


float * __thiscall FUN_0044a880(float *param_1,float *param_2)

{
  float fVar1;
  short sVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  float *pfVar11;
  
  sVar2 = *(short *)(param_1 + 2);
  do {
    if (sVar2 < 0) {
      return param_1;
    }
    fVar1 = *(float *)(&DAT_007ca3a4 + *(short *)((int)param_1 + 10) * -4);
    if (sVar2 != 0) {
      fVar1 = -fVar1;
    }
    pfVar3 = (float *)param_1[3];
    fVar7 = (float)(&DAT_007ca388)[*(short *)((int)param_1 + 10)] * *param_2;
    fVar6 = fVar7 + fVar1 * param_2[2];
    fVar7 = fVar1 * param_2[3] + fVar7;
    fVar4 = (float)(&DAT_007ca388)[*(short *)((int)param_1 + 10)] * param_2[1];
    fVar5 = fVar4 + fVar1 * param_2[2];
    fVar4 = fVar4 + fVar1 * param_2[3];
    if ((((*pfVar3 <= fVar6) || (*pfVar3 <= fVar7)) || (*pfVar3 <= fVar5)) || (*pfVar3 <= fVar4)) {
      bVar9 = false;
    }
    else {
      bVar9 = true;
    }
    if (((fVar6 <= pfVar3[1]) || (fVar7 <= pfVar3[1])) ||
       ((fVar5 <= pfVar3[1] || (fVar4 <= pfVar3[1])))) {
      bVar8 = false;
    }
    else {
      bVar8 = true;
    }
    if ((bVar9) || (bVar8)) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
    pfVar11 = pfVar3 + 4;
    if ((((*pfVar11 <= fVar6) || (*pfVar11 <= fVar7)) || (*pfVar11 <= fVar5)) || (*pfVar11 <= fVar4)
       ) {
      bVar8 = false;
    }
    else {
      bVar8 = true;
    }
    if (((fVar6 <= pfVar3[5]) || (fVar7 <= pfVar3[5])) ||
       ((fVar5 <= pfVar3[5] || (fVar4 <= pfVar3[5])))) {
      bVar10 = false;
    }
    else {
      bVar10 = true;
    }
    if ((bVar8) || (bVar8 = false, bVar10)) {
      bVar8 = true;
    }
    if (bVar9) {
      if (bVar8) {
        return (float *)0x0;
      }
    }
    else {
      pfVar11 = pfVar3;
      if (!bVar8) {
        return param_1;
      }
    }
    sVar2 = *(short *)(pfVar11 + 2);
    param_1 = pfVar11;
  } while( true );
}


