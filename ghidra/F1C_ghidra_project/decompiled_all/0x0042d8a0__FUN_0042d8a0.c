// Function: FUN_0042d8a0 @ 0042d8a0
// Strings:  [D:\dev\F1_1999_2002\Source\game.cpp, Next state %d was not expected]


undefined4 __fastcall FUN_0042d8a0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  
  *param_1 = 5;
  do {
    FUN_004f9f00();
    iVar2 = FUN_00461cd0();
    if (iVar2 == 1) {
      cVar1 = '\x01';
    }
    else {
      iVar2 = FUN_004a0fd0();
      cVar1 = DAT_007ce254;
      if (iVar2 != 5) {
        if (iVar2 == 4) {
          return 0;
        }
        if (iVar2 != 6) {
          cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_game__005c3590,0x274);
          if (cVar1 != '\0') {
            FUN_004d7aa0(&DAT_008ad25c,s_Next_state__d_was_not_expected_005c3670,iVar2);
          }
        }
        return 1;
      }
    }
    FUN_004ba180();
    FUN_00463ca0();
    FUN_004ba150();
    FUN_004b3b40();
    FUN_00404460();
    FUN_004d4580();
    FUN_00455e50();
    FUN_0042c690();
    FUN_004b3ba0();
    FUN_004643c0();
    FUN_00463cd0();
    FUN_004ba6c0();
    FUN_004b3b40();
    if (cVar1 == '\0') {
      FUN_0040ca30();
      FUN_004cfcc0();
      FUN_004b40a0();
      FUN_0049f070();
    }
    else {
      FUN_004cfcc0();
    }
    FUN_004f9f30();
    FUN_004c8b70();
    FUN_004fa7e0();
    FUN_004fcee0();
    FUN_004a1830();
    iVar2 = FUN_00461cd0();
  } while (iVar2 != 1);
  return 0;
}


