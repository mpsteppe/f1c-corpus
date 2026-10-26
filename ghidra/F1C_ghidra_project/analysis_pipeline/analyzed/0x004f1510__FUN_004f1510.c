// Function: FUN_004f1510 @ 004f1510
// Size (bytes): 202


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f1510(int param_1,float param_2)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  float10 fVar4;
  float fVar5;
  
  fVar5 = param_2 / *(float *)(param_1 + 0x3bf4);
  iVar3 = 4;
  pfVar2 = (float *)(param_1 + 0x361c);
  do {
    iVar3 = iVar3 + -1;
    *pfVar2 = fVar5 * *pfVar2;
    pfVar2 = pfVar2 + 0x3e;
  } while (iVar3 != 0);
  if ((DAT_007d01c4 & 1) != 0) {
    fVar4 = (float10)FUN_005881f0();
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x39b0)) {
      do {
        iVar1 = iVar3 * 8;
        pfVar2 = (float *)(*(int *)(param_1 + 0x39a4) + iVar3 * 8);
        iVar3 = iVar3 + 1;
        pfVar2[1] = (*(float *)(*(int *)(param_1 + 0x39a4) + iVar1) + pfVar2[1]) * (float)fVar4 -
                    *pfVar2;
      } while (iVar3 < *(int *)(param_1 + 0x39b0));
    }
  }
  if ((DAT_007d01c4 & 2) != 0) {
    FUN_005881f0();
    if (0 < *(int *)(param_1 + 0x39f8)) {
      FUN_0059d9b5(fVar5);
      return;
    }
  }
  if ((DAT_007d01c4 & 4) != 0) {
    fVar4 = (float10)FUN_005881f0();
    *(float *)(param_1 + 0x3984) = (float)(fVar4 * (float10)*(float *)(param_1 + 0x3984));
  }
  *(float *)(param_1 + 0x3bf4) = param_2;
  FUN_004e8010(0);
  return;
}


