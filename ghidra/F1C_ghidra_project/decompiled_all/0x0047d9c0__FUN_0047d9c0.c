// Function: FUN_0047d9c0 @ 0047d9c0
// Strings:  [%s%s%s, Times, Drivers, PrevYear, Results]


void FUN_0047d9c0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_108;
  undefined2 local_107;
  undefined1 local_105;
  undefined1 local_100 [256];
  
  local_107 = 0;
  local_105 = 0;
  local_108 = DAT_005ea438;
  FUN_00489cb0();
  FUN_004894d0(&local_108);
  iVar1 = FUN_004c5840(0);
  if (((iVar1 != 0) && (iVar1 = FUN_005679c0(s_PrevYear_005c72c8), iVar1 != 0)) &&
     (iVar1 = FUN_005679c0(s_Results_005c72d4), iVar1 != 0)) {
    iVar1 = FUN_005679c0(s_Drivers_005c72b8);
    iVar2 = FUN_005679c0(s_Times_005c72b0);
    if ((iVar1 != 0) && (iVar2 != 0)) {
      iVar1 = FUN_00567980();
      iVar2 = FUN_00567980();
      if (iVar2 == iVar1) {
        iVar2 = 0;
        iVar1 = FUN_00567980();
        if (0 < iVar1) {
          do {
            iVar1 = thunk_FUN_0059d6a9(iVar2);
            iVar3 = thunk_FUN_0059d6a9(iVar2);
            if ((iVar1 != 0) && (iVar3 != 0)) {
              uVar4 = FUN_00567970();
              uVar4 = FUN_00567970(&local_108,uVar4);
              FUN_0058815f(local_100,s__s_s_s_005c6784,uVar4);
            }
            FUN_00489600(local_100,0,0,0,0);
            iVar2 = iVar2 + 1;
            iVar1 = FUN_00567980();
          } while (iVar2 < iVar1);
        }
      }
    }
  }
  return;
}


