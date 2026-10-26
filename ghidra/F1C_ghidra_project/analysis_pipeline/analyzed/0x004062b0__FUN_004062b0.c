
/* WARNING: Removing unreachable block (ram,0x00406409) */

void __thiscall FUN_004062b0(int *param_1,undefined4 *param_2,int param_3,char param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  int *piVar8;
  bool bVar9;
  
  puVar5 = param_2;
  if (((param_2 != (undefined4 *)0x0) && (param_3 < 4)) && (0 < param_3)) {
    if (param_4 == '\0') {
      FUN_00406750();
      param_1 = param_1 + 7;
      iVar3 = 3;
      piVar8 = param_1;
      do {
        FUN_00566650(&DAT_005ea438);
        piVar8[-1] = -1;
        *piVar8 = -1;
        *(undefined1 *)(piVar8 + 1) = 0;
        piVar8 = piVar8 + 5;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      if (0 < param_3) {
        piVar8 = param_2 + 3;
        do {
          puVar4 = (undefined1 *)piVar8[-3];
          if (puVar4 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          FUN_00566650(puVar4);
          param_1[-1] = piVar8[-1];
          *param_1 = *piVar8;
          *(char *)(param_1 + 1) = (char)piVar8[1];
          piVar8 = piVar8 + 5;
          param_1 = param_1 + 5;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      FUN_00406790();
    }
    else {
      _param_4 = 0;
      FUN_00566650(&DAT_005ea438);
      param_2 = (undefined4 *)0x0;
      piVar8 = param_1 + 7;
      do {
        if (param_3 <= _param_4) break;
        pbVar7 = &DAT_005ea438;
        pbVar2 = (byte *)piVar8[-3];
        if (pbVar2 == (byte *)0x0) {
          pbVar2 = &DAT_005ea438;
        }
        do {
          bVar1 = *pbVar2;
          bVar9 = bVar1 < *pbVar7;
          if (bVar1 != *pbVar7) {
LAB_00406374:
            iVar3 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_00406379;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar9 = bVar1 < pbVar7[1];
          if (bVar1 != pbVar7[1]) goto LAB_00406374;
          pbVar2 = pbVar2 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar1 != 0);
        iVar3 = 0;
LAB_00406379:
        puVar6 = puVar5;
        if (((iVar3 == 0) && (piVar8[-1] == -1)) && ((*piVar8 == -1 && ((char)piVar8[1] == '\0'))))
        {
          _param_4 = _param_4 + 1;
          puVar4 = (undefined1 *)*puVar5;
          puVar6 = puVar5 + 5;
          if (puVar4 == (undefined1 *)0x0) {
            puVar4 = &DAT_005ea438;
          }
          FUN_00566650(puVar4);
          piVar8[-1] = puVar5[2];
          *piVar8 = puVar5[3];
          *(undefined1 *)(piVar8 + 1) = *(undefined1 *)(puVar5 + 4);
        }
        param_2 = (undefined4 *)((int)param_2 + 1);
        piVar8 = piVar8 + 5;
        puVar5 = puVar6;
      } while ((int)param_2 < 3);
      if ((0 < _param_4) && (iVar3 = (**(code **)(*param_1 + 8))(), iVar3 == 0)) {
        FUN_00406790();
      }
    }
  }
  return;
}

