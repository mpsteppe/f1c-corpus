// Function: FUN_0059d74e @ 0059d74e
// Strings:  [Recon Pit Closed, Recon Pit Open, RaceTime]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059d74e(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_005679c0(s_Recon_Pit_Open_005d1898);
  if (iVar1 != 0) {
    uVar2 = FUN_00567970();
    _DAT_007cec30 = FUN_00587ece(uVar2);
  }
  iVar1 = FUN_005679c0(s_Recon_Pit_Closed_005d183c);
  if (iVar1 != 0) {
    uVar2 = FUN_00567970();
    _DAT_007cec54 = FUN_00587ece(uVar2);
  }
  FUN_005679c0(s_RaceTime_005d2310);
  FUN_004b1375();
  return;
}


