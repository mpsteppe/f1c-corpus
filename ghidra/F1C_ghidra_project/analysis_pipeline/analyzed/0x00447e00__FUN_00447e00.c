// Function: FUN_00447e00 @ 00447e00
// Size (bytes): 291


void __thiscall FUN_00447e00(int param_1,int param_2,int param_3)

{
  if (param_2 != *(int *)(param_1 + 0x1ef4)) {
    if (param_2 == -1) {
      *(undefined4 *)(param_1 + 0x1ef8) = 1;
    }
    else if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x1ef8) = 0;
    }
    else {
      *(uint *)(param_1 + 0x1ef8) = (uint)(*(int *)(param_1 + 0x1ef0) < param_2) * 2 + -1;
    }
    *(int *)(param_1 + 0x1ef4) = param_2;
    *(undefined4 *)(param_1 + 0x1ef0) = 0;
    if (*(int *)(param_1 + 0x1ef8) < 1) {
      *(undefined4 *)(param_1 + 0x1e7c) = *(undefined4 *)(param_1 + 0x1e94);
      *(undefined4 *)(param_1 + 0x1e80) = *(undefined4 *)(param_1 + 0x1e98);
      FUN_004f89a0();
      if (param_3 == 0) {
        *(undefined4 *)(param_1 + 0x34) = 2;
        *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x60);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 100);
        return;
      }
      if (param_3 == 4) {
        *(undefined4 *)(param_1 + 0x34) = 5;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1e7c) = *(undefined4 *)(param_1 + 0x1e84);
      *(undefined4 *)(param_1 + 0x1e80) = *(undefined4 *)(param_1 + 0x1e88);
      FUN_004f88a0();
      if (param_3 == 0) {
        *(undefined4 *)(param_1 + 0x34) = 3;
        *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x60);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 100);
        return;
      }
      if (param_3 == 4) {
        *(undefined4 *)(param_1 + 0x34) = 6;
        *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x60);
        *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 100);
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_1 + 100);
  }
  return;
}


