// Function: FUN_00469630 @ 00469630
// Size (bytes): 546


undefined4 __fastcall FUN_00469630(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int unaff_ESI;
  undefined4 *puVar12;
  bool bVar13;
  undefined1 local_500;
  undefined4 local_4ff;
  char local_401 [1025];
  
  uVar3 = FUN_0048d360();
  pcVar4 = (char *)FUN_004693e0(uVar3);
  if (pcVar4 != (char *)0x0) {
    iVar10 = -1;
    pcVar5 = pcVar4;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (iVar10 != -2) {
      pcVar5 = pcVar4;
      do {
        cVar1 = *pcVar5;
        pcVar5[(int)(local_401 + (1 - (int)pcVar4))] = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      pcVar5 = local_401;
      uVar11 = 0xffffffff;
      do {
        pcVar5 = pcVar5 + 1;
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
      } while (*pcVar5 != '\0');
      pcVar5 = local_401 + ~uVar11;
      if (local_401 + 1 < pcVar5) {
        do {
          if (*pcVar5 == '.') {
            *pcVar5 = '\0';
            break;
          }
          pcVar5 = pcVar5 + -1;
        } while (local_401 + 1 < pcVar5);
      }
      FUN_00566650(local_401 + 1);
      pbVar6 = DAT_007d0434;
      if (DAT_007d0434 == (byte *)0x0) {
        pbVar6 = &DAT_005ea438;
      }
      FUN_00566650(pbVar6);
      FUN_004b04e0(pcVar4,0);
      pbVar6 = DAT_007d0434;
      if (DAT_007d0434 == (byte *)0x0) {
        pbVar6 = &DAT_005ea438;
      }
      pbVar7 = &DAT_005ea438;
      do {
        bVar2 = *pbVar7;
        bVar13 = bVar2 < *pbVar6;
        if (bVar2 != *pbVar6) {
LAB_00469744:
          iVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
          goto LAB_00469749;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar7[1];
        bVar13 = bVar2 < pbVar6[1];
        if (bVar2 != pbVar6[1]) goto LAB_00469744;
        pbVar7 = pbVar7 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar2 != 0);
      iVar10 = 0;
LAB_00469749:
      if (iVar10 != 0) {
        local_500 = DAT_005ea438;
        puVar12 = &local_4ff;
        for (iVar10 = 0x3f; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar12 = 0;
          puVar12 = puVar12 + 1;
        }
        *(undefined2 *)puVar12 = 0;
        *(undefined1 *)((int)puVar12 + 2) = 0;
        puVar8 = DAT_005ec3d8;
        if (DAT_005ec3d8 == (undefined1 *)0x0) {
          puVar8 = &DAT_005ea438;
        }
        iVar10 = FUN_0058969d(&local_500,0xff,&DAT_005be860,puVar8,&DAT_005ea438);
        if (-1 < iVar10) {
          FUN_005684a0(&local_500);
          pbVar6 = DAT_007d0434;
          if (DAT_007d0434 == (byte *)0x0) {
            pbVar6 = &DAT_005ea438;
          }
          puVar8 = DAT_005ec3d8;
          if (DAT_005ec3d8 == (undefined1 *)0x0) {
            puVar8 = &DAT_005ea438;
          }
          iVar10 = FUN_0058969d(&local_500,0xff,&DAT_005be860,puVar8,pbVar6);
          if (-1 < iVar10) {
            FUN_00567f40(&local_500,0);
          }
        }
      }
      iVar10 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(0x1d);
      iVar9 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(2);
      if (iVar10 != 0) {
        FUN_00470190();
      }
      if (iVar9 != 0) {
        FUN_00468640();
      }
      if (unaff_ESI != 0) {
        FUN_00587bcf(unaff_ESI);
      }
      return 1;
    }
  }
  return 0;
}


