// Function: FUN_0057afa0 @ 0057afa0
// Size (bytes): 168


uint __thiscall FUN_0057afa0(int param_1,undefined4 *param_2)

{
  u_short uVar1;
  undefined4 *puVar2;
  u_long uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  *(undefined1 *)(param_1 + 4) = 0;
  puVar2 = operator_new(0x10);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *(undefined2 *)puVar2 = 2;
    uVar3 = htonl(0);
    puVar2[1] = uVar3;
    uVar1 = htons(0);
    *(u_short *)((int)puVar2 + 2) = uVar1;
  }
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = param_2[2];
  puVar2[3] = param_2[3];
  puVar4 = operator_new(0xc);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = puVar2;
    puVar4[1] = 0;
    *(undefined1 *)(puVar4 + 2) = 1;
  }
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 **)(param_1 + 8) = puVar4;
    *(undefined4 **)(param_1 + 0x10) = puVar4;
    *(undefined4 **)(param_1 + 0xc) = puVar4;
    uVar5 = *(int *)(param_1 + 0x14) + 1;
    *(uint *)(param_1 + 0x14) = uVar5;
    return uVar5 & 0xffffff00;
  }
  *(undefined4 **)(*(int *)(param_1 + 0xc) + 4) = puVar4;
  *(undefined4 **)(param_1 + 0xc) = puVar4;
  uVar5 = *(int *)(param_1 + 0x14) + 1;
  *(uint *)(param_1 + 0x14) = uVar5;
  return uVar5 & 0xffffff00;
}


