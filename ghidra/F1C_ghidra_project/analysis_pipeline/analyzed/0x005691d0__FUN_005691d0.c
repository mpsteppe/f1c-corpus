// Function: FUN_005691d0 @ 005691d0
// Size (bytes): 162


void __thiscall FUN_005691d0(int param_1,undefined4 param_2)

{
  FUN_0056bd40(param_2);
  FUN_005692a0();
  *(double *)(param_1 + 0x7c) =
       *(double *)(param_1 + 0xec) * *(double *)(param_1 + 0x94) +
       *(double *)(param_1 + 0xf4) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0xfc) * *(double *)(param_1 + 0xa4);
  *(double *)(param_1 + 0x84) =
       *(double *)(param_1 + 0x104) * *(double *)(param_1 + 0x94) +
       *(double *)(param_1 + 0x10c) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0x114) * *(double *)(param_1 + 0xa4);
  *(double *)(param_1 + 0x8c) =
       *(double *)(param_1 + 0x11c) * *(double *)(param_1 + 0x94) +
       *(double *)(param_1 + 0x124) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 300) * *(double *)(param_1 + 0xa4);
  return;
}


