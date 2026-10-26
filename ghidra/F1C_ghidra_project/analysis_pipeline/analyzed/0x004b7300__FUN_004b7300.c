// Function: FUN_004b7300 @ 004b7300
// Size (bytes): 497


bool __thiscall FUN_004b7300(int param_1,undefined4 param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined1 *puVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  FUN_004b7500(1);
  if (param_3 == '\0') {
    piVar1 = (int *)(param_1 + 0x6e4);
    FUN_00566b20(param_2,0);
    cVar4 = FUN_004b6c90(piVar1);
    if (cVar4 == '\0') {
      FUN_00566b90();
      return *piVar1 != 0;
    }
    FUN_004b86e0(*(undefined4 *)(param_1 + 0xf30));
    *(undefined4 *)(param_1 + 0x700) = 2;
    return *piVar1 != 0;
  }
  FUN_004b5f60();
  FUN_004b5e50();
  iVar3 = *(int *)(param_1 + 0x6c0);
  while (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 4);
    FUN_004bb3d0();
    FUN_00587bcf(iVar3);
    iVar3 = iVar2;
  }
  *(undefined4 *)(param_1 + 0x6c0) = 0;
  *(undefined4 *)(param_1 + 0x6c4) = 0;
  *(undefined4 *)(param_1 + 0x6c8) = 0;
  *(undefined4 *)(param_1 + 0x6cc) = 0;
  FUN_00566650(param_2);
  pcVar8 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  uVar6 = 0xffffffff;
  pcVar7 = pcVar8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar4 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar4 != '\0');
  for (pcVar7 = pcVar8 + (~uVar6 - 1); pcVar8 < pcVar7; pcVar7 = pcVar7 + -1) {
    if (*pcVar7 == '\\') {
      pcVar7 = pcVar7 + 1;
      break;
    }
  }
  FUN_00566650(pcVar7);
  pcVar8 = DAT_007ce608;
  if (DAT_007ce608 == (char *)0x0) {
    pcVar8 = &DAT_005ea438;
  }
  uVar6 = 0xffffffff;
  pcVar7 = pcVar8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar4 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar4 != '\0');
  pcVar7 = pcVar8 + (~uVar6 - 1);
  do {
    if (pcVar7 <= pcVar8) {
LAB_004b73dd:
      FUN_00566650(pcVar7);
      FUN_004b8010();
      FUN_004b9830((undefined4 *)(param_1 + 0x704));
      puVar5 = *(undefined1 **)(param_1 + 0x704);
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      cVar4 = FUN_00566940(puVar5,0,0,1);
      if (cVar4 == '\0') {
        FUN_00566650(&DAT_005ea438);
        *(undefined4 *)(param_1 + 0x700) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x700) = 1;
      }
      *(undefined4 *)(param_1 + 0xf24) = 0;
      *(undefined4 *)(param_1 + 0xf28) = 0;
      *(undefined4 *)(param_1 + 0xf2c) = 0;
      *(undefined4 *)(param_1 + 0xd28) = 0;
      *(undefined1 *)(param_1 + 0xf78) = 0;
      *(undefined4 *)(param_1 + 0xf1c) = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894);
      *(undefined4 *)(param_1 + 0xf20) = DAT_007c56a4;
      return *(int *)(param_1 + 0x6e4) != 0;
    }
    if (*pcVar7 == '\\') {
      pcVar7 = pcVar7 + 1;
      goto LAB_004b73dd;
    }
    pcVar7 = pcVar7 + -1;
  } while( true );
}


