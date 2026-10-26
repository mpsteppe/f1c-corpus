// Function: FUN_00456f70 @ 00456f70
// Size (bytes): 59


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00456f70(int param_1,char param_2,int param_3,float param_4)

{
  float fVar1;
  
  fVar1 = _DAT_0059ef9c;
  if (param_3 == 1) {
    fVar1 = _DAT_0059efa0;
  }
  if (param_2 == '\0') {
    fVar1 = fVar1 * _DAT_0059e670;
  }
  FUN_00456fb0(fVar1 * param_4 + *(float *)(param_1 + 0xac));
  return;
}


