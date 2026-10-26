// Function: FUN_004e43d0 @ 004e43d0
// Size (bytes): 290


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e43d0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x60) + *(float *)(param_1 + 0x34);
  if (*(float *)(param_1 + 0x30) <= DAT_0059e440) {
    fVar2 = *(float *)(param_1 + 0x58) + *(float *)(param_1 + 0x54);
  }
  else {
    fVar2 = *(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x58);
  }
  fVar2 = fVar2 * *(float *)(param_1 + 0x6c);
  fVar3 = DAT_0059e440;
  if (fVar2 != DAT_0059e440) {
    fVar3 = fVar2 * *(float *)(param_1 + 0x70);
    fVar1 = *(float *)(param_1 + 0x30);
    if (DAT_0059e440 <= fVar3) {
      if ((fVar1 < DAT_0059e440 != (fVar1 == DAT_0059e440)) && (-fVar3 < *(float *)(param_1 + 0x30))
         ) goto LAB_004e444c;
    }
    else if ((fVar1 >= DAT_0059e440) && (*(float *)(param_1 + 0x30) < -fVar3)) {
LAB_004e444c:
      fVar3 = -(*(float *)(param_1 + 0x30) / fVar2);
      fVar2 = *(float *)(param_1 + 0x30);
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(float *)(param_1 + 0x24) = fVar3 * fVar2 + *(float *)(param_1 + 0x24);
      if (*(float *)(param_1 + 0x58) < ABS(*(float *)(param_1 + 0x54))) {
        if (*(float *)(param_1 + 0x54) <= DAT_0059e440) {
          fVar2 = *(float *)(param_1 + 0x58) + *(float *)(param_1 + 0x54);
        }
        else {
          fVar2 = *(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x58);
        }
        *(float *)(param_1 + 0x30) =
             (*(float *)(param_1 + 0x70) - fVar3) * *(float *)(param_1 + 0x6c) * fVar2;
      }
      goto LAB_004e44cc;
    }
  }
  *(float *)(param_1 + 0x24) =
       *(float *)(param_1 + 0x70) * *(float *)(param_1 + 0x30) + *(float *)(param_1 + 0x24);
  *(float *)(param_1 + 0x30) = fVar3 + *(float *)(param_1 + 0x30);
LAB_004e44cc:
  if (_DAT_005ad180 < ABS(*(float *)(param_1 + 0x24))) {
    fVar4 = (float10)FUN_0058957a();
    *(float *)(param_1 + 0x24) = (float)fVar4;
  }
  return;
}


