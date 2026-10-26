// Function: FUN_004da9e0 @ 004da9e0
// Strings:  [%d:%06.3f, %d %s]


void __thiscall FUN_004da9e0(int param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  float10 fVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float local_114;
  undefined4 local_110;
  int local_10c;
  int local_108;
  undefined4 local_104;
  char local_100;
  undefined4 local_ff;
  undefined1 local_81;
  char local_80;
  undefined4 local_7f;
  
  local_100 = DAT_005ea438;
  puVar4 = &local_ff;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  local_80 = DAT_005ea438;
  puVar4 = &local_7f;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  FUN_004dac30(param_2,&local_10c,&local_104,&local_110);
  if (*(int *)(param_3 + 0x4060) == 1) {
    iVar3 = FUN_00423a00(&DAT_005cce6c,&DAT_005ec4cc);
    if (iVar3 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = &DAT_005cce6c + iVar3;
        (&DAT_005ec4cc)[iVar3] = *pcVar1;
        iVar3 = iVar3 + 1;
      } while (*pcVar1 != '\0');
    }
    FUN_0058815f(&local_80,s__d__s_005c3778,*(undefined4 *)(param_1 + 0x24));
  }
  else {
    fVar5 = (float10)FUN_004dad50();
    local_114 = (float)fVar5;
    fVar5 = (float10)FUN_004dad30();
    if (((float10)DAT_0059e440 < fVar5) &&
       (fVar2 = (float10)local_114, local_114 = (float)(fVar5 - fVar2),
       (float10)DAT_0059e440 < fVar5 - fVar2)) {
      FUN_0049b630(local_114,&local_108,&local_114);
      if (local_108 < 1) {
        FUN_0058815f(&local_80,&DAT_005d4b74,(double)local_114);
      }
      else {
        FUN_0058815f(&local_80,s__d__06_3f_005c3310,local_108);
      }
    }
  }
  FUN_0058815f(&local_100,&DAT_005ccef0);
  FUN_004d7e40(&local_100,local_10c,local_110,0xffffff,0,3,0x3f800000,0x3f800000);
  _strncpy(&local_100,(char *)(param_3 + 0x46f8),0x7f);
  local_81 = 0;
  FUN_00589901(&local_100);
  local_10c = local_10c + 0x28;
  FUN_004d7e40(&local_100,local_10c,local_110,0xffffff,0,0,0x3f800000,0x3f800000);
  _strncpy(&local_100,&local_80,0x7f);
  local_81 = 0;
  FUN_004d7e40(&local_100,local_104,local_110,0xffff00,1,0,0x3f800000,0x3f800000);
  return;
}


