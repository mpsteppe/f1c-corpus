// Function: FUN_004bf0a0 @ 004bf0a0
// Size (bytes): 736


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004bf0a0(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  float fVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  float fVar9;
  float10 fVar10;
  float local_1ac;
  float local_1a4 [105];
  
  fVar9 = DAT_005c329c;
  local_1a4[0] = DAT_005c329c;
  FUN_004ba140(1);
  *(float *)(param_1 + 0x354) = (float)_DAT_008afea0;
  *(undefined4 *)(param_1 + 0x358) = param_2;
  puVar3 = DAT_007ce5ec;
  if (DAT_007ce5ec == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_004be760(*(undefined4 *)(param_1 + 0x360),puVar3,(float)DAT_007d01a0 * _DAT_005acde0);
  switch(DAT_007cea5c) {
  default:
    local_1ac = 0.0;
    break;
  case 1:
    if (DAT_007c56a4 != 7) goto switchD_004bf119_caseD_2;
    local_1ac = _DAT_0059e43c / _DAT_008acf9c;
    if (local_1ac != DAT_0059e440) {
      uVar4 = 1;
      goto LAB_004bf12a;
    }
    break;
  case 2:
switchD_004bf119_caseD_2:
    local_1ac = 1.0;
    uVar4 = 1;
    goto LAB_004bf12a;
  }
  uVar4 = 0;
LAB_004bf12a:
  FUN_004be9e0(1,uVar4,local_1ac,DAT_005acdb0);
  iVar8 = 0;
  pfVar7 = local_1a4;
  for (iVar6 = 0x68; pfVar7 = pfVar7 + 1, iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar7 = 0.0;
  }
  do {
    *(undefined4 *)(param_1 + iVar8 * 4) = 0xbf800000;
    *(undefined4 *)(param_1 + 0x1a0 + iVar8 * 4) = 0;
    fVar2 = DAT_005ea3fc;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x68);
  iVar6 = 0;
  local_1ac = 0.0;
  if (0 < (int)fVar9) {
    do {
      iVar8 = (&DAT_007c54f0)[iVar6];
      if ((((*(int *)(iVar8 + 13000) != -1) && (*(int *)(iVar8 + 13000) != 0)) &&
          (iVar1 = *(int *)(iVar8 + 0x403c), iVar1 < *(int *)(param_1 + 0x35c))) &&
         (((DAT_007c56a4 == 7 || (iVar5 = FUN_0042ae90(), iVar1 <= iVar5)) &&
          ((*(int *)((&DAT_007c54f0)[iVar6] + 0x4064) != 1 &&
           ((*(int *)(iVar8 + 0x4064) != 3 && (*(int *)(iVar8 + 0x4064) != 2)))))))) {
        fVar10 = (float10)FUN_004bea10(iVar8,*(undefined4 *)(param_1 + 0x34c));
        *(float *)(param_1 + iVar6 * 4) = (float)fVar10;
        if ((*(int *)(iVar8 + 0x4094) == 0) ||
           (fVar9 = *(float *)(iVar8 + 0x4044), *(int *)(iVar8 + 0x4094) == 1)) {
          fVar9 = DAT_0059e440;
        }
        *(int *)(iVar8 + 0x403c) = *(int *)(iVar8 + 0x403c) + 1;
        fVar9 = (*(float *)(param_1 + iVar6 * 4) / fVar2) * (fVar2 - fVar9);
        local_1a4[iVar6 + 1] = fVar9;
        if (local_1ac < fVar9) {
          local_1ac = fVar9;
        }
        fVar9 = fVar9 + *(float *)(param_1 + 0x354);
        if (fVar9 < DAT_0059e440) {
          fVar9 = DAT_0059e440;
        }
        *(float *)(iVar8 + 0x4098) = fVar9;
        if ((*(float *)(iVar8 + 0x409c) < DAT_0059e440 !=
             (*(float *)(iVar8 + 0x409c) == DAT_0059e440)) ||
           (*(float *)(param_1 + iVar6 * 4) < *(float *)(iVar8 + 0x409c))) {
          *(undefined4 *)(iVar8 + 0x409c) = *(undefined4 *)(param_1 + iVar6 * 4);
        }
        *(float *)(iVar8 + 0x40b8) =
             (*(float *)(param_1 + 0x354) - _DAT_008acf90) + local_1a4[iVar6 + 1];
        FUN_004bf390(iVar8);
        if (((*(int *)(param_1 + 0x35c) <= *(int *)(iVar8 + 0x403c)) || (param_3 != '\0')) &&
           (*(undefined4 *)(param_1 + iVar6 * 4) = 0xbf800000, *(int *)(iVar8 + 0x4064) != 3)) {
          *(undefined4 *)(iVar8 + 0x4064) = 1;
        }
      }
      iVar6 = iVar6 + 1;
      fVar9 = local_1a4[0];
    } while (iVar6 < (int)local_1a4[0]);
  }
  iVar6 = 0;
  *(float *)(param_1 + 0x354) = local_1ac + *(float *)(param_1 + 0x354);
  if (0 < (int)fVar9) {
    pfVar7 = (float *)(param_1 + 0x1a0);
    do {
      iVar6 = iVar6 + 1;
      *pfVar7 = local_1ac - local_1a4[iVar6];
      pfVar7 = pfVar7 + 1;
    } while (iVar6 < (int)fVar9);
  }
  return;
}


