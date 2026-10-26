// Function: FUN_004f18c0 @ 004f18c0
// Size (bytes): 403


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f18c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  undefined4 uVar6;
  double *pdVar7;
  float10 fVar8;
  int unaff_retaddr;
  
  *(undefined4 *)(param_1 + 0x3970) = param_3;
  iVar5 = FUN_004d7570(param_3);
  uVar6 = FUN_004a4830();
  FUN_004e2370(uVar6);
  iVar1 = unaff_retaddr * 0xf8 + 0x3580 + param_1;
  if ((unaff_retaddr == 0) || (pdVar7 = (double *)(iVar5 + 0x160), unaff_retaddr == 1)) {
    pdVar7 = (double *)(iVar5 + 0x18);
  }
  fVar8 = (float10)FUN_004d6ae0(0,0x4067c000);
  if (fVar8 <= (float10)_DAT_0059e430) {
    *(undefined4 *)(iVar1 + 0xb8) = 0;
  }
  else {
    *(float *)(iVar1 + 0xb8) = (float)((float10)pdVar7[0x16] / fVar8);
  }
  *(float *)(iVar1 + 0x90) =
       (float)((((float10)_DAT_0059ecd8 / (float10)pdVar7[4]) * (float10)pdVar7[5] +
               (float10)pdVar7[4]) * (float10)_DAT_005ad250);
  dVar2 = pdVar7[0x20];
  fVar8 = (float10)_DAT_0059e450;
  *(float *)(iVar1 + 0xa0) =
       (float)((float10)dVar2 * fVar8 * ((float10)pdVar7[1] + (float10)*pdVar7));
  dVar3 = pdVar7[3];
  dVar4 = pdVar7[2];
  *(undefined4 *)(iVar1 + 0xb0) = 0x3f800000;
  *(float *)(iVar1 + 0xa4) = (float)(((float10)dVar3 + (float10)dVar4) * (float10)dVar2 * fVar8);
  *(float *)(iVar1 + 0x9c) = *(float *)(iVar1 + 0xa0);
  *(float *)(iVar1 + 0xb4) = (float)pdVar7[0x22];
  *(float *)(iVar1 + 0x9c) = *(float *)(iVar1 + 0xa0) * *(float *)(param_1 + 0x3bf4);
  if (pdVar7[0x21] <= _DAT_0059e430) {
    *(undefined4 *)(iVar1 + 0x94) = 0x418c0000;
  }
  else {
    *(float *)(iVar1 + 0x94) = (float)((float10)_DAT_0059e420 / (float10)pdVar7[0x21]);
  }
  FUN_004d5ea0((float)pdVar7[0x1e],(float)pdVar7[0x1f]);
  if ((char)param_3 != '\0') {
    FUN_004e8010(0);
  }
  if (*(int *)(param_1 + 0x32bc) == 0) {
    _DAT_007c8884 = param_2;
    FUN_0043da10(unaff_retaddr);
  }
  return;
}


