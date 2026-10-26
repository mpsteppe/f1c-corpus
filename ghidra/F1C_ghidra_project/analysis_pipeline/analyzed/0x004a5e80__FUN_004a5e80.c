// Function: FUN_004a5e80 @ 004a5e80
// Size (bytes): 27


void __fastcall FUN_004a5e80(int param_1)

{
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined1 *)(param_1 + 0x180) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_004a3fe0();
    return;
  }
  return;
}


