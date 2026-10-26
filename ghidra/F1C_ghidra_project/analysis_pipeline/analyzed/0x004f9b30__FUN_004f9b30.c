// Function: FUN_004f9b30 @ 004f9b30
// Size (bytes): 60


void FUN_004f9b30(char param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = FUN_004f9b20();
  uVar2 = 2 - (cVar1 != '\0');
  if ((param_1 != '\0') || (DAT_007ce254 != '\0')) {
    uVar2 = uVar2 | 4;
  }
  iVar3 = FUN_0055c060(uVar2);
  if (iVar3 == -2) {
    DAT_008afe72 = 1;
  }
  return;
}


