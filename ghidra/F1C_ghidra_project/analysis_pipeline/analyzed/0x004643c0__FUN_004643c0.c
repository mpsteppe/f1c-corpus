// Function: FUN_004643c0 @ 004643c0
// Size (bytes): 566


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004643c0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  float fVar4;
  int *piVar5;
  bool bVar6;
  int *piVar7;
  char cVar8;
  int iVar9;
  undefined1 *puVar10;
  int *piVar11;
  undefined8 uVar12;
  
  iVar9 = *param_1;
  iVar1 = *(int *)(iVar9 + 0x3fc4);
  if (iVar1 == 0) {
    return;
  }
  fVar4 = (float)_DAT_008afe98;
  if ((iVar1 == 2) || (iVar1 == 1)) {
    bVar6 = true;
    uVar12 = FUN_00462370();
    iVar9 = (int)((ulonglong)uVar12 >> 0x20);
    if ((int)uVar12 < 2) goto LAB_00464412;
  }
  else {
    bVar6 = false;
  }
  *(float *)(iVar9 + 0x388) = fVar4 + *(float *)(iVar9 + 0x388);
LAB_00464412:
  iVar9 = FUN_0057a900();
  if (iVar9 == 0) {
    *(float *)(*param_1 + 0x37c) = *(float *)(*param_1 + 0x37c) - fVar4;
    if (*(float *)(*param_1 + 0x37c) < DAT_0059e440) {
      FUN_004a0d30(1);
      FUN_004a0db0();
      FUN_004a0490();
    }
  }
  else {
    FUN_00460cb0(0);
    FUN_0045fc50();
    FUN_00460380();
    FUN_0045c7e0(fVar4);
    FUN_00460dd0();
    FUN_004612e0();
    if (*(char *)(*param_1 + 0x28) != '\0') {
      FUN_00460470();
      *(undefined1 *)(*param_1 + 0x28) = 0;
      if ((bVar6) && (*(char *)(*param_1 + 0x29) == '\0')) {
        FUN_00460e90();
      }
    }
  }
  piVar11 = (int *)0x0;
  *(float *)(*param_1 + 900) = fVar4 + *(float *)(*param_1 + 900);
  puVar2 = *(undefined4 **)(*param_1 + 0x1b770);
  if (puVar2 != (undefined4 *)0x0) {
    piVar11 = (int *)*puVar2;
    *(undefined1 *)(puVar2 + 2) = 0;
    cVar8 = FUN_00464740(piVar11,1);
    if (cVar8 == '\0') {
      piVar11 = (int *)0x0;
    }
  }
joined_r0x0046450e:
  do {
    do {
      if (piVar11 == (int *)0x0) {
        if (bVar6) {
          FUN_0045d4e0();
        }
        FUN_0045f030();
        return;
      }
      puVar10 = (undefined1 *)*piVar11;
      if (puVar10 == (undefined1 *)0x0) {
        puVar10 = &DAT_005ea438;
      }
      FUN_004a0df0(puVar10);
      if (*piVar11 != 0) {
        FUN_00587bcf(*piVar11);
      }
      FUN_00587bcf(piVar11);
      iVar9 = *param_1;
      puVar2 = *(undefined4 **)(iVar9 + 0x1b770);
      piVar11 = (int *)0x0;
    } while (puVar2 == (undefined4 *)0x0);
    piVar11 = (int *)*puVar2;
    *(undefined1 *)(puVar2 + 2) = 0;
    if (piVar11 != (int *)0x0) {
      piVar7 = *(int **)(iVar9 + 0x1b770);
      piVar3 = (int *)0x0;
      while (piVar5 = piVar7, piVar5 != (int *)0x0) {
        if ((int *)*piVar5 == piVar11) {
          if (piVar5 == *(int **)(iVar9 + 0x1b778)) {
            *(int *)(iVar9 + 0x1b778) = piVar5[1];
          }
          if (piVar3 == (int *)0x0) {
            *(int *)(iVar9 + 0x1b770) = piVar5[1];
          }
          else {
            piVar3[1] = piVar5[1];
          }
          if (*(int **)(iVar9 + 0x1b774) == piVar5) {
            *(int **)(iVar9 + 0x1b774) = piVar3;
          }
          *(int *)(iVar9 + 0x1b77c) = *(int *)(iVar9 + 0x1b77c) + -1;
          if (((char)piVar5[2] != '\0') && (piVar3 = (int *)*piVar5, piVar3 != (int *)0x0)) {
            if (*piVar3 != 0) {
              FUN_00587bcf(*piVar3);
            }
            FUN_00587bcf(piVar3);
          }
          FUN_00587bcf(piVar5);
          goto joined_r0x0046450e;
        }
        piVar3 = piVar5;
        piVar7 = (int *)piVar5[1];
      }
    }
    piVar11 = (int *)0x0;
  } while( true );
}


