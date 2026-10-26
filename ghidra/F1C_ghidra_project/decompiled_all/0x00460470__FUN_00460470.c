// Function: FUN_00460470 @ 00460470
// Strings:  [Phl_\, D:\dev\F1_1999_2002\Source\NetComm.cpp, Sending server OK request (ret=%s)]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00460470(int param_1)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  undefined1 local_1b0 [424];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((0 < *(int *)(param_1 + 0x3fc4)) && (*(int *)(param_1 + 0x3fc4) < 3)) {
    uStack_4 = 0xffffffff;
    uStack_8 = 0x460486;
    FUN_00460520();
    return;
  }
  FUN_004b33b0(4,3,0,0,(float)_DAT_008afea0,1);
  cVar1 = FUN_00462250(local_1b0,2,0xffffffff,0xffffffff);
  if (DAT_007c569c != 5) {
    cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1113);
    if (cVar2 != '\0') {
      puVar3 = &DAT_005c5f94;
      if (cVar1 == '\0') {
        puVar3 = &DAT_005c5f90;
      }
      FUN_004d7aa0(&DAT_008ad25c,s_Sending_server_OK_request__ret___005c5f6c,puVar3);
    }
  }
  return;
}


