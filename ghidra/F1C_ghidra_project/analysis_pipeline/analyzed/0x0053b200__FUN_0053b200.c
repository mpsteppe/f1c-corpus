// Function: FUN_0053b200 @ 0053b200
// Size (bytes): 50


void __thiscall FUN_0053b200(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x58) = param_2;
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 100) = 0x3f800000;
  return;
}


