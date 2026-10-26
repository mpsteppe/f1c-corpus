// Function: FUN_0041ad80 @ 0041ad80
// Size (bytes): 577


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0041ad80(int param_1,int param_2,int param_3,float param_4)

{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 local_20 [32];
  
  if (((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) && (DAT_007c56a8 != 8)) {
    fVar3 = (float)_DAT_008afea0 - _DAT_0059e800;
    pfVar1 = (float *)(param_1 + 0x4fc + *(int *)(param_2 + 0x4894) * 4);
    if (((*pfVar1 < fVar3) && (*(float *)(param_1 + 0x4fc + *(int *)(param_3 + 0x4894) * 4) < fVar3)
        ) && (_DAT_0059e820 < param_4)) {
      *pfVar1 = (float)_DAT_008afea0;
      *(float *)(param_1 + 0x69c + *(int *)(param_2 + 0x4894) * 4) = param_4;
      *(int *)(param_1 + 0x83c + *(int *)(param_2 + 0x4894) * 4) = param_3;
      *(float *)(param_1 + 0x4fc + *(int *)(param_3 + 0x4894) * 4) = (float)_DAT_008afea0;
      *(float *)(param_1 + 0x69c + *(int *)(param_3 + 0x4894) * 4) = param_4;
      *(int *)(param_1 + 0x83c + *(int *)(param_3 + 0x4894) * 4) = param_2;
      fVar4 = (float10)FUN_004f0050();
      fVar5 = (float10)FUN_004f0050();
      FUN_004144d0();
      bVar2 = (float)fVar5 < (float)fVar4;
      if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_2 + 0x4894)) {
        uVar7 = 0xffffffff;
        if (bVar2) {
          uVar6 = 0x72;
          uVar8 = *(undefined4 *)(param_3 + 0x489c);
        }
        else {
          uVar6 = 0x73;
          uVar8 = *(undefined4 *)(param_3 + 0x489c);
        }
      }
      else if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_3 + 0x4894)) {
        uVar7 = 0xffffffff;
        if (bVar2) {
          uVar6 = 0x73;
          uVar8 = *(undefined4 *)(param_2 + 0x489c);
        }
        else {
          uVar6 = 0x72;
          uVar8 = *(undefined4 *)(param_2 + 0x489c);
        }
      }
      else {
        if (bVar2) {
          uVar7 = *(undefined4 *)(param_2 + 0x489c);
          if (DAT_0059e440 < *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4)) {
            uVar8 = *(undefined4 *)(param_3 + 0x489c);
            uVar6 = 0xe1;
            DAT_008aae70 = DAT_008aae70 + 1;
            goto LAB_0041af97;
          }
          uVar9 = *(undefined4 *)(param_3 + 0x489c);
        }
        else {
          uVar7 = *(undefined4 *)(param_3 + 0x489c);
          if (DAT_0059e440 < *(float *)(&DAT_008ab274 + (DAT_008aae70 & 0xff) * 4)) {
            uVar6 = 0xe1;
            DAT_008aae70 = DAT_008aae70 + 1;
            uVar8 = *(undefined4 *)(param_2 + 0x489c);
            goto LAB_0041af97;
          }
          uVar9 = *(undefined4 *)(param_2 + 0x489c);
        }
        DAT_008aae70 = DAT_008aae70 + 1;
        uVar6 = 0xe2;
        uVar8 = uVar7;
        uVar7 = uVar9;
      }
LAB_0041af97:
      FUN_004144f0(uVar6,uVar8,uVar7,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      return;
    }
  }
  return;
}


