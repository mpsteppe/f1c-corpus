// Function: FUN_0042bc80 @ 0042bc80
// Size (bytes): 211


int FUN_0042bc80(void)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar1 = &DAT_005ec6d8;
  do {
    if (*(int *)(puVar1 + 13000) != -1) {
      (&DAT_007c54f0)[iVar5] = puVar1;
      iVar5 = iVar5 + 1;
    }
    puVar1 = puVar1 + 0x48c0;
  } while ((int)puVar1 < 0x7c54d8);
  if (iVar5 < 0x68) {
    puVar4 = &DAT_007c54f0 + iVar5;
    for (iVar3 = 0x68 - iVar5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    if (iVar5 < 0x68) {
      puVar4 = &DAT_007c54f0 + iVar5;
      do {
        puVar1 = &DAT_005ec6d8;
        do {
          puVar2 = &DAT_007c54f0;
          do {
            if ((undefined *)*puVar2 == puVar1) goto LAB_0042bcf2;
            puVar2 = puVar2 + 1;
          } while ((int)puVar2 < 0x7c5690);
          if (puVar1 != (undefined *)0x0) {
            *puVar4 = puVar1;
            break;
          }
LAB_0042bcf2:
          puVar1 = puVar1 + 0x48c0;
        } while ((int)puVar1 < 0x7c54d8);
        puVar4 = puVar4 + 1;
      } while ((int)puVar4 < 0x7c5690);
    }
  }
  iVar3 = 0;
  DAT_007c54dc = 0;
  DAT_007c54e4 = 0;
  if (0 < iVar5) {
    do {
      if ((&DAT_007c54f0)[iVar3] == DAT_007c54e0) {
        DAT_007c54dc = iVar3;
      }
      if ((&DAT_007c54f0)[iVar3] == DAT_007c54e8) {
        DAT_007c54e4 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar5);
  }
  return iVar5;
}


