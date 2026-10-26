// Function: FUN_004034d0 @ 004034d0
// Size (bytes): 98


void __fastcall FUN_004034d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x134);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x134) = 0;
    *(undefined4 *)(param_1 + 0x130) = 0;
    return;
  }
  iVar2 = *(int *)(iVar1 + -4);
  if (-1 < iVar2 + -1) {
    do {
      FUN_004b0170();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00587bcf(iVar1 + -4);
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  return;
}


