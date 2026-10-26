// Function: FUN_004f83b0 @ 004f83b0
// Size (bytes): 135


void __fastcall FUN_004f83b0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x694) != 0) {
    iVar1 = 0;
    do {
      FUN_004f8250(*(int *)(param_1 + 0x694) + iVar1);
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0xb4);
    FUN_00587bcf(*(undefined4 *)(param_1 + 0x694));
    *(undefined4 *)(param_1 + 0x694) = 0;
  }
  if (*(int *)(param_1 + 0x6d8) != 0) {
    iVar1 = 0;
    do {
      FUN_004f8250(*(int *)(param_1 + 0x6d8) + iVar1);
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0xb4);
    FUN_00587bcf(*(undefined4 *)(param_1 + 0x6d8));
    *(undefined4 *)(param_1 + 0x6d8) = 0;
  }
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


