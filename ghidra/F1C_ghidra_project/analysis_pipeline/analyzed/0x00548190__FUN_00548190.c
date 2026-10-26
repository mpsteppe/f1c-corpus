// Function: FUN_00548190 @ 00548190
// Size (bytes): 1154


/* WARNING: Removing unreachable block (ram,0x00548509) */

undefined4 __thiscall FUN_00548190(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  char cVar2;
  void *pvVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  int local_28;
  undefined2 local_24;
  undefined2 local_22;
  uint local_20;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  char local_8 [8];
  
  FUN_0054a5c0(4);
  local_18 = 0;
  if (0 < local_14) {
    do {
      pvVar3 = operator_new(0xc4);
      if (pvVar3 == (void *)0x0) {
        pcVar4 = (char *)0x0;
      }
      else {
        pcVar4 = (char *)FUN_00546250();
      }
      *(undefined4 *)(pcVar4 + 0xb8) = param_1;
      FUN_0054a5c0(0x20);
      FUN_0054a5c0(4);
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      *(uint *)(pcVar4 + 0x9c) = *(uint *)(pcVar4 + 0x9c) | 2;
      FUN_00547240(local_24,local_22);
      FUN_005471c0(local_10);
      FUN_0054a5c0(4);
      iVar8 = *(int *)(pcVar4 + 0xa4);
      if (0 < iVar8) {
        piVar5 = operator_new(iVar8 * 0x94 + 4);
        if (piVar5 == (int *)0x0) {
          piVar9 = (int *)0x0;
        }
        else {
          piVar9 = piVar5 + 1;
          *piVar5 = iVar8;
          if (-1 < iVar8 + -1) {
            do {
              FUN_0054fb90();
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
        }
        *(int **)(pcVar4 + 0xa8) = piVar9;
        local_28 = 0;
        if (0 < *(int *)(pcVar4 + 0xa4)) {
          do {
            FUN_0054a5c0(0x20);
            puVar1 = (uint *)(piVar9 + 0x10);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            if (1 < piVar9[0x12]) {
              FUN_0054a5c0(4);
              pvVar3 = operator_new(piVar9[0x14] << 2);
              piVar9[0x13] = (int)pvVar3;
              FUN_0054a5c0(piVar9[0x14] << 2);
              FUN_0054a5c0(4);
              FUN_0054a5c0(4);
            }
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054a5c0(4);
            FUN_0054fc50((float)local_c);
            FUN_0054fcb0(local_20 & 0xffffff);
            FUN_0054fcc0(local_20 >> 0x18);
            FUN_0054fd50(*puVar1 & 0xc,piVar9[0x11]);
            iVar8 = piVar9[0x18];
            if (iVar8 < 0x800001) {
              if (iVar8 == 0x800000) {
                iVar8 = FUN_00546f70(local_28);
                goto LAB_005484ee;
              }
              if (iVar8 == 0x100000) {
                FUN_00546f30(local_28);
              }
              else if (iVar8 == 0x400000) {
                iVar8 = FUN_00546fe0(local_28);
                goto LAB_005484ee;
              }
            }
            else {
              if (iVar8 == 0x1000000) {
                iVar8 = FUN_00547040(local_28);
              }
              else {
                if (iVar8 != 0x8000000) goto LAB_005484f6;
                iVar8 = FUN_005470a0(local_28);
              }
LAB_005484ee:
              if (iVar8 != 0) {
                return 0xffffffff;
              }
            }
LAB_005484f6:
            *puVar1 = *puVar1 & 0xfffffeff;
            if ((*puVar1 & 0x200) != 0) {
              *(uint *)(pcVar4 + 0x9c) = *(uint *)(pcVar4 + 0x9c) | 0x4000;
            }
            piVar9 = piVar9 + 0x25;
            local_28 = local_28 + 1;
          } while (local_28 < *(int *)(pcVar4 + 0xa4));
        }
      }
      if ((*(uint *)(pcVar4 + 0x9c) & 0x200) != 0) {
        FUN_00548a30(param_2,local_8);
        _strncpy(pcVar4 + 0x40,local_8,4);
        uVar6 = 0xffffffff;
        pcVar10 = local_8;
        do {
          pcVar12 = pcVar10;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar12 = pcVar10 + 1;
          cVar2 = *pcVar10;
          pcVar10 = pcVar12;
        } while (cVar2 != '\0');
        uVar6 = ~uVar6;
        iVar8 = -1;
        pcVar10 = pcVar4;
        do {
          pcVar11 = pcVar10;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar11 = pcVar10 + 1;
          cVar2 = *pcVar10;
          pcVar10 = pcVar11;
        } while (cVar2 != '\0');
        pcVar10 = pcVar12 + -uVar6;
        pcVar12 = pcVar11 + -1;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
          pcVar10 = pcVar10 + 4;
          pcVar12 = pcVar12 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar12 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          pcVar12 = pcVar12 + 1;
        }
      }
      iVar8 = FUN_005477f0(pcVar4);
      if (iVar8 == 0) {
        FUN_00547670(pcVar4);
        uVar6 = *(uint *)(pcVar4 + 0x9c);
        if (-1 < (char)(uVar6 >> 8)) {
          *(uint *)(pcVar4 + 0x9c) = uVar6 | 1;
        }
      }
      else {
        FUN_00546370();
        FUN_00557470();
        FUN_00587bcf(pcVar4);
      }
      local_18 = local_18 + 1;
    } while (local_18 < local_14);
  }
  return 0;
}


