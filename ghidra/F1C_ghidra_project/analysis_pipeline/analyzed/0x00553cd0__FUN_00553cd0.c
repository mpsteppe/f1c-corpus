// Function: FUN_00553cd0 @ 00553cd0
// Size (bytes): 47


void __fastcall
FUN_00553cd0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = param_1;
  if (param_2 < param_1) {
    iVar1 = param_2;
    param_2 = param_1;
  }
  FUN_005619f1(param_3 * param_5 + iVar1,(param_2 - iVar1) + 1,param_4,param_6);
  return;
}


