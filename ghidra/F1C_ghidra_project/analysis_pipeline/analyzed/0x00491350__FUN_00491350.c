// Function: FUN_00491350 @ 00491350
// Size (bytes): 592


int __thiscall FUN_00491350(short *param_1,int param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int local_50;
  int local_40;
  char local_2c [12];
  int local_20 [8];
  
  iVar5 = (int)*param_1;
  sVar1 = param_1[2];
  sVar2 = param_1[3];
  iVar8 = (int)param_1[1];
  local_20[5] = param_3;
  local_20[4] = iVar8;
  local_50 = 0;
  local_20[6] = sVar2 + iVar8;
  local_20[7] = param_5 + param_3;
  local_20[0] = iVar5;
  local_20[1] = param_2;
  local_20[2] = sVar1 + iVar5;
  local_20[3] = param_4 + param_2;
  iVar9 = 3;
  do {
    iVar6 = 0;
    do {
      iVar7 = *(int *)((int)local_20 + iVar6);
      iVar10 = *(int *)((int)local_20 + iVar6 + 4);
      if (iVar10 < iVar7) {
        *(int *)((int)local_20 + iVar6) = iVar10;
        *(int *)((int)local_20 + iVar6 + 4) = iVar7;
      }
      iVar7 = *(int *)((int)local_20 + iVar6 + 0x10);
      iVar10 = *(int *)((int)local_20 + iVar6 + 0x14);
      if (iVar10 < iVar7) {
        *(int *)((int)local_20 + iVar6 + 0x10) = iVar10;
        *(int *)((int)local_20 + iVar6 + 0x14) = iVar7;
      }
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0xc);
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  local_40 = 0;
  pcVar11 = local_2c;
  do {
    iVar9 = local_20[local_40];
    iVar6 = local_20[local_40 + 1];
    iVar7 = 0;
    do {
      if ((((iVar9 < iVar5) || (sVar1 + iVar5 < iVar6)) || (local_20[iVar7 + 4] < iVar8)) ||
         (sVar2 + iVar8 < local_20[iVar7 + 5])) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (((iVar9 < param_2) || (param_4 + param_2 < iVar6)) ||
         ((local_20[iVar7 + 4] < param_3 || (param_5 + param_3 < local_20[iVar7 + 5])))) {
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      if ((!bVar3) || (bVar4)) {
        pcVar11[iVar7] = '\x01';
      }
      else {
        pcVar11[iVar7] = '\0';
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 3);
    local_40 = local_40 + 1;
    pcVar11 = pcVar11 + 3;
  } while (local_40 < 3);
  param_5 = 0;
  do {
    iVar5 = param_5 * 3 + -0x2c;
    param_3 = 0;
    do {
      iVar8 = local_50;
      if (local_2c[param_3 + iVar5 + 0x2c] == '\0') {
        iVar9 = local_20[param_3 + 4];
        iVar6 = local_20[param_3 + 5];
        iVar7 = local_20[param_5];
        iVar10 = local_20[param_5 + 1];
        if ((iVar6 - iVar9 < 1) || (iVar10 == iVar7 || iVar10 - iVar7 < 0)) {
          local_2c[param_3 + iVar5 + 0x2c] = '\x01';
        }
        else {
          if ((param_5 < 2) && (iVar8 = param_5 + 1, iVar8 < 3)) {
            pcVar11 = local_2c + param_3 + iVar8 * 3;
            do {
              if (*pcVar11 != '\0') break;
              iVar10 = local_20[iVar8 + 1];
              *pcVar11 = '\x01';
              iVar8 = iVar8 + 1;
              pcVar11 = pcVar11 + 3;
            } while (iVar8 < 3);
          }
          iVar8 = FUN_00490940(iVar10 - iVar7,iVar6 - iVar9);
          *(short *)(iVar8 + 8) = param_1[4];
          if (local_50 != 0) {
            iVar6 = *(int *)(local_50 + 0xc);
            iVar9 = local_50;
            while (iVar7 = iVar6, iVar7 != 0) {
              iVar9 = iVar7;
              iVar6 = *(int *)(iVar7 + 0xc);
            }
            *(int *)(iVar9 + 0xc) = iVar8;
            iVar8 = local_50;
          }
        }
      }
      local_50 = iVar8;
      param_3 = param_3 + 1;
    } while (param_3 < 3);
    param_5 = param_5 + 1;
    if (2 < param_5) {
      return local_50;
    }
  } while( true );
}


