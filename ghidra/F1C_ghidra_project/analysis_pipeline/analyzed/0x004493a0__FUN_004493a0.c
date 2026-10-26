// Function: FUN_004493a0 @ 004493a0
// Size (bytes): 802


void __thiscall
FUN_004493a0(int *param_1,uint param_2,int *param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [12];
  
  iVar12 = param_1[1];
  if (iVar12 <= *param_1) {
    iVar3 = iVar12 + 0x2000;
    param_1[1] = iVar3;
    piVar2 = operator_new(iVar3 * 0x20 + 4);
    if (piVar2 == (int *)0x0) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = piVar2 + 1;
      *piVar2 = iVar3;
      if (-1 < iVar12 + 0x1fff) {
        iVar12 = iVar12 + 0x2000;
        do {
          FUN_00448e90();
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
    }
    iVar12 = 0;
    if (0 < *param_1) {
      iVar3 = 0;
      do {
        puVar9 = (undefined4 *)(param_1[2] + iVar3);
        puVar7 = (undefined4 *)(iVar3 + (int)piVar11);
        for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar7 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar7 = puVar7 + 1;
        }
        *(undefined4 **)(param_1[2] + 0x1c + iVar3) = (undefined4 *)(iVar3 + (int)piVar11);
        iVar12 = iVar12 + 1;
        iVar3 = iVar3 + 0x20;
      } while (iVar12 < *param_1);
    }
    if (param_1[3] != 0) {
      FUN_00448e50();
    }
    if (param_1[4] != 0) {
      FUN_00448e50();
    }
    if (param_1[2] != 0) {
      FUN_00587bcf(param_1[2] + -4);
    }
    param_1[2] = (int)piVar11;
  }
  puVar9 = (undefined4 *)(*param_1 * 0x20 + param_1[2]);
  *param_1 = *param_1 + 1;
  FUN_00448ec0(param_5);
  FUN_00448480(param_2,param_3);
  FUN_00448480(param_3,param_4);
  FUN_00448480(param_4,param_2);
  if (param_1[3] == 0) {
    pvVar4 = operator_new(0x60);
    param_1[3] = (int)pvVar4;
    FUN_00448510(param_2);
  }
  if (param_1[4] == 0) {
    pvVar4 = operator_new(0x60);
    param_1[4] = (int)pvVar4;
    FUN_00448510(local_30);
  }
  uVar5 = FUN_004485d0(param_2);
  *puVar9 = uVar5;
  uVar5 = FUN_004485d0(param_3);
  puVar9[2] = uVar5;
  uVar5 = FUN_004485d0(param_4);
  puVar9[4] = uVar5;
  param_5 = 1;
  do {
    iVar12 = puVar9[param_5 + -1];
    if (param_5 == 5) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_5 + 1;
    }
    iVar3 = puVar9[iVar3];
    param_4 = *(uint *)(iVar12 + 0x18);
    iVar8 = 0;
    if (param_4 < 0xb) {
      if (0 < (int)param_4) goto LAB_00449550;
    }
    else {
      param_4 = 0xb;
LAB_00449550:
      param_3 = (int *)(iVar12 + 0x1c);
      do {
        iVar1 = *param_3;
        param_2 = *(uint *)(iVar3 + 0x18);
        if (param_2 < 0xb) {
          if (0 < (int)param_2) goto LAB_00449579;
        }
        else {
          param_2 = 0xb;
LAB_00449579:
          piVar2 = (int *)(iVar3 + 0x1c);
          do {
            if (iVar1 == *piVar2) {
              iVar6 = 0;
              do {
                if (*(int *)(iVar1 + iVar6 * 4) == iVar12) {
                  iVar10 = 4;
                  if (iVar6 != 0) {
                    iVar10 = iVar6 + -2;
                  }
                  if (*(int *)(iVar1 + iVar10 * 4) == iVar3) {
                    iVar8 = 5;
                    if (iVar6 != 0) {
                      iVar8 = iVar6 + -1;
                    }
                  }
                  else {
                    if (iVar6 == 4) {
                      iVar10 = 0;
                    }
                    else {
                      iVar10 = iVar6 + 2;
                    }
                    if (*(int *)(iVar1 + iVar10 * 4) != iVar3) goto LAB_004495ca;
                    if (iVar6 == 5) {
                      iVar8 = 0;
                    }
                    else {
                      iVar8 = iVar6 + 1;
                    }
                  }
                  iVar8 = *(int *)(iVar1 + iVar8 * 4);
                }
LAB_004495ca:
                iVar6 = iVar6 + 2;
              } while (iVar6 < 6);
            }
            piVar2 = piVar2 + 1;
            param_2 = param_2 - 1;
          } while (param_2 != 0);
        }
        param_3 = param_3 + 1;
        param_4 = param_4 - 1;
      } while (param_4 != 0);
    }
    if (param_5 == 1) {
      puVar7 = local_30;
    }
    else {
      puVar7 = local_30 + 4;
      if (param_5 != 3) {
        puVar7 = local_30 + 8;
      }
    }
    local_40 = *puVar7;
    local_3c = puVar7[1];
    local_38 = puVar7[2];
    local_34 = puVar7[3];
    if (iVar8 == 0) {
      uVar5 = FUN_004485d0(&local_40);
      puVar9[param_5] = uVar5;
    }
    else {
      puVar9[param_5] = iVar8;
    }
    param_5 = param_5 + 2;
    if (5 < param_5) {
      iVar12 = 0;
      do {
        iVar3 = puVar9[iVar12];
        if (*(uint *)(iVar3 + 0x18) < 0xb) {
          *(undefined4 **)(iVar3 + 0x1c + *(uint *)(iVar3 + 0x18) * 4) = puVar9;
        }
        iVar12 = iVar12 + 1;
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
      } while (iVar12 < 6);
      if (param_6 != 0) {
        iVar12 = 0;
        piVar2 = puVar9 + 1;
        do {
          iVar8 = *piVar2;
          *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(param_6 + iVar12 * 8);
          iVar3 = iVar12 * 8;
          iVar12 = iVar12 + 1;
          piVar2 = piVar2 + 2;
          *(undefined4 *)(iVar8 + 0x14) = *(undefined4 *)(param_6 + 4 + iVar3);
        } while (iVar12 < 3);
      }
      return;
    }
  } while( true );
}


