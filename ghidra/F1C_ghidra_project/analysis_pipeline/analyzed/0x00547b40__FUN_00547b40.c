// Function: FUN_00547b40 @ 00547b40
// Size (bytes): 1604


/* WARNING: Removing unreachable block (ram,0x00547da3) */
/* WARNING: Removing unreachable block (ram,0x00547dd2) */
/* WARNING: Removing unreachable block (ram,0x00547ddb) */

undefined4 __thiscall FUN_00547b40(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  int local_f8;
  int local_f0;
  undefined2 local_e8;
  undefined2 local_e6;
  undefined4 local_e4;
  int local_e0;
  uint local_dc;
  int local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c4;
  int local_bc;
  undefined4 local_b8;
  int local_b4;
  undefined4 local_b0;
  uint local_ac;
  char local_a8 [8];
  char local_a0 [32];
  char local_80 [32];
  undefined1 local_60 [32];
  char local_40 [64];
  
  FUN_0054a5c0(4);
  local_e0 = 0;
  if (0 < local_d8) {
    do {
      local_60[0] = 0;
      local_a0[0] = '\0';
      local_80[0] = '\0';
      local_40[0] = '\0';
      iVar6 = 0;
      pvVar2 = operator_new(0xc4);
      if (pvVar2 == (void *)0x0) {
        pcVar3 = (char *)0x0;
      }
      else {
        pcVar3 = (char *)FUN_00546250();
      }
      FUN_00546330(local_60,param_1);
      FUN_0054a5c0(0x20);
      FUN_0054a5c0(4);
      if (0 < local_f8) {
        FUN_0054a5c0(0x20);
        iVar6 = 1;
        while (local_f8 = local_f8 + -1, local_f8 != 0) {
          FUN_0054a5c0(0x20);
        }
      }
      FUN_0054a5c0(4);
      if (0 < local_b4) {
        FUN_0054a5c0(0x20);
        FUN_0054a5c0(0x20);
        FUN_0054a5c0(4);
        FUN_0054a5c0(4);
        operator_new(local_f0 * 4);
        FUN_0054a5c0(local_f0 * 4);
        FUN_0054a5c0(4);
        FUN_0054a5c0(4);
        iVar6 = iVar6 + 1;
      }
      FUN_0054a5c0(4);
      if (0 < local_bc) {
        FUN_0054a5c0(0x20);
        iVar6 = iVar6 + 1;
      }
      FUN_00546330(local_60,param_1);
      *(int *)(pcVar3 + 0xa4) = iVar6;
      piVar4 = operator_new(iVar6 * 0x94 + 4);
      if (piVar4 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = piVar4 + 1;
        *piVar4 = iVar6;
        if (-1 < iVar6 + -1) {
          do {
            FUN_0054fb90();
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
      *(int **)(pcVar3 + 0xa8) = piVar5;
      if (local_40[0] == '\0') {
        FUN_0054fc10(local_a0);
        FUN_00552fc0(1);
        iVar6 = FUN_00546f30(0);
      }
      else {
        FUN_0054fc10(local_40);
        FUN_00552fc0(1);
        iVar6 = FUN_005470a0(0);
      }
      if (iVar6 != 0) {
        return 0xffffffff;
      }
      if (local_80[0] != '\0') {
        FUN_0054fc10(local_80);
        FUN_00552fc0(1);
        FUN_0054fc70(1);
        iVar6 = FUN_00546f70(1);
        if (iVar6 != 0) {
          return 0xffffffff;
        }
      }
      FUN_0054a5c0(4);
      uVar9 = 0;
      if ((local_ac & 8) != 0) {
        uVar9 = 0x20;
      }
      if ((local_ac & 0x10) != 0) {
        uVar9 = uVar9 | 0x40;
      }
      if ((local_ac & 0x20) != 0) {
        uVar9 = uVar9 | 0x80;
      }
      if ((local_ac & 0x800) != 0) {
        uVar9 = uVar9 | 0x100;
      }
      uVar7 = (uint)((local_ac & 0x1000) != 0);
      if ((local_ac & 0x4000) != 0) {
        uVar7 = uVar7 | 2;
      }
      if ((char)local_ac < '\0') {
        uVar7 = uVar7 | 4;
      }
      if ((local_ac & 0x100) != 0) {
        uVar7 = uVar7 | 8;
      }
      if ((local_ac & 0x400) != 0) {
        uVar7 = uVar7 | 0x80;
      }
      if ((local_ac & 0x2000) != 0) {
        uVar7 = uVar7 | 0x100;
      }
      if ((char)(local_ac >> 8) < '\0') {
        uVar7 = uVar7 | 0x200;
      }
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(0x10);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      FUN_0054a5c0(4);
      *(uint *)(pcVar3 + 0x9c) = uVar9;
      FUN_005471c0(local_b8);
      FUN_00547240(local_e8,local_e6);
      *(uint *)(*(int *)(pcVar3 + 0xa8) + 0x40) = uVar7;
      FUN_0054fc80(local_d0,local_b0);
      FUN_0054fd30(local_c4,local_cc);
      FUN_0054fcb0(local_dc & 0xffffff);
      FUN_0054fcc0(local_dc >> 0x18);
      FUN_0054fd50(uVar7 & 0xc,local_e4);
      *(uint *)(pcVar3 + 0x9c) = *(uint *)(pcVar3 + 0x9c) | 2;
      if (local_80[0] != '\0') {
        FUN_0054fd50(uVar7 & 0xc,local_e4);
      }
      *(uint *)(*(int *)(pcVar3 + 0xa8) + 0x40) =
           *(uint *)(*(int *)(pcVar3 + 0xa8) + 0x40) & 0xfffffeff;
      if ((*(uint *)(*(int *)(pcVar3 + 0xa8) + 0x40) & 0x100) != 0) {
        FUN_00548a30(param_2,local_a8);
        uVar9 = 0xffffffff;
        pcVar8 = local_a8;
        do {
          pcVar11 = pcVar8;
          if (uVar9 == 0) break;
          uVar9 = uVar9 - 1;
          pcVar11 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar11;
        } while (cVar1 != '\0');
        uVar9 = ~uVar9;
        iVar6 = -1;
        pcVar8 = pcVar3;
        do {
          pcVar10 = pcVar8;
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          pcVar10 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar10;
        } while (cVar1 != '\0');
        pcVar8 = pcVar11 + -uVar9;
        pcVar11 = pcVar10 + -1;
        for (uVar7 = uVar9 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pcVar11 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      if (((*(uint *)(*(int *)(pcVar3 + 0xa8) + 0x40) & 0x100) == 0) &&
         (iVar6 = FUN_005477f0(pcVar3), iVar6 != 0)) {
        FUN_00546370();
        FUN_00557470();
        FUN_00587bcf(pcVar3);
      }
      else {
        FUN_00547670(pcVar3);
        if (-1 < (char)(*(uint *)(pcVar3 + 0x9c) >> 8)) {
          *(uint *)(pcVar3 + 0x9c) = *(uint *)(pcVar3 + 0x9c) | 1;
        }
      }
      local_e0 = local_e0 + 1;
    } while (local_e0 < local_d8);
  }
  return 0;
}


