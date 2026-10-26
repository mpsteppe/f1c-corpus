// Function: FUN_00589fcc @ 00589fcc
// Size (bytes): 49


uint FUN_00589fcc(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  
  FUN_0058c1b1(param_1);
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_0058c255(param_1);
  }
  else {
    uVar2 = (uint)*(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
  }
  FUN_0058c203(param_1);
  return uVar2;
}


