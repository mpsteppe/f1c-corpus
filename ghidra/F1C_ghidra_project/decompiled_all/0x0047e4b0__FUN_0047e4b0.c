// Function: FUN_0047e4b0 @ 0047e4b0
// Strings:  [%s%s%s, %s%s%s, %s%s%s, %s%s%s, RaceLaps, Lap Record, Circuit Length, First Grand Prix]


void FUN_0047e4b0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 local_104;
  undefined2 local_103;
  undefined1 local_101;
  undefined1 local_100 [256];
  
  local_103 = 0;
  local_101 = 0;
  local_104 = DAT_005ea438;
  iVar1 = FUN_004c5840(0);
  FUN_00489cb0();
  FUN_004894d0(&local_104);
  if (iVar1 != 0) {
    iVar1 = FUN_005679c0(s_First_Grand_Prix_005c74cc);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970();
      puVar4 = &local_104;
      uVar3 = FUN_00487010(2);
      FUN_0058815f(local_100,s__s_s_s_005c6784,uVar3,puVar4,uVar2);
      FUN_00489600(local_100,0,0,0,0);
    }
    iVar1 = FUN_005679c0(s_Circuit_Length_005c74bc);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970();
      puVar4 = &local_104;
      uVar3 = FUN_00487010(3);
      FUN_0058815f(local_100,s__s_s_s_005c6784,uVar3,puVar4,uVar2);
      FUN_00489600(local_100,0,0,0,0);
    }
    iVar1 = FUN_005679c0(s_Lap_Record_005c74b0);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970();
      puVar4 = &local_104;
      uVar3 = FUN_00487010(4);
      FUN_0058815f(local_100,s__s_s_s_005c6784,uVar3,puVar4,uVar2);
      FUN_00489600(local_100,0,0,0,0);
    }
    iVar1 = FUN_005679c0(s_RaceLaps_005c7444);
    if (iVar1 != 0) {
      uVar2 = FUN_00567970();
      puVar4 = &local_104;
      uVar3 = FUN_00487010(5);
      FUN_0058815f(local_100,s__s_s_s_005c6784,uVar3,puVar4,uVar2);
      FUN_00489600(local_100,0,0,0,0);
    }
  }
  return;
}


