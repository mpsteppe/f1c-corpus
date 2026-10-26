// Function: FUN_005631d0 @ 005631d0
// Size (bytes): 91


int __fastcall FUN_005631d0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_4) {
    do {
      FUN_005648b0();
      iVar1 = FUN_005644a0();
      if ((param_3 == iVar1) && (iVar1 = FUN_00563e70(), iVar1 == param_2)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_4);
  }
  return -1;
}


