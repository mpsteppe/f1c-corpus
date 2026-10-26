// Function: FUN_00461de0 @ 00461de0
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, Starting Internet update... (err=%d), Starting LAN update on ports %d - %d... (err=%d)]


void __fastcall FUN_00461de0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (*(int *)(*param_1 + 0x1b79c) != 0) {
    iVar2 = FUN_00563e70();
    if (iVar2 != 0) {
      FUN_00563df0();
    }
    iVar2 = FUN_00563e00();
    if (iVar2 == 0) {
      if (DAT_007d0e74 == 1) {
        uVar3 = FUN_00562c80();
        if (DAT_007c569c != 5) {
          cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1690);
          if (cVar1 != '\0') {
            FUN_004d7aa0(&DAT_008ad25c,s_Starting_Internet_update_____err_005c616c,uVar3);
          }
        }
      }
      else {
        uVar4 = (uint)DAT_007d0fe8;
        uVar3 = FUN_00563020(uVar4,uVar4 + 99,1);
        if (DAT_007c569c != 5) {
          cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1685);
          if (cVar1 != '\0') {
            FUN_004d7aa0(&DAT_008ad25c,s_Starting_LAN_update_on_ports__d___005c6194,uVar4,uVar4 + 99
                         ,uVar3);
            return;
          }
        }
      }
    }
  }
  return;
}


