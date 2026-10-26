// Function: FUN_004d7150 @ 004d7150
// Strings:  [Could not open %s, D:\dev\F1_1999_2002\Source\tire_manager.cpp, D:\dev\F1_1999_2002\Source\tire_manager.cpp, D:\dev\F1_1999_2002\Source\tire_manager.cpp, D:\dev\F1_1999_2002\Source\tire_manager.cpp, D:\dev\F1_1999_2002\Source\tire_manager.cpp, Bad syntax in file %s caused miscount, Bad syntax in file %s caused miscount of tire compounds]


void __thiscall FUN_004d7150(int param_1,char *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_378;
  undefined1 local_374 [27];
  char acStack_359 [64];
  undefined1 local_319;
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  FUN_004d7050();
  FUN_00566650(param_2);
  FUN_00568a60(0x5b,param_1 + 0x20);
  uVar5 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  for (pcVar6 = param_2 + (~uVar5 - 1); param_2 < pcVar6; pcVar6 = pcVar6 + -1) {
    if (*pcVar6 == '\\') {
      pcVar6 = pcVar6 + 1;
      break;
    }
  }
  _strncpy(acStack_359 + 1,pcVar6,0x3f);
  uVar5 = 0xffffffff;
  pcVar6 = acStack_359;
  local_319 = 0;
  do {
    pcVar6 = pcVar6 + 1;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
  } while (*pcVar6 != '\0');
  pcVar6 = acStack_359 + ~uVar5;
  if (acStack_359 + 1 < pcVar6) {
    do {
      if (*pcVar6 == '.') {
        *pcVar6 = '\0';
        break;
      }
      pcVar6 = pcVar6 + -1;
    } while (acStack_359 + 1 < pcVar6);
  }
  FUN_00589901(acStack_359 + 1);
  FUN_00566650(acStack_359 + 1);
  FUN_005668b0();
  cVar1 = FUN_00566b20(param_2,1);
  if (cVar1 == '\0') {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x366);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Could_not_open__s_005c6810,param_2);
    }
  }
  else {
    puVar8 = local_180;
    for (iVar7 = 0x60; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    local_198 = 0;
    local_184 = 0;
    local_18c = 0;
    local_188 = 0;
    local_194 = 1;
    iVar7 = FUN_00566cc0(local_180,0x180);
    while (iVar7 != 0) {
      FUN_005651b0();
      iVar7 = FUN_00587c20(local_180,s__SLIPCURVE__005d4944);
      if (iVar7 == 0) {
        iVar7 = FUN_00587c20(local_180,s__COMPOUND__005d4938);
        if (iVar7 != 0) {
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        }
      }
      else {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      }
      iVar7 = FUN_00566cc0(local_180,0x180);
    }
    iVar7 = *(int *)(param_1 + 8);
    piVar2 = operator_new(iVar7 * 0x18 + 4);
    if (piVar2 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = piVar2 + 1;
      *piVar2 = iVar7;
      piVar2 = piVar3;
      if (-1 < iVar7 + -1) {
        do {
          *piVar2 = 0;
          piVar2[1] = -1;
          piVar2[5] = 0;
          iVar7 = iVar7 + -1;
          piVar2 = piVar2 + 6;
        } while (iVar7 != 0);
      }
    }
    iVar7 = *(int *)(param_1 + 0x10);
    *(int **)(param_1 + 0xc) = piVar3;
    piVar2 = operator_new(iVar7 * 0x2a8 + 4);
    if (piVar2 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = piVar2 + 1;
      *piVar2 = iVar7;
      piVar2 = piVar3;
      if (-1 < iVar7 + -1) {
        do {
          *piVar2 = 0;
          piVar2[1] = -1;
          FUN_004d68a0();
          FUN_004d68a0();
          iVar7 = iVar7 + -1;
          piVar2 = piVar2 + 0xaa;
        } while (iVar7 != 0);
      }
    }
    *(int **)(param_1 + 0x14) = piVar3;
    if (((*(int *)(param_1 + 0x10) == 0) || (piVar3 == (int *)0x0)) &&
       (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x37d), cVar1 != '\0')) {
      FUN_004d7aa0(&DAT_008ad25c,s_No_compounds_found_in__s_005d491c,param_2);
    }
    FUN_00566d30();
    iVar7 = 0;
    local_378 = 0;
    iVar4 = FUN_00566cc0(local_180,0x180);
    while (iVar4 != 0) {
      FUN_005651b0();
      iVar4 = FUN_00587c20(local_180,s__SLIPCURVE__005d4944);
      if (iVar4 != 0) {
        if (iVar7 < *(int *)(param_1 + 8)) {
          iVar7 = iVar7 + 1;
          FUN_004d5f70(local_374);
          goto LAB_004d744c;
        }
        cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x391);
        if (cVar1 != '\0') {
          pcVar6 = s_Bad_syntax_in_file__s_caused_mis_005d48e0;
LAB_004d74fc:
          FUN_004d7aa0(&DAT_008ad25c,pcVar6,param_2);
        }
        break;
      }
LAB_004d744c:
      iVar4 = FUN_00587c20(local_180,s__COMPOUND__005d4938);
      if (iVar4 != 0) {
        if (*(int *)(param_1 + 0x10) <= local_378) {
          cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x3a0);
          if (cVar1 != '\0') {
            pcVar6 = s_Bad_syntax_in_file__s_caused_mis_005d48a8;
            goto LAB_004d74fc;
          }
          break;
        }
        local_378 = local_378 + 1;
        FUN_004d6b00(local_374);
      }
      iVar4 = FUN_00566cc0(local_180,0x180);
    }
    if (((iVar7 != *(int *)(param_1 + 8)) || (local_378 != *(int *)(param_1 + 0x10))) &&
       (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x3ad), cVar1 != '\0')) {
      FUN_004d7aa0(&DAT_008ad25c,s_Bad_syntax_in_file__s_caused_mis_005d4880,param_2);
    }
    FUN_00566b90();
  }
  FUN_005668d0();
  return;
}


