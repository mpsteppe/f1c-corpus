// Function: FUN_00552d70 @ 00552d70
// Size (bytes): 430


void __fastcall FUN_00552d70(int param_1)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_10;
  char *local_8;
  
  puVar3 = (uint *)FUN_00543210(*(undefined4 *)(*(int *)(param_1 + 100) + 0x18),0);
  iVar8 = *(int *)(param_1 + 100);
  iVar4 = *(int *)(iVar8 + 0x20);
  iVar10 = *(int *)(iVar8 + 0x28) >> 2;
  iVar6 = (iVar4 + -2) * iVar10 + *(int *)(iVar8 + 0x1c);
  *(uint *)(param_1 + 0x28) = puVar3[iVar6 + -1];
  *(uint *)(param_1 + 0x2c) = puVar3[iVar6 + -2];
  *(uint *)(param_1 + 0x30) = puVar3[iVar6 + -3];
  iVar6 = 1;
  do {
    iVar9 = iVar6;
    iVar6 = iVar9 + 1;
  } while (*(uint *)((int)puVar3 + iVar9 * 4 + *(int *)(iVar8 + 0x28)) != *(uint *)(param_1 + 0x28))
  ;
  *(int *)(param_1 + 0x34) = iVar9;
  puVar7 = puVar3 + iVar10 + 1;
  *(int *)(param_1 + 0x3c) = *(int *)(iVar8 + 0x1c) / iVar9;
  iVar8 = 1;
  do {
    iVar6 = iVar8;
    uVar2 = *puVar7;
    puVar7 = puVar7 + iVar10;
    iVar8 = iVar6 + 1;
  } while (uVar2 != *(uint *)(param_1 + 0x28));
  iVar4 = iVar4 / iVar6;
  *(int *)(param_1 + 0x38) = iVar6;
  local_10 = 0;
  iVar8 = *(int *)(param_1 + 0x3c) * iVar4;
  *(int *)(param_1 + 0x40) = iVar4;
  *(int *)(param_1 + 0x44) = iVar8 + 0x20;
  if (0 < iVar8) {
    local_8 = (char *)(param_1 + 0x6d);
    do {
      iVar10 = *(int *)(param_1 + 0x34) * (local_10 % *(int *)(param_1 + 0x3c)) + 1;
      iVar9 = *(int *)(param_1 + 0x38) * (local_10 / *(int *)(param_1 + 0x3c)) + 1;
      piVar1 = (int *)((int)puVar3 + iVar10 * 4 + *(int *)(*(int *)(param_1 + 100) + 0x28) * iVar9);
      iVar4 = *piVar1;
      iVar6 = 0;
      while ((iVar4 != *(int *)(param_1 + 0x30) &&
             (iVar5 = iVar6 + 1, iVar5 < *(int *)(param_1 + 0x34)))) {
        iVar4 = piVar1[iVar5];
        iVar6 = iVar5;
      }
      local_8[-1] = (char)iVar6;
      *local_8 = *(char *)(param_1 + 0x38) + -1;
      *(short *)(local_8 + -5) = (short)iVar10;
      local_10 = local_10 + 1;
      *(short *)(local_8 + -3) = (short)iVar9;
      local_8 = local_8 + 8;
    } while (local_10 < iVar8);
  }
  iVar8 = *(int *)(*(int *)(param_1 + 100) + 0x20) * *(int *)(*(int *)(param_1 + 100) + 0x1c);
  if (0 < iVar8) {
    do {
      uVar2 = *puVar3;
      if (((uVar2 == *(uint *)(param_1 + 0x30)) || (uVar2 == *(uint *)(param_1 + 0x28))) ||
         (uVar2 == *(uint *)(param_1 + 0x2c))) {
        *puVar3 = 0xf0f0f0;
        puVar7 = (uint *)(*(int *)(param_1 + 100) + 0x18);
        *puVar7 = *puVar7 | 0x800;
      }
      else {
        *puVar3 = uVar2 | 0xff000000;
      }
      puVar3 = puVar3 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  *(undefined4 *)(param_1 + 0x2c) = 0xf0f0f0;
  FUN_00543230(*(undefined4 *)(*(int *)(param_1 + 100) + 0x18),0);
  return;
}


