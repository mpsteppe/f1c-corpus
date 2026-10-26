// Function: FUN_0054d030 @ 0054d030
// Size (bytes): 78


undefined4 __fastcall FUN_0054d030(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x14) & 0x8000000) != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x118)) {
      iVar1 = 0;
      do {
        FUN_00540cb0(*(int *)(param_1 + 0x11c) + iVar1);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x40;
      } while (iVar2 < *(int *)(param_1 + 0x118));
    }
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xf7ffffff;
  }
  return 0;
}


