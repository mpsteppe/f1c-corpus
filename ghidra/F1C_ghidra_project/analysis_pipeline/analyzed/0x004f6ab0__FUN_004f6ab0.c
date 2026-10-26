// Function: FUN_004f6ab0 @ 004f6ab0
// Size (bytes): 57


void FUN_004f6ab0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_008af8f8;
  iVar2 = 0x2d;
  do {
    puVar1[-2] = 0;
    puVar1[-1] = 0xffffffff;
    FUN_00566650(&DAT_005ea438);
    *puVar1 = 0xffffffff;
    puVar1[1] = 0xffffffff;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1 = puVar1 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


