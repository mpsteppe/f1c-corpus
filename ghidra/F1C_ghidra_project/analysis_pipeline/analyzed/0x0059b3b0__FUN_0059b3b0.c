// Function: FUN_0059b3b0 @ 0059b3b0
// Size (bytes): 209


undefined4 * __thiscall FUN_0059b3b0(undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  if ((uint)param_1[1] < (uint)param_2[1]) {
    FUN_00587bcf(*param_1);
    pvVar1 = operator_new(param_2[1]);
    *param_1 = pvVar1;
    param_1[1] = param_2[1];
  }
  if ((uint)param_1[3] < (uint)param_2[3]) {
    FUN_00587bcf(param_1[2]);
    iVar6 = param_2[3];
    puVar2 = operator_new(iVar6 * 4);
    if (puVar2 == (undefined2 *)0x0) {
      puVar2 = (undefined2 *)0x0;
    }
    else {
      puVar3 = puVar2;
      if (-1 < iVar6 + -1) {
        do {
          puVar3[1] = 0;
          *puVar3 = 0;
          iVar6 = iVar6 + -1;
          puVar3 = puVar3 + 2;
        } while (iVar6 != 0);
      }
    }
    param_1[2] = puVar2;
    param_1[3] = param_2[3];
  }
  uVar5 = param_2[1];
  puVar7 = (undefined4 *)*param_2;
  puVar8 = (undefined4 *)*param_1;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  puVar7 = (undefined4 *)param_2[2];
  puVar8 = (undefined4 *)param_1[2];
  for (uVar5 = param_2[5] & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  return param_1;
}


