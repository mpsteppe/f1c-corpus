// Function: FUN_004a5c40 @ 004a5c40
// Size (bytes): 60


undefined4 __fastcall FUN_004a5c40(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_005c329c) {
    do {
      iVar1 = (&DAT_007c54f0)[iVar2];
      if ((*(int *)(iVar1 + 0x48a4) == *(int *)(*param_1 + 0x48a4)) && (iVar1 != *param_1)) {
        return *(undefined4 *)(iVar1 + 0x3450);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005c329c);
  }
  return 0;
}


