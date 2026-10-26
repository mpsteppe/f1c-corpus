// Function: FUN_004c0690 @ 004c0690
// Size (bytes): 342


uint __thiscall FUN_004c0690(undefined4 *param_1,int *param_2,int param_3)

{
  uint in_EAX;
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  
  if (*param_2 != 0) {
    if (param_3 != 0) {
      FUN_00566cf0(param_3);
      FUN_00566cf0(&DAT_005c30b4);
    }
    puVar1 = (undefined1 *)*param_1;
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    FUN_00566c30(param_2,s_Name___s__005d27f8,puVar1);
    puVar1 = (undefined1 *)param_1[2];
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    FUN_00566c30(param_2,s_VehFile___s__005d27e8,puVar1);
    puVar1 = (undefined1 *)param_1[4];
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    FUN_00566c30(param_2,s_RCDFile___s__005d27d8,puVar1);
    iVar3 = 0;
    piVar2 = param_1 + 6;
    do {
      if (*piVar2 < 0) break;
      FUN_00566c30(param_2,s_FinishPosition_2_2d__d_005d27c0,iVar3,*piVar2);
      FUN_00566c30(param_2,s_FinishPoints_2_2d__d_005d27a8,iVar3,piVar2[0x30]);
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < 0x30);
    FUN_00566c30(param_2,s_SeasonPoints__d_005d2794,param_1[0x66]);
    FUN_00566c30(param_2,s_PointsPosition__d_005d2780,param_1[0x67]);
    FUN_00566c30(param_2,s_PolesTaken__d_005d2770,param_1[0x68]);
    FUN_00566c30(param_2,s_OriginalGridPosition__d_005d2754,param_1[0x69]);
    FUN_00566c30(param_2,s_CurrentGridPosition__d_005d273c,param_1[0x6a]);
    FUN_00566c30(param_2,s_ControlType__d_005d272c,param_1[0x6b]);
    FUN_00566c30(param_2,s_Active__d_005d2720,*(char *)(param_1 + 0x6c) != '\0');
    in_EAX = FUN_00566c30(param_2,&DAT_005c30b4);
  }
  return in_EAX & 0xffffff00;
}


