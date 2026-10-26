// Function: FUN_00434090 @ 00434090
// Size (bytes): 427


void __fastcall FUN_00434090(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  bool bVar13;
  
  puVar10 = (undefined4 *)*param_1;
  iVar5 = 0;
  puVar7 = puVar10;
  if (puVar10 != (undefined4 *)0x0) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      iVar5 = iVar5 + 1;
    } while (puVar7 != (undefined4 *)0x0);
    if (1 < iVar5) {
      iVar5 = iVar5 / 2 + -1;
      puVar7 = puVar10;
      if (0 < iVar5) {
        do {
          iVar5 = iVar5 + -1;
          puVar7 = (undefined4 *)puVar7[1];
        } while (iVar5 != 0);
      }
      uVar2 = puVar7[1];
      puVar7[1] = 0;
      puVar6 = (undefined4 *)FUN_00434290(puVar10);
      puVar7 = (undefined4 *)FUN_00434290(uVar2);
      puVar10 = puVar7;
      if ((puVar6 != (undefined4 *)0x0) && (puVar10 = puVar6, puVar7 != (undefined4 *)0x0)) {
        pbVar11 = *(byte **)*puVar7;
        if (pbVar11 == (byte *)0x0) {
          pbVar11 = &DAT_005ea438;
        }
        pbVar9 = *(byte **)*puVar6;
        if (pbVar9 == (byte *)0x0) {
          pbVar9 = &DAT_005ea438;
        }
        do {
          bVar1 = *pbVar9;
          bVar13 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_00434148:
            iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
            goto LAB_0043414d;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar9[1];
          bVar13 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_00434148;
          pbVar9 = pbVar9 + 2;
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_0043414d:
        if (iVar5 < 0) {
          puVar4 = puVar6;
          puVar3 = puVar7;
          puVar12 = (undefined4 *)puVar6[1];
          puVar7 = puVar6;
        }
        else {
          puVar3 = (undefined4 *)puVar7[1];
          puVar4 = puVar7;
          puVar12 = puVar6;
        }
        while (puVar10 = puVar7, puVar12 != (undefined4 *)0x0) {
          if (puVar3 == (undefined4 *)0x0) {
            if (puVar12 == (undefined4 *)0x0) goto LAB_004341ed;
            puVar4[1] = puVar12;
            goto LAB_0043420b;
          }
          pbVar11 = *(byte **)*puVar3;
          if (pbVar11 == (byte *)0x0) {
            pbVar11 = &DAT_005ea438;
          }
          pbVar9 = *(byte **)*puVar12;
          if (pbVar9 == (byte *)0x0) {
            pbVar9 = &DAT_005ea438;
          }
          do {
            bVar1 = *pbVar9;
            bVar13 = bVar1 < *pbVar11;
            if (bVar1 != *pbVar11) {
LAB_004341b5:
              iVar5 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
              goto LAB_004341ba;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar9[1];
            bVar13 = bVar1 < pbVar11[1];
            if (bVar1 != pbVar11[1]) goto LAB_004341b5;
            pbVar9 = pbVar9 + 2;
            pbVar11 = pbVar11 + 2;
          } while (bVar1 != 0);
          iVar5 = 0;
LAB_004341ba:
          if (iVar5 < 0) {
            puVar6 = puVar12;
            puVar10 = puVar3;
            puVar12 = (undefined4 *)puVar12[1];
          }
          else {
            puVar10 = (undefined4 *)puVar3[1];
            puVar6 = puVar3;
          }
          puVar4[1] = puVar6;
          puVar4 = puVar6;
          puVar3 = puVar10;
        }
        if (puVar3 == (undefined4 *)0x0) {
LAB_004341ed:
          puVar4[1] = 0;
        }
        else {
          puVar4[1] = puVar3;
        }
      }
    }
  }
LAB_0043420b:
  *param_1 = puVar10;
  if ((puVar10 != (undefined4 *)0x0) && (iVar5 = puVar10[1], puVar10[1] != 0)) {
    do {
      iVar8 = iVar5;
      iVar5 = *(int *)(iVar8 + 4);
    } while (iVar5 != 0);
    param_1[1] = iVar8;
    param_1[2] = puVar10;
    return;
  }
  param_1[1] = puVar10;
  param_1[2] = puVar10;
  return;
}


