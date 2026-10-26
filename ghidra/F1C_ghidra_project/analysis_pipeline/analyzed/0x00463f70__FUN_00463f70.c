// Function: FUN_00463f70 @ 00463f70
// Size (bytes): 776


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00463f70(int *param_1)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int local_120;
  undefined4 local_11c;
  char local_118 [31];
  undefined1 local_f9;
  char local_f8 [23];
  undefined1 local_e1;
  char local_e0 [31];
  undefined1 local_c1;
  char local_c0 [31];
  undefined1 local_a1;
  char local_90;
  undefined4 local_8f;
  char local_40 [64];
  
  iVar5 = *(int *)(*param_1 + 0x3fc4);
  if (iVar5 != 0) {
    if ((iVar5 == 2) || (iVar5 == 1)) {
      bVar1 = true;
      _DAT_007c56a0 = 3;
    }
    else {
      bVar1 = false;
      _DAT_007c56a0 = 2;
    }
    if (DAT_007ce260 == '\0') {
      FUN_00461470();
      pcVar3 = (char *)(*param_1 + 0x11c);
      iVar5 = -1;
      local_11c = 2;
      pcVar7 = pcVar3;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      if (iVar5 == -2) {
        local_90 = DAT_005ea438;
        puVar8 = &local_8f;
        for (iVar5 = 0x13; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        *(undefined2 *)puVar8 = 0;
        *(undefined1 *)((int)puVar8 + 2) = 0;
        FUN_004b0b20(&local_90,0x50);
        pcVar3 = &local_90;
      }
      _strncpy(local_118,pcVar3,0x1f);
      local_f9 = 0;
      pcVar3 = DAT_007ce684;
      if (DAT_007ce684 == (char *)0x0) {
        pcVar3 = &DAT_005ea438;
      }
      _strncpy(local_f8,pcVar3,0x17);
      local_e1 = 0;
      local_40[0] = '\0';
      cVar2 = FUN_004b0390(local_40,0x40);
      if (cVar2 != '\0') {
        _strncpy(local_e0,local_40,0x1f);
        local_c1 = 0;
        pcVar3 = DAT_007cfe0c;
        if (DAT_007cfe0c == (char *)0x0) {
          pcVar3 = &DAT_005ea438;
        }
        uVar6 = 0xffffffff;
        pcVar7 = pcVar3;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        for (pcVar7 = pcVar3 + (~uVar6 - 1); pcVar3 < pcVar7; pcVar7 = pcVar7 + -1) {
          if (*pcVar7 == '\\') {
            pcVar7 = pcVar7 + 1;
            break;
          }
        }
        _strncpy(local_c0,pcVar7,0x1f);
        local_a1 = 0;
      }
      FUN_004623b0(&local_11c);
      *(undefined4 *)(*param_1 + 0x37c) = DAT_0059f0a8;
    }
    *(undefined1 *)(*param_1 + 0x28) = 1;
    *(undefined1 *)(*param_1 + 0x3fd8) = 8;
    *(undefined1 *)(*param_1 + 0x3fd9) = 0;
    switch(DAT_007d0e50) {
    case 1:
      DAT_007d0e98 = 8;
      break;
    case 2:
      DAT_007d0e98 = 0xc;
      break;
    case 3:
      DAT_007d0e98 = 0xe;
      break;
    case 4:
      DAT_007d0e98 = 0x20;
      break;
    default:
      DAT_007d0e98 = 6;
    }
    iVar5 = DAT_007d0ea0;
    if ((DAT_007d0e98 < DAT_007d0ea0) || (iVar5 = DAT_007d0ea4, DAT_007d0ea4 < DAT_007d0e98)) {
      DAT_007d0e98 = iVar5;
    }
    if (bVar1) {
      FUN_00465150(DAT_007d0e50);
      FUN_00465160(DAT_007d10ec,0xffffffff);
      puVar4 = DAT_007d0e88;
      if (DAT_007d0e88 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      FUN_00566650(puVar4);
      puVar4 = DAT_007d0e90;
      if (DAT_007d0e90 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      FUN_00566650(puVar4);
      _DAT_007d0ec0 = DAT_007d0e9c;
      DAT_007d0ec4 = DAT_007d0ea0;
      DAT_007d0ebc = DAT_007d0e98;
      DAT_007d0ec8 = DAT_007d0ea4;
    }
    iVar5 = DAT_007d0e98;
    if (DAT_007d0e98 < 5) {
      iVar5 = 4;
    }
    local_120 = DAT_007d0ebc;
    if ((iVar5 <= DAT_007d0ebc) && (local_120 = DAT_007d0e98, DAT_007d0e98 < 5)) {
      local_120 = 4;
    }
    FUN_0045f2a0((float)local_120);
    FUN_0057a750(DAT_007d0ee0);
    *(undefined1 *)(*param_1 + 0x30) = 0;
    FUN_0045d490();
  }
  FUN_0045ecd0();
  return;
}


