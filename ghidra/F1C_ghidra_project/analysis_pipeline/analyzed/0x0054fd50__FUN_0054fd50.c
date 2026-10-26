// Function: FUN_0054fd50 @ 0054fd50
// Size (bytes): 80


void __thiscall FUN_0054fd50(int param_1,int param_2,int param_3)

{
  if (param_2 == 8) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffffb | 8;
    if (param_3 < 1) {
      *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
      return;
    }
  }
  else {
    if (param_2 != 4) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffff3;
      *(undefined4 *)(param_1 + 0x44) = 1;
      return;
    }
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffff7 | 4;
  }
  *(int *)(param_1 + 0x44) = param_3;
  return;
}


