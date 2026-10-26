// Function: FUN_00410890 @ 00410890
// Size (bytes): 233


void __fastcall FUN_00410890(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      FUN_0040f130();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x24));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x30)) {
    do {
      FUN_0040f130();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x30));
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    do {
      FUN_0040f130();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x3c));
  }
  iVar1 = 0x1a0;
  if (0x1a0 < *(int *)(param_1 + 0x48)) {
    do {
      FUN_0040f130();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x48));
  }
  iVar1 = 0xd0;
  if (0xd0 < *(int *)(param_1 + 0x54)) {
    do {
      FUN_0040f130();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x54));
  }
  iVar1 = 0x340;
  if (0x340 < *(int *)(param_1 + 0x60)) {
    do {
      FUN_0040f130();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x60));
  }
  return;
}


