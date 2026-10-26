// Function: FUN_004d7050 @ 004d7050
// Size (bytes): 245


void __fastcall FUN_004d7050(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00566650(&DAT_005ea438);
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 8) = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    piVar3 = (int *)(iVar1 + iVar2 * 0x18);
    if (-1 < iVar2 + -1) {
      do {
        piVar3 = piVar3 + -6;
        FUN_004d6800();
        if (*piVar3 != 0) {
          FUN_00587bcf(*piVar3);
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_00414370();
        FUN_00414370();
        FUN_00414370();
        FUN_00414370();
        FUN_00414370();
        FUN_00414370();
        FUN_00414370();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  return;
}


