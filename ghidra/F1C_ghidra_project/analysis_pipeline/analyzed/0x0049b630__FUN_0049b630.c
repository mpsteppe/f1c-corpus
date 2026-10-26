// Function: FUN_0049b630 @ 0049b630
// Size (bytes): 63


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0049b630(undefined4 param_1,float param_2,int *param_3,float *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = __ftol(param_1);
  iVar2 = __ftol(uVar1);
  *param_3 = iVar2;
  *param_4 = param_2 - (float)iVar2 * _DAT_0059f118;
  return;
}


