// Function: FUN_004c3a00 @ 004c3a00
// Strings:  [*.tga]


void __thiscall FUN_004c3a00(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char local_520 [31];
  char acStack_501 [127];
  char acStack_482 [128];
  char acStack_402 [512];
  char acStack_202 [514];
  
  FUN_00565dc0();
  iVar2 = 0;
  do {
    cVar1 = (&DAT_005d3074)[iVar2];
    local_520[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  pcVar6 = (char *)*param_1;
  if (pcVar6 == (char *)0x0) {
    pcVar6 = &DAT_005ea438;
  }
  pcVar9 = acStack_202 + 2;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar9 = cVar1;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  uVar7 = 0xffffffff;
  pcVar6 = acStack_202 + 2;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  if ((0 < (int)(~uVar7 - 1)) && (pcVar6 = acStack_202 + ~uVar7, acStack_202 + 2 <= pcVar6)) {
    do {
      if (*pcVar6 == '\\') break;
      *pcVar6 = '\0';
      pcVar6 = pcVar6 + -1;
    } while (acStack_202 + 2 <= pcVar6);
  }
  FUN_00565eb0();
  FUN_00565f80(local_520,1,acStack_202 + 2,0);
  FUN_00566380(0);
  FUN_00565f50();
  iVar2 = FUN_005662d0();
  do {
    if (iVar2 == 0) {
      FUN_00565e20();
      return;
    }
    pcVar6 = (char *)FUN_00565ef0();
    _strncpy(acStack_501 + 1,pcVar6,0x7f);
    uVar7 = 0xffffffff;
    pcVar6 = acStack_501;
    acStack_482[1] = 0;
    do {
      pcVar6 = pcVar6 + 1;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
    } while (*pcVar6 != '\0');
    pcVar6 = acStack_501 + ~uVar7;
    if (acStack_501 + 1 < pcVar6) {
      do {
        if (*pcVar6 == '.') {
          *pcVar6 = '\0';
          break;
        }
        pcVar6 = pcVar6 + -1;
      } while (acStack_501 + 1 < pcVar6);
    }
    pcVar6 = (char *)FUN_005662d0();
    _strncpy(acStack_402 + 2,pcVar6,0x1ff);
    uVar7 = 0xffffffff;
    acStack_202[1] = 0;
    pcVar6 = acStack_402 + 2;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if ((0 < (int)(~uVar7 - 1)) && (pcVar6 = acStack_402 + ~uVar7, acStack_402 + 2 <= pcVar6)) {
      do {
        if (*pcVar6 == '\\') break;
        *pcVar6 = '\0';
        pcVar6 = pcVar6 + -1;
      } while (acStack_402 + 2 <= pcVar6);
    }
    iVar2 = -1;
    pcVar6 = acStack_402 + 2;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      uVar7 = 0xffffffff;
      iVar2 = 0;
      pcVar6 = acStack_402 + 2;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      iVar8 = ~uVar7 - 2;
      if (-1 < iVar8) {
LAB_004c3bb2:
        if (acStack_402[iVar8 + 2] == '\\') {
          iVar2 = iVar2 + 1;
        }
        if ((iVar2 != 2) && (iVar8 != 0)) break;
        pcVar6 = acStack_402 + iVar8 + 3;
        iVar2 = 2 - (int)pcVar6;
        do {
          cVar1 = *pcVar6;
          pcVar6[(int)(acStack_482 + iVar2)] = cVar1;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        uVar7 = 0xffffffff;
        pcVar6 = acStack_482 + 2;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        if (acStack_482[~uVar7] == '\\') {
          uVar7 = 0xffffffff;
          pcVar6 = acStack_482 + 2;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          acStack_482[~uVar7] = '\0';
        }
        iVar2 = FUN_00588410(acStack_501 + 1,acStack_482 + 2);
        if (iVar2 == 0) {
          puVar3 = operator_new(8);
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            uVar4 = FUN_005662d0();
            *puVar3 = 0;
            puVar3[1] = 0xffffffff;
            FUN_00566650(uVar4);
          }
          iVar2 = FUN_00566810();
          if ((iVar2 == 0) || (iVar2 = FUN_00588410(iVar2,acStack_202 + 2), iVar2 != 0)) {
            if (puVar3 != (undefined4 *)0x0) {
              puVar5 = operator_new(0xc);
              if (puVar5 == (undefined4 *)0x0) {
                puVar5 = (undefined4 *)0x0;
              }
              else {
                *puVar5 = puVar3;
                puVar5[1] = 0;
                *(undefined1 *)(puVar5 + 2) = 1;
              }
              if (*param_2 == 0) {
                *param_2 = (int)puVar5;
                param_2[2] = (int)puVar5;
              }
              else {
                *(undefined4 **)(param_2[1] + 4) = puVar5;
              }
              param_2[1] = (int)puVar5;
              goto LAB_004c3d05;
            }
          }
          else if (puVar3 != (undefined4 *)0x0) {
            puVar5 = operator_new(0xc);
            if (puVar5 == (undefined4 *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              *puVar5 = puVar3;
              puVar5[1] = 0;
              *(undefined1 *)(puVar5 + 2) = 1;
            }
            if (*param_2 == 0) {
              param_2[1] = (int)puVar5;
              param_2[2] = (int)puVar5;
              *param_2 = (int)puVar5;
            }
            else {
              puVar5[1] = *param_2;
              *param_2 = (int)puVar5;
            }
LAB_004c3d05:
            param_2[3] = param_2[3] + 1;
          }
        }
      }
    }
LAB_004c3d08:
    FUN_00565f20();
    iVar2 = FUN_005662d0();
  } while( true );
  iVar8 = iVar8 + -1;
  if (iVar8 < 0) goto LAB_004c3d08;
  goto LAB_004c3bb2;
}


