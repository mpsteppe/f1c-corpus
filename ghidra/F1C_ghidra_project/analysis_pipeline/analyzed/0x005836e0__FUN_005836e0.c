// Function: FUN_005836e0 @ 005836e0
// Size (bytes): 30


void __thiscall FUN_005836e0(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  param_1[1] = param_3;
  iVar1 = *param_1;
  param_1[2] = param_4;
  *param_1 = iVar1 + 1;
  *param_2 = iVar1 + 1;
  return;
}


