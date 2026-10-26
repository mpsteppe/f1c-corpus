// Function: FUN_0041ed30 @ 0041ed30
// Size (bytes): 100


int FUN_0041ed30(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = -1;
  iVar1 = FUN_004c2850();
  if (iVar1 != 0) {
    FUN_004c2850();
    iVar1 = FUN_004c11d0();
    if (iVar1 < 2) {
      return -1;
    }
    iVar2 = FUN_0041eb30();
    if (iVar2 == 0) {
      return -1;
    }
    if (0 < iVar1 + -1) {
      do {
        uVar4 = FUN_0041ed20();
        iVar3 = iVar3 + (int)uVar4;
      } while ((int)((ulonglong)uVar4 >> 0x20) + 1 < iVar1 + -1);
    }
  }
  return iVar3;
}


