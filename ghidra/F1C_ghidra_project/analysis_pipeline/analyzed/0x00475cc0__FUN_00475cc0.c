// Function: FUN_00475cc0 @ 00475cc0
// Size (bytes): 108


void FUN_00475cc0(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  if (*param_2 != *param_3) {
    iVar1 = param_3[1];
    iVar2 = __ftol();
    *param_4 = param_1;
    param_4[1] = iVar1 - iVar2;
    return;
  }
  *param_4 = 10;
  param_4[1] = 10;
  return;
}


