// Function: FUN_00493c80 @ 00493c80
// Strings:  [OSC Read Error, OSC %s on line %d : , Critical Error, Error, Warning, Undefined Error]


undefined4 __thiscall FUN_00493c80(int param_1,int param_2,char *param_3)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  char *unaff_ESI;
  undefined4 *puVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char acStack_220 [236];
  undefined4 uStack_134;
  char *pcStack_130;
  char local_100;
  undefined4 uStack_ff;
  
  if (1 < param_2) {
    local_100 = DAT_005ea438;
    puVar8 = &uStack_ff;
    for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    *(undefined2 *)puVar8 = 0;
    *(undefined1 *)((int)puVar8 + 2) = 0;
    pcStack_130 = &local_100;
    uStack_134 = 0x493cef;
    FUN_0058815f();
    uVar2 = DAT_005c64d4;
    if (param_3 != (char *)0x0) {
      iVar3 = -1;
      pcVar9 = &local_100;
      do {
        pcVar11 = pcVar9;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar11 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar11;
      } while (cVar1 != '\0');
      uVar4 = 0xffffffff;
      *(undefined2 *)(pcVar11 + -1) = DAT_005c64d4;
      do {
        pcVar9 = param_3;
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        pcVar9 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar9;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      iVar3 = -1;
      pcVar11 = &local_100;
      do {
        pcVar10 = pcVar11;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar10 = pcVar11 + 1;
        cVar1 = *pcVar11;
        pcVar11 = pcVar10;
      } while (cVar1 != '\0');
      pcVar9 = pcVar9 + -uVar4;
      pcVar11 = pcVar10 + -1;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar11 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar11 = pcVar11 + 1;
      }
      iVar3 = -1;
      pcVar9 = &local_100;
      do {
        pcVar11 = pcVar9;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar11 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar11;
      } while (cVar1 != '\0');
      *(undefined2 *)(pcVar11 + -1) = uVar2;
      iVar3 = -1;
      pcVar9 = &local_100;
      do {
        pcVar11 = pcVar9;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar11 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar11;
      } while (cVar1 != '\0');
      *(undefined2 *)(pcVar11 + -1) = DAT_005c30b4;
    }
    if (*(int *)(param_1 + 8) == 0) {
      iVar3 = FUN_00587db0();
      *(int *)(param_1 + 8) = iVar3;
      if (iVar3 != 0) {
        FUN_00587f64();
      }
    }
    if (*(int *)(param_1 + 8) != 0) {
      FUN_005887b1();
      pcStack_130 = *(char **)(param_1 + 8);
      uStack_134 = 0x493dc6;
      FUN_005887b1();
    }
    if ((param_2 == 3) || (param_2 == 2)) {
      if (*(int *)(param_1 + 0x1a4) == 0) {
        pcStack_130 = (char *)0x493e0a;
        MessageBoxA((HWND)0x0,&local_100,s_OSC_Read_Error_005cc938,0);
        FUN_00589ca4();
        iVar7 = *(int *)(extraout_ECX + 0x194) * 4;
        pcVar9 = acStack_220;
        for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
          pcVar9[0] = '\0';
          pcVar9[1] = '\0';
          pcVar9[2] = '\0';
          pcVar9[3] = '\0';
          pcVar9 = pcVar9 + 4;
        }
        if (unaff_ESI == (char *)0x0) {
          return 0xffffffff;
        }
        iVar3 = -1;
        pcVar9 = unaff_ESI;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        if (iVar3 == -2) {
          return 0xffffffff;
        }
        iVar3 = iVar7;
        if (0 < iVar7) {
          do {
            pcVar9 = (char *)&DAT_005c406c;
            if (4 < iVar7) {
              pcVar9 = (char *)&DAT_005c32d8;
            }
            uVar4 = 0xffffffff;
            do {
              pcVar11 = pcVar9;
              if (uVar4 == 0) break;
              uVar4 = uVar4 - 1;
              pcVar11 = pcVar9 + 1;
              cVar1 = *pcVar9;
              pcVar9 = pcVar11;
            } while (cVar1 != '\0');
            uVar4 = ~uVar4;
            iVar6 = -1;
            pcVar9 = acStack_220;
            do {
              pcVar10 = pcVar9;
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              pcVar10 = pcVar9 + 1;
              cVar1 = *pcVar9;
              pcVar9 = pcVar10;
            } while (cVar1 != '\0');
            pcVar9 = pcVar11 + -uVar4;
            pcVar11 = pcVar10 + -1;
            for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
              pcVar9 = pcVar9 + 4;
              pcVar11 = pcVar11 + 4;
            }
            iVar3 = iVar3 + -1;
            for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
              *pcVar11 = *pcVar9;
              pcVar9 = pcVar9 + 1;
              pcVar11 = pcVar11 + 1;
            }
          } while (iVar3 != 0);
        }
        uVar4 = 0xffffffff;
        do {
          pcVar9 = unaff_ESI;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar9 = unaff_ESI + 1;
          cVar1 = *unaff_ESI;
          unaff_ESI = pcVar9;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        iVar3 = -1;
        pcVar11 = acStack_220;
        do {
          pcVar10 = pcVar11;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar10 = pcVar11 + 1;
          cVar1 = *pcVar11;
          pcVar11 = pcVar10;
        } while (cVar1 != '\0');
        pcVar9 = pcVar9 + -uVar4;
        pcVar11 = pcVar10 + -1;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
          pcVar9 = pcVar9 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar11 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          pcVar11 = pcVar11 + 1;
        }
        iVar3 = -1;
        pcVar9 = acStack_220;
        do {
          pcVar11 = pcVar9;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar11 = pcVar9 + 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar11;
        } while (cVar1 != '\0');
        *(undefined2 *)(pcVar11 + -1) = DAT_005c30b4;
        if ((*(char *)(extraout_ECX + 0x19a) != '\0') && (*(int *)(extraout_ECX + 4) != 0)) {
          FUN_005887b1(*(int *)(extraout_ECX + 4),&DAT_005c2c18,acStack_220);
        }
        return 0;
      }
      FUN_004986d0();
    }
  }
  return 0;
}


