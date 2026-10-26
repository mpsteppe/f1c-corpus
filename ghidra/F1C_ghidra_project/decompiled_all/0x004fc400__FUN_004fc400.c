// Function: FUN_004fc400 @ 004fc400
// Strings:  [%s%c%s]


void FUN_004fc400(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char local_c0 [32];
  char local_a0 [32];
  undefined1 local_80 [32];
  undefined1 local_60 [32];
  undefined1 local_40 [32];
  char local_20 [32];
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_c0 + -(int)param_2)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)FUN_00589db0(local_c0,0x2e);
  if (pcVar2 == (char *)0x0) {
    iVar5 = 0;
    do {
      cVar1 = (&DAT_005d6f48)[iVar5];
      local_a0[iVar5] = cVar1;
      iVar5 = iVar5 + 1;
    } while (cVar1 != '\0');
  }
  else {
    pcVar3 = pcVar2;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_a0 + -(int)pcVar2)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    *pcVar2 = '\0';
  }
  uVar4 = 0xffffffff;
  pcVar2 = local_c0;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar4 - 1)) {
    cVar1 = local_c0[~uVar4 - 2];
    if (('@' < cVar1) && (cVar1 < 'E')) {
      local_c0[~uVar4 - 2] = '\0';
    }
  }
  iVar6 = 0x41;
  iVar5 = 4;
  do {
    FUN_0058815f(local_60,s__s_c_s_005d6f40,local_c0,iVar6,local_a0);
    FUN_0058815f(local_40,&DAT_005be860,local_c0,local_a0);
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2[(int)(local_20 + -(int)param_2)] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_0058815f(local_80,&DAT_005d6f38,param_1,iVar6);
    FUN_004dc770(local_60,local_40,local_20,0,0);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


