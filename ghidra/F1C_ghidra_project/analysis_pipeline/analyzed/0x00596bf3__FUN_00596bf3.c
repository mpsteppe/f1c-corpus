// Function: FUN_00596bf3 @ 00596bf3
// Size (bytes): 45


undefined4 FUN_00596bf3(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_3 == 10) && (param_1 < 0)) {
    uVar1 = 1;
    param_3 = 10;
  }
  else {
    uVar1 = 0;
  }
  FUN_00596c20(param_1,param_2,param_3,uVar1);
  return param_2;
}


