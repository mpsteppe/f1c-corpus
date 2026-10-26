// Function: FUN_0054eb40 @ 0054eb40
// Size (bytes): 818


undefined4 __fastcall FUN_0054eb40(undefined4 param_1,int *param_2,float *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float10 fVar10;
  
  switch(param_1) {
  case 0:
    iVar1 = param_2[1];
    iVar2 = *param_2;
    if ((param_3[1] - *(float *)(iVar2 + 4)) * (*(float *)(iVar1 + 8) - *(float *)(iVar2 + 8)) -
        (param_3[2] - *(float *)(iVar2 + 8)) * (*(float *)(iVar1 + 4) - *(float *)(iVar2 + 4)) <
        DAT_0059e440) {
      return 0;
    }
    iVar3 = param_2[2];
    if ((param_3[1] - *(float *)(iVar1 + 4)) * (*(float *)(iVar3 + 8) - *(float *)(iVar1 + 8)) -
        (param_3[2] - *(float *)(iVar1 + 8)) * (*(float *)(iVar3 + 4) - *(float *)(iVar1 + 4)) <
        DAT_0059e440) {
      return 0;
    }
    fVar7 = (param_3[1] - *(float *)(iVar3 + 4)) * (*(float *)(iVar2 + 8) - *(float *)(iVar3 + 8));
    fVar8 = *(float *)(iVar2 + 4) - *(float *)(iVar3 + 4);
    fVar9 = param_3[2] - *(float *)(iVar3 + 8);
    goto LAB_0054ebd8;
  case 1:
    iVar1 = param_2[1];
    iVar2 = *param_2;
    if (DAT_0059e440 <
        (param_3[1] - *(float *)(iVar2 + 4)) * (*(float *)(iVar1 + 8) - *(float *)(iVar2 + 8)) -
        (param_3[2] - *(float *)(iVar2 + 8)) * (*(float *)(iVar1 + 4) - *(float *)(iVar2 + 4))) {
      return 0;
    }
    iVar3 = param_2[2];
    if (DAT_0059e440 <
        (param_3[1] - *(float *)(iVar1 + 4)) * (*(float *)(iVar3 + 8) - *(float *)(iVar1 + 8)) -
        (param_3[2] - *(float *)(iVar1 + 8)) * (*(float *)(iVar3 + 4) - *(float *)(iVar1 + 4))) {
      return 0;
    }
    fVar10 = ((float10)param_3[1] - (float10)*(float *)(iVar3 + 4)) *
             ((float10)*(float *)(iVar2 + 8) - (float10)*(float *)(iVar3 + 8)) -
             ((float10)param_3[2] - (float10)*(float *)(iVar3 + 8)) *
             ((float10)*(float *)(iVar2 + 4) - (float10)*(float *)(iVar3 + 4));
    break;
  case 2:
    pfVar4 = (float *)*param_2;
    pfVar5 = (float *)param_2[1];
    if ((*pfVar5 - *pfVar4) * (param_3[2] - pfVar4[2]) -
        (*param_3 - *pfVar4) * (pfVar5[2] - pfVar4[2]) < DAT_0059e440) {
      return 0;
    }
    pfVar6 = (float *)param_2[2];
    if ((param_3[2] - pfVar5[2]) * (*pfVar6 - *pfVar5) -
        (*param_3 - *pfVar5) * (pfVar6[2] - pfVar5[2]) < DAT_0059e440) {
      return 0;
    }
    fVar7 = (*pfVar4 - *pfVar6) * (param_3[2] - pfVar6[2]);
    fVar8 = pfVar4[2] - pfVar6[2];
    fVar9 = *param_3 - *pfVar6;
LAB_0054ebd8:
    if (DAT_0059e440 <= fVar7 - fVar9 * fVar8) {
      return 1;
    }
    return 0;
  case 3:
    pfVar4 = (float *)param_2[1];
    pfVar5 = (float *)*param_2;
    if (DAT_0059e440 <
        (param_3[2] - pfVar5[2]) * (*pfVar4 - *pfVar5) -
        (*param_3 - *pfVar5) * (pfVar4[2] - pfVar5[2])) {
      return 0;
    }
    pfVar6 = (float *)param_2[2];
    if (DAT_0059e440 <
        (*pfVar6 - *pfVar4) * (param_3[2] - pfVar4[2]) -
        (*param_3 - *pfVar4) * (pfVar6[2] - pfVar4[2])) {
      return 0;
    }
    fVar10 = ((float10)param_3[2] - (float10)pfVar6[2]) * ((float10)*pfVar5 - (float10)*pfVar6) -
             ((float10)*param_3 - (float10)*pfVar6) * ((float10)pfVar5[2] - (float10)pfVar6[2]);
    break;
  case 4:
    fVar10 = (float10)FUN_0054ee90(param_2[1],0,1);
    if (fVar10 < (float10)DAT_0059e440) {
      return 0;
    }
    fVar10 = (float10)FUN_0054ee90(param_2[2],0,1);
    if ((float10)DAT_0059e440 <= fVar10) {
      fVar10 = (float10)FUN_0054ee90(*param_2,0,1);
      if ((float10)DAT_0059e440 <= fVar10) {
        return 1;
      }
      return 0;
    }
    return 0;
  case 5:
    fVar10 = (float10)FUN_0054ee90(param_2[1],0,1);
    if ((float10)DAT_0059e440 < fVar10) {
      return 0;
    }
    fVar10 = (float10)FUN_0054ee90(param_2[2],0,1);
    if ((float10)DAT_0059e440 < fVar10) {
      return 0;
    }
    fVar10 = (float10)FUN_0054ee90(*param_2,0,1);
    break;
  default:
    goto switchD_0054eb4d_default;
  }
  if ((float10)DAT_0059e440 < fVar10) {
    return 0;
  }
switchD_0054eb4d_default:
  return 1;
}


