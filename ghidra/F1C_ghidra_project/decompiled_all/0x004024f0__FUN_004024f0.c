// Function: FUN_004024f0 @ 004024f0
// Strings:  [Incomplete waypoint path, D:\dev\F1_1999_2002\Source\ai_db.cpp]


void __fastcall FUN_004024f0(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_70 [24];
  int local_58;
  undefined1 local_54 [24];
  int local_3c;
  undefined1 local_38 [24];
  undefined4 local_20;
  undefined1 local_1c [24];
  undefined4 local_4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x134) + 0x110);
  iVar4 = 0;
  do {
    if (iVar1 == 0) {
LAB_00402531:
      cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_ai_db_005be41c,0x347);
      if (cVar2 == '\0') {
        return;
      }
      FUN_004d7aa0(&DAT_008ad25c,s_Incomplete_waypoint_path_005be400);
      return;
    }
    if (iVar1 == *(int *)(param_1 + 0x134)) {
      if (iVar1 != 0) {
        FUN_004cf010(9);
        FUN_004cf010(10);
        FUN_0053ac70(2,0);
        iVar4 = iVar1;
        do {
          iVar3 = __ftol();
          iVar5 = iVar3 * -0x1000000 + 0xffffff;
          local_3c = iVar5;
          iVar3 = __ftol();
          local_58 = iVar3 * -0x1000000 + 0xffffff;
          if ((iVar5 != 0xffffff) || (local_58 != 0xffffff)) {
            FUN_00402220(iVar4,local_54,0);
            FUN_00402220(*(undefined4 *)(iVar4 + 0x110),local_70,0);
            FUN_004cefa0(9,local_54,local_70);
          }
          FUN_00402220(iVar4,local_1c,1);
          FUN_00402220(*(undefined4 *)(iVar4 + 0x110),local_38,1);
          local_4 = 0xffffff;
          local_20 = 0xffffff;
          FUN_004cefa0(10,local_1c,local_38);
          iVar4 = *(int *)(iVar4 + 0x110);
        } while (iVar4 != iVar1);
        FUN_0053ac70(1,0);
        return;
      }
      goto LAB_00402531;
    }
    iVar4 = iVar4 + 1;
    if (12000 < iVar4) {
      return;
    }
    iVar1 = *(int *)(iVar1 + 0x110);
  } while( true );
}


