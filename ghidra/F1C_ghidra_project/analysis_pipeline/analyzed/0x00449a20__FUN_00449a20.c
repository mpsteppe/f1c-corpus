// Function: FUN_00449a20 @ 00449a20
// Size (bytes): 89


undefined4 __fastcall FUN_00449a20(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined1 local_24 [28];
  undefined4 local_8;
  
  iVar1 = FUN_00595ae2(param_1,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  iVar2 = FUN_0059b760(iVar1,local_24);
  if (iVar2 != 0) {
    FUN_0058c331(iVar1);
    return 0xffffffff;
  }
  FUN_0058c331(iVar1);
  return local_8;
}


