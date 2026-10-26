// Function: FUN_00558b30 @ 00558b30
// Size (bytes): 296


void __thiscall FUN_00558b30(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  
  if (((0 < *(int *)(param_1 + 0x30)) && (param_2 < *(int *)(param_1 + 0x2c))) &&
     (puVar5 = (uint *)(param_2 * 0x80 + *(int *)(param_1 + 0x34)),
     (*(byte *)(param_2 * 0x80 + *(int *)(param_1 + 0x34)) & 0x40) != 0)) {
    if (*(char *)(param_1 + 0x20) < '\0') {
      if (*(uint **)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4) != puVar5) {
        FUN_00558d10(0);
        iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0x20);
        if (iVar1 != 0) {
          iVar2 = *(int *)(param_1 + 0x24);
          puVar3 = (undefined4 *)(puVar5[1] * iVar2 * 0x40 + iVar1);
          puVar4 = (undefined4 *)
                   (*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4)
                            + 4) * iVar2 * 0x40 + iVar1);
          param_2 = 0;
          if (0 < iVar2) {
            do {
              *puVar3 = *puVar4;
              puVar3[1] = puVar4[1];
              puVar3[2] = puVar4[2];
              puVar3[6] = puVar4[6];
              puVar3 = puVar3 + 0x10;
              puVar4 = puVar4 + 0x10;
              param_2 = param_2 + 1;
            } while (param_2 < *(int *)(param_1 + 0x24));
          }
        }
        *(uint *)(*(int *)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4) + 4) =
             puVar5[1];
        *(undefined4 *)(*(int *)(param_1 + 0x3c) + puVar5[1] * 4) =
             *(undefined4 *)(*(int *)(param_1 + 0x3c) + -4 + *(int *)(param_1 + 0x30) * 4);
        *puVar5 = *puVar5 & 0xffffffbf;
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
        return;
      }
    }
    else {
      if (puVar5[0x1e] != 0) {
        *(uint *)(puVar5[0x1e] + 0x7c) = puVar5[0x1f];
      }
      if (puVar5[0x1f] != 0) {
        *(uint *)(puVar5[0x1f] + 0x78) = puVar5[0x1e];
      }
      if (puVar5[0x1e] == 0) {
        *(uint *)(param_1 + 0x38) = puVar5[0x1f];
      }
      puVar5[0x1e] = 0;
      puVar5[0x1f] = 0;
    }
    *puVar5 = *puVar5 & 0xffffffbf;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
  }
  return;
}


