// Function: FUN_004da990 @ 004da990
// Size (bytes): 43


int __fastcall FUN_004da990(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (0 < DAT_005c329c) {
    do {
      if (*(int *)(param_1 + 0x24) <= *(int *)((&DAT_007c54f0)[iVar2] + 0x403c)) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005c329c);
  }
  return iVar1;
}


