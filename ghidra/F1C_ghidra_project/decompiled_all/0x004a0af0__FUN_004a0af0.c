// Function: FUN_004a0af0 @ 004a0af0
// Strings:  [Game Filter]


void FUN_004a0af0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0x17);
  if (iVar1 != 0) {
    uVar2 = FUN_005681f0(s_Game_Filter_005c7130);
    FUN_00476f90(uVar2);
  }
  return;
}


