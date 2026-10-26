// Function: FUN_004c5840 @ 004c5840
// Strings:  [SeasonRaces]


undefined4 FUN_004c5840(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00568210(s_SeasonRaces_005d31c8);
  if (iVar1 != 0) {
    if (param_1 != 0) {
      uVar2 = FUN_005679c0();
      return uVar2;
    }
    if (DAT_008ac490 != 0) {
      uVar2 = FUN_005679c0();
      return uVar2;
    }
  }
  return 0;
}


