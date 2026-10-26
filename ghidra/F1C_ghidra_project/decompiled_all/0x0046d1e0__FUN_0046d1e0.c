// Function: FUN_0046d1e0 @ 0046d1e0
// Strings:  [CHAMPIONSHIP START NEW SEASON WANING]


undefined4 FUN_0046d1e0(void)

{
  int iVar1;
  
  iVar1 = FUN_004c2850();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xb144) == 2)) {
    FUN_00497940(s_CHAMPIONSHIP_START_NEW_SEASON_WA_005c6b74,0xffffffff);
    return 0xffffffff;
  }
  return 0;
}


