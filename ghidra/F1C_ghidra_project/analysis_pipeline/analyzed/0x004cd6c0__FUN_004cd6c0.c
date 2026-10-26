// Function: FUN_004cd6c0 @ 004cd6c0
// Size (bytes): 528


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cd6c0(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  float10 fVar4;
  
  if (0 < *(int *)(param_1 + 0x58)) {
    puVar2 = (undefined4 *)FUN_004cb540();
    if (DAT_008ab6e4 == 2) {
      fVar4 = (float10)FUN_004b9ce0();
    }
    else {
      fVar4 = (float10)_DAT_008afea0;
    }
    puVar2[2] = (float)fVar4;
    if (*(int *)(param_1 + 4) == 8) {
      puVar2[3] = (float)(fVar4 + (float10)*(float *)(param_1 + 0x30));
      puVar2[0x18] = (float)((uint)param_3[6] & 0xff) * _DAT_005acec0;
      fVar1 = (float)((uint)param_2[6] & 0xff) * _DAT_005acec0;
      if (DAT_008ab6e4 == 2) {
        iVar3 = FUN_004b9e30();
        if (iVar3 == 5) {
          fVar4 = (float10)DAT_0059e440;
        }
        else {
          fVar4 = (float10)FUN_004b9cf0();
        }
      }
      else {
        fVar4 = (float10)_DAT_008afe98;
      }
      fVar4 = (float10)fVar1 - fVar4 * (float10)*(float *)(param_1 + 0x40);
      if ((float10)DAT_0059e440 <= fVar4) {
        if ((float10)_DAT_0059e43c < fVar4) {
          fVar4 = (float10)_DAT_0059e43c;
        }
      }
      else {
        fVar4 = (float10)DAT_0059e440;
      }
      puVar2[0x19] = (float)fVar4;
      param_2[6] = (float)(int)ROUND((float)(fVar4 * (float10)_DAT_005acebc));
    }
    else {
      puVar2[3] = 0x7f7fffff;
    }
    FUN_00558e10(*puVar2,0,*param_2 + param_2[3],param_2[4] + param_2[1],param_2[5] + param_2[2],
                 param_2[6]);
    FUN_00558e10(*puVar2,1,param_3[3] + *param_3,param_3[4] + param_3[1],param_3[5] + param_3[2],
                 param_3[6]);
    FUN_00558e10(*puVar2,2,*param_3 - param_3[3],param_3[1] - param_3[4],param_3[2] - param_3[5],
                 param_3[6]);
    FUN_00558e10(*puVar2,3,*param_2 - param_2[3],param_2[1] - param_2[4],param_2[2] - param_2[5],
                 param_2[6]);
  }
  return;
}


