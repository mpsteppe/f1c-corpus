// Function: FUN_0055a790 @ 0055a790
// Strings:  [INSTANCE, INSTANCE, INSTANCE, STORAGE, STORAGE, ADJACENT, LIGHT]


undefined4 __thiscall FUN_0055a790(undefined4 param_1,undefined4 param_2,int *param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  undefined4 local_114;
  char local_110 [16];
  undefined1 local_100 [256];
  
  local_114 = 0;
  pvVar1 = operator_new(0x108);
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00548e20();
  }
  *puVar2 = param_1;
  iVar3 = FUN_00559a70();
  while ((iVar3 != 1 && (*param_3 != 3))) {
    if (*param_3 != 2) {
      FUN_00559e20(&DAT_005dc274,local_110,0);
      iVar3 = FUN_00559e20(s_INSTANCE_005cd620,local_100,0);
      if (iVar3 != 0) {
        FUN_00549020(local_100);
      }
      iVar3 = FUN_00559e20(s_LIGHT_005dc298,local_100,0);
      if (iVar3 != 0) {
        FUN_005491d0(local_100);
      }
      iVar3 = FUN_00559e20(&DAT_005dc290,local_100,0);
      if (iVar3 != 0) {
        FUN_005492f0(local_100);
      }
      iVar3 = FUN_00559e20(s_ADJACENT_005dc284,local_100,0);
      if (iVar3 != 0) {
        FUN_005493b0(local_100);
      }
    }
    iVar3 = FUN_00559a70();
  }
  iVar3 = 8;
  bVar6 = true;
  pcVar4 = local_110;
  pcVar5 = s_STORAGE_005dc27c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    local_114 = 0x40;
  }
  iVar3 = 9;
  bVar6 = true;
  pcVar4 = local_110;
  pcVar5 = s_INSTANCE_005cd620;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (bVar6) {
    local_114 = 0x80;
  }
  FUN_00548e80(param_2,local_114);
  FUN_0054a270(puVar2);
  return 0;
}


