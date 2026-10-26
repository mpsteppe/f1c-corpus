// Function: FUN_004b5be0 @ 004b5be0
// Size (bytes): 87


void __thiscall FUN_004b5be0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x9ac) = param_2;
  switch(param_2) {
  case 0:
    *(undefined4 *)(param_1 + 0xf7c) = 0x3e2aaaab;
    return;
  case 1:
    *(undefined4 *)(param_1 + 0xf7c) = 0x3e000000;
    return;
  case 2:
    *(undefined4 *)(param_1 + 0xf7c) = 0x3dcccccd;
    return;
  case 3:
    *(undefined4 *)(param_1 + 0xf7c) = 0x3daaaaab;
    return;
  case 4:
    *(undefined4 *)(param_1 + 0xf7c) = 0x3d2aaaab;
  }
  return;
}


