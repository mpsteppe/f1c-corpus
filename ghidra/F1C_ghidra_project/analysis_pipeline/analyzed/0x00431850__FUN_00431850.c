// Function: FUN_00431850 @ 00431850
// Size (bytes): 215


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00431850(int param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)FUN_0042ed00(param_2 + 0x2c);
  iVar1 = FUN_004d7880(&DAT_008adb88);
  if (iVar1 == 0) {
    return (float10)_DAT_0059e430;
  }
  iVar1 = FUN_004d7570(*(undefined4 *)(param_1 + 0xbc4));
  if (iVar1 == 0) {
    return (float10)_DAT_0059e430;
  }
  if (DAT_008aeec0 == 0) {
    fVar3 = (float10)*(double *)(iVar1 + 0x180) * (float10)_DAT_0059ea70;
  }
  else if (DAT_008aeec0 == 1) {
    fVar3 = ((float10)*(double *)(iVar1 + 0x180) + (float10)*(double *)(iVar1 + 0x38)) *
            (float10)_DAT_0059e880;
  }
  else {
    if (DAT_008aeec0 != 2) {
      return (float10)_DAT_0059e430;
    }
    fVar3 = (float10)*(double *)(iVar1 + 0x38);
  }
  fVar3 = fVar3 * (float10)_DAT_0059ea70;
  if (fVar3 < (float10)_DAT_0059e430 != (fVar3 == (float10)_DAT_0059e430)) {
    return (float10)_DAT_0059e430;
  }
  return (((float10)*(int *)(param_1 + 0x1584) * (float10)*(double *)(param_1 + 0x1578) +
          (float10)*(double *)(param_1 + 0x1570)) / (float10)(double)fVar2) * fVar3;
}


