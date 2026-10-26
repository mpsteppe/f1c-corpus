// Function: FUN_00460520 @ 00460520
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, NetComm::SetSelfAsReady(): Setting self as server node, NetComm::SetSelfAsReady(): UNKNOWN NODE ID passed back from server.  No need to set slot, NetComm::SetSelfAsReady(): Setting self as slot %d]


void __thiscall FUN_00460520(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 local_8c [124];
  char local_10;
  undefined1 local_f;
  
  FUN_00461470();
  FUN_004623e0(local_8c);
  if (*(int *)(param_1 + 0x3fc4) != 1) {
    FUN_004614f0(2,1);
  }
  FUN_004614f0(4,0);
  if (DAT_007c569c != 5) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x112a);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_NetComm__SetSelfAsReady____Setti_005c6060);
    }
  }
  local_f = (undefined1)DAT_007d0e50;
  if ((*(int *)(param_1 + 0x3fc4) == 2) || (*(int *)(param_1 + 0x3fc4) == 1)) {
    if (local_10 == -1) {
      uVar2 = FUN_0045e5b0();
      local_10 = (char)uVar2;
      uVar3 = FUN_0057a810();
      FUN_0045e5d0(uVar2,uVar3);
      if (DAT_007c569c != 5) {
        cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1138);
        if (cVar1 != '\0') {
          FUN_004d7aa0(&DAT_008ad25c,s_NetComm__SetSelfAsReady____Setti_005c602c,uVar2);
        }
      }
    }
    FUN_004614f0(1,1);
    if (DAT_007c569c == 5) goto LAB_004606ec;
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x113c);
    if (cVar1 == '\0') goto LAB_004606ec;
    pcVar4 = s_NetComm__SetSelfAsReady____Setti_005c5f98;
  }
  else {
    if (param_2 != -1) {
      local_10 = (char)param_2;
      if (DAT_007c569c != 5) {
        cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1147);
        if (cVar1 != '\0') {
          FUN_004d7aa0(&DAT_008ad25c,s_NetComm__SetSelfAsReady____Setti_005c602c,param_2);
        }
      }
      goto LAB_004606ec;
    }
    if (DAT_007c569c == 5) goto LAB_004606ec;
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x114e);
    if (cVar1 == '\0') goto LAB_004606ec;
    pcVar4 = s_NetComm__SetSelfAsReady____UNKNO_005c5fd0;
  }
  FUN_004d7aa0(&DAT_008ad25c,pcVar4);
LAB_004606ec:
  FUN_004623b0(local_8c);
  FUN_004b0170();
  return;
}


