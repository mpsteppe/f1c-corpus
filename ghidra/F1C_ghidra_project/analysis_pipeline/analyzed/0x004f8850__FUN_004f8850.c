// Function: FUN_004f8850 @ 004f8850
// Size (bytes): 74


void __thiscall
FUN_004f8850(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6)

{
  FUN_004f87c0(param_2,param_3,param_4,param_5);
  param_1 = param_2 * 0x20 + param_1;
  *(undefined1 *)(param_1 + 0xc4) = 1;
  *(undefined4 *)(param_1 + 200) = *param_6;
  *(undefined4 *)(param_1 + 0xcc) = param_6[1];
  *(undefined4 *)(param_1 + 0xd0) = param_6[2];
  return;
}


