// Function: FUN_004080f0 @ 004080f0
// Size (bytes): 228


undefined4 FUN_004080f0(int param_1)

{
  uint *puVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    FUN_00587f64(*(int *)(param_1 + 0xc),0,0);
    puVar1 = (uint *)(param_1 + 0x14);
    iVar2 = FUN_0058803f(puVar1,4,1,*(undefined4 *)(param_1 + 0xc));
    if (iVar2 != 0) {
      pvVar3 = operator_new(*puVar1 << 2);
      *(void **)(param_1 + 0x18) = pvVar3;
      uVar4 = 0;
      if (*puVar1 != 0) {
        do {
          *(undefined4 *)(*(int *)(param_1 + 0x18) + uVar4 * 4) = 0;
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar1);
      }
      uVar4 = 0;
      if (*puVar1 != 0) {
        do {
          iVar2 = FUN_0058803f(*(int *)(param_1 + 0x18) + uVar4 * 4,4,1,
                               *(undefined4 *)(param_1 + 0xc));
          if (iVar2 == 0) {
            FUN_0041a160(*(undefined4 *)(param_1 + 0xc));
            FUN_00587bcf(*(undefined4 *)(param_1 + 0x18));
            *(undefined4 *)(param_1 + 0x18) = 0;
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < *puVar1);
      }
      if (uVar4 != *puVar1) {
        return 1;
      }
      return 0;
    }
  }
  return 1;
}


