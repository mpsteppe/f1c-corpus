
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00486ac0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int **ppiVar6;
  int **ppiVar7;
  int unaff_EBX;
  int iVar8;
  int unaff_EBP;
  int *piVar9;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 *******pppppppuVar10;
  undefined4 *******pppppppuVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined1 auStack_5c [3];
  char cStack_59;
  int iStack_58;
  int iStack_54;
  int *piStack_50;
  undefined4 ******ppppppuStack_4c;
  int **ppiStack_48;
  int iStack_44;
  float fStack_40;
  int iStack_3c;
  float fStack_38;
  int iStack_34;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  int **ppiStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  if ((char)param_1[0x1b] != '\0') {
    (**(code **)(*param_1 + 0xa0))();
    *(undefined1 *)(param_1 + 0x1b) = 0;
  }
  ppiStack_48 = (int **)FUN_00495150();
  auStack_5c = (undefined1  [3])CONCAT12(0,auStack_5c._0_2_);
  if (*(int *)(param_1[0x10] + 0x38) == 2) {
    ppiStack_48 = (int **)FUN_00495110();
    auStack_5c = (undefined1  [3])CONCAT12(1,auStack_5c._0_2_);
  }
  uStack_4 = FUN_00486830();
  iVar2 = FUN_00486830();
  if ((iVar2 == 0) && (auStack_5c[2] == '\0')) {
    return 0xffffffff;
  }
  if (*(char *)((int)param_1 + 0x65) == '\0') {
    return 0;
  }
  cVar1 = (**(code **)(*param_1 + 0x14))();
  _auStack_5c = CONCAT13(cVar1,auStack_5c);
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 8))(auStack_30,auStack_2c);
  }
  (**(code **)(*param_1 + 0xc))();
  piVar3 = (int *)FUN_00486460(param_1[0x21]);
  iVar2 = param_1[0x22];
  if (0 < iVar2) {
    do {
      if (piVar3 != (int *)0x0) {
        piVar3 = (int *)piVar3[10];
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (piVar3 != (int *)0x0) {
    iStack_58 = param_1[3];
    iStack_54 = param_1[1];
    iStack_34 = piVar3[2];
    iStack_8 = *piVar3;
    iVar2 = *(int *)(piVar3[8] + 0xc);
    iVar12 = piVar3[1] - iStack_8;
    if (*(int *)(iVar2 + 0x1c) < piVar3[1] - iStack_8) {
      iVar12 = *(int *)(iVar2 + 0x1c);
    }
    iVar8 = piVar3[3] - iStack_34;
    if (*(int *)(iVar2 + 0x20) < piVar3[3] - iStack_34) {
      iVar8 = *(int *)(iVar2 + 0x20);
    }
    iStack_44 = iVar8;
    iStack_3c = iVar12;
    if (auStack_5c[2] == '\0') {
      FUN_00494a30(iVar2,iStack_8,iStack_34,ppiStack_48,iStack_58,iStack_54,iVar12,iVar8,0,0);
      (**(code **)(*param_1 + 0x10))(iStack_54,iVar8 + iStack_54,iStack_58,iVar12 + iStack_58);
    }
    else {
      FUN_00495120(&iStack_20,&iStack_1c);
      fStack_38 = (float)iStack_20 * _DAT_005a68ec;
      fStack_40 = (float)iStack_1c * _DAT_005a68e8;
      iStack_54 = __ftol();
      iStack_58 = __ftol();
      (**(code **)(*param_1 + 0x88))(&uStack_c,&uStack_10,&uStack_14,&uStack_18);
      uVar4 = __ftol(uStack_c,uStack_10,uStack_14,uStack_18);
      uVar5 = __ftol(uVar4);
      FUN_00494a70(*(undefined4 *)(piVar3[8] + 0xc),iStack_8,iStack_34,iVar12,iVar8,ppiStack_48,
                   iStack_58,iStack_54,uVar5,uVar4,uStack_c,uStack_10,uStack_14,uStack_18);
    }
  }
  pppppppuVar10 = &ppppppuStack_4c;
  piVar3 = &iStack_58;
  ppiVar6 = &piStack_50;
  piVar14 = &iStack_54;
  piStack_50 = (int *)0x0;
  ppppppuStack_4c = (undefined4 *******)0x0;
  iStack_54 = 600;
  iStack_58 = 800;
  (**(code **)(*param_1 + 0x34))();
  if ((unaff_ESI != unaff_EBX && -1 < unaff_ESI - unaff_EBX) &&
     (_auStack_5c != unaff_EBP && -1 < _auStack_5c - unaff_EBP)) {
    (**(code **)(*param_1 + 0x10))(unaff_EBX,unaff_ESI,unaff_EBP,_auStack_5c);
  }
  (**(code **)(*param_1 + 8))(&stack0xffffff9c,&stack0xffffffa0,&stack0xffffff98,auStack_5c);
  iVar2 = unaff_EDI;
  ppiVar7 = ppiVar6;
  piVar9 = piVar3;
  pppppppuVar11 = pppppppuVar10;
  if (((char)((uint)piVar14 >> 0x18) != '\0') &&
     (cVar1 = (**(code **)(*param_1 + 0x14))(), iVar2 = iStack_44, ppiVar7 = ppiStack_48,
     piVar9 = piStack_50, pppppppuVar11 = (undefined4 *******)ppppppuStack_4c, cVar1 != '\0')) {
    if ((int)piStack_50 <= (int)piVar3) {
      piVar3 = piStack_50;
    }
    if ((int)pppppppuVar10 <= (int)ppppppuStack_4c) {
      pppppppuVar10 = (undefined4 *******)ppppppuStack_4c;
    }
    if ((int)ppiStack_48 <= (int)ppiVar6) {
      ppiVar6 = ppiStack_48;
    }
    iVar2 = unaff_EDI;
    ppiVar7 = ppiVar6;
    piVar9 = piVar3;
    pppppppuVar11 = pppppppuVar10;
    if (unaff_EDI <= iStack_44) {
      iVar2 = iStack_44;
    }
  }
  if ((char)((uint)piVar14 >> 0x10) != '\0') {
    return 0;
  }
  iVar2 = iVar2 - (int)ppiVar7;
  iVar12 = (int)pppppppuVar11 - (int)piVar9;
  ppiStack_28 = ppiVar7;
  if (iStack_24 == 1) {
    piVar3 = piVar9;
    iVar8 = iVar2;
    iVar13 = iVar12;
    FUN_00490920(ppiVar7,piVar9,iVar2,iVar12);
    FUN_004918d0(ppiVar7,piVar3,iVar8,iVar13);
  }
  else if ((iStack_24 < 2) || (3 < iStack_24)) goto LAB_00486e5c;
  ppiVar6 = ppiStack_28;
  FUN_00490920(ppiStack_28,piVar9,iVar2,iVar12);
  FUN_00491960(ppiVar6,piVar9,iVar2,iVar12);
LAB_00486e5c:
  (**(code **)(*param_1 + 0x2c))(0);
  return 0;
}

