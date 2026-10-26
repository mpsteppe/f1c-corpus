// Function: FUN_0042e530 @ 0042e530
// Strings:  [Road Course, Track Type, RearSpoilerAngle]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042e530(int param_1,int param_2,int param_3)

{
  double dVar1;
  bool bVar2;
  double dVar3;
  bool bVar4;
  undefined1 uVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  double *pdVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  int local_74;
  double local_70;
  undefined1 local_68 [32];
  undefined1 local_48 [68];
  
  if ((param_2 == -1) || (param_3 == -1)) {
    bVar4 = true;
    iVar11 = 0x2c;
    iVar10 = 0x32;
LAB_0042e579:
    if (iVar11 <= iVar10) {
      puVar6 = (uint *)(iVar11 * 0x40 + 0xbc4 + param_1);
      do {
        if (((iVar11 < 0x32) && ((char)puVar6[0x12] != '\0')) && ((int)puVar6[0x10] <= (int)*puVar6)
           ) {
          uVar8 = puVar6[0x10] - 1;
          *puVar6 = uVar8 & ((int)uVar8 < 0) - 1;
        }
        if ((0x2c < iVar11) && ((int)*puVar6 <= (int)puVar6[-0x10])) {
          uVar8 = puVar6[-0x10] + 1;
          if ((int)(puVar6[-1] - 1) < (int)uVar8) {
            uVar8 = puVar6[-1] - 1;
          }
          *puVar6 = uVar8;
        }
        iVar11 = iVar11 + 1;
        puVar6 = puVar6 + 0x10;
      } while (iVar11 <= iVar10);
    }
  }
  else {
    bVar4 = false;
    if (((param_2 == 4) && (0x2b < param_3)) && (iVar11 = param_3, iVar10 = param_3, param_3 < 0x33)
       ) goto LAB_0042e579;
  }
  if (*(char *)(param_1 + 0x1988) == '\0') {
    if ((param_2 == -1) && (param_3 == 0x11)) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    FUN_0042e4a0(param_1 + 0xff0,param_1 + 0x1030,uVar5);
    if ((param_2 == -1) && (param_3 == 0x13)) {
      uVar7 = 1;
    }
    else {
      uVar7 = 0;
    }
    FUN_0042e4a0(param_1 + 0x1070,param_1 + 0x10b0,uVar7);
    if ((param_2 == -1) && (param_3 == 0x17)) {
      uVar7 = 1;
    }
    else {
      uVar7 = 0;
    }
    FUN_0042e4a0(param_1 + 0x1170,param_1 + 0x11b0,uVar7);
    if ((param_2 == -1) && (param_3 == 0x19)) {
      uVar7 = 1;
    }
    else {
      uVar7 = 0;
    }
    FUN_0042e4a0(param_1 + 0x11f0,param_1 + 0x1230,uVar7);
    iVar10 = 0;
    iVar11 = param_1 + 0x1f0;
    do {
      if ((param_2 == iVar10) && (param_3 == 5)) {
        uVar7 = 1;
      }
      else {
        uVar7 = 0;
      }
      FUN_0042e4a0(iVar11,iVar11 + 0x40,uVar7);
      if ((param_2 == iVar10) && (param_3 == 7)) {
        uVar7 = 1;
      }
      else {
        uVar7 = 0;
      }
      FUN_0042e4a0(iVar11 + 0x80,iVar11 + 0xc0,uVar7);
      iVar10 = iVar10 + 1;
      iVar11 = iVar11 + 0x2c0;
    } while (iVar10 < 4);
  }
  else {
    FUN_0042e470(param_1 + 0xff0,param_1 + 0x1030);
    FUN_0042e470(param_1 + 0x1070,param_1 + 0x10b0);
    FUN_0042e470(param_1 + 0x1170,param_1 + 0x11b0);
    FUN_0042e470(param_1 + 0x11f0,param_1 + 0x1230);
    iVar11 = param_1 + 0x1f0;
    iVar10 = 4;
    do {
      FUN_0042e470(iVar11,iVar11 + 0x40);
      FUN_0042e470(iVar11 + 0x80,iVar11 + 0xc0);
      iVar11 = iVar11 + 0x2c0;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  if (*(int *)(param_1 + 0x1990) != 1) {
    return;
  }
  if (bVar4) {
LAB_0042e798:
    iVar11 = FUN_004c58a0(local_68,0x20,s_RearSpoilerAngle_005c371c,0);
    if (iVar11 == 0) {
      fVar12 = (float10)FUN_0058850f(local_68);
      iVar11 = *(int *)(param_1 + 0x12c4);
      local_70 = 1.7976931348623157e+308;
      local_74 = 0;
      if (0 < *(int *)(param_1 + 0x12c0)) {
        iVar10 = local_74;
        do {
          local_74 = iVar10;
          fVar13 = ABS(((float10)local_74 * (float10)*(double *)(param_1 + 0x12b8) +
                       (float10)*(double *)(param_1 + 0x12b0)) - fVar12);
          if (fVar13 < (float10)local_70) {
            local_70 = (double)fVar13;
            iVar11 = local_74;
          }
          iVar10 = local_74 + 1;
        } while (local_74 + 1 < *(int *)(param_1 + 0x12c0));
        *(int *)(param_1 + 0x12c4) = local_74;
      }
      *(int *)(param_1 + 0x12c4) = iVar11;
    }
    if (bVar4) {
LAB_0042e84a:
      if ((DAT_007c56a4 != 0) && (0 < *(int *)(param_1 + 0xcc0))) {
        *(int *)(param_1 + 0xcc4) = *(int *)(param_1 + 0xcc0) + -1;
      }
    }
    else if (param_2 == 4) goto LAB_0042e845;
  }
  else if (param_2 == 4) {
    if (param_3 == 0x1c) goto LAB_0042e798;
LAB_0042e845:
    if (param_3 == 4) goto LAB_0042e84a;
  }
  bVar2 = false;
  iVar11 = FUN_004c58a0(local_48,0x40,s_Track_Type_005c3710,0);
  if ((iVar11 == 0) && (iVar11 = FUN_00588410(local_48,s_Road_Course_005c3704), iVar11 == 0)) {
    bVar2 = true;
  }
  if (bVar4) {
LAB_0042e8b9:
    if (bVar2) {
      pdVar9 = (double *)(param_1 + 0x6b0);
      dVar1 = (double)*(int *)(param_1 + 0x6c4) * *(double *)(param_1 + 0x6b8) + *pdVar9;
      if ((dVar1 < _DAT_0059e9f8) &&
         (dVar3 = (double)*(int *)(param_1 + 0x984) * *(double *)(param_1 + 0x978) +
                  *(double *)(param_1 + 0x970), dVar3 < _DAT_0059e9f8)) {
        if ((param_2 != 2) && ((param_2 == 3 || (dVar1 <= dVar3)))) {
          pdVar9 = (double *)(param_1 + 0x970);
        }
        iVar11 = *(int *)((int)pdVar9 + 0x14);
        while ((iVar11 < *(int *)(pdVar9 + 2) &&
               ((double)*(int *)((int)pdVar9 + 0x14) * pdVar9[1] + *pdVar9 < _DAT_0059e9f8))) {
          iVar11 = *(int *)((int)pdVar9 + 0x14) + 1;
          *(int *)((int)pdVar9 + 0x14) = iVar11;
        }
      }
    }
    else {
      iVar11 = *(int *)(param_1 + 0x984);
      while ((iVar11 < *(int *)(param_1 + 0x980) &&
             ((double)*(int *)(param_1 + 0x984) * *(double *)(param_1 + 0x978) +
              *(double *)(param_1 + 0x970) < _DAT_0059e9f8))) {
        iVar11 = *(int *)(param_1 + 0x984) + 1;
        *(int *)(param_1 + 0x984) = iVar11;
      }
    }
    if (bVar4) goto LAB_0042e9bc;
LAB_0042e9ac:
    if (param_2 == 4) goto LAB_0042e9b1;
  }
  else {
    if (param_2 != 4) {
      if (param_3 == 2) goto LAB_0042e8b9;
      goto LAB_0042e9ac;
    }
LAB_0042e9b1:
    if (param_3 != 0) {
      return;
    }
LAB_0042e9bc:
    if (!bVar2) {
      *(undefined4 *)(param_1 + 0xbc4) = 0;
    }
    if (bVar4) goto LAB_0042e9e1;
    if (param_2 == 4) {
      return;
    }
  }
  if (param_3 != 2) {
    return;
  }
LAB_0042e9e1:
  iVar11 = *(int *)(param_1 + 0x404);
  local_70 = 1.7976931348623157e+308;
  local_74 = 0;
  if (0 < *(int *)(param_1 + 0x400)) {
    iVar10 = local_74;
    do {
      local_74 = iVar10;
      dVar1 = ABS(((double)local_74 * *(double *)(param_1 + 0x3f8) + *(double *)(param_1 + 0x3f0)) -
                  ((double)*(int *)(param_1 + 0x984) * *(double *)(param_1 + 0x978) +
                   *(double *)(param_1 + 0x970) +
                  (((double)*(int *)(param_1 + 0x144) * *(double *)(param_1 + 0x138) +
                   *(double *)(param_1 + 0x130)) -
                  ((double)*(int *)(param_1 + 0x6c4) * *(double *)(param_1 + 0x6b8) +
                  *(double *)(param_1 + 0x6b0)))));
      if (dVar1 < local_70) {
        iVar11 = local_74;
        local_70 = dVar1;
      }
      iVar10 = local_74 + 1;
    } while (local_74 + 1 < *(int *)(param_1 + 0x400));
    *(int *)(param_1 + 0x404) = local_74;
  }
  *(int *)(param_1 + 0x404) = iVar11;
  return;
}


