// Function: FUN_0054a340 @ 0054a340
// Size (bytes): 562


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_0054a340(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  float local_8;
  
  iVar9 = *(int *)(param_1 + 0x1a4);
  fVar2 = -*(float *)(param_2 + 0x24);
  fVar3 = -*(float *)(param_2 + 0x28);
  iVar10 = 0;
  iVar1 = *(int *)(param_1 + 0x100);
  fVar4 = -*(float *)(param_2 + 0x2c);
  local_8 = 1e+38;
  if (iVar9 != 0) {
    fVar5 = fVar2 - *(float *)(iVar9 + 0x7c);
    fVar7 = fVar3 - *(float *)(iVar9 + 0x80);
    fVar6 = fVar4 - *(float *)(iVar9 + 0x84);
    if (fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6 <
        *(float *)(iVar9 + 0x18) * *(float *)(iVar9 + 0x18)) {
      *(int *)(param_1 + 0x1a4) = iVar9;
      return iVar9;
    }
    iVar9 = *(int *)(iVar9 + 0xfc);
    if (iVar9 != 0) {
      if (iVar9 != 0) {
        do {
          iVar1 = *(int *)(iVar9 + 0x10);
          fVar5 = fVar2 - *(float *)(iVar1 + 0x7c);
          fVar7 = fVar3 - *(float *)(iVar1 + 0x80);
          fVar6 = fVar4 - *(float *)(iVar1 + 0x84);
          fVar5 = fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6;
          if (fVar5 < local_8) {
            iVar8 = 0;
            pfVar11 = (float *)(iVar1 + 0x8c);
            do {
              if (fVar3 * *pfVar11 + fVar2 * pfVar11[-1] + fVar4 * pfVar11[1] + pfVar11[2] <
                  (float)_DAT_0059e430) break;
              iVar8 = iVar8 + 1;
              pfVar11 = pfVar11 + 4;
            } while (iVar8 < 6);
            if (iVar8 == 6) {
              iVar10 = iVar1;
              local_8 = fVar5;
            }
          }
          iVar9 = *(int *)(iVar9 + 0x14);
          if (iVar9 == 0) {
            *(int *)(param_1 + 0x1a4) = iVar10;
            return iVar10;
          }
        } while( true );
      }
      goto LAB_0054a560;
    }
  }
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x104)) {
    if ((((*(byte *)(iVar1 + 4) & 0x40) == 0) &&
        (fVar5 = fVar2 - *(float *)(iVar1 + 0x7c), fVar7 = fVar3 - *(float *)(iVar1 + 0x80),
        fVar6 = fVar4 - *(float *)(iVar1 + 0x84),
        fVar5 = fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6,
        fVar5 < *(float *)(iVar1 + 0x18) * *(float *)(iVar1 + 0x18))) && (fVar5 < local_8)) {
      iVar9 = 0;
      pfVar11 = (float *)(iVar1 + 0x8c);
      do {
        if (fVar3 * *pfVar11 + fVar2 * pfVar11[-1] + fVar4 * pfVar11[1] + pfVar11[2] <
            (float)_DAT_0059e430) break;
        iVar9 = iVar9 + 1;
        pfVar11 = pfVar11 + 4;
      } while (iVar9 < 6);
      if (iVar9 == 6) {
        iVar10 = iVar1;
        local_8 = fVar5;
      }
    }
  }
LAB_0054a560:
  *(int *)(param_1 + 0x1a4) = iVar10;
  return iVar10;
}


