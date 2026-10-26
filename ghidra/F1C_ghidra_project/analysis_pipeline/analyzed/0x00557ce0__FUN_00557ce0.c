// Function: FUN_00557ce0 @ 00557ce0
// Size (bytes): 1581


undefined4 __thiscall FUN_00557ce0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  void *pvVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  
  iVar2 = FUN_00545f40();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_005474d0(param_2,*(undefined4 *)(param_2 + 0x58),*(undefined4 *)(param_2 + 0x5c),
                       param_2 + 0x70,param_2 + 0x90,*(undefined4 *)(param_2 + 0x68));
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_005487a0();
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  iVar2 = *(int *)(param_2 + 0x24);
  if (0 < iVar2) {
    *(int *)(param_1 + 0x2c) = iVar2;
    piVar3 = operator_new(iVar2 * 0x80 + 4);
    if (piVar3 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = piVar3 + 1;
      *piVar3 = iVar2;
      if (-1 < iVar2 + -1) {
        do {
          FUN_005573a0();
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    *(int **)(param_1 + 0x34) = piVar4;
    pcVar5 = param_2;
    do {
      cVar1 = *pcVar5;
      pcVar5[param_1 - (int)param_2] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(param_1);
    pvVar6 = operator_new(*(int *)(param_1 + 0x2c) << 2);
    *(void **)(param_1 + 0x40) = pvVar6;
    pvVar6 = operator_new(*(int *)(param_1 + 0x2c) << 2);
    *(void **)(param_1 + 0x3c) = pvVar6;
    if ((param_2[0x58] & 0x20U) == 0) {
      param_2[100] = '\x02';
      param_2[0x65] = '\0';
      param_2[0x66] = '\x01';
      param_2[0x67] = '\0';
    }
    *(undefined4 *)(param_1 + 0x4c) = 1;
    puVar7 = operator_new(0x44);
    if (puVar7 == (undefined4 *)0x0) {
      puVar12 = (undefined4 *)0x0;
    }
    else {
      puVar12 = puVar7 + 1;
      *puVar7 = 1;
      FUN_0053c2a0();
    }
    *(undefined4 **)(param_1 + 0x50) = puVar12;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    uVar8 = FUN_00548890(param_1);
    *(undefined4 *)(*(int *)(param_1 + 0x50) + 4) = uVar8;
    if (*(int *)(*(int *)(param_1 + 0x50) + 4) != 0) {
      FUN_005473c0();
      FUN_00547240(*(uint *)(param_2 + 100) & 0xffff,*(undefined2 *)(param_2 + 0x66));
      if (0 < *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 4) + 0xa4)) {
        FUN_0054fcb0(*(undefined4 *)(param_2 + 0x68));
        FUN_0054fcc0(*(undefined4 *)(param_2 + 0x6c));
      }
    }
    **(undefined4 **)(param_1 + 0x50) = 0;
    if ((param_2[0x58] & 8U) != 0) {
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 1;
    }
    if ((param_2[0x58] & 0x10U) != 0) {
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 2;
    }
    if ((param_2[0x20] & 0x10U) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x210;
    }
    if ((param_2[0x20] & 0x20U) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x220;
    }
    if ((*(uint *)(param_2 + 0x20) & 0x200) != 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x200;
    }
    uVar10 = *(uint *)(param_2 + 0x20);
    if ((uVar10 & 1) == 0) {
      if ((uVar10 & 4) != 0) {
        return 0xffffffff;
      }
      if ((uVar10 & 2) != 0) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 2;
        *(undefined4 *)(param_1 + 0x24) = 8;
        if ((**(byte **)(param_1 + 0x50) & 0x10) == 0) {
          *(undefined4 *)(param_1 + 0x28) = 0x24;
        }
        else {
          *(undefined4 *)(param_1 + 0x28) = 0x30;
        }
        *(int *)(*(byte **)(param_1 + 0x50) + 8) = *(int *)(param_1 + 0x2c) << 3;
        *(int *)(*(int *)(param_1 + 0x50) + 0x10) =
             *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x28);
        if ((param_2[0x20] & 0x80U) == 0) {
          iVar2 = *(int *)(param_1 + 0x24);
        }
        else {
          iVar2 = *(int *)(*(int *)(param_1 + 0x50) + 8);
        }
        pvVar6 = operator_new(iVar2 * 0x24);
        *(void **)(*(int *)(param_1 + 0x50) + 0xc) = pvVar6;
        pvVar6 = operator_new(*(int *)(*(int *)(param_1 + 0x50) + 0x10) << 1);
        *(void **)(*(int *)(param_1 + 0x50) + 0x14) = pvVar6;
        uVar10 = *(uint *)(param_2 + 0x60);
        if ((uVar10 & 0xff000000) == 0) {
          uVar10 = uVar10 | 0xff000000;
        }
        if ((param_2[0x20] & 0x80U) == 0) {
          puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x50) + 0xc);
          puVar7[6] = uVar10;
          puVar7[1] = 0x3d4ccccd;
          *puVar7 = 0xbd4ccccd;
          puVar7[2] = 0xbd4ccccd;
          puVar7[9] = 0xbd4ccccd;
          puVar7[10] = 0xbd4ccccd;
          puVar7[0xb] = 0xbd4ccccd;
          puVar7[0xf] = uVar10;
          puVar7[0x12] = 0x3d4ccccd;
          puVar7[0x13] = 0xbd4ccccd;
          puVar7[0x14] = 0xbd4ccccd;
          puVar7[0x18] = uVar10;
          puVar7[0x1b] = 0x3d4ccccd;
          puVar7[0x1c] = 0x3d4ccccd;
          puVar7[0x1d] = 0xbd4ccccd;
          puVar7[0x21] = uVar10;
          puVar7[0x24] = 0xbd4ccccd;
          puVar7[0x25] = 0x3d4ccccd;
          puVar7[0x26] = 0x3d4ccccd;
          puVar7[0x2a] = uVar10;
          puVar7[0x2d] = 0xbd4ccccd;
          puVar7[0x2e] = 0xbd4ccccd;
          puVar7[0x2f] = 0x3d4ccccd;
          puVar7[0x33] = uVar10;
          puVar7[0x36] = 0x3d4ccccd;
          puVar7[0x37] = 0xbd4ccccd;
          puVar7[0x38] = 0x3d4ccccd;
          puVar7[0x3c] = uVar10;
          puVar7[0x3f] = 0x3d4ccccd;
          puVar7[0x40] = 0x3d4ccccd;
          puVar7[0x41] = 0x3d4ccccd;
          puVar7[0x45] = uVar10;
          iVar2 = 0;
          if (0 < *(int *)(param_1 + 0x2c)) {
            iVar11 = 0;
            do {
              *(int *)(*(int *)(param_1 + 0x34) + 4 + iVar11) = iVar2;
              *(uint *)(*(int *)(param_1 + 0x34) + 0xc + iVar11) = uVar10;
              iVar2 = iVar2 + 1;
              iVar11 = iVar11 + 0x80;
            } while (iVar2 < *(int *)(param_1 + 0x2c));
          }
        }
        else {
          iVar2 = 0;
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x80;
          if (0 < *(int *)(param_1 + 0x2c)) {
            param_2 = (char *)0x0;
            do {
              iVar9 = *(int *)(param_1 + 0x24) * iVar2;
              iVar11 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
              *(undefined4 *)(iVar11 + iVar9 * 0x24) = 0xbf000000;
              *(undefined4 *)(iVar11 + 4 + iVar9 * 0x24) = 0x3f000000;
              *(undefined4 *)(iVar11 + 8 + iVar9 * 0x24) = 0xbf000000;
              *(uint *)(iVar11 + 0x18 + iVar9 * 0x24) = uVar10;
              iVar11 = iVar11 + iVar9 * 0x24;
              *(undefined4 *)(iVar11 + 0x24) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x28) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x2c) = 0xbf000000;
              *(uint *)(iVar11 + 0x3c) = uVar10;
              *(undefined4 *)(iVar11 + 0x48) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x4c) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x50) = 0xbf000000;
              *(uint *)(iVar11 + 0x60) = uVar10;
              *(undefined4 *)(iVar11 + 0x6c) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x70) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x74) = 0xbf000000;
              *(uint *)(iVar11 + 0x84) = uVar10;
              *(undefined4 *)(iVar11 + 0x90) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0x94) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x98) = 0x3f000000;
              *(uint *)(iVar11 + 0xa8) = uVar10;
              *(undefined4 *)(iVar11 + 0xb4) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0xb8) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0xbc) = 0x3f000000;
              *(uint *)(iVar11 + 0xcc) = uVar10;
              *(undefined4 *)(iVar11 + 0xd8) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0xdc) = 0xbf000000;
              *(undefined4 *)(iVar11 + 0xe0) = 0x3f000000;
              *(uint *)(iVar11 + 0xf0) = uVar10;
              *(undefined4 *)(iVar11 + 0xfc) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x100) = 0x3f000000;
              *(undefined4 *)(iVar11 + 0x104) = 0x3f000000;
              *(uint *)(iVar11 + 0x114) = uVar10;
              *(int *)((int)param_2 + 4 + *(int *)(param_1 + 0x34)) = iVar2;
              *(uint *)((int)param_2 + 0xc + *(int *)(param_1 + 0x34)) = uVar10;
              param_2 = (char *)((int)param_2 + 0x80);
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(int *)(param_1 + 0x2c));
          }
        }
      }
    }
    else {
      uVar10 = *(uint *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar10 | 1;
      *(undefined4 *)(param_1 + 0x24) = 4;
      if ((uVar10 & 0x200) == 0) {
        *(undefined4 *)(param_1 + 0x28) = 0xc;
      }
      else {
        *(undefined4 *)(param_1 + 0x28) = 6;
      }
      *(int *)(*(int *)(param_1 + 0x50) + 8) = *(int *)(param_1 + 0x2c) << 2;
      *(int *)(*(int *)(param_1 + 0x50) + 0x10) =
           *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x28);
      if ((param_2[0x20] & 0x80U) == 0) {
        pvVar6 = operator_new(0x90);
        *(void **)(*(int *)(param_1 + 0x50) + 0xc) = pvVar6;
      }
      else {
        pvVar6 = operator_new(*(int *)(*(int *)(param_1 + 0x50) + 8) * 0x24);
        *(void **)(*(int *)(param_1 + 0x50) + 0xc) = pvVar6;
      }
      pvVar6 = operator_new(*(int *)(*(int *)(param_1 + 0x50) + 0x10) << 1);
      *(void **)(*(int *)(param_1 + 0x50) + 0x14) = pvVar6;
      uVar10 = *(uint *)(param_2 + 0x60);
      if ((uVar10 & 0xff000000) == 0) {
        uVar10 = uVar10 | 0xff000000;
      }
      if ((param_2[0x20] & 0x80U) == 0) {
        puVar7 = *(undefined4 **)(*(int *)(param_1 + 0x50) + 0xc);
        puVar7[6] = uVar10;
        puVar7[1] = 0x3f000000;
        puVar7[2] = 0;
        *puVar7 = 0xbf000000;
        puVar7[9] = 0xbf000000;
        puVar7[10] = 0xbf000000;
        puVar7[0xb] = 0;
        puVar7[0xf] = uVar10;
        puVar7[0x12] = 0x3f000000;
        puVar7[0x13] = 0xbf000000;
        puVar7[0x14] = 0;
        puVar7[0x18] = uVar10;
        puVar7[0x1b] = 0x3f000000;
        puVar7[0x1c] = 0x3f000000;
        puVar7[0x1d] = 0;
        puVar7[0x21] = uVar10;
        iVar2 = 0;
        if (0 < *(int *)(param_1 + 0x2c)) {
          iVar11 = 0;
          do {
            *(int *)(*(int *)(param_1 + 0x34) + 4 + iVar11) = iVar2;
            *(uint *)(*(int *)(param_1 + 0x34) + 0xc + iVar11) = uVar10;
            iVar2 = iVar2 + 1;
            iVar11 = iVar11 + 0x80;
          } while (iVar2 < *(int *)(param_1 + 0x2c));
        }
      }
      else {
        iVar2 = 0;
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x80;
        if (0 < *(int *)(param_1 + 0x2c)) {
          param_2 = (char *)0x0;
          do {
            iVar9 = *(int *)(param_1 + 0x24) * iVar2;
            iVar11 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
            *(undefined4 *)(iVar11 + iVar9 * 0x24) = 0xbf000000;
            *(undefined4 *)(iVar11 + 4 + iVar9 * 0x24) = 0x3f000000;
            *(uint *)(iVar11 + 0x18 + iVar9 * 0x24) = uVar10;
            iVar11 = iVar11 + iVar9 * 0x24;
            *(undefined4 *)(iVar11 + 8) = 0;
            *(undefined4 *)(iVar11 + 0x24) = 0xbf000000;
            *(undefined4 *)(iVar11 + 0x28) = 0xbf000000;
            *(undefined4 *)(iVar11 + 0x2c) = 0;
            *(uint *)(iVar11 + 0x3c) = uVar10;
            *(undefined4 *)(iVar11 + 0x48) = 0x3f000000;
            *(undefined4 *)(iVar11 + 0x4c) = 0xbf000000;
            *(undefined4 *)(iVar11 + 0x50) = 0;
            *(uint *)(iVar11 + 0x60) = uVar10;
            *(undefined4 *)(iVar11 + 0x6c) = 0x3f000000;
            *(undefined4 *)(iVar11 + 0x70) = 0x3f000000;
            *(undefined4 *)(iVar11 + 0x74) = 0;
            *(uint *)(iVar11 + 0x84) = uVar10;
            *(int *)(*(int *)(param_1 + 0x34) + 4 + (int)param_2) = iVar2;
            *(uint *)(*(int *)(param_1 + 0x34) + 0xc + (int)param_2) = uVar10;
            param_2 = (char *)((int)param_2 + 0x80);
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_1 + 0x2c));
        }
      }
    }
    pvVar6 = operator_new(*(int *)(param_1 + 0x4c) << 2);
    *(void **)(param_1 + 0x44) = pvVar6;
    pvVar6 = operator_new(*(int *)(param_1 + 0x4c) << 2);
    *(void **)(param_1 + 0x48) = pvVar6;
    return 0;
  }
  return 0xffffffff;
}


