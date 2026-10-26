// Function: FUN_004e94a3 @ 004e94a3
// Size (bytes): 146


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004e94a3(float *param_1,int param_2)

{
  float fVar1;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iVar2;
  float10 fVar3;
  float in_stack_00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_0000001c;
  float in_stack_00000024;
  
  if (param_2 < unaff_EBX) {
    fVar1 = SQRT(in_stack_00000024);
    in_stack_00000018 = in_stack_00000018 * *(float *)(unaff_ESI + 0x3cbc);
    fVar3 = (float10)FUN_005895a2((double)in_stack_00000018);
    in_stack_00000024 = (float)(int)ROUND((float)fVar3);
    if ((int)in_stack_00000024 < 0) {
      fVar3 = (float10)*(float *)(unaff_ESI + 0x3cc0);
    }
    else {
      if (0xd < (int)in_stack_00000024) {
        in_stack_00000024 = 1.82169e-44;
      }
      fVar3 = (float10)*(float *)(unaff_ESI + 0x3cc0 + (int)in_stack_00000024 * 4);
      fVar3 = ((float10)in_stack_00000018 - (float10)(int)in_stack_00000024) *
              ((float10)*(float *)(unaff_ESI + 0x3cc4 + (int)in_stack_00000024 * 4) - fVar3) + fVar3
      ;
    }
    fVar3 = fVar3 * (float10)*(float *)(unaff_ESI + 0x3518) * (float10)(fVar1 / in_stack_00000010);
    if ((float10)in_stack_0000001c < fVar3) {
      fVar3 = (float10)in_stack_0000001c;
    }
    return (fVar3 - (float10)*(float *)(unaff_ESI + 0x3d44) *
                    (float10)*(float *)(unaff_ESI + 0x3518) * (float10)in_stack_00000014) -
           (float10)*(float *)(*(int *)(unaff_EBP + 0x10) + 8);
  }
  iVar2 = unaff_ESI + 0x3580;
  if (*(int *)(unaff_ESI + 0x39b4) != 2) {
    iVar2 = unaff_ESI + 0x3770;
  }
  fVar1 = (*(float *)(unaff_EBP + 8) / *(float *)(iVar2 + 0x90)) * *param_1;
  if (*(float *)(unaff_ESI + 0x3998) <= fVar1) {
    fVar3 = (float10)FUN_0059d99e();
    return fVar3;
  }
  fVar1 = fVar1 * _DAT_0059ed18;
  FUN_005895a2((double)fVar1);
  FUN_005895a2((double)fVar1);
  fVar3 = (float10)FUN_0059d984();
  return fVar3;
}


