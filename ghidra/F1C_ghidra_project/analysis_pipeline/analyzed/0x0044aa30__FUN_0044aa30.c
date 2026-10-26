// Function: FUN_0044aa30 @ 0044aa30
// Size (bytes): 175


void __thiscall FUN_0044aa30(int param_1,double *param_2)

{
  float fVar1;
  short sVar2;
  int iVar3;
  float fVar4;
  
  sVar2 = *(short *)(param_1 + 8);
  while( true ) {
    if (sVar2 < 0) {
      FUN_0044a070(param_2);
      if (*(short *)(param_1 + 8) == -2) {
        FUN_0044a070(param_2);
      }
      return;
    }
    if (sVar2 == 0) {
      fVar4 = *(float *)(&DAT_007ca3a4 + *(short *)(param_1 + 10) * -4) * (float)param_2[2] +
              (float)(&DAT_007ca388)[*(short *)(param_1 + 10)] * (float)*param_2;
    }
    else {
      fVar4 = (float)(&DAT_007ca388)[*(short *)(param_1 + 10)] * (float)*param_2 -
              *(float *)(&DAT_007ca3a4 + *(short *)(param_1 + 10) * -4) * (float)param_2[2];
    }
    fVar1 = (*(float **)(param_1 + 0xc))[1];
    if ((fVar4 < fVar1 != (fVar4 == fVar1)) && (**(float **)(param_1 + 0xc) <= fVar4)) {
      FUN_0044aa30(param_2);
    }
    iVar3 = *(int *)(param_1 + 0xc);
    param_1 = iVar3 + 0x10;
    if (fVar4 < *(float *)(iVar3 + 0x10)) break;
    if (fVar4 < *(float *)(iVar3 + 0x14) == (fVar4 == *(float *)(iVar3 + 0x14))) {
      return;
    }
    sVar2 = *(short *)(iVar3 + 0x18);
  }
  return;
}


