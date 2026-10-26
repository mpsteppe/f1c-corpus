
void FUN_004f6b00(void)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = &DAT_008afc74;
  iVar3 = 0x2d;
  do {
    piVar1 = (int *)(puVar2 + -0x14);
    puVar2 = puVar2 + -0x14;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

