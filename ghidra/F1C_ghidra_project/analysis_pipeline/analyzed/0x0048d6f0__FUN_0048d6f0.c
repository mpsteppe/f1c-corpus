// Function: FUN_0048d6f0 @ 0048d6f0
// Size (bytes): 68


undefined4 __thiscall
FUN_0048d6f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xec) != 0) {
    iVar1 = FUN_004862c0();
    if (iVar1 != 0) {
      FUN_00498560(iVar1);
    }
    uVar2 = FUN_00488be0(param_2,param_3,param_4,param_5);
    return uVar2;
  }
  return 0;
}


