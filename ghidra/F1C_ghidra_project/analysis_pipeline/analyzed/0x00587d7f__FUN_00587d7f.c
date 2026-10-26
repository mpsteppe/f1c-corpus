// Function: FUN_00587d7f @ 00587d7f
// Size (bytes): 49


undefined4 FUN_00587d7f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0058c5ac();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_0058c43c(param_1,param_2,param_3,iVar1);
  FUN_0058c203(iVar1);
  return uVar2;
}


