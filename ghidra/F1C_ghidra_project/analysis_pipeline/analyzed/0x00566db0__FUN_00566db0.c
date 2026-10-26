// Function: FUN_00566db0 @ 00566db0
// Size (bytes): 64


undefined4 __thiscall FUN_00566db0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[4] != 0) {
    uVar2 = FUN_00535390(0);
    return uVar2;
  }
  iVar1 = FUN_00587f64(*param_1,param_2);
  if (iVar1 == 0) {
    return param_2;
  }
  return 0xffffffff;
}


