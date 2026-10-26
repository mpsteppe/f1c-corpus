// Function: FUN_004b8da0 @ 004b8da0
// Size (bytes): 605


void __fastcall FUN_004b8da0(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  byte *pbVar7;
  int iVar8;
  int extraout_ECX;
  int *piVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  bool bVar12;
  undefined *local_8c;
  byte local_80;
  undefined4 local_7f;
  byte local_60;
  undefined4 local_5f;
  byte local_40;
  undefined4 local_3f;
  
  piVar9 = (int *)(param_1 + 0x40);
  local_8c = &DAT_005ec6d8;
  do {
    local_80 = DAT_005ea438;
    puVar10 = &local_7f;
    for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = 0;
    *(undefined1 *)((int)puVar10 + 2) = 0;
    local_60 = DAT_005ea438;
    puVar10 = &local_5f;
    for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = 0;
    *(undefined1 *)((int)puVar10 + 2) = 0;
    local_40 = DAT_005ea438;
    puVar10 = &local_3f;
    for (iVar8 = 0xf; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined2 *)puVar10 = 0;
    *(undefined1 *)((int)puVar10 + 2) = 0;
    piVar2 = (int *)*piVar9;
    piVar9[2] = (int)piVar2;
    if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
LAB_004b8e21:
      cVar4 = FUN_004b50c0(*(undefined4 *)(param_1 + 0xf38));
      if (cVar4 == '\0') break;
      pcVar5 = (char *)(extraout_ECX + 0x41);
      iVar8 = -(int)pcVar5;
      do {
        cVar4 = *pcVar5;
        pcVar5[(int)(&local_80 + iVar8)] = cVar4;
        pcVar5 = pcVar5 + 1;
      } while (cVar4 != '\0');
      pcVar5 = (char *)(extraout_ECX + 0x61);
      iVar8 = -(int)pcVar5;
      do {
        cVar4 = *pcVar5;
        pcVar5[(int)(&local_60 + iVar8)] = cVar4;
        pcVar5 = pcVar5 + 1;
      } while (cVar4 != '\0');
      pcVar5 = (char *)(extraout_ECX + 1);
      iVar8 = -(int)pcVar5;
      do {
        cVar4 = *pcVar5;
        pcVar5[(int)(&local_40 + iVar8)] = cVar4;
        pcVar5 = pcVar5 + 1;
      } while (cVar4 != '\0');
    }
LAB_004b8e8d:
    iVar8 = -1;
    pbVar7 = &local_80;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      bVar1 = *pbVar7;
      pbVar7 = pbVar7 + 1;
    } while (bVar1 != 0);
    iVar3 = *(int *)(local_8c + 0x6f4);
    if (iVar8 == -2) {
      if (iVar3 != 0) {
        FUN_004c6e80();
        FUN_004ef5a0(0xffffffff,0);
        DAT_005c329c = DAT_005c329c + -1;
        FUN_0042bc80();
      }
    }
    else {
      uVar6 = FUN_004c69e0(&local_80);
      iVar8 = FUN_00588410(uVar6);
      if ((iVar8 != 0) || (iVar3 == 0)) {
        FUN_004c7b20(&local_80);
        FUN_00566650(&local_60);
        uVar6 = FUN_004c69e0(&local_80);
        iVar8 = FUN_00588410(uVar6);
        if (iVar8 == 0) {
          if (iVar3 != 0) {
            FUN_004c6e80();
          }
          FUN_004ef5a0(0,0);
          DAT_005c329c = DAT_005c329c + 1;
          FUN_0042bc80();
          FUN_004c6c40(1);
          FUN_004c6d90(1);
          FUN_004ef5a0(3,0);
        }
      }
    }
    pbVar11 = &local_40;
    pbVar7 = local_8c + 0x4620;
    do {
      bVar1 = *pbVar7;
      bVar12 = bVar1 < *pbVar11;
      if (bVar1 != *pbVar11) {
LAB_004b8fb8:
        iVar8 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_004b8fbd;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar7[1];
      bVar12 = bVar1 < pbVar11[1];
      if (bVar1 != pbVar11[1]) goto LAB_004b8fb8;
      pbVar7 = pbVar7 + 2;
      pbVar11 = pbVar11 + 2;
    } while (bVar1 != 0);
    iVar8 = 0;
LAB_004b8fbd:
    if (iVar8 != 0) {
      FUN_004c6980(&local_40);
    }
    local_8c = local_8c + 0x48c0;
    piVar9 = piVar9 + 4;
    if (0x7c54d7 < (int)local_8c) {
      return;
    }
  } while( true );
  if (piVar9[2] != 0) {
    piVar9[2] = *(int *)(piVar9[2] + 4);
  }
  if (((int *)piVar9[2] == (int *)0x0) || (*(int *)piVar9[2] == 0)) goto LAB_004b8e8d;
  goto LAB_004b8e21;
}


