// Function: FUN_004045f0 @ 004045f0
// Size (bytes): 178


void __fastcall FUN_004045f0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x150) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x150));
  }
  if (*(int *)(param_1 + 0x154) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x154));
  }
  if (*(int *)(param_1 + 0x158) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x158));
  }
  iVar1 = *(int *)(param_1 + 0x134);
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0xbf800000;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004b0170();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  return;
}


