// Function: FUN_004637a0 @ 004637a0
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, D:\dev\F1_1999_2002\Source\NetComm.cpp, Could not autojoin session @ "%s", Could not switch to AutoJoin wait page...  Autojoin was not attempted, AutoJoin Failure Page, Client Team Select, AutoJoin attempt %d succeeded]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004637a0(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined *puVar6;
  float10 fVar7;
  float10 fVar8;
  float fStack_e8;
  int iStack_e4;
  int iStack_dc;
  undefined1 auStack_d4 [84];
  undefined1 auStack_80 [128];
  
  if (*(char *)(*param_1 + 0xc6) != '\0') {
    DAT_007d0410 = 5;
    if (DAT_007d0418 < 6) {
      if (DAT_007d041c < 5) {
        DAT_007d0410 = DAT_007d041c;
      }
    }
    else {
      DAT_007d0410 = DAT_007d0418;
    }
    FUN_0057a920();
    uVar2 = FUN_00463750(0);
    cVar1 = FUN_00462ce0(*param_1 + 200,uVar2);
    if (cVar1 == '\0') {
      if ((DAT_007c569c != 5) &&
         (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1cdb), cVar1 != '\0')
         ) {
        FUN_004d7aa0(&DAT_008ad25c,s_Could_not_autojoin_session_____s_005c6508,*param_1 + 200);
      }
    }
    else {
      iVar3 = FUN_00497940(s_AutoJoin_Wait_Page_005c65d8,0xffffffff);
      if (iVar3 != 0) {
        FUN_00568ba0();
        FUN_00568be0(1);
        FUN_00568c60();
        fStack_e8 = 0.0;
        iStack_e4 = 1;
        do {
          iVar3 = FUN_00423a00(s_Joining_Session_005c65c8,&DAT_005ec4cc);
          if (iVar3 != 0) {
            iVar3 = 0;
            do {
              pcVar5 = s_Joining_Session_005c65c8 + iVar3;
              (&DAT_005ec4cc)[iVar3] = *pcVar5;
              iVar3 = iVar3 + 1;
            } while (*pcVar5 != '\0');
          }
          FUN_00566650(&DAT_005ec4cc);
          FUN_005665b0(&DAT_005c65c4);
          auStack_d4[0] = 0;
          FUN_00568d90();
          uVar4 = __ftol();
          FUN_0058815f(auStack_d4,&DAT_005c3280,uVar4);
          FUN_005665b0(auStack_d4);
          FUN_004537b0((float)_DAT_008afe90);
          FUN_00485b90();
          FUN_004f9ad0();
          FUN_004a1830();
          if (DAT_005cc9e8 == -1) {
LAB_00463b0c:
            FUN_004b0170();
            return 0;
          }
          fVar7 = (float10)FUN_00568cf0();
          iVar3 = FUN_00461cd0();
          if (iVar3 == 3) {
            if ((DAT_007c569c != 5) &&
               (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1c87),
               cVar1 != '\0')) {
              FUN_004d7aa0(&DAT_008ad25c,s_AutoJoin_attempt__d_succeeded_005c65a4,iStack_e4);
            }
            FUN_00461550();
            cVar1 = FUN_004630d0(auStack_80);
            if (cVar1 != '\0') {
              FUN_004b1600();
              FUN_00461900();
              puVar6 = &DAT_005ec6e4;
              do {
                FUN_004ef5a0(0xffffffff,0);
                puVar6 = puVar6 + 0x48c0;
              } while ((int)puVar6 < 0x7c54e4);
              DAT_005c329c = 0;
              FUN_0042bc80();
              DAT_007c5690 = 1;
              _DAT_007c56a0 = 2;
              FUN_004a0af0();
              FUN_00497940(s_Client_Team_Select_005c6590,0xffffffff);
              FUN_004b0170();
              return 1;
            }
          }
          else {
            fVar8 = (float10)FUN_00568d90();
            if (((float10)_DAT_007d0f28 < fVar8) || (iStack_dc = FUN_00462d30(0), iStack_dc != 0)) {
              pcVar5 = (char *)FUN_00462da0(5);
              iVar3 = FUN_00423a00(pcVar5,&DAT_005ec4cc);
              if (iVar3 != 0) {
                if (pcVar5 == (char *)0x0) {
                  DAT_005ec4cc = 0;
                }
                else {
                  iVar3 = (int)&DAT_005ec4cc - (int)pcVar5;
                  do {
                    cVar1 = *pcVar5;
                    pcVar5[iVar3] = cVar1;
                    pcVar5 = pcVar5 + 1;
                  } while (cVar1 != '\0');
                }
              }
              FUN_00466080();
              if (iStack_dc != 3) {
                FUN_00497940(s_AutoJoin_Failure_Page_005c6578,0xffffffff);
                FUN_00497250(1);
                goto LAB_00463b0c;
              }
            }
          }
          if (_DAT_0059e5fc < fStack_e8) {
            FUN_00462ce0(*param_1 + 200,uVar2);
            iStack_e4 = iStack_e4 + 1;
            fStack_e8 = 0.0;
          }
          fStack_e8 = (float)fVar7 + fStack_e8;
        } while( true );
      }
      if ((DAT_007c569c != 5) &&
         (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1cd5), cVar1 != '\0')
         ) {
        FUN_004d7aa0(&DAT_008ad25c,s_Could_not_switch_to_AutoJoin_wai_005c6530);
        return 0;
      }
    }
  }
  return 0;
}


