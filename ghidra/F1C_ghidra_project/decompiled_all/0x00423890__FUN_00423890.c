// Function: FUN_00423890 @ 00423890
// Strings:  [__OSC_LOCALE_STRING, GAME.DIC]


int __thiscall FUN_00423890(int param_1,int param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  char local_480 [128];
  undefined1 local_400;
  undefined4 local_3ff;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  iVar3 = 0;
  if (param_3 == (char *)0x0) {
    param_3 = s_GAME_DIC_005c30d0;
  }
  else if (param_2 == 0) goto LAB_004238e4;
  FUN_0058815f(local_480,&DAT_005be860,param_2,param_3);
LAB_004238e4:
  iVar2 = FUN_00534b00();
  if (iVar2 == 0) {
    return -1;
  }
  local_400 = DAT_005ea438;
  puVar4 = &local_3ff;
  for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  iVar2 = FUN_005351d0(0x100);
  while (iVar2 != 0) {
    iVar2 = FUN_004236f0(&local_400,local_100,local_200);
    if ((iVar2 != -1) && (iVar2 = FUN_00423530(local_100,local_200), iVar2 == 0)) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = FUN_005351d0(0x100);
  }
  FUN_005355a0();
  FUN_005890aa(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4),0x10,&LAB_00423830);
  local_480[0] = '\0';
  iVar2 = FUN_00423a00(s___OSC_LOCALE_STRING_005c30bc,local_480);
  if (iVar2 == 0) {
    iVar2 = -1;
    pcVar5 = local_480;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      FUN_00588a34(2,local_480);
    }
  }
  return iVar3;
}


