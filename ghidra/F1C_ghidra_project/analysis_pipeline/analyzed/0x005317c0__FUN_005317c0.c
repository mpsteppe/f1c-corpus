// Function: FUN_005317c0 @ 005317c0
// Size (bytes): 109


void FUN_005317c0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  FUN_004b0170();
  puVar3 = &DAT_008b1924;
  iVar6 = 0;
  do {
    iVar5 = 0;
    puVar4 = puVar3;
    do {
      iVar1 = iVar5 - iVar6;
      iVar5 = iVar5 + 0x40;
      puVar3 = puVar4 + 8;
      puVar7 = (undefined4 *)((int)&DAT_005b6f0a + iVar1 + 2);
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar4 = puVar3;
    } while (iVar5 < 0x381);
    iVar6 = iVar6 + 2;
  } while (iVar6 < 0x20);
  iVar6 = 0;
  do {
    iVar5 = 0;
    puVar4 = puVar3;
    do {
      iVar1 = iVar5 - iVar6;
      iVar5 = iVar5 + 0x40;
      puVar3 = puVar4 + 8;
      puVar7 = (undefined4 *)((int)&DAT_005b730a + iVar1 + 2);
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar4 = puVar3;
    } while (iVar5 < 0x401);
    iVar6 = iVar6 + 2;
  } while (iVar6 < 0x20);
  return;
}


