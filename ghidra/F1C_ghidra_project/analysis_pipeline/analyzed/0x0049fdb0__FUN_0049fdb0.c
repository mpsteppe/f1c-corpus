// Function: FUN_0049fdb0 @ 0049fdb0
// Size (bytes): 251


void FUN_0049fdb0(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (((((DAT_007ce254 == '\0') && (cVar2 = FUN_00461db0(), cVar2 != '\0')) &&
       ((iVar3 = FUN_00461cd0(), iVar3 == 3 || (iVar3 = FUN_00462380(), 1 < iVar3)))) &&
      (((cVar2 = FUN_004636e0(), iVar3 = DAT_007ce244, cVar2 != '\0' ||
        (cVar2 = FUN_004636f0(), iVar3 = DAT_007ce248, cVar2 != '\0')) ||
       (cVar2 = FUN_004636a0(), iVar3 = DAT_007ce240, cVar2 != '\0')))) &&
     (iVar1 = DAT_005d6d64, iVar3 != 0)) {
    iVar3 = (int)(DAT_005d6d64 + (DAT_005d6d64 >> 0x1f & 7U)) >> 3;
    uVar4 = FUN_0049b200(0x8ffffff,0xffffffff,0);
    FUN_004dcdd0((DAT_005d6d60 - iVar3) + -4,iVar1 / 2 - iVar3 / 2,1,0);
    FUN_004dcd80(iVar3,iVar3);
    FUN_004dcf20(uVar4);
    FUN_004dcd60(0);
  }
  return;
}


