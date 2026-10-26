// Function: FUN_0048d1a0 @ 0048d1a0
// Size (bytes): 115


void __thiscall FUN_0048d1a0(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1[0xce] + (uint)(param_2 == 1) * 2 + -1;
  param_1[0xce] = uVar1;
  *(bool *)(param_1 + 0xcf) = param_2 == 1;
  if ((int)uVar1 < 0) {
    uVar1 = param_1[0xca] - 1U;
  }
  param_1[0xce] = uVar1;
  param_1[0xce] = uVar1 & ((int)(param_1[0xca] - 1U) < (int)uVar1) - 1;
  (**(code **)(*param_1 + 0x2c))(1);
  (**(code **)(*param_1 + 0xbc))(param_2,param_1[0xce]);
  return;
}


