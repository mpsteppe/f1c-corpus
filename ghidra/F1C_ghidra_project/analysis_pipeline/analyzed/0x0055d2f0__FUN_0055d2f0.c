// Function: FUN_0055d2f0 @ 0055d2f0
// Size (bytes): 44


void __thiscall FUN_0055d2f0(uint *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = *param_1 & 0xffffff7f;
  }
  else {
    uVar1 = *param_1 | 0x80;
  }
  *param_1 = uVar1;
  FUN_005416a0(param_1,param_1[1],1);
  return;
}


