// Function: FUN_00566b90 @ 00566b90
// Size (bytes): 62


bool __fastcall FUN_00566b90(int *param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  iVar1 = *param_1;
  if (param_1[4] == 0) {
    if (iVar1 != 0) {
      iVar1 = FUN_00587d02(iVar1);
      *param_1 = 0;
      return iVar1 == 0;
    }
  }
  else if (iVar1 != 0) {
    iVar1 = FUN_005355a0();
    bVar2 = iVar1 == 0;
    *param_1 = 0;
  }
  return bVar2;
}


