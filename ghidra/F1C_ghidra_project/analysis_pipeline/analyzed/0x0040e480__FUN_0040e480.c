// Function: FUN_0040e480 @ 0040e480
// Size (bytes): 531


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040e480(undefined4 param_1,float *param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  float local_50;
  int local_4c;
  int local_48;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_4;
  
  FUN_004dd550(&local_3c);
  local_24 = local_3c - local_30;
  local_20 = local_38 - local_2c;
  local_1c = local_34 - local_28;
  FUN_0054c230(0);
  iVar2 = FUN_0054e100();
  local_4 = local_28 + local_34;
  local_18 = (local_30 + local_3c) * _DAT_0059e450;
  *param_2 = local_18;
  local_14 = (local_2c + local_38) * _DAT_0059e450;
  param_2[1] = local_14;
  local_10 = local_4 * _DAT_0059e450;
  local_48 = 0;
  param_2[2] = local_10;
  *param_3 = SQRT(local_24 * local_24 + local_20 * local_20 + local_1c * local_1c) * _DAT_0059e450;
  do {
    local_4c = 0;
    local_24 = (local_3c - local_30) * (float)(local_48 + -2) * _DAT_0059e6ec + *param_2;
    do {
      iVar4 = 0;
      local_20 = (local_38 - local_2c) * (float)(local_4c + -2) * _DAT_0059e6ec + param_2[1];
      do {
        iVar5 = 0;
        local_50 = 0.0;
        local_1c = (local_34 - local_28) * (float)(iVar4 + -2) * _DAT_0059e6ec + param_2[2];
        if (0 < iVar2) {
          do {
            pfVar3 = (float *)FUN_0054e120(iVar5);
            fVar1 = (pfVar3[2] - local_1c) * (pfVar3[2] - local_1c) +
                    (pfVar3[1] - local_20) * (pfVar3[1] - local_20) +
                    (*pfVar3 - local_24) * (*pfVar3 - local_24);
            if (local_50 < fVar1) {
              local_50 = fVar1;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar2);
        }
        if (SQRT(local_50) < *param_3) {
          *param_2 = local_24;
          param_2[1] = local_20;
          param_2[2] = local_1c;
          *param_3 = SQRT(local_50);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 5);
      local_4c = local_4c + 1;
    } while (local_4c < 5);
    local_48 = local_48 + 1;
  } while (local_48 < 5);
  return;
}


