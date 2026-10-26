// Function: FUN_004dd8f0 @ 004dd8f0
// Size (bytes): 247


float10 FUN_004dd8f0(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = FUN_004dd4e0();
  fVar3 = -INFINITY;
  iVar5 = FUN_0054c210();
  iVar8 = 0;
  if (0 < iVar5) {
    do {
      iVar6 = FUN_0054c230(iVar8);
      if (*(float *)(iVar6 + 0xf4) == DAT_0059e440) {
        uVar1 = *(uint *)(iVar6 + 0x14);
        if ((uVar1 & 0x2000000) == 0) {
          iVar6 = 4 - (uint)((uVar1 & 0x40) != 0);
        }
        else {
          iVar6 = 2 - (uint)((uVar1 & 0x40) != 0);
        }
      }
      else {
        iVar6 = 0;
      }
      if (iVar4 <= iVar6) {
        iVar6 = FUN_0054e100();
        iVar9 = 0;
        if (0 < iVar6) {
          do {
            pfVar7 = (float *)FUN_0054e120(iVar9);
            fVar2 = pfVar7[2] * pfVar7[2] + pfVar7[1] * pfVar7[1] + *pfVar7 * *pfVar7;
            if (fVar3 < fVar2) {
              fVar3 = fVar2;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar6);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar5);
  }
  return (float10)fVar3;
}


