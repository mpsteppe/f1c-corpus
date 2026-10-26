// Function: FUN_00425670 @ 00425670
// Size (bytes): 591


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00425670(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  
  if (*(int *)(param_1 + 0x4510) == 6) {
    fVar5 = (float10)*(float *)(*(int *)(param_1 + 0x4354) + 0x9c) -
            (float10)*(float *)(param_1 + 0x34e8);
    if (fVar5 == (float10)DAT_0059e440) {
      fVar5 = (float10)_DAT_0059e898;
    }
    else {
      fVar5 = (float10)fpatan(-((float10)*(float *)(*(int *)(param_1 + 0x4354) + 0x94) -
                               (float10)*(float *)(param_1 + 0x34e0)),-fVar5);
    }
    fVar5 = fVar5 - (float10)*(float *)(param_1 + 0x34f0);
    if ((float10)_DAT_0059e890 <= ABS(fVar5)) {
      if ((float10)DAT_0059e440 <= fVar5) {
        fVar5 = fVar5 - (float10)_DAT_0059e888;
      }
      else {
        fVar5 = fVar5 + (float10)_DAT_0059e888;
      }
    }
    if ((ABS(fVar5) < (float10)_DAT_0059e450) ||
       ((double)*(float *)(param_1 + 0x447c) < _DAT_008afea0)) {
      *(undefined4 *)(param_1 + 0x4510) = 7;
    }
    goto LAB_00425811;
  }
  if (*(float *)(param_1 + 0x3500) == DAT_0059e440) {
    fVar5 = (float10)_DAT_0059e898;
  }
  else {
    fVar5 = (float10)fpatan(-(float10)*(float *)(param_1 + 0x34f8),
                            -(float10)*(float *)(param_1 + 0x3500));
  }
  fVar5 = fVar5 - (float10)*(float *)(param_1 + 0x34f0);
  if ((float10)_DAT_0059e890 <= ABS(fVar5)) {
    if ((float10)DAT_0059e440 <= fVar5) {
      fVar5 = fVar5 - (float10)_DAT_0059e888;
    }
    else {
      fVar5 = fVar5 + (float10)_DAT_0059e888;
    }
  }
  if ((ABS(fVar5) <= (float10)_DAT_0059e880) || (*(float *)(param_1 + 0x4440) <= _DAT_0059e450)) {
    if (0 < *(int *)(param_1 + 0x446c)) {
      iVar4 = *(int *)(param_1 + 0x446c) + -1;
      goto LAB_004257c5;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x446c) + 5;
LAB_004257c5:
    *(int *)(param_1 + 0x446c) = iVar4;
  }
  if (*(int *)(param_1 + 0x4558) < *(int *)(param_1 + 0x446c)) {
    if ((2 < *(int *)(param_1 + 0x39fc)) && (0 < *(int *)(param_1 + 0x39fc))) {
      FUN_004ef930(*(int *)(param_1 + 0x39fc) + -1);
    }
    *(undefined4 *)(param_1 + 0x446c) = 0;
    FUN_0042ae00();
    *(undefined4 *)(param_1 + 0x4510) = 1;
  }
LAB_00425811:
  if ((double)*(float *)(param_1 + 0x447c) < _DAT_008afea0) {
    fVar1 = *(float *)(param_1 + 0x4470) - *(float *)(param_1 + 0x34e0);
    fVar2 = *(float *)(param_1 + 0x4474) - *(float *)(param_1 + 0x34e4);
    fVar3 = *(float *)(param_1 + 0x4478) - *(float *)(param_1 + 0x34e8);
    if (fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2 < _DAT_0059e43c) {
      *(uint *)(param_1 + 0x4510) = (*(int *)(param_1 + 0x4510) == 6) - 1 & 6;
    }
    *(undefined4 *)(param_1 + 0x4470) = *(undefined4 *)(param_1 + 0x34e0);
    *(undefined4 *)(param_1 + 0x4474) = *(undefined4 *)(param_1 + 0x34e4);
    *(undefined4 *)(param_1 + 0x4478) = *(undefined4 *)(param_1 + 0x34e8);
    *(float *)(param_1 + 0x447c) = (float)_DAT_008afea0 + _DAT_0059e46c;
  }
  return;
}


