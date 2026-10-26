// Function: FUN_004dd4e0 @ 004dd4e0
// Size (bytes): 102


int FUN_004dd4e0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = FUN_0054c210();
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_0054c230(iVar4);
      if (*(float *)(iVar3 + 0xf4) == DAT_0059e440) {
        uVar1 = *(uint *)(iVar3 + 0x14);
        if ((uVar1 & 0x2000000) == 0) {
          iVar3 = 4 - (uint)((uVar1 & 0x40) != 0);
        }
        else {
          iVar3 = 2 - (uint)((uVar1 & 0x40) != 0);
        }
      }
      else {
        iVar3 = 0;
      }
      if (iVar5 < iVar3) {
        iVar5 = iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return iVar5;
}


