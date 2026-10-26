// Function: FUN_004a58b0 @ 004a58b0
// Strings:  [%s/%d, Do Not Repair, Do Not Repair, Do Not Repair, Repair, Repair, %d (-%d), %d (+%d)]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004a58b0(int *param_1)

{
  double dVar1;
  double dVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined **ppuVar9;
  undefined8 uVar10;
  undefined1 local_40 [64];
  
  iVar6 = param_1[0x1b];
  dVar1 = *(double *)(param_1 + 0x18);
  dVar2 = *(double *)(param_1 + 0x16);
  if ((float)param_1[0x5f] == DAT_0059e440) {
    local_40[0] = 0;
  }
  else {
    uVar4 = __ftol();
    FUN_0058815f(local_40,&PTR_DAT_005ccea4,uVar4);
  }
  if (DAT_007d0450 == 1) {
    FUN_0058815f((int)param_1 + 0x76,s__4_1f_s_005cd678,
                 ((double)iVar6 * dVar1 + dVar2) * _DAT_0059ea40,local_40);
  }
  else {
    uVar4 = __ftol(local_40);
    FUN_0058815f((int)param_1 + 0x76,&DAT_005cd670,uVar4);
  }
  puVar5 = (undefined4 *)FUN_004a5820(param_1[0x2b]);
  if (puVar5 == (undefined4 *)0x0) {
    iVar6 = FUN_00423a00();
    if (iVar6 != 0) {
      iVar6 = 0;
      do {
        pcVar8 = s_No_Change_005cd664 + iVar6;
        (&DAT_005ec4cc)[iVar6] = *pcVar8;
        iVar6 = iVar6 + 1;
      } while (*pcVar8 != '\0');
    }
  }
  else {
    pcVar8 = (char *)*puVar5;
    if (pcVar8 == (char *)0x0) {
      pcVar8 = &DAT_005ea438;
    }
    iVar6 = FUN_00423a00();
    if (iVar6 != 0) {
      if (pcVar8 == (char *)0x0) {
        DAT_005ec4cc = 0;
      }
      else {
        iVar6 = (int)&DAT_005ec4cc - (int)pcVar8;
        do {
          cVar3 = *pcVar8;
          pcVar8[iVar6] = cVar3;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
      }
    }
  }
  FUN_0058815f(CONCAT44(&DAT_005c2c18,(int)param_1 + 0xb6),&DAT_005ec4cc);
  iVar6 = param_1[0x3b];
  iVar7 = param_1[0x3c];
  if (iVar6 == iVar7) {
    FUN_0058815f((int)param_1 + 0xf6,&DAT_005c3280,iVar6 + 1);
  }
  else {
    if (iVar7 < iVar6) {
      iVar7 = iVar6 - iVar7;
      uVar10 = CONCAT44(iVar6 + 1,s__d____d__005cd658);
    }
    else {
      iVar7 = iVar7 - iVar6;
      uVar10 = CONCAT44(iVar6 + 1,s__d____d__005cd64c);
    }
    FUN_0058815f((int)param_1 + 0xf6,uVar10,iVar7);
  }
  if (param_1[0x4a] == 1) {
    iVar6 = FUN_00423a00();
    if (iVar6 != 0) {
      iVar6 = 0;
      do {
        pcVar8 = &DAT_005c3810 + iVar6;
        (&DAT_005ec4cc)[iVar6] = *pcVar8;
        iVar6 = iVar6 + 1;
      } while (*pcVar8 != '\0');
    }
  }
  else {
    pcVar8 = s_Repair_005cd644;
    if (param_1[0x4b] == 0) {
      pcVar8 = s_Do_Not_Repair_005cd634;
    }
    iVar6 = FUN_00423a00();
    if (iVar6 != 0) {
      if (pcVar8 == (char *)0x0) {
        DAT_005ec4cc = 0;
      }
      else {
        iVar6 = (int)&DAT_005ec4cc - (int)pcVar8;
        do {
          cVar3 = *pcVar8;
          pcVar8[iVar6] = cVar3;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
      }
    }
  }
  FUN_0058815f(CONCAT44(&DAT_005c2c18,(int)param_1 + 0x136),&DAT_005ec4cc);
  if (param_1[10] != 1) {
    uVar4 = *(undefined4 *)(*param_1 + 0x4074);
    ppuVar9 = &PTR_DAT_005c6e14;
    if (param_1[0xb] == 0) {
      ppuVar9 = (undefined **)&DAT_005c6e18;
    }
    iVar6 = FUN_00423a00();
    if (iVar6 != 0) {
      if (ppuVar9 == (undefined **)0x0) {
        DAT_005ec4cc = 0;
      }
      else {
        iVar6 = (int)&DAT_005ec4cc - (int)ppuVar9;
        do {
          cVar3 = *(char *)ppuVar9;
          *(char *)((int)ppuVar9 + iVar6) = cVar3;
          ppuVar9 = (undefined **)((int)ppuVar9 + 1);
        } while (cVar3 != '\0');
      }
    }
    FUN_0058815f((int)param_1 + 0x36,s__s__d_005cd62c,&DAT_005ec4cc,uVar4);
    return;
  }
  iVar6 = FUN_00423a00();
  if (iVar6 != 0) {
    iVar6 = 0;
    do {
      pcVar8 = &DAT_005c3810 + iVar6;
      (&DAT_005ec4cc)[iVar6] = *pcVar8;
      iVar6 = iVar6 + 1;
    } while (*pcVar8 != '\0');
  }
  FUN_0058815f((int)param_1 + 0x36,&DAT_005c2c18,&DAT_005ec4cc);
  return;
}


