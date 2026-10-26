// Function: FUN_00415230 @ 00415230
// Size (bytes): 747


int __thiscall FUN_00415230(int *param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  bool bVar11;
  byte local_80 [128];
  
  if (param_2 != (byte *)0x0) {
    iVar9 = param_1[3];
    FUN_004b0b20(local_80,0x7f);
    pbVar10 = local_80;
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar11 = bVar1 < *pbVar10;
      if (bVar1 != *pbVar10) {
LAB_00415294:
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00415299;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar11 = bVar1 < pbVar10[1];
      if (bVar1 != pbVar10[1]) goto LAB_00415294;
      pbVar3 = pbVar3 + 2;
      pbVar10 = pbVar10 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00415299:
    if (iVar4 == 0) {
      puVar5 = DAT_007ce64c;
      if (DAT_007ce64c == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      FUN_004c3f80(puVar5);
      iVar4 = FUN_004c4080();
      if (iVar4 != 0) {
        param_2 = (byte *)(iVar4 + 0xbc);
      }
    }
    iVar4 = 0;
    if (0 < iVar9) {
      do {
        if ((iVar4 < 0) || (param_1[3] <= iVar4)) {
LAB_00415310:
          puVar6 = (undefined4 *)0x0;
        }
        else {
          puVar6 = (undefined4 *)*param_1;
          for (iVar8 = iVar4; 0 < iVar8; iVar8 = iVar8 + -1) {
            if (puVar6 == (undefined4 *)0x0) goto LAB_00415310;
            puVar6 = (undefined4 *)puVar6[1];
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_00415310;
          puVar6 = (undefined4 *)*puVar6;
        }
        puVar5 = (undefined1 *)*puVar6;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar8 = FUN_00588410(puVar5,param_2);
        if (iVar8 == 0) {
          if ((iVar4 < 0) || (param_1[3] <= iVar4)) {
LAB_00415351:
            iVar8 = 0;
          }
          else {
            piVar2 = (int *)*param_1;
            for (iVar8 = iVar4; 0 < iVar8; iVar8 = iVar8 + -1) {
              if (piVar2 == (int *)0x0) goto LAB_00415351;
              piVar2 = (int *)piVar2[1];
            }
            if (piVar2 == (int *)0x0) goto LAB_00415351;
            iVar8 = *piVar2;
          }
          puVar5 = *(undefined1 **)(*(int *)(iVar8 + 8) * 0x424 + DAT_008ac394);
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          iVar8 = FUN_00588410(puVar5,param_3);
          if (iVar8 == 0) {
            return iVar4;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar9);
      if (0 < iVar9) {
        puVar6 = operator_new(0xb0);
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          *puVar6 = 0;
          puVar6[1] = 0xffffffff;
          iVar9 = 2;
          do {
            FUN_00415520();
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          FUN_00401000(puVar6 + 0xe,0x14,2,FUN_00415520);
          FUN_00401000(puVar6 + 0x18,0x14,2,FUN_00415520);
          FUN_00401000(puVar6 + 0x22,0x14,2,FUN_00415520);
          FUN_004149a0();
        }
        FUN_00566650(param_2);
        puVar6[2] = 0xffffffff;
        iVar9 = FUN_00414600(1);
        if (iVar9 == 0) {
          puVar7 = operator_new(0xc);
          if (puVar7 == (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            *puVar7 = puVar6;
            puVar7[1] = 0;
            *(undefined1 *)(puVar7 + 2) = 1;
          }
          if (*param_1 != 0) {
            *(undefined4 **)(param_1[1] + 4) = puVar7;
            param_1[1] = (int)puVar7;
            iVar9 = param_1[3];
            param_1[3] = iVar9 + 1;
            return iVar9;
          }
          *param_1 = (int)puVar7;
          param_1[2] = (int)puVar7;
          param_1[1] = (int)puVar7;
          iVar9 = param_1[3];
          param_1[3] = iVar9 + 1;
          return iVar9;
        }
        FUN_004149a0();
        iVar9 = 2;
        do {
          FUN_00414370();
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        FUN_00401030(puVar6 + 0x18,0x14,2,FUN_00414370);
        FUN_00401030(puVar6 + 0xe,0x14,2,FUN_00414370);
        FUN_00401030(puVar6 + 4,0x14,2,FUN_00414370);
        FUN_00414370();
        FUN_00587bcf(puVar6);
      }
    }
  }
  return -1;
}


