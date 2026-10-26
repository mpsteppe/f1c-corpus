// Function: FUN_00564110 @ 00564110
// Strings:  [other, other]


undefined4 __fastcall
FUN_00564110(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  int local_14;
  
  local_14 = 0;
  uVar2 = FUN_005642f0(param_4,param_5);
  pcVar3 = (char *)FUN_00564220();
  if (param_2 < 1) {
    return uVar2;
  }
  do {
    pcVar6 = *(char **)(param_1 + local_14 * 4);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = &DAT_005ea438;
    }
    iVar4 = 3;
    bVar8 = true;
    pcVar5 = pcVar6;
    pcVar7 = &DAT_005e5050;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar5 == *pcVar7;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) {
      FUN_005642b0();
    }
    else {
      iVar4 = 6;
      if (param_4 == 6) {
        bVar8 = true;
        pcVar5 = s_other_005e5048;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar8 = *pcVar6 == *pcVar5;
          pcVar6 = pcVar6 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar8);
        if (bVar8) {
          cVar1 = *pcVar3;
          while (cVar1 != '\0') {
            if (*pcVar3 == '\x01') {
              *pcVar3 = '\\';
            }
            pcVar6 = pcVar3 + 1;
            pcVar3 = pcVar3 + 1;
            cVar1 = *pcVar6;
          }
          FUN_00564390();
          goto LAB_005641e8;
        }
      }
      FUN_00564270();
      FUN_00564270();
      FUN_00564780();
    }
LAB_005641e8:
    local_14 = local_14 + 1;
    if (param_2 <= local_14) {
      return uVar2;
    }
    pcVar3 = (char *)FUN_00564220();
  } while( true );
}


