// Function: FUN_00477720 @ 00477720
// Size (bytes): 225


void __fastcall FUN_00477720(int *param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  bool bVar7;
  
  iVar3 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x14);
  if (iVar3 != 0) {
    FUN_00476660();
  }
  iVar3 = FUN_00477810();
  if (iVar3 != 0) {
    FUN_00476ec0();
    param_1[0x61] = *(int *)(iVar3 + 0x174);
    (**(code **)(*param_1 + 0xa0))();
  }
  piVar2 = (int *)param_1[0x3c];
  iVar3 = 0;
  param_1[0x3e] = (int)piVar2;
  if ((piVar2 != (int *)0x0) && (iVar5 = *piVar2, iVar5 != 0)) {
    do {
      if (*(undefined4 **)(iVar5 + 0x3c) != (undefined4 *)0x0) {
        pbVar6 = DAT_007ce64c;
        if (DAT_007ce64c == (byte *)0x0) {
          pbVar6 = &DAT_005ea438;
        }
        pbVar4 = (byte *)**(undefined4 **)(iVar5 + 0x3c);
        if (pbVar4 == (byte *)0x0) {
          pbVar4 = &DAT_005ea438;
        }
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_004777c9:
            iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_004777ce;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_004777c9;
          pbVar4 = pbVar4 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_004777ce:
        if (iVar5 == 0) {
          param_1[0x5d] = iVar3;
        }
      }
      iVar3 = iVar3 + 1;
      if (param_1[0x3e] == 0) break;
      piVar2 = *(int **)(param_1[0x3e] + 4);
      param_1[0x3e] = (int)piVar2;
      if ((piVar2 == (int *)0x0) || (iVar5 = *piVar2, iVar5 == 0)) break;
    } while( true );
  }
  FUN_0048f640();
  return;
}


