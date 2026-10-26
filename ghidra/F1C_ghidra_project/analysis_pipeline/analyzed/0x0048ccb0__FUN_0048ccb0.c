// Function: FUN_0048ccb0 @ 0048ccb0
// Size (bytes): 997


undefined4 __thiscall FUN_0048ccb0(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
  uVar2 = 0xffffffff;
  if (((((param_1[5] != -1) || (param_1[6] != -1)) || (param_1[7] != -1)) || (param_1[8] != -1)) &&
     (0 < param_1[0xca])) {
    iVar3 = (**(code **)(*param_1 + 0x20))();
    iVar4 = (**(code **)(*param_1 + 0x18))();
    iVar5 = (**(code **)(*param_1 + 0x24))();
    iVar6 = (**(code **)(*param_1 + 0x1c))();
    iVar7 = (**(code **)(*param_1 + 0x18))();
    iVar8 = param_1[0xcb];
    iVar10 = param_1[0xcd];
    iStack_34 = (iVar7 + (iVar3 - iVar4) / 2) - iVar10 % iVar8;
    iVar3 = (**(code **)(*param_1 + 0x18))();
    iStack_30 = (iStack_34 - iVar3) / iVar8 + 1;
    iStack_34 = iStack_34 - iVar8 * iStack_30;
    iStack_30 = iVar10 / iVar8 - iStack_30;
    if (iStack_30 < 0) {
      do {
        iStack_30 = iStack_30 + param_1[0xca];
      } while (iStack_30 < 0);
    }
    iVar8 = (**(code **)(*param_1 + 0x20))();
    if (iStack_34 < iVar8) {
      do {
        iVar8 = 0;
        if ((iStack_30 < 0) || (param_1[0xca] <= iStack_30)) {
          param_1[0xc9] = 0;
        }
        else {
          param_1[0xc9] = param_1[199];
          iVar10 = iStack_30;
          while ((0 < iVar10 && (param_1[0xc9] != 0))) {
            iVar10 = iVar10 + -1;
            param_1[0xc9] = *(int *)(param_1[0xc9] + 4);
          }
        }
        if ((int *)param_1[0xc9] == (int *)0x0) {
          iStack_24 = 0;
LAB_0048cdce:
          iStack_2c = 0;
        }
        else {
          iStack_24 = *(int *)param_1[0xc9];
          if (((iStack_24 == 0) || (*(int *)(iStack_24 + 4) == 0)) ||
             (iVar10 = *(int *)(*(int *)(iStack_24 + 4) + 0xc), iVar10 == 0)) goto LAB_0048cdce;
          iStack_2c = *(int *)(iVar10 + 0x1c);
        }
        if (((iStack_24 == 0) || (*(int *)(iStack_24 + 4) == 0)) ||
           (iVar10 = *(int *)(*(int *)(iStack_24 + 4) + 0xc), iVar10 == 0)) {
          iStack_28 = 0;
        }
        else {
          iStack_28 = *(int *)(iVar10 + 0x20);
        }
        if ((0 < iStack_2c) && (0 < iStack_28)) {
          iVar3 = param_1[0xcb] - iStack_2c;
          iVar10 = (iVar5 - iVar6) - iStack_28;
          if (iVar3 < 1) {
            iStack_20 = 0;
          }
          else {
            iStack_20 = iVar3 / 2;
          }
          if (0 < iVar10) {
            iVar8 = iVar10 / 2;
          }
          iVar7 = iStack_20 + iStack_34;
          iVar4 = (**(code **)(*param_1 + 0x1c))();
          iVar4 = iVar4 + iVar8;
          if (iVar3 < 1) {
            iVar11 = -(iVar3 / 2);
            iVar8 = iStack_2c + (iVar3 / 2) * 2;
          }
          else {
            iVar11 = 0;
            iVar8 = iStack_2c;
          }
          if (iVar10 < 1) {
            iStack_2c = -(iVar10 / 2);
            iStack_28 = iStack_28 + (iVar10 / 2) * 2;
          }
          else {
            iStack_2c = 0;
          }
          iVar10 = (**(code **)(*param_1 + 0x18))();
          if (iStack_34 < iVar10) {
            iVar10 = (**(code **)(*param_1 + 0x18))();
            iVar10 = (iVar10 - iStack_20) - iStack_34;
            if (0 < iVar10) {
              iVar11 = iVar11 + iVar10;
              iVar7 = iVar7 + iVar10;
              iVar8 = iVar8 - iVar10;
            }
          }
          iVar10 = (**(code **)(*param_1 + 0x20))();
          if (iVar10 - iVar7 <= iVar8) {
            iVar8 = (**(code **)(*param_1 + 0x20))();
            iVar8 = iVar8 - iVar7;
          }
          if ((0 < iVar8) && (0 < iStack_28)) {
            uVar13 = 0;
            uVar12 = 0;
            uVar2 = FUN_00495150(iVar7,iVar4,iVar8,iStack_28,0,0);
            FUN_00494a30(*(undefined4 *)(*(int *)(iStack_24 + 4) + 0xc),iVar11,iStack_2c,uVar2,iVar7
                         ,iVar4,iVar8,iStack_28,uVar12,uVar13);
          }
        }
        iStack_30 = iStack_30 + 1;
        if (param_1[0xca] + -1 < iStack_30) {
          iStack_30 = 0;
        }
        iStack_34 = iStack_34 + param_1[0xcb];
        iVar8 = (**(code **)(*param_1 + 0x20))();
      } while (iStack_34 < iVar8);
    }
    iVar8 = FUN_00486830();
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    cVar1 = (**(code **)(*param_1 + 0x14))();
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 8))(auStack_4,auStack_8,auStack_c,auStack_10);
    }
    (**(code **)(*param_1 + 0xc))();
    piVar9 = (int *)FUN_00486460(param_1[0x21]);
    iVar8 = param_1[0x22];
    if (0 < iVar8) {
      do {
        if (piVar9 != (int *)0x0) {
          piVar9 = (int *)piVar9[10];
        }
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    if (piVar9 != (int *)0x0) {
      *param_4 = param_1[3];
      iVar8 = param_1[1];
      *param_2 = iVar8;
      iVar10 = *(int *)(*(int *)(piVar9[8] + 0xc) + 0x1c);
      iVar3 = *(int *)(*(int *)(piVar9[8] + 0xc) + 0x20);
      iVar4 = piVar9[1] - *piVar9;
      if (iVar10 < piVar9[1] - *piVar9) {
        iVar4 = iVar10;
      }
      iVar10 = piVar9[3] - piVar9[2];
      if (iVar3 < piVar9[3] - piVar9[2]) {
        iVar10 = iVar3;
      }
      uVar13 = 0;
      uVar12 = 0;
      iVar3 = *param_4;
      iVar5 = iVar4;
      iVar6 = iVar10;
      uVar2 = FUN_00495150(iVar3,iVar8,iVar4,iVar10,0,0);
      FUN_00494a30(*(undefined4 *)(piVar9[8] + 0xc),*piVar9,piVar9[2],uVar2,iVar3,iVar8,iVar5,iVar6,
                   uVar12,uVar13);
      (**(code **)(*param_1 + 0x10))(*param_2,*param_2 + iVar10,*param_4,*param_4 + iVar4);
    }
    uVar2 = 0;
  }
  return uVar2;
}


