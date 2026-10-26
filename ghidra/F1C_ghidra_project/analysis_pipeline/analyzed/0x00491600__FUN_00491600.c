// Function: FUN_00491600 @ 00491600
// Size (bytes): 119


void __thiscall FUN_00491600(short *param_1,int param_2,int param_3,short param_4,int param_5)

{
  short sVar1;
  
  if (param_1[1] < param_3) {
    param_1[3] = param_1[3] - ((short)param_3 - param_1[1]);
    param_1[1] = (short)param_3;
  }
  sVar1 = (short)param_2;
  if (*param_1 < param_2) {
    param_1[2] = param_1[2] - (sVar1 - *param_1);
    *param_1 = sVar1;
  }
  sVar1 = param_4 + 1 + sVar1;
  if (sVar1 < (short)(param_1[2] + *param_1 + 1)) {
    param_1[2] = sVar1 - *param_1;
  }
  if (param_3 + param_5 < (int)param_1[3] + (int)param_1[1]) {
    param_1[3] = (short)(param_3 + param_5) - param_1[1];
  }
  return;
}


