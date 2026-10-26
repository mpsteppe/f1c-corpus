// Function: FUN_00476ec0 @ 00476ec0
// Size (bytes): 194


void __fastcall FUN_00476ec0(int *param_1)

{
  byte bVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  
  (**(code **)(*param_1 + 0xa0))();
  iVar7 = 0;
  puVar3 = DAT_007ce64c;
  if (DAT_007ce64c == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  iVar4 = FUN_004c40b0(puVar3);
  if (iVar4 != 0) {
    piVar2 = (int *)param_1[0x3c];
    param_1[0x3e] = (int)piVar2;
    if ((piVar2 != (int *)0x0) && (iVar6 = *piVar2, iVar6 != 0)) {
      do {
        pbVar8 = *(byte **)(iVar6 + 4);
        if (pbVar8 == (byte *)0x0) {
          pbVar8 = &DAT_005ea438;
        }
        pbVar5 = (byte *)(iVar4 + 0x7c);
        do {
          bVar1 = *pbVar5;
          bVar9 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_00476f45:
            iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_00476f4a;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar5[1];
          bVar9 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_00476f45;
          pbVar5 = pbVar5 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        iVar6 = 0;
LAB_00476f4a:
        if (iVar6 == 0) {
          param_1[0x5d] = iVar7;
          return;
        }
        iVar7 = iVar7 + 1;
        if (param_1[0x3e] != 0) {
          param_1[0x3e] = *(int *)(param_1[0x3e] + 4);
        }
        if ((int *)param_1[0x3e] == (int *)0x0) {
          return;
        }
        iVar6 = *(int *)param_1[0x3e];
        if (iVar6 == 0) {
          return;
        }
      } while( true );
    }
  }
  return;
}


