// Function: FUN_00462e20 @ 00462e20
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, !!!!!  Could not find self in server's qualification view, setting self in last position (%d), --Set slot %d to place %d %s, (local), (local),        comparing NODEIDs (nodemap[%d]=%d,pos[%d]=%d)]


void __fastcall FUN_00462e20(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iStack_c;
  int iStack_8;
  
  bVar1 = false;
  iVar4 = FUN_00462300();
  iStack_c = 0;
  if ('\0' < *(char *)(*param_1 + 0x3fd9)) {
    iStack_8 = 0;
    do {
      iVar6 = 0x3e18;
      iVar7 = 0;
      do {
        if ((DAT_007c569c != 5) &&
           (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1a76),
           cVar3 != '\0')) {
          FUN_004d7aa0(&DAT_008ad25c,s_comparing_NODEIDs__nodemap__d____005c6318,iVar7,
                       *(undefined4 *)(iVar6 + *param_1),iStack_c,
                       *(undefined4 *)(iStack_8 + 0x3fda + *param_1));
        }
        if (*(int *)(iVar6 + *param_1) == *(int *)(iStack_8 + 0x3fda + *param_1)) {
          if (iVar4 == *(int *)(*param_1 + 0x3e18 + iVar7 * 4)) {
            bVar1 = true;
          }
          (&DAT_005f0730)[iVar7 * 0x1230] = iStack_c + 1;
          if ((DAT_007c569c != 5) &&
             (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1a7f),
             cVar3 != '\0')) {
            pcVar5 = s__local__005c6310;
            if (iVar4 != *(int *)(*param_1 + 0x3e18 + iVar7 * 4)) {
              pcVar5 = &DAT_005ea438;
            }
            FUN_004d7aa0(&DAT_008ad25c,s___Set_slot__d_to_place__d__s_005c62f0,iVar7,iStack_c + 1,
                         pcVar5);
          }
          break;
        }
        iVar6 = iVar6 + 4;
        iVar7 = iVar7 + 1;
      } while (iVar6 < 0x3fb8);
      iStack_8 = iStack_8 + 4;
      iStack_c = iStack_c + 1;
    } while (iStack_c < *(char *)(*param_1 + 0x3fd9));
    if (bVar1) {
      return;
    }
  }
  uVar2 = DAT_005c329c;
  FUN_004bc2f0(DAT_005c329c);
  FUN_004bc320();
  if ((DAT_007c569c != 5) &&
     (cVar3 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1a8a), cVar3 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_______Could_not_find_self_in_ser_005c6290,uVar2);
  }
  return;
}


