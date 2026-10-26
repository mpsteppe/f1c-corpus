// Function: FUN_004c6810 @ 004c6810
// Size (bytes): 263


undefined4 * FUN_004c6810(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
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
      uVar1 = puVar7[1];
      puVar7[1] = 0;
      puVar6 = (undefined4 *)FUN_004c6810(param_1);
      puVar7 = (undefined4 *)FUN_004c6810(uVar1);
      if (puVar6 == (undefined4 *)0x0) {
        return puVar7;
      }
      if (puVar7 == (undefined4 *)0x0) {
        return puVar6;
      }
      cVar4 = FUN_004c5d30(*puVar7);
      if (cVar4 == '\0') {
        puVar2 = (undefined4 *)puVar7[1];
        puVar3 = puVar7;
        puVar9 = puVar6;
      }
      else {
        puVar3 = puVar6;
        puVar2 = puVar7;
        puVar9 = (undefined4 *)puVar6[1];
        puVar7 = puVar6;
      }
      do {
        if (puVar9 == (undefined4 *)0x0) {
          if (puVar2 != (undefined4 *)0x0) {
            puVar3[1] = puVar2;
            return puVar7;
          }
LAB_004c68eb:
          puVar3[1] = 0;
          return puVar7;
        }
        if (puVar2 == (undefined4 *)0x0) {
          if (puVar9 != (undefined4 *)0x0) {
            puVar3[1] = puVar9;
            return puVar7;
          }
          goto LAB_004c68eb;
        }
        cVar4 = FUN_004c5d30(*puVar2);
        if (cVar4 == '\0') {
          puVar6 = (undefined4 *)puVar2[1];
          puVar8 = puVar2;
        }
        else {
          puVar8 = puVar9;
          puVar6 = puVar2;
          puVar9 = (undefined4 *)puVar9[1];
        }
        puVar3[1] = puVar8;
        puVar3 = puVar8;
        puVar2 = puVar6;
      } while( true );
    }
  }
  return param_1;
}


