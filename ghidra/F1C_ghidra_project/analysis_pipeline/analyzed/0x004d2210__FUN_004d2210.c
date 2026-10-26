// Function: FUN_004d2210 @ 004d2210
// Size (bytes): 65


void FUN_004d2210(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_005c329c) {
    do {
      if ((*(int *)((&DAT_007c54f0)[iVar1] + 13000) == 0) ||
         (*(int *)((&DAT_007c54f0)[iVar1] + 13000) == 1)) {
        FUN_004bc9b0(1,0);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_005c329c);
  }
  return;
}


