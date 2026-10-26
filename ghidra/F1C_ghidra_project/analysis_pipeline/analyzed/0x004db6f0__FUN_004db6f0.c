// Function: FUN_004db6f0 @ 004db6f0
// Size (bytes): 246


void FUN_004db6f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  char local_c [9];
  undefined1 local_3;
  
  uVar4 = 0xffff00;
  if (param_1 == -1) {
    iVar3 = FUN_00423a00(&DAT_005ccec4,&DAT_005ec4cc);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = &DAT_005ccec4 + iVar3;
        (&DAT_005ec4cc)[iVar3] = *pcVar1;
        iVar3 = iVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    _strncpy(local_c,&DAT_005ec4cc,9);
    local_3 = 0;
  }
  else if (param_1 == 0) {
    iVar3 = FUN_00423a00(&DAT_005c36fc,&DAT_005ec4cc);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = &DAT_005c36fc + iVar3;
        (&DAT_005ec4cc)[iVar3] = *pcVar1;
        iVar3 = iVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    _strncpy(local_c,&DAT_005ec4cc,9);
    local_3 = 0;
  }
  else {
    FUN_0058815f(local_c,&DAT_005c3280,param_1);
  }
  bVar2 = FUN_0049b7a0();
  if ((bVar2 & 0xf) == 0xf) {
    uVar4 = 0xff0000;
  }
  FUN_004d7e40(local_c,param_2,param_3,uVar4,2,0,0x3fa00000,0x3fc00000);
  return;
}


