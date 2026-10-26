// Function: FUN_004f9310 @ 004f9310
// Strings:  [CUBE error : %s, D:\dev\F1_1999_2002\Source\vidman.cpp]


undefined4 FUN_004f9310(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  if (DAT_008afe68 == 0) {
    return 1;
  }
  uVar2 = (DAT_005ec4a4 == '\0') + 1;
  DAT_008afe7c = uVar2 & 1;
  if (DAT_005ec4b0 == 2) {
    uVar2 = uVar2 | 0x20;
  }
  else if (DAT_005ec4b0 == 3) {
    uVar2 = uVar2 | 0x100;
  }
  else if (DAT_005ec4b0 == 4) {
    uVar2 = uVar2 | 0x40;
  }
  else if (DAT_005ec4b0 == 6) {
    uVar2 = uVar2 | 0x400;
  }
  else if (DAT_005ec4b0 == 0x10) {
    uVar2 = uVar2 | 0x100000;
  }
  if (DAT_005ec4a6 != '\0') {
    uVar2 = uVar2 | 0x80;
  }
  DAT_008afe74 = param_1;
  iVar3 = FUN_0055bff0(DAT_008afe6c,DAT_005d6d60,DAT_005d6d64,DAT_005d6d68,uVar2,DAT_008afe78);
  if (iVar3 != 0) {
    FUN_0053c5b0(0,local_100);
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vidma_005d6dc4,0x1e4);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_CUBE_error____s_005d6db4,local_100);
    }
  }
  return 0;
}


