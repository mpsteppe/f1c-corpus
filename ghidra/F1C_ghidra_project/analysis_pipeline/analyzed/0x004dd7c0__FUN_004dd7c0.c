// Function: FUN_004dd7c0 @ 004dd7c0
// Size (bytes): 303


void __fastcall FUN_004dd7c0(undefined4 param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  int local_38;
  
  iVar8 = FUN_004dd4e0();
  *param_3 = 0.0;
  param_3[1] = 0.0;
  param_3[2] = 0.0;
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar4 = 0.0;
  fVar3 = param_2[2];
  iVar9 = FUN_0054c210();
  local_38 = 0;
  if (0 < iVar9) {
    do {
      iVar10 = FUN_0054c230(local_38);
      if (*(float *)(iVar10 + 0xf4) == DAT_0059e440) {
        uVar6 = *(uint *)(iVar10 + 0x14);
        if ((uVar6 & 0x2000000) == 0) {
          iVar10 = 4 - (uint)((uVar6 & 0x40) != 0);
        }
        else {
          iVar10 = 2 - (uint)((uVar6 & 0x40) != 0);
        }
      }
      else {
        iVar10 = 0;
      }
      if (iVar8 <= iVar10) {
        iVar10 = FUN_0054e100();
        iVar12 = 0;
        if (0 < iVar10) {
          do {
            pfVar11 = (float *)FUN_0054e120(iVar12);
            fVar7 = pfVar11[1] * fVar2 + pfVar11[2] * fVar3 + *pfVar11 * fVar1;
            if (fVar4 < fVar7) {
              fVar4 = pfVar11[2];
              fVar5 = pfVar11[1];
              *param_3 = *pfVar11;
              param_3[1] = fVar5;
              param_3[2] = fVar4;
              fVar4 = fVar7;
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 < iVar10);
        }
      }
      local_38 = local_38 + 1;
    } while (local_38 < iVar9);
  }
  return;
}


