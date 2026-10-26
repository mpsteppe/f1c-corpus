// Function: FUN_00567900 @ 00567900
// Size (bytes): 61


int * __thiscall FUN_00567900(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = -1;
  param_1[4] = 0;
  param_1[5] = -1;
  param_1[6] = 0;
  param_1[7] = -1;
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if (param_2 != 0) {
    iVar1 = FUN_004979d0();
  }
  param_1[8] = iVar1;
  param_1[9] = 0;
  param_1[10] = 0;
  return param_1;
}


