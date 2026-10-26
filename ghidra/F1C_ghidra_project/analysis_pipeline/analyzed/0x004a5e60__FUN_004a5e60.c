// Function: FUN_004a5e60 @ 004a5e60
// Size (bytes): 30


void __fastcall FUN_004a5e60(int param_1)

{
  *(undefined4 *)(param_1 + 0x184) = 4;
  *(undefined1 *)(param_1 + 0x180) = 1;
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_004a3fe0();
    return;
  }
  return;
}


