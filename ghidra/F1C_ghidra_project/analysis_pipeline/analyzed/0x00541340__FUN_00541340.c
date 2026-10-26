// Function: FUN_00541340 @ 00541340
// Size (bytes): 215


undefined4 __thiscall FUN_00541340(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = operator_new(0x4c);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = puVar1 + 1;
    *puVar1 = 2;
    iVar3 = 2;
    puVar1 = puVar2;
    do {
      puVar1[5] = 0;
      puVar1[4] = 0;
      puVar1[3] = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
      *puVar1 = 0;
      puVar1[7] = 0;
      puVar1[6] = 0;
      puVar1[8] = 0;
      puVar1 = puVar1 + 9;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(undefined4 **)(param_1 + 0x114c) = puVar2;
  *puVar2 = 0x22;
  *(undefined4 *)(*(int *)(param_1 + 0x114c) + 0xc) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x114c) + 4) = 0x142;
  *(undefined4 *)(*(int *)(param_1 + 0x114c) + 8) = 0x18;
  *(undefined4 *)(*(int *)(param_1 + 0x114c) + 0x24) = 0x22;
  *(undefined4 *)(*(int *)(param_1 + 0x114c) + 0x30) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x114c) + 0x28) = 0x142;
  *(undefined4 *)(*(int *)(param_1 + 0x114c) + 0x2c) = 0x18;
  iVar3 = FUN_00540df0(*(undefined4 *)(param_1 + 0x114c));
  if ((iVar3 == 0) && (iVar3 = FUN_00540df0(*(int *)(param_1 + 0x114c) + 0x24), iVar3 == 0)) {
    return 0;
  }
  return 0xffffffff;
}


