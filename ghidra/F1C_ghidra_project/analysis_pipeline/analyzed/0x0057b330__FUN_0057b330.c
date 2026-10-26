// Function: FUN_0057b330 @ 0057b330
// Size (bytes): 509


undefined4 __thiscall FUN_0057b330(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  u_short uVar4;
  undefined4 *puVar5;
  u_long uVar6;
  undefined4 *puVar7;
  void *pvVar8;
  undefined4 uVar9;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c7bb;
  if (param_2 == 0) {
    return 0;
  }
  ExceptionList = &local_c;
  *(undefined1 *)(param_1 + 4) = *(undefined1 *)(param_2 + 4);
  puVar7 = *(undefined4 **)(param_1 + 8);
  while (puVar7 != (undefined4 *)0x0) {
    puVar5 = (undefined4 *)puVar7[1];
    if (*(char *)(puVar7 + 2) != '\0') {
      FUN_00587bcf(*puVar7);
    }
    FUN_00587bcf(puVar7);
    puVar7 = puVar5;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar3 = *(int *)(param_1 + 0x18);
  while (iVar3 != 0) {
    iVar1 = *(int *)(iVar3 + 4);
    FUN_00582290();
    FUN_00587bcf(iVar3);
    iVar3 = iVar1;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  piVar2 = *(int **)(param_2 + 8);
  *(int **)(param_2 + 0x10) = piVar2;
  if ((piVar2 != (int *)0x0) && (puVar7 = (undefined4 *)*piVar2, puVar7 != (undefined4 *)0x0)) {
    while( true ) {
      puVar5 = operator_new(0x10);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *(undefined2 *)puVar5 = 2;
        uVar6 = htonl(0);
        puVar5[1] = uVar6;
        uVar4 = htons(0);
        *(u_short *)((int)puVar5 + 2) = uVar4;
      }
      *puVar5 = *puVar7;
      puVar5[1] = puVar7[1];
      puVar5[2] = puVar7[2];
      puVar5[3] = puVar7[3];
      puVar7 = operator_new(0xc);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = puVar5;
        puVar7[1] = 0;
        *(undefined1 *)(puVar7 + 2) = 1;
      }
      if (*(int *)(param_1 + 8) == 0) {
        *(undefined4 **)(param_1 + 8) = puVar7;
        *(undefined4 **)(param_1 + 0x10) = puVar7;
      }
      else {
        *(undefined4 **)(*(int *)(param_1 + 0xc) + 4) = puVar7;
      }
      *(undefined4 **)(param_1 + 0xc) = puVar7;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      if (*(int *)(param_2 + 0x10) == 0) break;
      puVar7 = *(undefined4 **)(*(int *)(param_2 + 0x10) + 4);
      *(undefined4 **)(param_2 + 0x10) = puVar7;
      if ((puVar7 == (undefined4 *)0x0) ||
         (puVar7 = (undefined4 *)*puVar7, puVar7 == (undefined4 *)0x0)) break;
    }
  }
  puVar7 = *(undefined4 **)(param_2 + 0x18);
  *(undefined4 **)(param_2 + 0x20) = puVar7;
  if (puVar7 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)*puVar7;
    while (puVar7 != (undefined4 *)0x0) {
      puVar5 = operator_new(4);
      *puVar5 = *puVar7;
      pvVar8 = operator_new(0xc);
      local_4 = 0;
      if (pvVar8 == (void *)0x0) {
        uVar9 = 0;
      }
      else {
        uVar9 = FUN_004bac20(puVar5,1);
      }
      local_4 = 0xffffffff;
      if (*(int *)(param_1 + 0x18) == 0) {
        *(undefined4 *)(param_1 + 0x18) = uVar9;
        *(undefined4 *)(param_1 + 0x20) = uVar9;
      }
      else {
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4) = uVar9;
      }
      *(undefined4 *)(param_1 + 0x1c) = uVar9;
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      puVar7 = (undefined4 *)FUN_00581780();
    }
  }
  ExceptionList = local_c;
  return 1;
}


