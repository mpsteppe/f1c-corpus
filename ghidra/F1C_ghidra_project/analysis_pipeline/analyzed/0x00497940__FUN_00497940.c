// Function: FUN_00497940 @ 00497940
// Size (bytes): 49


undefined4 FUN_00497940(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_004976c0(param_1);
    if (iVar1 != 0) {
      uVar2 = FUN_00497890(iVar1,param_2);
      return uVar2;
    }
  }
  return 0;
}


