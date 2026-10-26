// Function: FUN_0044f6f0 @ 0044f6f0
// Size (bytes): 198


void __thiscall FUN_0044f6f0(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  switch(param_4) {
  case 0:
    param_1[0x2c] = param_5;
    return;
  case 1:
    param_1[0x2d] = param_5;
    return;
  case 2:
    param_1[0x2e] = param_5;
    return;
  case 3:
    param_1[0x2f] = param_1[0x2f] + param_5;
    return;
  }
  param_1[8] = (int)((float)(param_2 - param_1[4]) * (float)param_1[6]);
  param_1[4] = param_2;
  param_1[9] = (int)((float)(param_3 - param_1[5]) * (float)param_1[7]);
  if (param_2 < param_1[2]) {
    param_1[4] = param_1[2];
  }
  if (param_1[3] < param_1[4]) {
    param_1[4] = param_1[3];
  }
  param_1[5] = param_3;
  if (param_3 < *param_1) {
    param_1[5] = *param_1;
  }
  if (param_1[1] < param_1[5]) {
    param_1[5] = param_1[1];
  }
  param_1[10] = (int)((float)param_1[4] * (float)param_1[6]);
  param_1[0xb] = (int)((float)param_1[5] * (float)param_1[7]);
  return;
}


