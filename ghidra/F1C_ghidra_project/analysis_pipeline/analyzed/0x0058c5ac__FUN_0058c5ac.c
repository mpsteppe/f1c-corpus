// Function: FUN_0058c5ac @ 0058c5ac
// Size (bytes): 200


undefined4 * FUN_0058c5ac(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  FUN_0058dfea(2);
  iVar3 = 0;
  if (0 < DAT_008d5a40) {
    do {
      iVar1 = *(int *)(DAT_008d4a24 + iVar3 * 4);
      if (iVar1 == 0) {
        iVar3 = iVar3 * 4;
        pvVar2 = _malloc(0x38);
        *(void **)(iVar3 + DAT_008d4a24) = pvVar2;
        if (*(int *)(iVar3 + DAT_008d4a24) != 0) {
          InitializeCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_008d4a24) + 0x20));
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar3 + DAT_008d4a24) + 0x20));
          puVar4 = *(undefined4 **)(iVar3 + DAT_008d4a24);
LAB_0058c650:
          if (puVar4 != (undefined4 *)0x0) {
            puVar4[4] = 0xffffffff;
            puVar4[1] = 0;
            puVar4[3] = 0;
            puVar4[2] = 0;
            *puVar4 = 0;
            puVar4[7] = 0;
          }
        }
        break;
      }
      if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
        FUN_0058c1e0(iVar3,iVar1);
        iVar1 = *(int *)(DAT_008d4a24 + iVar3 * 4);
        if ((*(byte *)(iVar1 + 0xc) & 0x83) == 0) {
          puVar4 = *(undefined4 **)(DAT_008d4a24 + iVar3 * 4);
          goto LAB_0058c650;
        }
        FUN_0058c232(iVar3,iVar1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_008d5a40);
  }
  FUN_0058e04b(2);
  return puVar4;
}


