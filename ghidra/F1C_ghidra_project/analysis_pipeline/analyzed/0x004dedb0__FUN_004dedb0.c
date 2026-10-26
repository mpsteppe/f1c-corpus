// Function: FUN_004dedb0 @ 004dedb0
// Size (bytes): 444


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004dedb0(int param_1,float *param_2)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float *pfVar10;
  float local_4;
  
  iVar5 = *(int *)(param_1 + 0x18);
  iVar6 = 0;
  if (0 < iVar5) {
    pfVar4 = (float *)(param_1 + 0x20);
    do {
      if ((((((*param_2 == pfVar4[-1]) && (param_2[1] == *pfVar4)) && (param_2[2] == pfVar4[1])) &&
           ((param_2[3] == pfVar4[2] && (param_2[4] == pfVar4[3])))) &&
          ((param_2[5] == pfVar4[4] && ((param_2[6] == pfVar4[5] && (param_2[7] == pfVar4[6]))))))
         && (param_2[8] == pfVar4[7])) {
        FUN_004df110(param_2[1],0xffffffff);
        return;
      }
      iVar6 = iVar6 + 1;
      pfVar4 = pfVar4 + 9;
    } while (iVar6 < iVar5);
  }
  if (iVar5 == 0x14) {
    iVar5 = -1;
    local_4 = 3.4028235e+38;
    iVar6 = 0;
    piVar7 = (int *)(param_1 + 0x1c);
    do {
      iVar3 = *piVar7;
      if (iVar3 == 0) {
        fVar1 = (float)piVar7[8];
      }
      else {
        fVar1 = _DAT_005ad140;
        if (iVar3 == 1) {
          if (0 < iVar6) {
            iVar3 = piVar7[-9];
            if (iVar3 != 1) {
LAB_004deeaa:
              if (iVar3 != 2) goto LAB_004deeb6;
            }
LAB_004deeae:
            fVar1 = _DAT_0059e670;
          }
        }
        else if (iVar3 == 2) {
          if (iVar6 == 0) goto LAB_004deeae;
          if (0 < iVar6) {
            iVar3 = piVar7[-9];
            goto LAB_004deeaa;
          }
        }
      }
LAB_004deeb6:
      if (fVar1 < local_4) {
        iVar5 = iVar6;
        local_4 = fVar1;
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 9;
    } while (iVar6 < 0x14);
    if (iVar5 < 0x14) {
      puVar2 = (undefined4 *)(param_1 + 0x1c + iVar5 * 0x24);
      do {
        puVar8 = puVar2 + 9;
        puVar9 = puVar2;
        for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
        iVar5 = iVar5 + 1;
        puVar2 = puVar2 + 9;
      } while (iVar5 < *(int *)(param_1 + 0x18));
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  }
  iVar5 = *(int *)(param_1 + 0x18);
  iVar6 = 0;
  if (0 < iVar5) {
    pfVar4 = (float *)(param_1 + 0x20);
    do {
      if (param_2[1] < *pfVar4) break;
      iVar6 = iVar6 + 1;
      pfVar4 = pfVar4 + 9;
    } while (iVar6 < iVar5);
  }
  iVar5 = iVar5 + -1;
  if (iVar6 <= iVar5) {
    iVar3 = (iVar5 - iVar6) + 1;
    puVar2 = (undefined4 *)(param_1 + 0x40 + iVar5 * 0x24);
    do {
      iVar3 = iVar3 + -1;
      puVar8 = puVar2 + -9;
      puVar9 = puVar2;
      for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      puVar2 = puVar2 + -9;
    } while (iVar3 != 0);
  }
  pfVar4 = param_2;
  pfVar10 = (float *)(param_1 + 0x1c + iVar6 * 0x24);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar10 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar10 = pfVar10 + 1;
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  FUN_004df110(param_2[1],iVar6);
  return;
}


