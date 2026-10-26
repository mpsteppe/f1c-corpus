// Function: FUN_004f1b50 @ 004f1b50
// Size (bytes): 66


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f1b50(int param_1,char param_2)

{
  if (param_2 == '\0') {
    if (*(int *)(param_1 + 0x32bc) == 0) {
      _DAT_007c74f8 = 0;
    }
    return;
  }
  if (*(int *)(param_1 + 0x32bc) == 0) {
    _DAT_007c74f8 = 2;
    return;
  }
  *(undefined4 *)(param_1 + 0x34ec) = 0;
  *(undefined4 *)(param_1 + 0x34f0) = 0;
  *(undefined4 *)(param_1 + 0x34f4) = 0;
  return;
}


