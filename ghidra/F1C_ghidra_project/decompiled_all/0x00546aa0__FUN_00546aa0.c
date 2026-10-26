// Function: FUN_00546aa0 @ 00546aa0
// Strings:  [%s%.2d%s]


undefined4 __thiscall FUN_00546aa0(int param_1,byte param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  int *piVar14;
  char *local_154;
  int local_150;
  char local_148 [8];
  char local_140 [64];
  char local_100;
  undefined1 local_ff;
  undefined1 local_fe;
  undefined1 local_fd;
  undefined1 local_fc;
  undefined1 local_fb;
  undefined1 local_fa;
  undefined1 local_f9;
  undefined4 local_f8 [62];
  
  local_100 = '\0';
  local_ff = 0;
  local_fe = 0;
  local_fd = 0;
  local_fc = 0;
  local_fb = 0;
  local_fa = 0;
  local_f9 = 0;
  puVar13 = local_f8;
  for (iVar6 = 0x3e; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar13 = 0;
    puVar13 = puVar13 + 1;
  }
  iVar6 = 0;
  iVar11 = 0;
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      if ((param_2 & 4) == 0) {
        if ((param_2 & 8) == 0) {
          if ((param_2 & 0x10) == 0) {
            if ((param_2 & 0x20) == 0) {
              if ((param_2 & 0x40) == 0) {
                if ((char)param_2 < '\0') {
                  iVar11 = 7;
                }
              }
              else {
                iVar11 = 6;
              }
            }
            else {
              iVar11 = 5;
            }
          }
          else {
            iVar11 = 4;
          }
        }
        else {
          iVar11 = 3;
        }
      }
      else {
        iVar11 = 2;
      }
    }
    else {
      iVar11 = 1;
    }
  }
  iVar12 = iVar11 * 0x94 + *(int *)(param_1 + 0xa8);
  if (*(int *)(iVar11 * 0x94 + 0x8c + *(int *)(param_1 + 0xa8)) != 0) {
    if (0 < *(int *)(iVar12 + 0x48)) {
      iVar11 = 0;
      pcVar10 = &local_100;
      do {
        pcVar7 = (char *)(iVar11 + 4 + *(int *)(iVar12 + 0x8c));
        pcVar9 = pcVar10;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          *pcVar9 = cVar1;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        iVar6 = iVar6 + 1;
        iVar11 = iVar11 + 0x60;
        pcVar10 = pcVar10 + 0x20;
      } while (iVar6 < *(int *)(iVar12 + 0x48));
    }
    piVar4 = *(int **)(iVar12 + 0x8c);
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      iVar6 = 0;
      if (0 < *(int *)(*(int *)(iVar12 + 0x8c) + 0x4c)) {
        do {
          FUN_005502c0();
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(*(int *)(iVar12 + 0x8c) + 0x4c));
      }
      FUN_005478b0(*(undefined4 *)(iVar12 + 0x8c));
    }
    *(undefined4 *)(iVar12 + 0x8c) = 0;
  }
  if (param_3 != (char *)0x0) {
    pcVar10 = param_3;
    do {
      cVar1 = *pcVar10;
      pcVar10[(int)(local_140 + -(int)param_3)] = cVar1;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    iVar6 = 0;
    uVar8 = 0xffffffff;
    pcVar10 = local_140;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    iVar11 = ~uVar8 - 1;
    do {
      cVar1 = *(char *)((int)&DAT_005cc79c + iVar6);
      local_148[iVar6] = cVar1;
      iVar6 = iVar6 + 1;
    } while (cVar1 != '\0');
    if (0 < iVar11) {
LAB_00546c35:
      if (local_140[iVar11] != '.') goto code_r0x00546c3b;
      pcVar10 = local_140 + iVar11;
      pcVar7 = pcVar10;
      do {
        cVar1 = *pcVar7;
        pcVar7[(int)(local_148 + -(int)pcVar10)] = cVar1;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      *pcVar10 = '\0';
    }
LAB_00546c5c:
    iVar6 = *(int *)(iVar12 + 0x48);
    iVar11 = 0;
    if (0 < iVar6) {
      pcVar10 = &local_100;
      do {
        if (iVar6 < 2) {
          FUN_0058815f(pcVar10,&DAT_005be860,local_140,local_148);
        }
        else {
          FUN_0058815f(pcVar10,s__s__2d_s_005dbe54,local_140,iVar11,local_148);
        }
        iVar6 = *(int *)(iVar12 + 0x48);
        iVar11 = iVar11 + 1;
        pcVar10 = pcVar10 + 0x20;
      } while (iVar11 < iVar6);
    }
  }
  FUN_0054fc10(param_3);
  if (local_140[0] != '\0') {
    iVar6 = FUN_00547920(param_3);
    if ((iVar6 == 0) || ((*(uint *)(iVar12 + 0x40) & 0x100) != 0)) {
      iVar6 = *(int *)(iVar12 + 0x48);
      piVar4 = operator_new(iVar6 * 0x60 + 4);
      if (piVar4 == (int *)0x0) {
        piVar14 = (int *)0x0;
      }
      else {
        piVar14 = piVar4 + 1;
        *piVar4 = iVar6;
        if (-1 < iVar6 + -1) {
          do {
            FUN_0054fe10();
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
      *(int **)(iVar12 + 0x8c) = piVar14;
      FUN_00550300(*(undefined4 *)(iVar12 + 0x48));
      if (1 < *(int *)(iVar12 + 0x48)) {
        *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x400;
      }
      local_150 = 0;
      if (0 < *(int *)(iVar12 + 0x48)) {
        uVar8 = 0;
        local_154 = &local_100;
        do {
          pcVar10 = local_154;
          do {
            cVar1 = *pcVar10;
            pcVar10[(int)(piVar14 + 1) - (int)local_154] = cVar1;
            pcVar10 = pcVar10 + 1;
          } while (cVar1 != '\0');
          uVar2 = *(uint *)(iVar12 + 0x40);
          uVar3 = uVar8 | 4;
          if ((char)uVar2 < '\0') {
            uVar3 = uVar8 | 0x804;
          }
          uVar8 = uVar3;
          if ((DAT_008b8e24 == 0) || ((uVar2 & 0xc) == 0)) {
            *(uint *)(iVar12 + 0x40) = uVar2 & 0xfffffff3;
            piVar14[0x14] = 1;
          }
          else {
            piVar14[0x14] = *(int *)(iVar12 + 0x44) + 1;
            if ((*(uint *)(iVar12 + 0x40) & 8) == 0) {
              if ((*(uint *)(iVar12 + 0x40) & 4) != 0) {
                uVar8 = uVar8 | 0x4000;
              }
            }
            else {
              uVar8 = uVar8 | 0x2000;
            }
          }
          if ((*(byte *)(iVar12 + 0x40) & 1) != 0) {
            piVar14[0x11] = piVar14[0x11] | 1;
          }
          if ((*(uint *)(iVar12 + 0x60) & 0x400000) != 0) {
            uVar8 = uVar8 | 0x800000;
          }
          iVar6 = FUN_00550080(piVar14 + 1,*(undefined4 *)(iVar12 + 0x80),uVar8);
          if (iVar6 != 0) {
            for (; 0 < local_150; local_150 = local_150 + 1) {
              FUN_005502c0();
            }
            iVar6 = *(int *)(iVar12 + 0x8c);
            if (iVar6 != 0) {
              iVar11 = *(int *)(iVar6 + -4);
              if (-1 < iVar11 + -1) {
                do {
                  FUN_00557470();
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
              }
              FUN_00587bcf(iVar6 + -4);
            }
            *(undefined4 *)(iVar12 + 0x8c) = 0;
            return 0xffffffff;
          }
          if ((1 < *(int *)(*(int *)(iVar12 + 0x8c) + 0x50)) &&
             ((*(uint *)(iVar12 + 0x40) & 0xc) == 0)) {
            *(uint *)(iVar12 + 0x40) = *(uint *)(iVar12 + 0x40) | 8;
          }
          piVar14 = piVar14 + 0x18;
          local_150 = local_150 + 1;
          local_154 = local_154 + 0x20;
        } while (local_150 < *(int *)(iVar12 + 0x48));
      }
      FUN_00547860(*(undefined4 *)(iVar12 + 0x8c));
    }
    else {
      *(int *)(iVar12 + 0x8c) = iVar6;
    }
    **(int **)(iVar12 + 0x8c) = **(int **)(iVar12 + 0x8c) + 1;
  }
  if ((*(byte *)(param_1 + 0x9c) & 0x40) != 0) {
    iVar6 = FUN_00548a00(*(undefined4 *)(param_1 + 0xb0));
    *(int *)(param_1 + 0xb4) = iVar6;
    if (iVar6 == 0) {
      FUN_005489a0(*(undefined4 *)(param_1 + 0xb0));
      uVar5 = FUN_00548a00(*(undefined4 *)(param_1 + 0xb0));
      *(undefined4 *)(param_1 + 0xb4) = uVar5;
    }
  }
  *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) & 0xfffffffd;
  return 0;
code_r0x00546c3b:
  iVar11 = iVar11 + -1;
  if (iVar11 < 1) goto LAB_00546c5c;
  goto LAB_00546c35;
}


