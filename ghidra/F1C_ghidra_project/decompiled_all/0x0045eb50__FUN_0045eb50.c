// Function: FUN_0045eb50 @ 0045eb50
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, *** Could not find name for nodeid %d]


undefined * __thiscall FUN_0045eb50(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x3e14)) {
    piVar3 = (int *)(param_1 + 0x3c74);
    do {
      if (*piVar3 == param_2) {
        return (undefined *)(iVar2 * 0x8c + 0x398 + param_1);
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x3e14));
  }
  if (DAT_007c569c != 5) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0xc16);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_____Could_not_find_name_for_node_005c5dc0,param_2);
    }
  }
  return &DAT_005c5dbc;
}


