// Function: FUN_004e88b0 @ 004e88b0
// Size (bytes): 711


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004e88b0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float local_c;
  float local_4;
  
  iVar3 = *(int *)(param_1 + 0x39b4);
  if (iVar3 == 0) {
    fVar4 = (float10)*(float *)(param_1 + 0x39c8) * (float10)*(float *)(param_1 + 0x39a8) *
            (float10)_DAT_0059e450;
    local_c = (float)(((float10)*(float *)(param_1 + 0x38f8) * (float10)*(float *)(param_1 + 0x38b4)
                      + fVar4) * (float10)*(float *)(param_1 + 0x3900));
    fVar4 = ((float10)*(float *)(param_1 + 0x3800) * (float10)*(float *)(param_1 + 0x37bc) + fVar4)
            * (float10)*(float *)(param_1 + 0x3808);
    fVar1 = *(float *)(param_1 + 0x3710) * *(float *)(param_1 + 0x3708) *
            *(float *)(param_1 + 0x36c4);
    local_4 = *(float *)(param_1 + 0x3618) * *(float *)(param_1 + 0x3610) *
              *(float *)(param_1 + 0x35cc);
    fVar2 = fVar1;
    if (fVar1 < local_4) {
      fVar2 = local_4;
    }
    fVar5 = fVar4;
    if (fVar4 <= (float10)local_c) {
      fVar5 = (float10)local_c;
    }
    if ((float10)fVar2 <= fVar5) {
LAB_004e8973:
      if ((float10)local_c < fVar4) goto LAB_004e8a63;
LAB_004e8984:
      fVar4 = (float10)local_c;
      goto LAB_004e8a63;
    }
    if (local_4 <= fVar1) {
      fVar4 = (float10)fVar1;
      goto LAB_004e8a63;
    }
  }
  else if (iVar3 == 1) {
    fVar4 = (float10)*(float *)(param_1 + 0x39c8) * (float10)*(float *)(param_1 + 0x39a8) *
            (float10)_DAT_0059e7f8;
    local_c = (float)(((float10)*(float *)(param_1 + 0x38f8) * (float10)*(float *)(param_1 + 0x38b4)
                      + fVar4) * (float10)*(float *)(param_1 + 0x3900));
    fVar2 = (float)(((float10)*(float *)(param_1 + 0x3800) * (float10)*(float *)(param_1 + 0x37bc) +
                    fVar4) * (float10)*(float *)(param_1 + 0x3808));
    local_4 = (float)(((float10)*(float *)(param_1 + 0x3708) * (float10)*(float *)(param_1 + 0x36c4)
                      + fVar4) * (float10)*(float *)(param_1 + 0x3710));
    fVar4 = ((float10)*(float *)(param_1 + 0x3610) * (float10)*(float *)(param_1 + 0x35cc) + fVar4)
            * (float10)*(float *)(param_1 + 0x3618);
    fVar5 = fVar4;
    if (fVar4 <= (float10)local_4) {
      fVar5 = (float10)local_4;
    }
    fVar1 = local_c;
    if (local_c < fVar2) {
      fVar1 = fVar2;
    }
    if (fVar5 <= (float10)fVar1) {
      if (local_c < fVar2) {
        fVar4 = (float10)fVar2;
        goto LAB_004e8a63;
      }
      goto LAB_004e8984;
    }
    if ((float10)local_4 < fVar4) goto LAB_004e8a63;
  }
  else if (iVar3 == 2) {
    fVar4 = (float10)*(float *)(param_1 + 0x39c8) * (float10)*(float *)(param_1 + 0x39a8) *
            (float10)_DAT_0059e450;
    local_4 = *(float *)(param_1 + 0x3900) * *(float *)(param_1 + 0x38f8) *
              *(float *)(param_1 + 0x38b4);
    fVar2 = *(float *)(param_1 + 0x3808) * *(float *)(param_1 + 0x3800) *
            *(float *)(param_1 + 0x37bc);
    local_c = (float)(((float10)*(float *)(param_1 + 0x3708) * (float10)*(float *)(param_1 + 0x36c4)
                      + fVar4) * (float10)*(float *)(param_1 + 0x3710));
    fVar4 = ((float10)*(float *)(param_1 + 0x3610) * (float10)*(float *)(param_1 + 0x35cc) + fVar4)
            * (float10)*(float *)(param_1 + 0x3618);
    fVar5 = fVar4;
    if (fVar4 <= (float10)local_c) {
      fVar5 = (float10)local_c;
    }
    fVar1 = local_4;
    if (local_4 < fVar2) {
      fVar1 = fVar2;
    }
    if ((float10)fVar1 < fVar5) goto LAB_004e8973;
    if (local_4 < fVar2) {
      fVar4 = (float10)fVar2;
      goto LAB_004e8a63;
    }
  }
  fVar4 = (float10)local_4;
LAB_004e8a63:
  if ((float10)DAT_0059e440 <= fVar4) {
    if ((float10)_DAT_0059e43c < fVar4) {
      fVar4 = (float10)_DAT_0059e43c;
    }
    return fVar4;
  }
  return (float10)DAT_0059e440;
}


