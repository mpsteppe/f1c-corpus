// Function: FUN_00563e80 @ 00563e80
// Size (bytes): 42


undefined4 __fastcall FUN_00563e80(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (-1 < param_2) {
    iVar1 = FUN_00563e70();
    if (param_2 < iVar1) {
      puVar2 = (undefined4 *)FUN_005648b0();
      return *puVar2;
    }
  }
  return 0;
}


