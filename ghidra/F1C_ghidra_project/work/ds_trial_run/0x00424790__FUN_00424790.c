// Function: FUN_00424790 @ 00424790
// Size (bytes): 805


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00424790(int *param_1,char param_2)

{
  byte bVar1;
  float fVar2;
  int *piVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  float10 fVar11;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar7 = 0;
  *(undefined1 *)(param_1 + 0x1104) = 0;
  *(undefined1 *)(param_1 + 0x1050) = 0;
  param_1[0x111f] = 0;
  param_1[0x1142] = 0;
  param_1[0x1143] = 0;
  param_1[0x1108] = 0;
  param_1[0x105c] = 0x7f7fffff;
  piVar3 = param_1 + 0x10b6;
  piVar5 = param_1 + 0x106d;
  iVar6 = 5;
  do {
    piVar5[-3] = 0x497423f0;
    piVar3[-3] = 0;
    *piVar5 = -1;
    piVar5[-0x10] = 0;
    *piVar3 = -0x3b864000;
    piVar3[-4] = -1;
    piVar3[-2] = -1;
    piVar5 = piVar5 + 0x11;
    piVar3 = piVar3 + 7;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined1 *)(param_1 + 0x115e) = 1;
  param_1[0x110c] = 0;
  param_1[0x1149] = 0;
  param_1[0x1118] = -0x40800000;
  param_1[0x1119] = 0x3f800000;
  param_1[0x1113] = 0;
  FUN_0042ae00();
  param_1[0x112d] = param_1[0xe5b];
  param_1[0x114f] = 0x3f800000;
  param_1[0x1155] = 0x3f800000;
  param_1[0x113e] = 0x3f800000;
  fVar2 = (float)-param_1[1] * _DAT_0059e864;
  param_1[0x1133] = 0x3f800000;
  param_1[0x1115] = (int)fVar2;
  param_1[0x117f] = 0;
  param_1[0x110b] = 0;
  param_1[0x1121] = 0x497423f0;
  param_1[0x114e] = 0x497423f0;
  param_1[0x1150] = 0x40c00000;
  param_1[0x1151] = 1;
  *(undefined1 *)(param_1 + 0x1152) = 0;
  param_1[0x1157] = 0;
  param_1[0x1153] = 0;
  param_1[0x1154] = 0;
  param_1[0x1144] = 0;
  param_1[0x1156] = 0x32;
  param_1[0x1158] = 0;
  param_1[0x1159] = 0;
  param_1[0x110f] = 0;
  param_1[0x1101] = -0x40800000;
  param_1[0x1116] = -1;
  param_1[0x112c] = -1;
  param_1[0x111b] = 0;
  param_1[0x10fe] = 0;
  *(undefined1 *)(param_1 + 0x117d) = 0;
  param_1[0x1187] = 0x497423f0;
  if (param_2 != '\0') {
    param_1[0x114d] = 0;
    piVar3 = param_1 + 0x1051;
    iVar6 = 5;
    do {
      *piVar3 = -1;
      piVar3 = piVar3 + 2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_00424080();
    if (param_1[0x112a] != 0) {
      FUN_00587bcf(param_1[0x112a]);
    }
    param_1[0x112b] = 10;
    pvVar4 = operator_new(0x50);
    param_1[0x112a] = (int)pvVar4;
    FUN_00424cd0(0,0);
    param_1[0x1113] = 0;
    param_1[0x112c] = -1;
    param_1[0x117e] = 0;
    _param_2 = 0.0;
    if (0 < DAT_005c329c) {
      do {
        piVar3 = (int *)(&DAT_007c54f0)[(int)_param_2];
        pbVar8 = (byte *)(piVar3 + 0x11ae);
        pbVar9 = (byte *)(*param_1 + 0x46b8);
        do {
          bVar1 = *pbVar9;
          bVar10 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_004249d7:
            iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_004249dc;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar9[1];
          bVar10 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_004249d7;
          pbVar9 = pbVar9 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_004249dc:
        if ((iVar6 == 0) && (piVar3 != param_1)) {
          param_1[0x117e] = (int)piVar3;
        }
        _param_2 = (float)((int)_param_2 + 1);
      } while ((int)_param_2 < DAT_005c329c);
    }
    param_1[2] = *(int *)(*param_1 + 0x48a4) + _DAT_005ea2d0;
    FUN_00403f70(*(undefined4 *)(*param_1 + 0x48a4),local_18,local_c);
    iVar6 = FUN_00403aa0(local_18,0,param_1[2],0);
    param_1[0x1100] = iVar6;
    FUN_00429960();
  }
  piVar3 = param_1 + 0x1180;
  do {
    iVar6 = FUN_004a5c10(iVar7);
    *piVar3 = iVar6;
    iVar7 = iVar7 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar7 < 7);
  param_1[0x104f] = 0x7f7fffff;
  fVar11 = (float10)FUN_00424ac0();
  _param_2 = (float)fVar11;
  if (((DAT_007c56a4 != 3) && (DAT_007c56a4 != 4)) && (DAT_007c56a4 != 5)) {
    _param_2 = _DAT_005ea3e8 * _param_2;
  }
  FUN_004f1510(_param_2);
  return;
}


