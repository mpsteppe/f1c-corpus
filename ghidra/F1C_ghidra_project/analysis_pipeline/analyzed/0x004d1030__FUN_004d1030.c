// Function: FUN_004d1030 @ 004d1030
// Size (bytes): 165


void FUN_004d1030(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined1 local_80 [12];
  undefined1 local_74 [12];
  char acStack_68 [104];
  
  iVar4 = 0;
  puVar2 = &DAT_005f0f80;
  do {
    if (puVar2[-0x578] != -1) {
      cVar1 = FUN_004effd0();
      acStack_68[iVar4] = cVar1;
      puVar2[-1] = 0xffffffff;
      *puVar2 = 0xffffffff;
    }
    puVar2 = puVar2 + 0x1230;
    iVar4 = iVar4 + 1;
  } while ((int)puVar2 < 0x7c9d80);
  iVar4 = 0;
  puVar3 = &DAT_005ec6d8;
  do {
    if (*(int *)(puVar3 + 13000) != -1) {
      FUN_004d1140(puVar3,local_74,local_80);
      if (acStack_68[iVar4] != '\0') {
        FUN_004ef7c0(local_74,local_80);
      }
    }
    puVar3 = puVar3 + 0x48c0;
    iVar4 = iVar4 + 1;
  } while ((int)puVar3 < 0x7c54d8);
  FUN_004d1670();
  return;
}


