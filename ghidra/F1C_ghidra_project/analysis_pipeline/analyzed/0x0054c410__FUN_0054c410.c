// Function: FUN_0054c410 @ 0054c410
// Size (bytes): 241


undefined4 __fastcall FUN_0054c410(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_00545f40();
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x118)) {
    iVar2 = 0;
    do {
      FUN_00547710(*(undefined4 *)(iVar2 + 4 + *(int *)(param_1 + 0x11c)));
      *(undefined4 *)(iVar2 + 4 + *(int *)(param_1 + 0x11c)) = 0;
      FUN_00540cb0(*(int *)(param_1 + 0x11c) + iVar2);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x40;
    } while (iVar1 < *(int *)(param_1 + 0x118));
  }
  iVar1 = *(int *)(param_1 + 0x13c);
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x24);
    FUN_005511a0();
    FUN_00587bcf(iVar1);
    iVar1 = iVar2;
  }
  iVar1 = *(int *)(param_1 + 0x110);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  if (*(int *)(param_1 + 0x144) != 0) {
    FUN_004b0170();
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  return 0;
}


