// Function: FUN_004ded20 @ 004ded20
// Size (bytes): 131


void __fastcall FUN_004ded20(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004dd4c0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004dd4d0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


