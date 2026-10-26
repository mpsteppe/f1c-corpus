// Function: FUN_0056eb90 @ 0056eb90
// Size (bytes): 109


void __fastcall FUN_0056eb90(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *param_1) {
    iVar3 = 0;
    do {
      iVar1 = param_1[1] + iVar3;
      *(undefined4 *)(iVar1 + 0x134) = 0;
      *(undefined4 *)(iVar1 + 0x138) = 0;
      *(undefined4 *)(iVar1 + 0x13c) = 0;
      *(undefined4 *)(iVar1 + 0x140) = 0;
      *(undefined4 *)(iVar1 + 0x144) = 0;
      *(undefined4 *)(iVar1 + 0x148) = 0;
      *(undefined4 *)(iVar1 + 0x14c) = 0;
      *(undefined4 *)(iVar1 + 0x150) = 0;
      *(undefined4 *)(iVar1 + 0x154) = 0;
      *(undefined4 *)(iVar1 + 0x158) = 0;
      *(undefined4 *)(iVar1 + 0x15c) = 0;
      *(undefined4 *)(iVar1 + 0x160) = 0;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x244;
    } while (iVar2 < *param_1);
  }
  return;
}


