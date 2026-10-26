// Function: FUN_00496930 @ 00496930
// Size (bytes): 1189


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00496930(int param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  float fVar4;
  char cVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  int iVar11;
  uint local_4;
  
  FUN_00498720();
  if (*(int *)(param_1 + 0x28) != 2) {
    *(undefined4 *)(param_1 + 0x28) = 2;
  }
  cVar5 = FUN_00496e20();
  if (cVar5 != '\0') {
    return 0;
  }
  FUN_00498740();
  uVar1 = *(uint *)(param_1 + 0x60);
  uVar10 = *(undefined4 *)(param_1 + 0x5c);
  piVar8 = *(int **)(param_1 + 0x156c);
  piVar2 = *(int **)(param_1 + 0x18);
  uVar7 = FUN_004987b0();
  *(undefined4 *)(param_1 + 0x74) = uVar7;
  switch(uVar7) {
  case 1:
  case 2:
  case 4:
  case 6:
  case 9:
    *(undefined4 *)(param_1 + 0x156c) = 0;
  }
  if (*(int *)(param_1 + 0x156c) == 0) {
    uVar7 = FUN_00495980();
    *(undefined4 *)(param_1 + 0x156c) = uVar7;
  }
  if ((piVar8 != *(int **)(param_1 + 0x156c)) && (piVar8 != (int *)0x0)) {
    (**(code **)(*piVar8 + 0x4c))();
  }
  if ((piVar2 != *(int **)(param_1 + 0x18)) && (piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 0x3c))(uVar10,uVar1);
  }
  if ((piVar8 == (int *)0x0) || (piVar8 != *(int **)(param_1 + 0x156c))) {
    fVar4 = *(float *)(param_1 + 0xcc) - (*(float *)(param_1 + 0xc0) + *(float *)(param_1 + 0xc0));
    *(float *)(param_1 + 0xcc) = fVar4;
    if (fVar4 < DAT_0059e440) {
      fVar4 = DAT_0059e440;
    }
LAB_00496a3b:
    *(float *)(param_1 + 0xcc) = fVar4;
  }
  else if (*(float *)(param_1 + 0xcc) < *(float *)(param_1 + 0xd4) + *(float *)(param_1 + 0xd0)) {
    fVar4 = *(float *)(param_1 + 0xc0) + *(float *)(param_1 + 0xcc);
    goto LAB_00496a3b;
  }
  if ((*(int *)(param_1 + 0x74) == 1) && (*(int *)(param_1 + 0x156c) != 0)) {
    FUN_004979c0(*(int *)(param_1 + 0x156c));
  }
  piVar3 = *(int **)(param_1 + 0x156c);
  if (piVar3 == (int *)0x0) goto switchD_00496a74_caseD_9;
  switch(*(undefined4 *)(param_1 + 0x74)) {
  case 1:
  case 2:
    iVar11 = (**(code **)(*piVar3 + 0x8c))();
    if (iVar11 == 0) {
      uVar10 = FUN_00486240();
      iVar11 = FUN_00497e80(uVar10);
      if (iVar11 != 0) {
        FUN_00498030(iVar11);
      }
    }
    if (*(int *)(param_1 + 0x74) == 2) {
      (**(code **)(**(int **)(param_1 + 0x156c) + 0x5c))();
    }
    break;
  case 3:
    iVar11 = (**(code **)(*piVar3 + 0x90))();
    if (iVar11 == 0) {
      uVar10 = FUN_00486260();
      iVar11 = FUN_00497e80(uVar10);
      if (iVar11 != 0) {
        FUN_00498030(iVar11);
      }
    }
    if (((_DAT_005ac994 < *(float *)(param_1 + 0xc4)) &&
        (piVar8 = (int *)FUN_00495980(), piVar8 != (int *)0x0)) && (*(int *)(param_1 + 0x1560) != 0)
       ) {
      puVar9 = *(undefined1 **)(param_1 + 0x1558);
      if (puVar9 == (undefined1 *)0x0) {
        puVar9 = &DAT_005ea438;
      }
      cVar5 = (**(code **)(*piVar8 + 0x80))(puVar9);
      if (cVar5 != '\0') {
        puVar9 = *(undefined1 **)(param_1 + 0x1558);
        if (puVar9 == (undefined1 *)0x0) {
          puVar9 = &DAT_005ea438;
        }
        (**(code **)(*piVar8 + 0x84))
                  (puVar9,*(undefined4 *)(param_1 + 0x1560),*(undefined4 *)(param_1 + 0x1564));
      }
    }
    FUN_004986a0();
    break;
  case 4:
    if (piVar2 != *(int **)(param_1 + 0x18)) {
      (**(code **)(**(int **)(param_1 + 0x18) + 0x38))(uVar10,uVar1);
    }
    if ((piVar8 == *(int **)(param_1 + 0x156c)) ||
       (iVar11 = (**(code **)(**(int **)(param_1 + 0x156c) + 0x48))(), iVar11 != 0)) break;
    uVar10 = FUN_00486280();
    goto LAB_00496cb0;
  case 5:
  case 8:
    if (*(float *)(param_1 + 0xc4) == DAT_0059e440) {
      (**(code **)(*piVar3 + 0x50))();
    }
    (**(code **)(**(int **)(param_1 + 0x156c) + 0x94))();
    uVar10 = FUN_004862a0();
LAB_00496cb0:
    iVar11 = FUN_00497e80(uVar10);
    if (iVar11 != 0) {
      FUN_00498030(iVar11);
    }
    break;
  case 6:
    iVar11 = (**(code **)(*piVar3 + 0x60))();
    if (iVar11 == 0) {
      uVar10 = FUN_00486240();
      iVar11 = FUN_00497e80(uVar10);
      if (iVar11 != 0) {
        FUN_00498030(iVar11);
      }
    }
    if (*(int *)(param_1 + 0x74) == 2) {
      (**(code **)(**(int **)(param_1 + 0x156c) + 0x5c))();
    }
    break;
  case 7:
    iVar11 = (**(code **)(*piVar3 + 100))();
    if (iVar11 == 0) {
      uVar10 = FUN_00486260();
      iVar11 = FUN_00497e80(uVar10);
      if (iVar11 != 0) {
        FUN_00498030(iVar11);
      }
    }
    if (((_DAT_005ac994 < *(float *)(param_1 + 0xc4)) &&
        (piVar8 = (int *)FUN_00495980(), piVar8 != (int *)0x0)) && (*(int *)(param_1 + 0x1560) != 0)
       ) {
      puVar9 = *(undefined1 **)(param_1 + 0x1558);
      if (puVar9 == (undefined1 *)0x0) {
        puVar9 = &DAT_005ea438;
      }
      cVar5 = (**(code **)(*piVar8 + 0x80))(puVar9);
      if (cVar5 != '\0') {
        puVar9 = *(undefined1 **)(param_1 + 0x1558);
        if (puVar9 == (undefined1 *)0x0) {
          puVar9 = &DAT_005ea438;
        }
        (**(code **)(*piVar8 + 0x84))
                  (puVar9,*(undefined4 *)(param_1 + 0x1560),*(undefined4 *)(param_1 + 0x1564));
      }
    }
    FUN_004986a0();
    break;
  case 0xc:
    (**(code **)(*piVar3 + 0x78))();
    break;
  case 0xd:
    (**(code **)(*piVar3 + 0x7c))();
  }
switchD_00496a74_caseD_9:
  *(undefined4 *)(param_1 + 0x1598) = 0;
  if (0 < DAT_007cb218) {
    do {
      *(undefined2 *)(param_1 + 0x159c + *(int *)(param_1 + 0x1598) * 2) =
           (&DAT_007cb21c)[*(int *)(param_1 + 0x1598)];
      iVar11 = *(int *)(param_1 + 0x1598) + 1;
      *(int *)(param_1 + 0x1598) = iVar11;
    } while (iVar11 < DAT_007cb218);
  }
  local_4 = uVar1 & 0xffffff00;
  if ((*(int **)(param_1 + 0x20) != (int *)0x0) && (0 < *(int *)(param_1 + 0x1598))) {
    uVar6 = (**(code **)(**(int **)(param_1 + 0x20) + 0x58))
                      (param_1 + 0x159c,*(int *)(param_1 + 0x1598));
    local_4 = CONCAT31((int3)(uVar1 >> 8),uVar6);
  }
  FUN_004957a0(*(undefined4 *)(param_1 + 0x1598),param_1 + 0x159c,local_4);
  if (DAT_005cc9e8 == 5) {
    FUN_00496880();
  }
  if (*(int *)(param_1 + 0x74) == 5) {
    *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc0) + *(float *)(param_1 + 0xc4);
  }
  else {
    *(undefined4 *)(param_1 + 0xc4) = 0;
  }
  FUN_00495440();
  *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x74);
  return 0;
}


