// Function: FUN_00490b00 @ 00490b00
// Size (bytes): 135


int * __thiscall FUN_00490b00(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  FUN_004912f0();
  *param_1 = param_2;
  param_1[1] = 0;
  piVar1 = operator_new(param_2 * 0x10 + 4);
  if (piVar1 == (int *)0x0) {
    param_1[2] = 0;
    return param_1;
  }
  *piVar1 = param_2;
  piVar2 = piVar1 + 1;
  if (-1 < param_2 + -1) {
    do {
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      piVar2[3] = 0;
      param_2 = param_2 + -1;
      piVar2 = piVar2 + 4;
    } while (param_2 != 0);
  }
  param_1[2] = (int)(piVar1 + 1);
  return param_1;
}


