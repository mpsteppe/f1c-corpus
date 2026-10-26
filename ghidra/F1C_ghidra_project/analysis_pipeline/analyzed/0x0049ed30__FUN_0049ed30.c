// Function: FUN_0049ed30 @ 0049ed30
// Size (bytes): 520


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049ed30(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  unkbyte10 extraout_ST0;
  float10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  
  if (*(int *)(param_1 + 4) != 0) {
    fVar1 = *(float *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x10) == 0) {
      if (*(float *)(param_1 + 0x14) <= *(float *)(param_1 + 0x18)) {
        fVar4 = _DAT_005acb0c - (*(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x14));
      }
      else {
        fVar4 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x18);
      }
      fVar1 = fVar1 - fVar4 * (*(float *)(param_1 + 0x1c) / *(float *)(param_1 + 0x20));
    }
    else if (*(int *)(param_1 + 0x10) == 1) {
      fVar4 = *(float *)(param_1 + 0x1c) / *(float *)(param_1 + 0x20);
      if (*(float *)(param_1 + 0x14) <= *(float *)(param_1 + 0x18)) {
        fVar1 = (*(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x14)) * fVar4 + fVar1;
      }
      else {
        fVar1 = (_DAT_005acb0c - (*(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x18))) * fVar4
                + fVar1;
      }
    }
    fVar1 = fVar1 * _DAT_0059e65c;
    fVar9 = (float10)FUN_00588570();
    fcos((float10)fVar1 + fVar9);
    iVar5 = __ftol();
    fsin(extraout_ST0);
    iVar6 = __ftol();
    fcos((float10)fVar1 - extraout_ST0_00);
    iVar7 = __ftol();
    fsin(extraout_ST0_01);
    iVar8 = __ftol();
    iVar2 = *(int *)(param_1 + 0x3c);
    iVar3 = *(int *)(param_1 + 0x40);
    FUN_00553650(0,(float)(iVar2 + iVar5),(float)(iVar3 - iVar6),0x3f800000,0,0,0xffffffff);
    FUN_00553650(1,(float)(iVar2 - iVar7),(float)(iVar8 + iVar3),0x3f800000,0,0x3f800000,0xffffffff)
    ;
    FUN_00553650(2,(float)(iVar2 - iVar5),(float)(iVar3 + iVar6),0x3f800000,0x3f800000,0x3f800000,
                 0xffffffff);
    FUN_00553650(3,(float)(iVar7 + iVar2),(float)(iVar3 - iVar8),0x3f800000,0x3f800000,0,0xffffffff)
    ;
  }
  return;
}


