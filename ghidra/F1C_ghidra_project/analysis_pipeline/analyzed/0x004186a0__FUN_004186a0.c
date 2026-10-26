// Function: FUN_004186a0 @ 004186a0
// Size (bytes): 78


void FUN_004186a0(void)

{
  int extraout_EDX;
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0x14;
  do {
    FUN_004144d0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar2 = (undefined4 *)(extraout_EDX + 0xaf8);
  for (iVar1 = 0x219; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xbf800000;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(extraout_EDX + 0xae8) = 0;
  *(undefined1 *)(extraout_EDX + 0xae4) = 0;
  *(undefined4 *)(extraout_EDX + 0xaec) = 0xffffffff;
  *(undefined4 *)(extraout_EDX + 0x135c) = 0;
  return;
}


