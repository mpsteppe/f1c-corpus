// Function: FUN_00563020 @ 00563020
// Size (bytes): 92


int __fastcall
FUN_00563020(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (*param_1 != 0) {
    return 4;
  }
  iVar1 = FUN_00562d20();
  if (iVar1 == 0) {
    iVar1 = FUN_00563080();
    if (iVar1 == 0) {
      iVar1 = FUN_005630d0(param_4,param_5);
      if (iVar1 == 0) {
        param_1[0x1c] = 0;
        param_1[0x1d] = 0;
        if (param_2 == 0) {
          FUN_00563000();
        }
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


