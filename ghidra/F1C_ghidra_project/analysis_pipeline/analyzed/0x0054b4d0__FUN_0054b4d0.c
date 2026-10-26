// Function: FUN_0054b4d0 @ 0054b4d0
// Size (bytes): 95


void __thiscall FUN_0054b4d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float10 fVar1;
  
  *(undefined4 *)(param_1 + 0x20) = param_2;
  *(undefined4 *)(param_1 + 0x24) = param_3;
  *(undefined4 *)(param_1 + 0x28) = param_4;
  fVar1 = (float10)FUN_0058957a();
  *(float *)(param_1 + 0x2c) = (float)fVar1;
  fVar1 = (float10)FUN_0058957a();
  *(float *)(param_1 + 0x30) = (float)fVar1;
  fVar1 = (float10)FUN_0058957a();
  *(float *)(param_1 + 0x34) = (float)fVar1;
  FUN_0054b330(0x40,0,0);
  return;
}


