// Function: FUN_004186f0 @ 004186f0
// Size (bytes): 525


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004186f0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_3c [60];
  
  if (((DAT_007d0308 == 0) || (DAT_007cf3c8 <= DAT_0059e440)) ||
     (*(char *)(param_1 + 0xaf0) == '\0')) {
    return 0;
  }
  if (*(int **)(param_1 + 0xaf4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xaf4) + 0x18))();
  }
  if (((*(int **)(param_1 + 0xaf4) != (int *)0x0) &&
      (iVar3 = (**(code **)(**(int **)(param_1 + 0xaf4) + 8))(), iVar3 == 0)) &&
     (*(char *)(param_1 + 0xae4) != '\0')) {
    *(undefined1 *)(param_1 + 0xae4) = 0;
    *(float *)(param_1 + 0xae8) = (float)_DAT_008afea8;
    *(undefined4 *)(param_1 + 0xaec) = 0xffffffff;
  }
  FUN_00418ac0();
  piVar1 = *(int **)(param_1 + 0xaf4);
  if (*(int *)(param_1 + 0x864) == -1) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    iVar3 = (**(code **)(*piVar1 + 8))();
    if (iVar3 != 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0xaec) = 0xffffffff;
    return 0;
  }
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar1 + 8))();
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x135c);
  if ((double)_DAT_007cf278 < _DAT_008afea8 - (double)*(float *)(param_1 + 0xae8)) {
    if (iVar3 < 1) goto LAB_004187e4;
  }
  else if (iVar3 < 1) {
    return 0;
  }
  *(int *)(param_1 + 0x135c) = iVar3 + -1;
LAB_004187e4:
  if (_DAT_008afea8 < (double)*(float *)(param_1 + 0x86c)) {
    *(undefined4 *)(param_1 + 0xaec) = 0xffffffff;
    return 0;
  }
  if ((double)*(float *)(&DAT_005bf9ac + *(int *)(param_1 + 0x864) * 0x14) <=
      _DAT_008afea8 - (double)*(float *)(param_1 + 0xaf8 + *(int *)(param_1 + 0x864) * 4)) {
    iVar3 = 3;
    puVar2 = (undefined4 *)&stack0xffffffb8;
    do {
      puVar2[3] = 0;
      puVar2[4] = 0xffffffff;
      FUN_00566650(&DAT_005ea438);
      puVar2[5] = 0xffffffff;
      puVar2[6] = 0xffffffff;
      *(undefined1 *)(puVar2 + 7) = 0;
      iVar3 = iVar3 + -1;
      puVar2 = puVar2 + 5;
    } while (iVar3 != 0);
    iVar3 = FUN_00411840((int *)(param_1 + 0x864),auStack_3c);
    if ((0 < iVar3) && (*(int **)(param_1 + 0xaf4) != (int *)0x0)) {
      (**(code **)(**(int **)(param_1 + 0xaf4) + 4))(auStack_3c,iVar3,0);
      iVar3 = *(int *)(param_1 + 0x864);
      *(undefined1 *)(param_1 + 0xae4) = 1;
      *(int *)(param_1 + 0xaec) = iVar3;
      *(float *)(param_1 + 0xaf8 + iVar3 * 4) = (float)_DAT_008afea8;
    }
    iVar3 = 3;
    do {
      piVar1 = (int *)((int)register0x00000010 + -0x14);
      register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + -0x14);
      if (*piVar1 != 0) {
        FUN_00587bcf(*piVar1);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_004144d0();
  FUN_00418ac0();
  return 0;
}


