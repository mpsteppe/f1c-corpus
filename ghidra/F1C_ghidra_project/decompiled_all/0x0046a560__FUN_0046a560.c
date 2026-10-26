// Function: FUN_0046a560 @ 0046a560
// Strings:  [%s%s%.1f, %s%s%.1f, %s%s%i, %s%s%i, %s%s%i, %s%s%i, %s%s%i, %s%s%i]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0046a560(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  double dVar6;
  undefined1 local_204;
  undefined2 local_203;
  undefined1 local_201;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  local_203 = 0;
  local_201 = 0;
  local_204 = DAT_005ea438;
  FUN_004b0b20(local_100,0x100);
  FUN_00489cb0();
  FUN_00566650();
  FUN_004894d0();
  iVar2 = *(int *)(param_1 + 0x44);
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    FUN_00434420();
    FUN_00587bcf(iVar2);
    iVar2 = iVar1;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_00486f30(s_Experience__Laps___005c6900,0xffffffff);
  FUN_00486f30(s_Starts__005c68f8,0xffffffff);
  FUN_00486f30(s_Avg__Starting_Position__005c68e0,0xffffffff);
  FUN_00486f30(s_Avg__Finish_Position__005c68c8,0xffffffff);
  FUN_00486f30(s_Pole_Positions__005c6888,0xffffffff);
  FUN_00486f30(s_Points__005c6880,0xffffffff);
  FUN_00486f30(s_Wins__005c6878,0xffffffff);
  FUN_00486f30(s_Lap_Records__005c69a8,0xffffffff);
  FUN_00486f30(s_Drivers_Champiionships__005c6990,0xffffffff);
  uVar5 = CONCAT44(DAT_007d2dd4,&local_204);
  uVar3 = FUN_00487010(0);
  FUN_0058815f(local_200,s__s_s_i_005c6858,uVar3,uVar5);
  FUN_00489600(local_200,0,0,0,0);
  uVar5 = CONCAT44(DAT_007d2dd8,&local_204);
  uVar3 = FUN_00487010(1);
  FUN_0058815f(local_200,s__s_s_i_005c6858,uVar3,uVar5);
  FUN_00489600(local_200,0,0,0,0);
  dVar6 = (double)_DAT_007d2df4;
  puVar4 = &local_204;
  uVar3 = FUN_00487010(2);
  FUN_0058815f(local_200,s__s_s__1f_005c684c,uVar3,puVar4,dVar6);
  FUN_00489600(local_200,0,0,0,0);
  dVar6 = (double)_DAT_007d2df8;
  puVar4 = &local_204;
  uVar3 = FUN_00487010(3);
  FUN_0058815f(local_200,s__s_s__1f_005c684c,uVar3,puVar4,dVar6);
  FUN_00489600(local_200,0,0,0,0);
  uVar5 = CONCAT44(DAT_007d2dec,&local_204);
  uVar3 = FUN_00487010(4);
  FUN_0058815f(local_200,s__s_s_i_005c6858,uVar3,uVar5);
  FUN_00489600(local_200,0,0,0,0);
  uVar5 = CONCAT44(DAT_007d2de0,&local_204);
  uVar3 = FUN_00487010(5);
  FUN_0058815f(local_200,s__s_s_i_005c6858,uVar3,uVar5);
  FUN_00489600(local_200,0,0,0,0);
  uVar5 = CONCAT44(DAT_007d2de8,&local_204);
  uVar3 = FUN_00487010(6);
  FUN_0058815f(local_200,s__s_s_i_005c6858,uVar3,uVar5);
  FUN_00489600(local_200,0,0,0,0);
  uVar5 = CONCAT44(DAT_007d2df0,&local_204);
  uVar3 = FUN_00487010(7);
  FUN_0058815f(local_200,s__s_s_i_005c6858,uVar3,uVar5);
  FUN_00489600(local_200,0,0,0,0);
  uVar5 = CONCAT44(DAT_007d2de4,&local_204);
  uVar3 = FUN_00487010(8);
  FUN_0058815f(local_200,s__s_s_i_005c6858,uVar3,uVar5);
  FUN_00489600(local_200,0,0,0,0);
  return;
}


