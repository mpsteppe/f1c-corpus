// Function: FUN_00540940 @ 00540940
// Strings:  [Error creating vertex buffer, Error creating vertex buffer]


undefined4 __thiscall FUN_00540940(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint local_8;
  
  iVar8 = param_2;
  puVar3 = operator_new(0x24);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[5] = 0;
    puVar3[4] = 0;
    puVar3[3] = 0;
    puVar3[2] = 0;
    puVar3[1] = 0;
    *puVar3 = 0;
    puVar3[7] = 0;
    puVar3[6] = 0;
    puVar3[8] = 0;
  }
  *(undefined4 **)(param_2 + 0x1c) = puVar3;
  *puVar3 = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(*(int *)(param_2 + 0x1c) + 0xc) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(*(int *)(param_2 + 0x1c) + 8) = 0x40;
  *(undefined4 *)(*(int *)(param_2 + 0x1c) + 4) = 0x4d2;
  puVar4 = operator_new(0x1c);
  if (puVar4 == (uint *)0x0) {
    puVar4 = (uint *)0x0;
  }
  else {
    puVar4[3] = 0;
    puVar4[2] = 0;
    puVar4[1] = 0;
    *puVar4 = 0;
    puVar4[5] = 0;
    puVar4[4] = 0;
    puVar4[6] = 0;
  }
  uVar9 = *(uint *)(param_2 + 0x38);
  *(uint **)(param_2 + 0x24) = puVar4;
  if ((uVar9 & 0x20) != 0) {
    uVar9 = uVar9 & 0xffffffdf | 2;
  }
  *puVar4 = uVar9;
  *(undefined4 *)(*(int *)(param_2 + 0x24) + 4) = *(undefined4 *)(param_2 + 0x10);
  if (*(int *)(param_1 + 0x13dc) == 0) {
    iVar8 = FUN_00540df0(*(undefined4 *)(param_2 + 0x1c));
    if (iVar8 != 0) {
      FUN_0053c590(0xffffffff,s_Error_creating_vertex_buffer_005dbd40);
      return 0xffffffff;
    }
    *(undefined4 *)(param_2 + 0x2c) = 0;
    iVar8 = FUN_00540fc0(*(undefined4 *)(param_2 + 0x24));
    if (iVar8 == 0) {
      *(undefined4 *)(param_2 + 0x30) = 0;
      return 0;
    }
    FUN_0053c590(0xffffffff,s_Error_creating_vertex_buffer_005dbd40);
    return 0xffffffff;
  }
  if ((*(byte *)(param_2 + 0x38) & 0x20) == 0) {
    param_2 = *(int *)(param_1 + 0x1150);
    local_8 = *(uint *)(param_1 + 0x1160);
    puVar3 = (undefined4 *)(param_1 + 0x1154);
  }
  else {
    param_2 = *(int *)(param_1 + 0x1158);
    local_8 = *(uint *)(param_1 + 0x1160);
    puVar3 = (undefined4 *)(param_1 + 0x115c);
  }
  iVar6 = *(int *)(iVar8 + 8);
  if (param_2 < iVar6) {
    param_2 = iVar6;
  }
  puVar1 = (undefined4 *)*puVar3;
  for (puVar5 = puVar1; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)puVar5[7]) {
    if (iVar6 <= (int)(puVar5[3] - puVar5[4])) goto LAB_00540b19;
  }
  if (puVar1 == (undefined4 *)0x0) {
    puVar5 = operator_new(0x24);
    if (puVar5 == (undefined4 *)0x0) {
      *puVar3 = 0;
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5[5] = 0;
      puVar5[4] = 0;
      puVar5[3] = 0;
      puVar5[2] = 0;
      puVar5[1] = 0;
      *puVar5 = 0;
      puVar5[7] = 0;
      puVar5[6] = 0;
      puVar5[8] = 0;
      *puVar3 = puVar5;
    }
  }
  else {
    for (puVar3 = (undefined4 *)puVar1[7]; puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)puVar3[7]) {
      puVar1 = puVar3;
    }
    puVar3 = operator_new(0x24);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[5] = 0;
      puVar3[4] = 0;
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      puVar3[7] = 0;
      puVar3[6] = 0;
      puVar3[8] = 0;
    }
    puVar1[7] = puVar3;
    puVar3[6] = puVar1;
    puVar5 = (undefined4 *)puVar1[7];
  }
  uVar2 = *(undefined4 *)(iVar8 + 0x38);
  puVar5[3] = param_2;
  *puVar5 = uVar2;
  puVar5[2] = 0x40;
  puVar5[1] = 0x4d2;
  iVar6 = FUN_00540df0(puVar5);
  if (iVar6 != 0) {
    return 0xffffffff;
  }
LAB_00540b19:
  *(undefined4 *)(*(int *)(iVar8 + 0x1c) + 0x20) = puVar5[8];
  *(undefined4 *)(iVar8 + 0x2c) = puVar5[4];
  puVar5[4] = puVar5[4] + *(int *)(iVar8 + 8);
  uVar9 = *(uint *)(iVar8 + 0x10);
  if ((int)local_8 < (int)uVar9) {
    local_8 = uVar9;
  }
  puVar4 = *(uint **)(param_1 + 0x1164);
  for (puVar7 = puVar4; puVar7 != (uint *)0x0; puVar7 = (uint *)puVar7[5]) {
    if ((int)uVar9 <= (int)(puVar7[1] - puVar7[2])) goto LAB_00540c17;
  }
  if (puVar4 == (uint *)0x0) {
    puVar7 = operator_new(0x1c);
    if (puVar7 == (uint *)0x0) {
      *(undefined4 *)(param_1 + 0x1164) = 0;
      puVar7 = (uint *)0x0;
    }
    else {
      puVar7[3] = 0;
      puVar7[2] = 0;
      puVar7[1] = 0;
      *puVar7 = 0;
      puVar7[5] = 0;
      puVar7[4] = 0;
      puVar7[6] = 0;
      *(uint **)(param_1 + 0x1164) = puVar7;
    }
  }
  else {
    for (puVar7 = (uint *)puVar4[5]; puVar7 != (uint *)0x0; puVar7 = (uint *)puVar7[5]) {
      puVar4 = puVar7;
    }
    puVar3 = operator_new(0x1c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[3] = 0;
      puVar3[2] = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      puVar3[5] = 0;
      puVar3[4] = 0;
      puVar3[6] = 0;
    }
    puVar4[5] = (uint)puVar3;
    puVar3[4] = puVar4;
    puVar7 = (uint *)puVar4[5];
  }
  uVar9 = *(uint *)(iVar8 + 0x38);
  if ((uVar9 & 0x20) != 0) {
    uVar9 = uVar9 & 0xffffffdf | 2;
  }
  *puVar7 = uVar9;
  puVar7[1] = local_8;
  iVar6 = FUN_00540fc0(puVar7);
  if (iVar6 != 0) {
    return 0xffffffff;
  }
LAB_00540c17:
  *(uint *)(*(int *)(iVar8 + 0x24) + 0x18) = puVar7[6];
  *(uint *)(iVar8 + 0x30) = puVar7[2];
  puVar7[2] = puVar7[2] + *(int *)(iVar8 + 0x10);
  return 0;
}


