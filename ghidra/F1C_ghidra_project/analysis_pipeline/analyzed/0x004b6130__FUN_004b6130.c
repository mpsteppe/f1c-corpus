// Function: FUN_004b6130 @ 004b6130
// Size (bytes): 82


void __fastcall FUN_004b6130(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x9b0);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b46f0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x9b0) = 0;
    *(undefined4 *)(param_1 + 0x9b4) = 0;
  }
  return;
}


