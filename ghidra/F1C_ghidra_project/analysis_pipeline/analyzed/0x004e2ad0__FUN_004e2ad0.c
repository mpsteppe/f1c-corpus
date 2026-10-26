// Function: FUN_004e2ad0 @ 004e2ad0
// Size (bytes): 411


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e2ad0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1 != 0) {
    FUN_004dd550(&local_c);
    local_20 = 0;
    local_10 = local_4 + local_10;
    local_c = (local_c + local_18) * _DAT_0059e450;
    local_8 = (local_8 + local_14) * _DAT_0059e450;
    local_4 = local_10 * _DAT_0059e450;
    do {
      iVar1 = param_2;
      if (local_20 == 0) {
        iVar1 = param_1;
      }
      if (iVar1 != 0) {
        FUN_0054b420(&local_18,&local_14,&local_10);
        local_18 = local_c + local_18;
        local_14 = local_8 + local_14;
        local_10 = local_4 + local_10;
        FUN_0054b3b0(local_18,local_14,local_10);
        iVar1 = FUN_0054c210();
        iVar5 = 0;
        if (0 < iVar1) {
          do {
            iVar2 = FUN_0054c230(iVar5);
            iVar3 = FUN_0054e100();
            iVar6 = 0;
            if (0 < iVar3) {
              do {
                pfVar4 = (float *)FUN_0054e120(iVar6);
                iVar6 = iVar6 + 1;
                *pfVar4 = *pfVar4 - local_c;
                pfVar4[1] = pfVar4[1] - local_8;
                pfVar4[2] = pfVar4[2] - local_4;
              } while (iVar6 < iVar3);
            }
            *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfeffffdf;
            FUN_0054d520(1);
            FUN_0054e270();
            FUN_0054d080(0);
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar1);
        }
      }
      local_20 = local_20 + 1;
    } while (local_20 < 2);
  }
  return;
}


