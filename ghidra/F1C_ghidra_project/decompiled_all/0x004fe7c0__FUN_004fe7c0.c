// Function: FUN_004fe7c0 @ 004fe7c0
// Strings:  [Weather]


undefined4 FUN_004fe7c0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00567a00();
  FUN_00567f40(param_1,0);
  iVar1 = FUN_00568210(s_Weather_005d173c);
  if (iVar1 == 0) {
    FUN_00567a30();
    return 0xffffffff;
  }
  uVar2 = FUN_004fe350(iVar1);
  FUN_00567a30();
  return uVar2;
}


