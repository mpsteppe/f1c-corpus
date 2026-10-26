// Function: FUN_00547240 @ 00547240
// Size (bytes): 62


void __thiscall FUN_00547240(int param_1,int param_2,int param_3)

{
  if ((0 < param_2) && (param_2 < 9)) {
    *(short *)(param_1 + 0xac) = (short)param_2;
  }
  if ((0 < param_3) && (param_3 < 9)) {
    *(short *)(param_1 + 0xae) = (short)param_3;
  }
  if ((param_2 != 2) || (param_3 != 1)) {
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x20;
  }
  return;
}


