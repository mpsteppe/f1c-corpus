// Function: FUN_004d24a0 @ 004d24a0
// Size (bytes): 46


undefined1 FUN_004d24a0(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 1;
  if (0 < DAT_005c329c) {
    while (*(int *)((&DAT_007c54f0)[iVar2] + 0x4064) != 0) {
      iVar2 = iVar2 + 1;
      if (DAT_005c329c <= iVar2) {
        return uVar1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


