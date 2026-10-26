// Function: FUN_00457b00 @ 00457b00
// Size (bytes): 91


void __thiscall FUN_00457b00(int param_1,char param_2)

{
  if ((*(char *)(param_1 + 0x9c) == '\0') && (param_2 == '\x01')) {
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined1 *)(param_1 + 0x9c) = 1;
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x20);
    return;
  }
  if ((*(char *)(param_1 + 0x9c) == '\x01') && (param_2 == '\0')) {
    FUN_00456130(param_1 + 0x90);
    *(undefined1 *)(param_1 + 0x9c) = 0;
  }
  return;
}


