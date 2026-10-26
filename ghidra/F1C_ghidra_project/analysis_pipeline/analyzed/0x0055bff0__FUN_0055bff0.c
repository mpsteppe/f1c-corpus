// Function: FUN_0055bff0 @ 0055bff0
// Size (bytes): 65


undefined4 __thiscall
FUN_0055bff0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  if (param_1[param_2 + 2] != 0) {
    iVar1 = FUN_0055bd20(param_3,param_4,param_5,param_6,param_7);
    if (iVar1 == 0) {
      *param_1 = param_2;
      return 0;
    }
  }
  return 0xffffffff;
}


