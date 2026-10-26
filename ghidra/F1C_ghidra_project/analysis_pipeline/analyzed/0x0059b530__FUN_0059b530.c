// Function: FUN_0059b530 @ 0059b530
// Size (bytes): 140


undefined4 __fastcall FUN_0059b530(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  uVar2 = *(int *)(param_1 + 0x14) + 1;
  if (uVar1 < uVar2) {
    do {
      uVar1 = *(int *)(param_1 + 0x1c) + uVar1;
    } while (uVar1 < uVar2);
    puVar3 = operator_new(uVar1 * 4);
    if (puVar3 == (undefined2 *)0x0) {
      return 0;
    }
    puVar4 = puVar3;
    uVar2 = uVar1;
    if (-1 < (int)(uVar1 - 1)) {
      do {
        puVar4[1] = 0;
        *puVar4 = 0;
        uVar2 = uVar2 - 1;
        puVar4 = puVar4 + 2;
      } while (uVar2 != 0);
    }
    uVar2 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      do {
        uVar2 = uVar2 + 1;
        *(undefined4 *)(puVar3 + uVar2 * 2 + -2) =
             *(undefined4 *)(*(int *)(param_1 + 8) + -4 + uVar2 * 4);
      } while (uVar2 < *(uint *)(param_1 + 0x14));
    }
    FUN_00587bcf(*(undefined4 *)(param_1 + 8));
    *(undefined2 **)(param_1 + 8) = puVar3;
    *(uint *)(param_1 + 0xc) = uVar1;
  }
  return 1;
}


