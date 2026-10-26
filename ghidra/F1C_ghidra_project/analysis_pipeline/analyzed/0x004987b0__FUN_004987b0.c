// Function: FUN_004987b0 @ 004987b0
// Size (bytes): 208


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004987b0(void)

{
  int iVar1;
  int extraout_ECX;
  int iVar2;
  float10 fVar3;
  
  fVar3 = (float10)FUN_00498730();
  fVar3 = fVar3 + (float10)*(float *)(extraout_ECX + 200);
  *(float *)(extraout_ECX + 200) = (float)fVar3;
  if (*(int *)(extraout_ECX + 100) == 0) {
    iVar2 = 4 - (uint)(*(int *)(extraout_ECX + 0x84) != 0);
  }
  else if (*(int *)(extraout_ECX + 0x84) == 0) {
    iVar2 = 1;
    if (fVar3 < (float10)_DAT_0059e970 == (fVar3 == (float10)_DAT_0059e970)) {
      *(undefined4 *)(extraout_ECX + 200) = 0;
    }
    else {
      iVar2 = 2;
      *(undefined4 *)(extraout_ECX + 200) = 0x3f266667;
    }
  }
  else {
    iVar2 = 5;
  }
  if (*(int *)(extraout_ECX + 0x68) == 0) {
    if (*(int *)(extraout_ECX + 0x88) != 0) {
      iVar2 = 10;
    }
  }
  else {
    iVar2 = (uint)(*(int *)(extraout_ECX + 0x88) != 0) * 2 + 9;
  }
  if (*(int *)(extraout_ECX + 0x6c) == 0) {
    if (*(int *)(extraout_ECX + 0x8c) != 0) {
      iVar2 = 7;
    }
  }
  else {
    iVar2 = (uint)(*(int *)(extraout_ECX + 0x8c) != 0) * 2 + 6;
  }
  iVar1 = *(int *)(extraout_ECX + 0x70);
  if ((iVar1 != 0) && (iVar2 = (iVar1 < 1) + 0xc, iVar1 != 0)) {
    return (iVar1 < 1) + 0xc;
  }
  return iVar2;
}


