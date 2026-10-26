// Function: FUN_004d2450 @ 004d2450
// Size (bytes): 72


void FUN_004d2450(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_005c329c) {
    while (*(int *)((&DAT_007c54f0)[iVar1] + 0x4064) != 0) {
      iVar1 = iVar1 + 1;
      if (DAT_005c329c <= iVar1) {
        return;
      }
    }
    if (*(int *)((&DAT_007c54f0)[iVar1] + 0x4064) != 3) {
      *(undefined4 *)((&DAT_007c54f0)[iVar1] + 0x4064) = 1;
    }
  }
  return;
}


