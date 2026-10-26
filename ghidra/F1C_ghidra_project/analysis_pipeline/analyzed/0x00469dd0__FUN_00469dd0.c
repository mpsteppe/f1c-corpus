// Function: FUN_00469dd0 @ 00469dd0
// Size (bytes): 87


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00469dd0(int *param_1)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  fVar3 = (float10)FUN_00498730();
  fVar1 = (float)param_1[0x5d];
  param_1[0x5d] = (int)(float)(fVar3 + (float10)fVar1);
  if ((float10)_DAT_0059e800 < fVar3 + (float10)fVar1) {
    iVar2 = param_1[0x5e];
    param_1[0x5d] = 0;
    param_1[0x5e] = iVar2 + 2;
    if (DAT_007d2dcc <= iVar2 + 2) {
      param_1[0x5e] = 0;
    }
    (**(code **)(*param_1 + 0xa0))();
  }
  return 0;
}


