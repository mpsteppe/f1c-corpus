// Function: FUN_00475920 @ 00475920
// Size (bytes): 179


void __fastcall FUN_00475920(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  bool bVar9;
  
  (**(code **)(*DAT_007cd8c0 + 0x1c))(3);
  uVar2 = FUN_0048d360();
  pbVar3 = (byte *)FUN_004693e0(uVar2);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0xf8)) {
    do {
      if ((iVar8 < 0) || (*(int *)(param_1 + 0xf4) <= iVar8)) {
LAB_00475980:
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = *(undefined4 **)(param_1 + 0xe8);
        for (iVar6 = iVar8; 0 < iVar6; iVar6 = iVar6 + -1) {
          if (puVar4 == (undefined4 *)0x0) goto LAB_00475980;
          puVar4 = (undefined4 *)puVar4[1];
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00475980;
        puVar4 = (undefined4 *)*puVar4;
      }
      pbVar7 = (byte *)*puVar4;
      pbVar5 = pbVar3;
      if (pbVar7 == (byte *)0x0) {
        pbVar7 = &DAT_005ea438;
      }
      do {
        bVar1 = *pbVar5;
        bVar9 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_004759b9:
          iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_004759be;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar9 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_004759b9;
        pbVar7 = pbVar7 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar6 = 0;
LAB_004759be:
      if (iVar6 == 0) {
        *(int *)(param_1 + 0xfc) = iVar8;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0xf8));
  }
  return;
}


