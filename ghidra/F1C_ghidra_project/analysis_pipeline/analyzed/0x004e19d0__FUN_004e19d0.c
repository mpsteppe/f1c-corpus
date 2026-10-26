// Function: FUN_004e19d0 @ 004e19d0
// Size (bytes): 1536


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e19d0(int *param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  float10 fVar11;
  int local_48;
  int local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_0054b4d0(param_1[2],param_1[3],param_1[4],param_1[5],param_1[6],param_1[7]);
  piVar9 = param_1 + 0x72;
  iVar8 = 4;
  do {
    if ((piVar9[-0x21] != 0) && ((char)piVar9[-0x11] != '\0')) {
      FUN_0054b4d0(piVar9[-0x20],piVar9[-0x1f],piVar9[-0x1e],piVar9[-0x1d],piVar9[-0x1c],
                   piVar9[-0x1b]);
    }
    if ((piVar9[-0x10] != 0) && ((char)*piVar9 != '\0')) {
      FUN_0054b4d0(piVar9[-0xf],piVar9[-0xe],piVar9[-0xd],piVar9[-0xc],piVar9[-0xb],piVar9[-10]);
    }
    if (piVar9[6] != 0) {
      FUN_004e21d0(piVar9[6],piVar9[8]);
      if (piVar9[7] != 0) {
        FUN_004e21d0(piVar9[7],piVar9[8]);
      }
    }
    piVar9 = piVar9 + 0x4a;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  local_48 = 0;
  if (0 < param_1[0xaf4]) {
    iVar8 = 0;
    do {
      iVar2 = *(int *)(param_1[0xaf5] + iVar8);
      iVar10 = param_1[0xaf5] + iVar8;
      local_3c = (float)param_1[iVar2 * 0x4a + 0x52] + *(float *)(iVar10 + 4);
      local_38 = (float)param_1[iVar2 * 0x4a + 0x53] + *(float *)(iVar10 + 8);
      local_34 = (float)param_1[iVar2 * 0x4a + 0x54] + *(float *)(iVar10 + 0xc);
      FUN_0054b4d0(local_3c,local_38,local_34,param_1[iVar2 * 0x4a + 0x55],
                   param_1[iVar2 * 0x4a + 0x56],param_1[iVar2 * 0x4a + 0x57]);
      FUN_0054c0b0(&local_40,&local_44);
      FUN_0054c030(local_40,local_44,1,0);
      FUN_005506a0(param_1[iVar2 * 0x4a + 0x7b],0,0);
      piVar9 = &DAT_008ad3ec;
      do {
        if (*piVar9 != 0) {
          FUN_005506a0(param_1[0x2db],*piVar9,0);
        }
        piVar9 = piVar9 + 1;
      } while ((int)piVar9 < 0x8ad3f8);
      local_48 = local_48 + 1;
      iVar8 = iVar8 + 0x14;
    } while (local_48 < param_1[0xaf4]);
  }
  if (((DAT_007cfcec == 0) && (DAT_005ea518 == DAT_005ea528)) &&
     (*(int *)(DAT_005ea528 + 0x34) == 1)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if ((*(int *)(*param_1 + 0x4894) == *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894)) &&
     (0 < DAT_007cf7f4)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if ((((!bVar3) && ((bVar4 || (DAT_008ab6e4 == 2)))) && (iVar8 = FUN_0040c870(), iVar8 != 0)) &&
     (fVar1 = *(float *)(iVar8 + 0xc) + (float)param_1[2],
     fVar6 = (float)param_1[3] + *(float *)(iVar8 + 0x10),
     fVar5 = (float)param_1[4] + *(float *)(iVar8 + 0x14),
     fVar1 * fVar1 + fVar6 * fVar6 + fVar5 * fVar5 < _DAT_0059f110)) {
    iVar8 = param_1[0x259];
    if (iVar8 == 0) {
      piVar9 = param_1 + 0x35;
      iVar8 = 4;
      do {
        FUN_004e3090(piVar9);
        piVar9 = piVar9 + 0x4a;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    else if (iVar8 == 1) {
      FUN_004e3090(param_1 + 0x35);
      FUN_004e3090(param_1 + 0x7f);
    }
    else if (iVar8 == 2) {
      if (DAT_007cfcc8 == 0) {
        FUN_004e3090(param_1 + 0x35);
        FUN_004e3090(param_1 + 0x7f);
      }
      else {
        piVar9 = param_1 + 0x35;
        iVar8 = 4;
        do {
          FUN_004e3090(piVar9);
          piVar9 = piVar9 + 0x4a;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
  }
  if (param_1[0x228] != 0) {
    local_34 = (float)param_1[0x254] * _DAT_005ad158;
    local_3c = (float)param_1[0x256] * local_34;
    local_38 = (float)param_1[599] * local_34;
    local_24 = 0x3f800000;
    local_20 = 0;
    local_34 = (float)param_1[600] * local_34;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0x3f800000;
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0x3f800000;
    FUN_00567120(&local_3c,&local_30);
    FUN_0054b450(local_30,local_2c,local_28);
  }
  if ((param_1[0x226] != 0) && (*(char *)((int)param_1 + 0x96d) != '\0')) {
    if (*(int *)(*param_1 + 0x4894) == *(int *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894)) {
      FUN_0054c030(1,1,0,0);
      iVar8 = 0;
      local_40 = ((float)param_1[0x254] + _DAT_0059e43c) - _DAT_0059e87c;
      if (0 < param_1[0x22d]) {
        piVar9 = param_1 + 0x231;
        do {
          FUN_00551810(*piVar9,local_40);
          iVar8 = iVar8 + 1;
          piVar9 = piVar9 + 4;
        } while (iVar8 < param_1[0x22d]);
      }
    }
    else {
      FUN_0054c030(0,0,0,0);
    }
  }
  cVar7 = '\0';
  if ((*(char *)((int)param_1 + 0x979) != '\0') ||
     ((float)param_1[0x253] < (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450)) {
    local_40 = (float)_DAT_008afea0;
    fVar11 = (float10)FUN_0058957a();
    if (fVar11 < (float10)_DAT_005ad154) {
      cVar7 = '\x01';
    }
  }
  if ((cVar7 != (char)param_1[0x25d]) && (*(char *)(param_1 + 0x25d) = cVar7, param_1[0x229] != 0))
  {
    FUN_005506a0(cVar7 != '\0',0,0);
  }
  if ((param_1[0x22a] != 0) &&
     (cVar7 = *(char *)((int)param_1 + 0x975), cVar7 != *(char *)((int)param_1 + 0x976))) {
    *(char *)((int)param_1 + 0x976) = cVar7;
    FUN_005506a0(cVar7 != '\0',0,0);
  }
  if ((param_1[0x22b] != 0) &&
     (cVar7 = *(char *)((int)param_1 + 0x977), cVar7 != (char)param_1[0x25e])) {
    *(char *)(param_1 + 0x25e) = cVar7;
    FUN_005506a0(cVar7 != '\0',0,0);
  }
  if (param_1[0x22c] != 0) {
    if (DAT_008ab6e4 == 2) {
      fVar11 = (float10)FUN_004b9ce0();
    }
    else {
      fVar11 = (float10)_DAT_008afea0;
    }
    iVar8 = 0;
    fVar1 = (float)(fVar11 - (float10)(float)param_1[0x261]);
    if ((DAT_0059e440 < fVar1) && (fVar1 < (float)param_1[0x262])) {
      local_40 = _DAT_007cf740 * fVar1 + _DAT_0059e450;
      iVar8 = (int)ROUND(local_40);
      local_44 = iVar8;
    }
    if (iVar8 != param_1[0x260]) {
      param_1[0x260] = iVar8;
      FUN_005506a0(0,0,0);
      FUN_005506a0(iVar8,0,0);
    }
  }
  return;
}


