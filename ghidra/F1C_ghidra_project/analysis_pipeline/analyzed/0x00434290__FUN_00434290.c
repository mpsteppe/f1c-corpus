// Function: FUN_00434290 @ 00434290
// Size (bytes): 387


undefined4 * FUN_00434290(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  bool bVar12;
  
  iVar5 = 0;
  puVar7 = param_1;
  if (param_1 != (undefined4 *)0x0) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      iVar5 = iVar5 + 1;
    } while (puVar7 != (undefined4 *)0x0);
    if (1 < iVar5) {
      iVar5 = iVar5 / 2 + -1;
      puVar7 = param_1;
      if (0 < iVar5) {
        do {
          iVar5 = iVar5 + -1;
          puVar7 = (undefined4 *)puVar7[1];
        } while (iVar5 != 0);
      }
      uVar2 = puVar7[1];
      puVar7[1] = 0;
      puVar6 = (undefined4 *)FUN_00434290(param_1);
      puVar7 = (undefined4 *)FUN_00434290(uVar2);
      if (puVar6 == (undefined4 *)0x0) {
        return puVar7;
      }
      if (puVar7 == (undefined4 *)0x0) {
        return puVar6;
      }
      pbVar8 = *(byte **)*puVar7;
      if (pbVar8 == (byte *)0x0) {
        pbVar8 = &DAT_005ea438;
      }
      pbVar10 = *(byte **)*puVar6;
      if (pbVar10 == (byte *)0x0) {
        pbVar10 = &DAT_005ea438;
      }
      do {
        bVar1 = *pbVar10;
        bVar12 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_0043433e:
          iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
          goto LAB_00434343;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar10[1];
        bVar12 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_0043433e;
        pbVar10 = pbVar10 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_00434343:
      if (iVar5 < 0) {
        puVar4 = puVar6;
        puVar3 = puVar7;
        puVar11 = (undefined4 *)puVar6[1];
        puVar7 = puVar6;
      }
      else {
        puVar3 = (undefined4 *)puVar7[1];
        puVar4 = puVar7;
        puVar11 = puVar6;
      }
      do {
        if (puVar11 == (undefined4 *)0x0) {
          if (puVar3 != (undefined4 *)0x0) {
            puVar4[1] = puVar3;
            return puVar7;
          }
LAB_004343e7:
          puVar4[1] = 0;
          return puVar7;
        }
        if (puVar3 == (undefined4 *)0x0) {
          if (puVar11 != (undefined4 *)0x0) {
            puVar4[1] = puVar11;
            return puVar7;
          }
          goto LAB_004343e7;
        }
        pbVar8 = *(byte **)*puVar3;
        if (pbVar8 == (byte *)0x0) {
          pbVar8 = &DAT_005ea438;
        }
        pbVar10 = *(byte **)*puVar11;
        if (pbVar10 == (byte *)0x0) {
          pbVar10 = &DAT_005ea438;
        }
        do {
          bVar1 = *pbVar10;
          bVar12 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_004343a5:
            iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
            goto LAB_004343aa;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar10[1];
          bVar12 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_004343a5;
          pbVar10 = pbVar10 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_004343aa:
        if (iVar5 < 0) {
          puVar9 = puVar11;
          puVar6 = puVar3;
          puVar11 = (undefined4 *)puVar11[1];
        }
        else {
          puVar6 = (undefined4 *)puVar3[1];
          puVar9 = puVar3;
        }
        puVar4[1] = puVar9;
        puVar4 = puVar9;
        puVar3 = puVar6;
      } while( true );
    }
  }
  return param_1;
}


