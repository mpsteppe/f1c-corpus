// Function: FUN_00433890 @ 00433890
// Strings:  [SettingsAI, SettingsAIQual, SettingsCopy]


undefined4 FUN_00433890(char *param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char local_100 [256];
  
  *param_1 = '\0';
  puVar2 = DAT_007ce5ec;
  if (DAT_007ce5ec == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar3 = FUN_004c5840(puVar2);
  if (iVar3 == 0) {
    return 1;
  }
  pcVar7 = (char *)0x0;
  iVar3 = FUN_005679c0(PTR_s_SettingsCopy_005c3fa8);
  if (iVar3 != 0) {
    pcVar7 = (char *)FUN_00567970();
  }
  iVar3 = FUN_005679c0(PTR_s_SettingsAI_005c3fb0);
  if (iVar3 != 0) {
    pcVar7 = (char *)FUN_00567970();
  }
  iVar3 = FUN_00432e50(DAT_007c56a4);
  if (iVar3 == 5) {
    iVar3 = FUN_005679c0(PTR_s_SettingsAIQual_005c3fac);
    if (iVar3 != 0) {
      pcVar7 = (char *)FUN_00567970();
    }
  }
  if (pcVar7 == (char *)0x0) {
    return 1;
  }
  pcVar4 = DAT_005ec440;
  if (DAT_005ec440 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  iVar3 = -(int)pcVar4;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)(local_100 + iVar3)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar5 = 0xffffffff;
  do {
    pcVar4 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar4 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar4;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar3 = -1;
  pcVar7 = local_100;
  do {
    pcVar8 = pcVar7;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar4 + -uVar5;
  pcVar4 = pcVar8 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar4 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar4 = pcVar4 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar4 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar4 = pcVar4 + 1;
  }
  _strncpy(param_1,local_100,param_2 - 1U);
  param_1[param_2 - 1U] = '\0';
  return 0;
}


