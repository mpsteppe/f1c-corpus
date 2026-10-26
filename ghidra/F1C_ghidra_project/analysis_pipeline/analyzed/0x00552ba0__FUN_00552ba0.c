// Function: FUN_00552ba0 @ 00552ba0
// Size (bytes): 457


void __fastcall FUN_00552ba0(int param_1)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int local_14;
  char *local_10;
  
  uVar3 = (*(int *)(*(int *)(param_1 + 100) + 0x30) != 5) - 1 & 0x8000;
  puVar4 = (ushort *)FUN_00543210(*(undefined4 *)(*(int *)(param_1 + 100) + 0x18),0);
  iVar9 = *(int *)(param_1 + 100);
  iVar5 = *(int *)(iVar9 + 0x20);
  iVar12 = *(int *)(iVar9 + 0x28) >> 1;
  iVar7 = (iVar5 + -2) * iVar12 + *(int *)(iVar9 + 0x1c);
  *(uint *)(param_1 + 0x28) = (uint)puVar4[iVar7 + -1];
  *(uint *)(param_1 + 0x2c) = (uint)puVar4[iVar7 + -2];
  *(uint *)(param_1 + 0x30) = (uint)puVar4[iVar7 + -3];
  iVar7 = 1;
  do {
    iVar11 = iVar7;
    iVar7 = iVar11 + 1;
  } while ((uint)*(ushort *)((int)puVar4 + iVar11 * 2 + *(int *)(iVar9 + 0x28)) !=
           *(uint *)(param_1 + 0x28));
  *(int *)(param_1 + 0x34) = iVar11;
  puVar8 = puVar4 + iVar12 + 1;
  *(int *)(param_1 + 0x3c) = *(int *)(iVar9 + 0x1c) / iVar11;
  iVar9 = 1;
  do {
    iVar7 = iVar9;
    uVar2 = *puVar8;
    puVar8 = puVar8 + iVar12;
    iVar9 = iVar7 + 1;
  } while ((uint)uVar2 != *(uint *)(param_1 + 0x28));
  iVar5 = iVar5 / iVar7;
  *(int *)(param_1 + 0x38) = iVar7;
  iVar9 = *(int *)(param_1 + 0x3c) * iVar5;
  *(int *)(param_1 + 0x40) = iVar5;
  *(int *)(param_1 + 0x44) = iVar9 + 0x20;
  local_14 = 0;
  if (0 < iVar9) {
    local_10 = (char *)(param_1 + 0x6d);
    do {
      iVar12 = *(int *)(param_1 + 0x34) * (local_14 % *(int *)(param_1 + 0x3c)) + 1;
      iVar11 = *(int *)(param_1 + 0x38) * (local_14 / *(int *)(param_1 + 0x3c)) + 1;
      iVar7 = *(int *)(*(int *)(param_1 + 100) + 0x28) * iVar11;
      uVar2 = *(ushort *)((int)puVar4 + iVar12 * 2 + iVar7);
      iVar5 = 0;
      while (((uint)uVar2 != *(uint *)(param_1 + 0x30) &&
             (iVar6 = iVar5 + 1, iVar6 < *(int *)(param_1 + 0x34)))) {
        uVar2 = *(ushort *)((int)puVar4 + iVar6 * 2 + iVar12 * 2 + iVar7);
        iVar5 = iVar6;
      }
      local_10[-1] = (char)iVar5;
      *local_10 = *(char *)(param_1 + 0x38) + -1;
      *(short *)(local_10 + -5) = (short)iVar12;
      local_14 = local_14 + 1;
      *(short *)(local_10 + -3) = (short)iVar11;
      local_10 = local_10 + 8;
    } while (local_14 < iVar9);
  }
  iVar9 = *(int *)(*(int *)(param_1 + 100) + 0x20) * *(int *)(*(int *)(param_1 + 100) + 0x1c);
  if (0 < iVar9) {
    do {
      uVar10 = (uint)*puVar4;
      uVar2 = (ushort)uVar3;
      if (((uVar10 == *(uint *)(param_1 + 0x30)) || (uVar10 == *(uint *)(param_1 + 0x28))) ||
         (uVar10 == *(uint *)(param_1 + 0x2c))) {
        *puVar4 = ~uVar2 & *(ushort *)(param_1 + 0x2c);
        puVar1 = (uint *)(*(int *)(param_1 + 100) + 0x18);
        *puVar1 = *puVar1 | 0x800;
      }
      else {
        *puVar4 = *puVar4 | uVar2;
      }
      puVar4 = puVar4 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & ~uVar3;
  FUN_00543230(*(undefined4 *)(*(int *)(param_1 + 100) + 0x18),0);
  return;
}


