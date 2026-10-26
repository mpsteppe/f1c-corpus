// Function: FUN_00589898 @ 00589898
// Size (bytes): 59


uint FUN_00589898(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  
  FUN_0058c1b1(param_2);
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = FUN_0058cf35(param_1,param_2);
  }
  else {
    uVar2 = param_1 & 0xff;
    *(undefined1 *)*param_2 = (undefined1)param_1;
    *param_2 = *param_2 + 1;
  }
  FUN_0058c203(param_2);
  return uVar2;
}


