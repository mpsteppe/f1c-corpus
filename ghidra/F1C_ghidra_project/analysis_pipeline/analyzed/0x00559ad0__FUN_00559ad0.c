// Function: FUN_00559ad0 @ 00559ad0
// Size (bytes): 567


undefined4 __fastcall FUN_00559ad0(int param_1)

{
  char *_Str1;
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined4 local_184;
  char local_180 [384];
  
  uVar5 = 0xffffffff;
  _Str1 = (char *)(param_1 + 0xc);
  pcVar2 = _Str1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  *(undefined1 *)(~uVar5 + 10 + param_1) = 0;
  uVar5 = 0xffffffff;
  pcVar2 = _Str1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (*(char *)(~uVar5 + 10 + param_1) == '\r') {
    uVar5 = 0xffffffff;
    pcVar2 = _Str1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    *(undefined1 *)(~uVar5 + 10 + param_1) = 0;
  }
  pcVar2 = _Str1;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_180 + -(int)_Str1)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  for (iVar6 = 0; (local_180[iVar6] == ' ' || (local_180[iVar6] == '\t')); iVar6 = iVar6 + 1) {
  }
  pcVar2 = local_180 + iVar6;
  iVar6 = (int)_Str1 - (int)pcVar2;
  do {
    cVar1 = *pcVar2;
    pcVar2[iVar6] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar5 = 0xffffffff;
  pcVar2 = _Str1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  cVar1 = *(char *)(~uVar5 + 10 + param_1);
  for (iVar6 = ~uVar5 - 2; (cVar1 == ' ' && (0 < iVar6)); iVar6 = iVar6 + -1) {
    cVar1 = *(char *)(param_1 + 0xb + iVar6);
  }
  *(undefined1 *)(iVar6 + 0xd + param_1) = 0;
  local_184 = param_1;
  iVar3 = _strncmp(_Str1,&DAT_005c30b8,2);
  if (iVar3 == 0) {
    return 2;
  }
  iVar3 = -1;
  pcVar2 = _Str1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar3 == -2) {
    return 2;
  }
  cVar1 = *(char *)(iVar6 + 0xc + param_1);
  if (cVar1 == ' ') {
    return 1;
  }
  if (cVar1 == '}') {
    return 1;
  }
  puVar4 = (undefined1 *)FUN_00587c20(_Str1,&DAT_005c30b8);
  *(undefined1 **)(param_1 + 0x30c) = puVar4;
  if (puVar4 != (undefined1 *)0x0) {
    *puVar4 = 0;
  }
  uVar5 = 0xffffffff;
  iVar6 = 0;
  pcVar2 = _Str1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = param_1;
  pcVar2 = _Str1;
  if (0 < (int)(~uVar5 - 1)) {
    do {
      cVar1 = *pcVar2;
      iVar3 = local_184;
      while ((local_184 = iVar3, cVar1 != '=' && (cVar1 != '\0'))) {
        cVar1 = FUN_00589a35(cVar1);
        iVar6 = iVar6 + 1;
        *pcVar2 = cVar1;
        pcVar2 = _Str1 + iVar6;
        iVar3 = local_184;
        cVar1 = _Str1[iVar6];
      }
      iVar7 = iVar6 + 1;
      if (*(char *)(param_1 + 0xd + iVar6) == '\"') {
        pcVar2 = (char *)(param_1 + 0xd + iVar7);
        iVar7 = iVar6 + 2;
        cVar1 = *pcVar2;
        while (cVar1 != '\"') {
          pcVar2 = (char *)(param_1 + 0xd + iVar7);
          iVar7 = iVar7 + 1;
          cVar1 = *pcVar2;
        }
      }
      cVar1 = _Str1[iVar7];
      iVar6 = iVar7;
      while ((cVar1 != ' ' && (cVar1 != '\0'))) {
        iVar6 = iVar6 + 1;
        cVar1 = _Str1[iVar6];
      }
      uVar5 = 0xffffffff;
      pcVar2 = _Str1;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = _Str1 + iVar6;
    } while (iVar6 < (int)(~uVar5 - 1));
  }
  uVar5 = 0xffffffff;
  iVar6 = 0;
  pcVar2 = _Str1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar5 - 1)) {
    pcVar2 = _Str1;
    do {
      if ((*pcVar2 != ' ') || (local_180[iVar6 + -1] != ',')) {
        local_180[iVar6] = *pcVar2;
        iVar6 = iVar6 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar2 = pcVar2 + 1;
      pcVar8 = _Str1;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
    } while ((int)(pcVar2 + (-0xc - iVar3)) < (int)(~uVar5 - 1));
  }
  local_180[iVar6] = '\0';
  pcVar2 = local_180;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)_Str1 - (int)local_180] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0;
}


