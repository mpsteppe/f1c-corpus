// Function: FUN_00432220 @ 00432220
// Strings:  [SettingsCopy]


/* WARNING: Removing unreachable block (ram,0x0043261a) */
/* WARNING: Removing unreachable block (ram,0x00432579) */
/* WARNING: Removing unreachable block (ram,0x004325d0) */
/* WARNING: Removing unreachable block (ram,0x004324cd) */

undefined1 __fastcall FUN_00432220(undefined4 *param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  undefined1 local_333;
  int local_320;
  int local_30c;
  char local_300 [256];
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  puVar4 = *(undefined1 **)*param_1;
  local_333 = 0;
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  FUN_00566650(puVar4);
  uVar14 = 0xffffffff;
  pcVar8 = &DAT_005ea438;
  do {
    if (uVar14 == 0) break;
    uVar14 = uVar14 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  iVar5 = FUN_00589671(&DAT_005ea438);
  if (0 < DAT_008ac488) {
    local_320 = 0;
    local_30c = DAT_008ac488;
    do {
      iVar10 = local_320 + 0x104 + DAT_008ac490;
      iVar6 = FUN_004c5840(iVar10);
      pcVar7 = (char *)FUN_004326a0();
      pcVar8 = pcVar7;
      do {
        cVar1 = *pcVar8;
        pcVar8[(int)(local_300 + -(int)pcVar7)] = cVar1;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00432650();
      iVar9 = FUN_00423a00(local_300,&DAT_005ec4cc);
      if (iVar9 != 0) {
        iVar9 = 0;
        do {
          cVar1 = local_300[iVar9];
          (&DAT_005ec4cc)[iVar9] = cVar1;
          iVar9 = iVar9 + 1;
        } while (cVar1 != '\0');
      }
      FUN_005665b0(&DAT_005ec4cc);
      FUN_00568620(0xff);
      FUN_00589671(local_100);
      bVar2 = false;
      if (DAT_007d03f8 != '\0') {
        puVar4 = DAT_007ce5ec;
        if (DAT_007ce5ec == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        iVar10 = FUN_00588410(iVar10,puVar4);
        if (iVar10 == 0) {
          bVar2 = true;
        }
      }
      if (((iVar5 == 0) || (bVar2)) && (local_333 = 1, iVar6 != 0)) {
        bVar3 = true;
        iVar10 = FUN_005679c0(PTR_s_SettingsCopy_005c3fa8);
        while (iVar10 != 0) {
          puVar11 = operator_new(0x80);
          *puVar11 = 0;
          puVar4 = DAT_005ec440;
          if (DAT_005ec440 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          FUN_005665b0(puVar4);
          uVar12 = FUN_00567970();
          FUN_005665b0(uVar12);
          uVar12 = FUN_00567970();
          FUN_00566650(uVar12);
          puVar4 = (undefined1 *)FUN_00566810();
          if (puVar4 != (undefined1 *)0x0) {
            *puVar4 = 0;
          }
          pcVar13 = operator_new(0x80);
          *pcVar13 = '\0';
          FUN_005665b0(&DAT_005ea438);
          pcVar8 = pcVar13;
          if (pcVar13 == (char *)0x0) {
            pcVar8 = &DAT_005ea438;
          }
          uVar15 = 0xffffffff;
          do {
            if (uVar15 == 0) break;
            uVar15 = uVar15 - 1;
            cVar1 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar1 != '\0');
          if ((0 < (int)(~uVar15 - 1)) &&
             (iVar10 = FUN_00415c30(), *(char *)(iVar10 + -1 + (~uVar15 - 1)) != '\\')) {
            FUN_005665b0(&DAT_005c2aac);
          }
          pcVar8 = &DAT_005ea438;
          iVar10 = FUN_00423a00(&DAT_005ea438,&DAT_005ec4cc);
          if (iVar10 != 0) {
            do {
              cVar1 = *pcVar8;
              pcVar8[0x2094] = cVar1;
              pcVar8 = pcVar8 + 1;
            } while (cVar1 != '\0');
          }
          FUN_005665b0(&DAT_005ec4cc);
          FUN_005665b0(&DAT_005c403c);
          FUN_00568620(0xff);
          if ((bVar2) && (bVar3)) {
            iVar10 = FUN_00433b60(local_200,pcVar7,0);
            if (iVar10 == 0) {
              FUN_00568b00();
            }
            if (iVar5 != 0) {
              if (pcVar13 != (char *)0x0) {
                FUN_00587bcf(pcVar13);
              }
              if (puVar11 != (undefined1 *)0x0) {
                FUN_00587bcf(puVar11);
              }
              break;
            }
          }
          else {
            FUN_00568b00();
          }
          bVar3 = false;
          if (pcVar13 != (char *)0x0) {
            FUN_00587bcf(pcVar13);
          }
          if (puVar11 != (undefined1 *)0x0) {
            FUN_00587bcf(puVar11);
          }
          iVar10 = FUN_0049adb0();
        }
      }
      (&DAT_005ea437)[~uVar14] = 0;
      local_320 = local_320 + 0x18c;
      local_30c = local_30c + -1;
    } while (local_30c != 0);
  }
  return local_333;
}


