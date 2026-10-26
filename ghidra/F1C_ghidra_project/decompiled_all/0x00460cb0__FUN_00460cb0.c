// Function: FUN_00460cb0 @ 00460cb0
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, ** Marking slot %d as unused, couldn't find nodeid %d in player list (et %8.3f)]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00460cb0(int param_1,char param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  *(undefined4 *)(param_1 + 0x3e14) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x3c74);
  iVar4 = 0x68;
  do {
    puVar2[0x69] = 0xffffffff;
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_0057a800();
  if ((param_2 != '\0') && (*(int *)(param_1 + 0x3e14) < 0x68)) {
    iVar4 = 0x68 - *(int *)(param_1 + 0x3e14);
    do {
      FUN_00461480();
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (*(int *)(param_1 + 0x3fc4) != 3) {
    iVar4 = 0;
    piVar6 = (int *)(param_1 + 0x1d4);
    do {
      if (*piVar6 != -1) {
        iVar3 = 0;
        if (0 < *(int *)(param_1 + 0x3e14)) {
          piVar5 = (int *)(param_1 + 0x3c74);
          do {
            if (*piVar5 == *piVar6) goto LAB_00460db7;
            iVar3 = iVar3 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar3 < *(int *)(param_1 + 0x3e14));
        }
        if ((DAT_007c569c != 5) &&
           (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1289),
           cVar1 != '\0')) {
          FUN_004d7aa0(&DAT_008ad25c,s____Marking_slot__d_as_unused__co_005c6098,iVar4,*piVar6);
        }
        *piVar6 = -1;
      }
LAB_00460db7:
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 < 0x68);
  }
  return;
}


