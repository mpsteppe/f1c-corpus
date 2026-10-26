// Function: FUN_00562530 @ 00562530
// Size (bytes): 209


void __fastcall FUN_00562530(undefined4 param_1,char *param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined2 local_100;
  undefined4 local_fe [63];
  
  uVar2 = DAT_005c2aac;
  local_100 = DAT_005c2aac;
  puVar8 = local_fe;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  DAT_008cf080 = DAT_008cf080 ^ 1;
  uVar4 = 0xffffffff;
  do {
    pcVar7 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar3 = -1;
  pcVar6 = (char *)&local_100;
  do {
    pcVar9 = pcVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  pcVar7 = pcVar7 + -uVar4;
  pcVar6 = pcVar9 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  }
  iVar3 = -1;
  pcVar7 = (char *)&local_100;
  do {
    pcVar6 = pcVar7;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar6;
  } while (cVar1 != '\0');
  *(undefined2 *)(pcVar6 + -1) = uVar2;
  iVar3 = FUN_00587c20(param_1,&local_100);
  if (iVar3 != 0) {
    uVar4 = 0xffffffff;
    pcVar7 = (char *)&local_100;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    pcVar6 = (char *)(iVar3 + (~uVar4 - 1));
    pcVar7 = &DAT_008cf088 + DAT_008cf080 * 0x100;
    cVar1 = *pcVar6;
    while ((cVar1 != '\0' && (cVar1 != '\\'))) {
      *pcVar7 = cVar1;
      pcVar9 = pcVar6 + 1;
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar9;
    }
    *pcVar7 = '\0';
  }
  return;
}


