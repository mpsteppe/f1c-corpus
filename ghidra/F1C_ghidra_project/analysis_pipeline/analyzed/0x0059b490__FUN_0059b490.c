// Function: FUN_0059b490 @ 0059b490
// Size (bytes): 150


undefined4 __thiscall FUN_0059b490(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if ((uint)(param_1[1] * 8) < (uint)(param_1[4] + param_2)) {
    iVar1 = param_1[6];
    uVar5 = iVar1 + param_1[1];
    if (uVar5 < 0x1f400) {
      uVar3 = uVar5 * 8;
      do {
        if ((uint)(param_1[4] + param_2) <= uVar3) break;
        uVar5 = uVar5 + iVar1;
        uVar3 = uVar3 + iVar1 * 8;
      } while (uVar5 < 0x1f400);
    }
    puVar2 = operator_new(uVar5);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    uVar3 = param_1[1];
    puVar6 = (undefined4 *)*param_1;
    puVar7 = puVar2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    FUN_00587bcf(*param_1);
    *param_1 = puVar2;
    param_1[1] = uVar5;
  }
  return 1;
}


