// Function: FUN_0055cc20 @ 0055cc20
// Size (bytes): 453


void __thiscall FUN_0055cc20(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_24c;
  undefined1 *puStack_248;
  int *piStack_244;
  undefined4 uStack_240;
  undefined1 *puStack_23c;
  int *piStack_238;
  undefined4 uStack_234;
  undefined1 *puStack_230;
  int *piStack_22c;
  undefined4 *puStack_228;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 auStack_1ec [3];
  undefined1 auStack_1e0 [52];
  undefined4 auStack_1ac [16];
  undefined4 auStack_16c [16];
  undefined4 auStack_12c [9];
  undefined1 auStack_108 [16];
  undefined1 auStack_f8 [12];
  undefined4 auStack_ec [16];
  undefined4 auStack_ac [6];
  undefined1 auStack_94 [28];
  undefined1 auStack_78 [12];
  undefined1 auStack_6c [108];
  
  piStack_22c = *(int **)(param_2 + 0x19c);
  puStack_228 = (undefined4 *)0x0;
  puStack_230 = (undefined1 *)0x55cc40;
  FUN_0055ca90();
  local_218 = *(undefined4 *)(param_2 + 0x68);
  local_210 = *(undefined4 *)(param_2 + 0x54);
  local_214 = *(undefined4 *)(param_2 + 100);
  local_20c = *(undefined4 *)(param_2 + 0x58);
  piStack_22c = (int *)param_1[0x440];
  puStack_228 = &local_218;
  local_208 = 0;
  local_204 = 0x3f800000;
  puStack_230 = (undefined1 *)0x55cc80;
  uVar1 = (**(code **)(*piStack_22c + 0xa0))();
  *param_1 = uVar1;
  if ((*(byte *)(param_2 + 0x80) & 0x10) == 0) {
    if (param_1[0x4e9] == 2) goto LAB_0055ccdf;
    piStack_238 = (int *)param_1[0x440];
    puStack_230 = (undefined1 *)0x2;
    uStack_234 = 0x16;
    param_1[0x4e9] = 2;
    puStack_23c = (undefined1 *)0x55ccd6;
    uVar1 = (**(code **)(*piStack_238 + 200))();
  }
  else {
    if (param_1[0x4e9] == 3) goto LAB_0055ccdf;
    piStack_238 = (int *)param_1[0x440];
    puStack_230 = (undefined1 *)0x3;
    uStack_234 = 0x16;
    param_1[0x4e9] = 3;
    puStack_23c = (undefined1 *)0x55ccb8;
    uVar1 = (**(code **)(*piStack_238 + 200))();
  }
  *param_1 = uVar1;
  param_1[0x45d] = param_1[0x45d] & 0xfffffffb;
LAB_0055ccdf:
  if (param_1[0x4f5] != 0) {
    piStack_238 = (int *)param_1[0x440];
    puStack_230 = auStack_108;
    uStack_234 = 0x100;
    puStack_23c = (undefined1 *)0x55cd09;
    uVar1 = (**(code **)(*piStack_238 + 0x98))();
    puStack_23c = auStack_94;
    *param_1 = uVar1;
    piStack_244 = (int *)param_1[0x440];
    uStack_240 = 3;
    puStack_248 = (undefined1 *)0x55cd24;
    uVar1 = (**(code **)(*piStack_244 + 0x98))();
    puStack_248 = auStack_1e0;
    *param_1 = uVar1;
    uStack_24c = 2;
    uVar1 = (**(code **)(*(int *)param_1[0x440] + 0x98))((int *)param_1[0x440]);
    puVar3 = auStack_12c;
    puVar4 = auStack_16c;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = auStack_ac;
    puVar4 = auStack_ec;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *param_1 = uVar1;
    puVar3 = auStack_1ec;
    puVar4 = auStack_1ac;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    thunk_FUN_0050cba3(auStack_6c,auStack_16c,auStack_1ac);
    thunk_FUN_0050cba3(&piStack_238,auStack_78,auStack_f8);
    thunk_FUN_0050cdec(&piStack_244,&piStack_244);
    uVar1 = (**(code **)(*(int *)param_1[0x440] + 0x13c))((int *)param_1[0x440],0,&uStack_24c,4);
    *param_1 = uVar1;
  }
  return;
}


