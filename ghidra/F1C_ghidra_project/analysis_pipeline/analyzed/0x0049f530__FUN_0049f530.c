// Function: FUN_0049f530 @ 0049f530
// Size (bytes): 317


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049f530(float param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = (int)param_3;
  iVar1 = (int)param_1;
  if (((-1 < (int)param_1) && ((int)param_1 < 5)) && (param_3 != 0.0)) {
    switch(param_1) {
    case 0.0:
      param_1 = 0.0;
      param_3 = 10000.0;
      fVar3 = (float10)FUN_0049b8d0();
      break;
    case 1.4013e-45:
      param_1 = 120.0;
      fVar3 = (float10)_DAT_007c91b4 - (float10)_DAT_005acafc;
      param_3 = 280.0;
      break;
    case 2.8026e-45:
      param_1 = 120.0;
      fVar3 = (float10)_DAT_007c9174 - (float10)_DAT_005acafc;
      param_3 = 280.0;
      break;
    case 4.2039e-45:
      fVar3 = (float10)_DAT_007c919c;
      param_1 = -3.0;
      param_3 = 100.0;
      break;
    case 5.60519e-45:
      param_1 = 0.0;
      param_3 = 12.0;
      fVar3 = (float10)FUN_00447bb0();
      break;
    default:
      goto switchD_0049f55c_default;
    }
    switch(iVar1) {
    case 1:
    case 2:
      fVar3 = (fVar3 - (float10)_DAT_0059eac0) * (float10)_DAT_0059eab8 - (float10)_DAT_0059eab0;
      break;
    case 3:
    case 4:
      fVar3 = fVar3 * (float10)_DAT_005acb10;
    }
    if ((float10)param_1 <= fVar3) {
      if ((float10)param_3 < fVar3) {
        fVar3 = (float10)param_3;
      }
    }
    else {
      fVar3 = (float10)param_1;
    }
    *(float *)(param_2 + 0x20) = param_3 - param_1;
    FUN_0049ed00((float)(fVar3 - (float10)param_1));
    FUN_0049ed10(iVar2);
    FUN_0049ed20(iVar2);
  }
switchD_0049f55c_default:
  return;
}


