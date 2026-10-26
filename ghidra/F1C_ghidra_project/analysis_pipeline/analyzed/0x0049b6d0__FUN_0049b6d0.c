// Function: FUN_0049b6d0 @ 0049b6d0
// Size (bytes): 203


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049b6d0(int param_1,int param_2,float *param_3,int *param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = *(int *)(param_1 + 0x403c);
    fVar4 = (float10)FUN_004f01b0();
    fVar1 = (float)fVar4;
    iVar3 = *(int *)(param_2 + 0x403c);
    fVar4 = (float10)FUN_004f01b0();
    *param_3 = 0.0;
    *param_4 = 0;
    if (iVar2 == iVar3) {
      *param_3 = (float)((float10)fVar1 - fVar4);
      return 0;
    }
    if (iVar3 < iVar2) {
      if ((iVar3 + 1 == iVar2) && ((float10)fVar1 < fVar4)) {
        *param_3 = (float)(((float10)_DAT_005ea408 - fVar4) + (float10)fVar1);
        return 0;
      }
      if ((float10)fVar1 < fVar4) {
        *param_4 = (iVar2 - iVar3) + -1;
        return 0;
      }
      *param_4 = iVar2 - iVar3;
      return 0;
    }
  }
  return 1;
}


