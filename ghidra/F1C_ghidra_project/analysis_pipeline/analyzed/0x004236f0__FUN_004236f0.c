// Function: FUN_004236f0 @ 004236f0
// Size (bytes): 315


undefined4 FUN_004236f0(char *param_1,undefined1 *param_2,undefined1 *param_3)

{
  char *pcVar1;
  undefined1 *puVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  int local_4;
  
  iVar7 = 0;
  local_4 = 0;
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  puVar2 = (undefined1 *)FUN_00587c20(param_1,&DAT_005c30b8);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0;
  }
  puVar2 = (undefined1 *)FUN_00587c20(param_1,&DAT_005c30b4);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0;
  }
  puVar2 = (undefined1 *)FUN_00587c20(param_1,&DAT_005c30b0);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = 0;
  }
  iVar4 = -1;
  pcVar3 = param_1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar6 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar6 != '\0');
  if (iVar4 == -2) {
    return 0xffffffff;
  }
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  pcVar3 = (char *)FUN_00587c20(param_1,&DAT_005c30ac);
  if (pcVar3 != (char *)0x0) {
    cVar6 = *param_1;
    while (cVar6 != '\"') {
      if (param_1 == pcVar3) goto LAB_004237d5;
      pcVar5 = param_1 + 1;
      param_1 = param_1 + 1;
      cVar6 = *pcVar5;
    }
    if (param_1 < pcVar3) {
      cVar6 = param_1[1];
      if (cVar6 != '\"') {
        iVar7 = 0;
        do {
          if (param_1 + 1 == pcVar3) break;
          param_2[iVar7] = cVar6;
          cVar6 = param_1[2];
          iVar7 = iVar7 + 1;
          param_1 = param_1 + 1;
        } while (cVar6 != '\"');
      }
      param_2[iVar7] = 0;
    }
LAB_004237d5:
    pcVar5 = pcVar3;
    if (*pcVar3 != '\"') {
      do {
        if (pcVar5 == pcVar3 + 0x100) break;
        pcVar1 = pcVar5 + 1;
        pcVar5 = pcVar5 + 1;
      } while (*pcVar1 != '\"');
    }
    if (pcVar5 < pcVar3 + 0x100) {
      cVar6 = pcVar5[1];
      while ((cVar6 != '\"' && (pcVar5 + 1 != pcVar3 + 0x100))) {
        param_3[local_4] = cVar6;
        cVar6 = pcVar5[2];
        local_4 = local_4 + 1;
        pcVar5 = pcVar5 + 1;
      }
      param_3[local_4] = 0;
    }
  }
  return 0;
}


