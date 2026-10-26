// Function: FUN_0054e1a0 @ 0054e1a0
// Size (bytes): 159


void __thiscall
FUN_0054e1a0(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  ushort *puVar1;
  undefined4 *puVar2;
  
  if (param_2 < *(int *)(param_1 + 0x120)) {
    puVar1 = (ushort *)(*(int *)(param_1 + 0x124) + param_2 * 0x24);
    puVar2 = (undefined4 *)
             ((uint)*puVar1 * 0x30 +
             *(int *)(*(int *)(*(int *)(param_1 + 0x124) + 8 + param_2 * 0x24) + 0xc));
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *puVar2;
      param_3[1] = puVar2[1];
      param_3[2] = puVar2[2];
    }
    puVar2 = (undefined4 *)((uint)puVar1[1] * 0x30 + *(int *)(*(int *)(puVar1 + 4) + 0xc));
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *puVar2;
      param_4[1] = puVar2[1];
      param_4[2] = puVar2[2];
    }
    puVar2 = (undefined4 *)((uint)puVar1[2] * 0x30 + *(int *)(*(int *)(puVar1 + 4) + 0xc));
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *puVar2;
      param_5[1] = puVar2[1];
      param_5[2] = puVar2[2];
    }
  }
  return;
}


