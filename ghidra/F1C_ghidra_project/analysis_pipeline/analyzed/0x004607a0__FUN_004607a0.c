// Function: FUN_004607a0 @ 004607a0
// Size (bytes): 611


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004607a0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  uint local_3bc;
  uint local_3b8;
  undefined4 local_3b4;
  char local_3b0;
  undefined4 uStack_3af;
  undefined1 local_1b1;
  undefined1 local_1b0 [8];
  undefined2 local_1a8;
  short local_1a6;
  uint local_1a4;
  int local_1a0;
  uint local_19c;
  uint local_198;
  
  FUN_0045c3c0(*(undefined1 *)(param_1 + 0x1b768),*(undefined1 *)(param_1 + 0x1b769));
  FUN_004b33b0(4,0x24,0x14,0,(float)_DAT_008afea0,1);
  local_1a8 = FUN_00460770(*(undefined1 *)(param_1 + 0x1b768),*(undefined1 *)(param_1 + 0x1b769));
  local_3b4 = (float)_DAT_008afea0;
  local_3b8 = (uint)ROUND(local_3b4);
  iVar2 = _rand();
  local_1a6 = ((ushort)iVar2 & 0xff) + (short)((local_3b8 & 0xfffc) << 6);
  puVar3 = DAT_007ce64c;
  if (DAT_007ce64c == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  iVar2 = FUN_004c40b0(puVar3);
  if (iVar2 != 0) {
    puVar3 = *(undefined1 **)(iVar2 + 8);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    cVar1 = FUN_0045c400(puVar3,&local_3bc);
    if (cVar1 != '\0') {
      local_1a4 = local_3bc;
      goto LAB_0046088f;
    }
  }
  local_1a4 = 0;
LAB_0046088f:
  local_3b0 = DAT_005ea438;
  puVar7 = &uStack_3af;
  for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined2 *)puVar7 = 0;
  *(undefined1 *)((int)puVar7 + 2) = 0;
  FUN_004ceef0(&local_3b0,0x200);
  cVar1 = FUN_0045c3d0(&local_3b0,&local_3bc);
  if (cVar1 == '\0') {
    local_1a0 = 0;
  }
  else {
    local_1a0 = DAT_008aced8 + -0x543edc8a + local_3bc;
  }
  pcVar4 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  _strncpy(&local_3b0,pcVar4,0x1ff);
  uVar6 = 0xffffffff;
  local_1b1 = 0;
  pcVar4 = &local_3b0;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = (char *)((int)&local_3b4 + ~uVar6 + 3);
  if (&local_3b0 < pcVar4) {
    do {
      if (*pcVar4 == '.') {
        *pcVar4 = '\0';
        break;
      }
      pcVar4 = pcVar4 + -1;
    } while (&local_3b0 < pcVar4);
  }
  iVar2 = -1;
  pcVar4 = &local_3b0;
  do {
    pcVar8 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar8 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar8;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar8 + -1) = DAT_005c5d24;
  pcVar8[3] = DAT_005c5d28;
  cVar1 = FUN_0045c650(&local_3b0,&local_3bc);
  local_19c = -(uint)(cVar1 != '\0') & local_3bc;
  puVar3 = DAT_007d0434;
  if (DAT_007d0434 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  puVar5 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  FUN_0058815f(&local_3b0,&DAT_005be860,puVar5,puVar3);
  cVar1 = FUN_0045c650(&local_3b0,&local_3bc);
  local_198 = -(uint)(cVar1 != '\0') & local_3bc;
  FUN_00462250(local_1b0,2,0xffffffff,0xffffffff);
  return;
}


