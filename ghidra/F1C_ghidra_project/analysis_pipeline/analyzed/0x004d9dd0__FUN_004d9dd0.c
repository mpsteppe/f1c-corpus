// Function: FUN_004d9dd0 @ 004d9dd0
// Size (bytes): 257


int FUN_004d9dd0(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char local_80 [127];
  undefined1 local_1;
  
  iVar2 = FUN_004d98a0();
  if (iVar2 == 0) {
    FUN_0058815f(local_80,&DAT_005ccef0,(int)DAT_005d4ae9);
    FUN_004d7e40(local_80,0x39c,0x35a,0xff0000,0,3,0x3f800000,0x3f800000);
    FUN_004d7e40(local_80,0x49c,0x35a,0xff00,1,3,0x3f800000,0x3f800000);
    iVar3 = FUN_00423a00(&DAT_005ea438,&DAT_005ec4cc);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = &DAT_005ea438 + iVar3;
        (&DAT_005ec4cc)[iVar3] = *pcVar1;
        iVar3 = iVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    _strncpy(local_80,&DAT_005ec4cc,0x7f);
    local_1 = 0;
    FUN_004d7e40(local_80,0x41c,0x35a,0xffff00,2,0,0x3f800000,0x3f800000);
  }
  return iVar2;
}


