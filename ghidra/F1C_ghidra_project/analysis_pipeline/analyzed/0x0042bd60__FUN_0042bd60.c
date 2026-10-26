// Function: FUN_0042bd60 @ 0042bd60
// Size (bytes): 54


void FUN_0042bd60(void)

{
  undefined *puVar1;
  int iVar2;
  
  DAT_007c5690 = 0;
  iVar2 = 0;
  puVar1 = &DAT_005ec6e4;
  do {
    FUN_004c6960(iVar2);
    FUN_004ef5a0(0xffffffff,0);
    puVar1 = puVar1 + 0x48c0;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < 0x7c54e4);
  return;
}


