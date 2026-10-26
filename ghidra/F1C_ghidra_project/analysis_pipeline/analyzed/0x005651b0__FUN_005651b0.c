// Function: FUN_005651b0 @ 005651b0
// Size (bytes): 507


int __fastcall FUN_005651b0(int param_1)

{
  char *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  int local_194;
  int local_190;
  int local_18c;
  char local_180 [384];
  
  pcVar1 = (char *)(param_1 + 0x198);
  uVar10 = 0xffffffff;
  pcVar9 = pcVar1;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar6 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar6 != '\0');
  local_18c = 0;
  local_190 = 0;
  bVar4 = false;
  bVar5 = false;
  bVar3 = false;
  local_194 = 0;
  for (iVar11 = 0;
      (iVar7 = FUN_00589bf3((int)pcVar1[iVar11]), iVar7 != 0 && (pcVar1[iVar11] != '\0'));
      iVar11 = iVar11 + 1) {
  }
  while ((iVar11 < (int)(~uVar10 - 1) && (!bVar3))) {
    cVar6 = pcVar1[iVar11];
    bVar2 = true;
    if (cVar6 == '\"') {
      bVar4 = !bVar4;
    }
    if (bVar4) goto LAB_005652b8;
    if (cVar6 != '/') {
      bVar5 = false;
    }
    iVar7 = (int)cVar6;
    switch(iVar7) {
    case 10:
    case 0xd:
      break;
    default:
      if ((local_190 != 0) && (iVar8 = FUN_00589bf3(iVar7), iVar8 != 0)) {
        bVar2 = false;
      }
      cVar6 = FUN_00589a35(iVar7);
      if (bVar2) goto LAB_005652b8;
      break;
    case 0x28:
      local_190 = local_190 + 1;
      goto LAB_005652b8;
    case 0x29:
      local_190 = local_190 + -1;
LAB_005652b8:
      local_180[local_194] = cVar6;
      local_194 = local_194 + 1;
      break;
    case 0x2f:
      if (!bVar5) {
        bVar5 = true;
        goto LAB_005652b8;
      }
      bVar3 = true;
      local_194 = local_194 + -1;
      local_18c = 3;
    }
    iVar11 = iVar11 + 1;
  }
  local_180[local_194] = '\0';
  pcVar9 = local_180;
  do {
    cVar6 = *pcVar9;
    pcVar9[(int)pcVar1 - (int)local_180] = cVar6;
    pcVar9 = pcVar9 + 1;
  } while (cVar6 != '\0');
  uVar10 = 0xffffffff;
  pcVar9 = pcVar1;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    cVar6 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar6 != '\0');
  for (iVar11 = ~uVar10 - 2; (0 < iVar11 && (pcVar1[iVar11] == ' ')); iVar11 = iVar11 + -1) {
  }
  iVar7 = -1;
  *(undefined1 *)(iVar11 + 0x199 + param_1) = 0;
  pcVar9 = pcVar1;
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    cVar6 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar6 != '\0');
  if (local_18c == 3) {
    if (iVar7 != -2) {
      return 0;
    }
  }
  else {
    if (iVar7 == -2) {
      return 1;
    }
    cVar6 = *(char *)(iVar11 + 0x198 + param_1);
    if (cVar6 == ' ') {
      return 1;
    }
    if (cVar6 == '}') {
      return 2;
    }
    iVar11 = FUN_005887ed(pcVar1,&DAT_005c2c18,local_180);
    if (iVar11 == -1) {
      return 4;
    }
  }
  return local_18c;
}


