// Function: FUN_004133b0 @ 004133b0
// Size (bytes): 285


/* WARNING: Removing unreachable block (ram,0x004134b9) */

undefined4 FUN_004133b0(undefined4 *param_1,int param_2,undefined4 param_3,char param_4)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  undefined4 uVar7;
  bool bVar8;
  
  iVar2 = FUN_00415680(param_3);
  if (iVar2 != 0) {
    if (param_2 == 0) {
      puVar5 = (undefined4 *)(iVar2 + 0xc);
      if (param_4 == '\0') {
        puVar5 = (undefined4 *)(iVar2 + 0x20);
      }
    }
    else {
      if (param_2 != 1) goto LAB_00413426;
      puVar5 = (undefined4 *)(iVar2 + 0x5c);
      if (param_4 == '\0') {
        puVar5 = (undefined4 *)(iVar2 + 0x70);
      }
    }
    puVar3 = (undefined1 *)*puVar5;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    param_1[2] = puVar5[2];
    param_1[3] = puVar5[3];
    *(undefined1 *)(param_1 + 4) = *(undefined1 *)(puVar5 + 4);
  }
LAB_00413426:
  FUN_00566650(&DAT_005ea438);
  pbVar6 = &DAT_005ea438;
  pbVar4 = (byte *)*param_1;
  if (pbVar4 == (byte *)0x0) {
    pbVar4 = &DAT_005ea438;
  }
  do {
    bVar1 = *pbVar4;
    bVar8 = bVar1 < *pbVar6;
    if (bVar1 != *pbVar6) {
LAB_0041348b:
      iVar2 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_00413490;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar4[1];
    bVar8 = bVar1 < pbVar6[1];
    if (bVar1 != pbVar6[1]) goto LAB_0041348b;
    pbVar4 = pbVar4 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar1 != 0);
  iVar2 = 0;
LAB_00413490:
  if ((((iVar2 == 0) && (param_1[2] == -1)) && (param_1[3] == -1)) &&
     (*(char *)(param_1 + 4) == '\0')) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar7 = 1;
  }
  return uVar7;
}


