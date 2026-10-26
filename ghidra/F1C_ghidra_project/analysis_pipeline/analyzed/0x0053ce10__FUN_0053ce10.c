// Function: FUN_0053ce10 @ 0053ce10
// Size (bytes): 37


void FUN_0053ce10(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0053cbc0(param_1,param_2);
  if ((iVar1 == 0) && (param_1 != (int *)0x0)) {
    *(uint *)(*param_1 + 0x114) = *(uint *)(*param_1 + 0x114) | 8;
  }
  return;
}


