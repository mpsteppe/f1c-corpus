// Function: FUN_0058babb @ 0058babb
// Size (bytes): 78


int FUN_0058babb(char *param_1,undefined4 param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  size_t sVar3;
  
  sVar1 = _strlen(param_1);
  FUN_0058c1b1(param_2);
  uVar2 = FUN_0058e41b(param_2);
  sVar3 = FUN_005886a7(param_1,1,sVar1,param_2);
  FUN_0058e4a8(uVar2,param_2);
  FUN_0058c203(param_2);
  return (sVar3 == sVar1) - 1;
}


