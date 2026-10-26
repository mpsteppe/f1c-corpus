// Function: FUN_0059168f @ 0059168f
// Size (bytes): 152


float10 FUN_0059168f(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,
                    undefined4 param_5)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_005919da(param_1,&param_4,param_5);
  if (iVar1 == 0) {
    FUN_00591727();
  }
  iVar1 = FUN_00591cc6(param_1);
  if ((DAT_005e9ad0 == 0) && (iVar1 != 0)) {
    fVar2 = (float10)FUN_00591bf1(iVar1,param_2,param_3,0,param_4,param_5);
    return fVar2;
  }
  FUN_00591c79(iVar1);
  FUN_00591e66();
  return (float10)param_4;
}


