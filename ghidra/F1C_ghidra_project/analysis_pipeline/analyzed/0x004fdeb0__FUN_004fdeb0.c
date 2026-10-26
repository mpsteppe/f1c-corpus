// Function: FUN_004fdeb0 @ 004fdeb0
// Size (bytes): 432


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004fdeb0(int param_1,float param_2,float param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  float local_4;
  
  do {
    pfVar1 = *(float **)(*(int *)(param_1 + 0x38) + 0xc);
    if (pfVar1 == (float *)0x0) {
      local_4 = *(float *)(*(int *)(param_1 + 0x38) + 4);
      param_3 = *(float *)(*(int *)(param_1 + 0x38) + 8);
LAB_004fdf0f:
      FUN_004fde00(param_3);
      *(float *)(extraout_ECX + 0x30) = local_4;
      if (*(float *)(extraout_ECX + 0x24) <= *(float *)(extraout_ECX + 0x28)) {
        if (DAT_0059e440 < *(float *)(extraout_ECX + 0x28)) {
          fVar3 = DAT_0059e440;
          if (DAT_0059e440 <= *(float *)(extraout_ECX + 0x34)) {
            fVar3 = *(float *)(extraout_ECX + 0x34);
          }
          fVar3 = *(float *)(extraout_ECX + 0x28) -
                  (fVar3 * _DAT_005ad314 + (float)param_4 * _DAT_005ad318 + _DAT_005ad318) * param_2
          ;
          *(float *)(extraout_ECX + 0x28) = fVar3;
          if (fVar3 < *(float *)(extraout_ECX + 0x24)) {
            *(undefined4 *)(extraout_ECX + 0x28) = *(undefined4 *)(extraout_ECX + 0x24);
          }
        }
      }
      else {
        *(undefined4 *)(extraout_ECX + 0x28) = *(undefined4 *)(extraout_ECX + 0x24);
      }
      if (*(float *)(extraout_ECX + 0x24) <= *(float *)(extraout_ECX + 0x2c)) {
        if (DAT_0059e440 < *(float *)(extraout_ECX + 0x2c)) {
          fVar3 = DAT_0059e440;
          if (DAT_0059e440 <= *(float *)(extraout_ECX + 0x34)) {
            fVar3 = *(float *)(extraout_ECX + 0x34);
          }
          fVar3 = *(float *)(extraout_ECX + 0x2c) -
                  (fVar3 * _DAT_005ad314 + _DAT_005ad318) * param_2;
          *(float *)(extraout_ECX + 0x2c) = fVar3;
          if (fVar3 < *(float *)(extraout_ECX + 0x24)) {
            *(undefined4 *)(extraout_ECX + 0x2c) = *(undefined4 *)(extraout_ECX + 0x24);
          }
        }
      }
      else {
        *(undefined4 *)(extraout_ECX + 0x2c) = *(undefined4 *)(extraout_ECX + 0x24);
      }
      FUN_004fd6f0();
      fVar3 = (float)param_4 * _DAT_0059e84c +
              (_DAT_0059e43c - param_3) * _DAT_0059e864 +
              (*(float *)(extraout_ECX_00 + 0x2c) + *(float *)(extraout_ECX_00 + 0x28)) *
              _DAT_0059e450 * _DAT_005ad310 + _DAT_0059e800 + *(float *)(extraout_ECX_00 + 0x30);
      if (param_2 < _DAT_005ad30c) {
        fVar3 = (fVar3 - *(float *)(extraout_ECX_00 + 0x34)) * param_2 * _DAT_005accb0 +
                *(float *)(extraout_ECX_00 + 0x34);
      }
      *(float *)(extraout_ECX_00 + 0x34) = fVar3;
      return;
    }
    if (param_3 < *pfVar1) {
      pfVar2 = *(float **)(param_1 + 0x38);
      fVar3 = (param_3 - *pfVar2) / (*pfVar1 - *pfVar2);
      local_4 = (pfVar1[1] - pfVar2[1]) * fVar3 + pfVar2[1];
      param_3 = (pfVar1[2] - pfVar2[2]) * fVar3 + pfVar2[2];
      goto LAB_004fdf0f;
    }
    *(float **)(param_1 + 0x38) = pfVar1;
  } while( true );
}


