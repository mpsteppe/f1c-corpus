// Function: FUN_0058ef5f @ 0058ef5f
// Size (bytes): 36


undefined4 FUN_0058ef5f(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  do {
    *param_1 = *param_1 + 1;
    uVar1 = FUN_0058ef2e(param_2);
    iVar2 = FUN_00589bf3(uVar1);
  } while (iVar2 != 0);
  return uVar1;
}


